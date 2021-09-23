#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// https://en.wikipedia.org/wiki/Spherical_coordinate_system
struct spherical_coord_f
{
    float theta;
    float phi;
    float rho;
};

struct cartesian_coord_f
{
    float x;
    float y;
    float z;
};

struct cartesian_coord_f
spherical_to_cartesian_f(struct spherical_coord_f const point)
{
    struct cartesian_coord_f ret;
    float const rho_sin_theta = point.rho * sinf(point.theta);
    ret.x = rho_sin_theta * cosf(point.phi);
    ret.y = rho_sin_theta * sinf(point.phi);
    ret.z = cosf(point.theta);
    return ret;
}

int
main(int const argc, char const * const * argv)
{
    printf("sizeof(spherical_coord_f) == %lu\n", sizeof(struct spherical_coord_f));
    printf("sizeof(cartesian_coord_f) == %lu\n", sizeof(struct cartesian_coord_f));
    size_t const coord_count = 2U << 30U;
    printf("coord_count == %lu\n", coord_count);
    struct spherical_coord_f const * const spherical_coords = (struct spherical_coord_f const * const)(malloc(sizeof(struct spherical_coord_f) * coord_count));
    if(!spherical_coords)
    {
        return EXIT_FAILURE;
    }
    struct cartesian_coord_f * const cartesian_coords = (struct cartesian_coord_f * const)(malloc(sizeof(struct cartesian_coord_f) * coord_count));
    if(!cartesian_coords)
    {
        return EXIT_FAILURE;
    }
    clock_t const begin = clock();
    for(size_t i = 0U; i < coord_count; ++i)
    {
        cartesian_coords[i] = spherical_to_cartesian_f(spherical_coords[i]);
    }
    clock_t const end = clock();
    double delta_t = ((double)(end - begin)) / CLOCKS_PER_SEC;
    printf("delta_t == %f\n", delta_t);
    printf("iters per second == %lu\n", coord_count / (size_t)(delta_t));
    return 0;
}
