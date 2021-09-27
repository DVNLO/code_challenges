#define _POSIX_C_SOURCE 199309L

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <pthread.h>
#include <unistd.h>

struct coord_3f
{
    float first;
    float second;
    float third;
};

// Transforms a point in spherical coordinates to a point in 
// cartesian coordinates. 
// https://en.wikipedia.org/wiki/Spherical_coordinate_system
struct coord_3f
spherical_to_cartesian_3f(struct coord_3f const point)
{
    struct coord_3f ret;
    float const rho_sin_theta = point.third * sinf(point.first);
    ret.first = rho_sin_theta * cosf(point.second);  // x
    ret.second = rho_sin_theta * sinf(point.second); // y
    ret.third = point.third * cosf(point.first);     // z
    return ret;
}


void
transform_coord_3f_seq(struct coord_3f const * const coords_in, 
                       struct coord_3f * const coords_out, 
                       size_t const coord_count,
                       struct coord_3f(*transformer)(struct coord_3f))
{
    for(size_t i = 0U; i < coord_count; ++i)
    {
        coords_out[i] = transformer(coords_in[i]);
    }
}

struct transform_coord_3f_args
{
    struct coord_3f * coords_in;
    struct coord_3f * coords_out;
    size_t coord_count;
    struct coord_3f(*transformer)(struct coord_3f);
};

void *
transform_coord_3f_worker(void * data)
{
    assert(data);
    struct transform_coord_3f_args * const args 
        = (struct transform_coord_3f_args * const)(data);
    assert(args);
    transform_coord_3f_seq(args->coords_in, 
        args->coords_out, args->coord_count, args->transformer);
    free(data);
    return NULL;
}

size_t
min(size_t const l, size_t const r)
{
    if(l < r)
        return l;
    else
        return r;
}

void
transform_coord_3f_para(struct coord_3f * coords_in, 
                        struct coord_3f * coords_out, 
                        size_t const coord_count,
                        struct coord_3f(*transformer)(struct coord_3f),
                        size_t const thread_count)
{
    pthread_t * const threads = (pthread_t * const)(malloc(sizeof(pthread_t) * thread_count));
    assert(threads);
    size_t const coord_count_per_thread = coord_count / thread_count;
    for(size_t i = 0U; i < thread_count; ++i)
    {
        size_t const offset_idx = i * coord_count_per_thread;
        struct transform_coord_3f_args * const args = (struct transform_coord_3f_args * const)(malloc(sizeof(struct transform_coord_3f_args)));
        assert(args);
        args->coords_in = coords_in + offset_idx;
        args->coords_out = coords_out + offset_idx;
        args->coord_count = min(coord_count_per_thread, coord_count - offset_idx);
        args->transformer = spherical_to_cartesian_3f;
        //printf("%lu : %p %p %lu\n", i, args->coords_in, args->coords_out, args->coord_count);
        pthread_create(&threads[i], NULL, transform_coord_3f_worker, (void *)(args));
    }
    for(size_t i = 0U; i < thread_count; ++i)
    {
        pthread_join(threads[i], NULL);
    }
    free(threads);
}

double
delta_t(struct timespec const * const begin, struct timespec const * const end)
{
    double elapsed = end->tv_sec - begin->tv_sec;
    elapsed += (end->tv_nsec - begin->tv_nsec) / 1000000000.0;
    return elapsed;
}

int
main(int const argc, char const * const * argv)
{
    printf("sizeof(spherical_coord_f) == %lu\n", sizeof(struct coord_3f));
    size_t const coord_count = 2U << 29U;
    printf("coord_count == %lu\n", coord_count);
    struct coord_3f * const coords = (struct coord_3f * const)(malloc(sizeof(struct coord_3f) * coord_count));
    if(!coords)
    {
        return EXIT_FAILURE;
    }
    int sample_count = 32;
    
    ///////////////////////////////////////////////////////////////////////////
    transform_coord_3f_seq(coords, coords, coord_count, spherical_to_cartesian_3f);
    struct timespec begin_seq;
    clock_gettime(CLOCK_MONOTONIC, &begin_seq);
    for(int i = 0; i < sample_count; ++i)
    {
        transform_coord_3f_seq(coords, coords, coord_count, spherical_to_cartesian_3f);
    }
    struct timespec end_seq;
    clock_gettime(CLOCK_MONOTONIC, &end_seq);
    double const elapsed_seq = delta_t(&begin_seq, &end_seq);
    printf("mean seq delta_t == %f\n", elapsed_seq / sample_count);
    ///////////////////////////////////////////////////////////////////////////
    
    ///////////////////////////////////////////////////////////////////////////
    size_t const thread_count = 24U;
    transform_coord_3f_para(coords, coords, coord_count, spherical_to_cartesian_3f, thread_count);
    struct timespec begin_para;
    clock_gettime(CLOCK_MONOTONIC, &begin_para);
    for(int i = 0; i < sample_count; ++i)
    {
        transform_coord_3f_para(coords, coords, coord_count, spherical_to_cartesian_3f, thread_count);
    }
    struct timespec end_para;
    clock_gettime(CLOCK_MONOTONIC, &end_para);
    double const elapsed_para = delta_t(&begin_para, &end_para);
    printf("mean para delta_t == %f\n", elapsed_para / sample_count);
    ///////////////////////////////////////////////////////////////////////////
    
    return 0;
}
