#include <limits.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int * vals;
    size_t n;
    long long sum;
} 
arr;    //gument pack

void * sum(void * const arg)
{
    arr * const vals = (arr *)(arg);
    long long s = 0;
    for(size_t i = 0; i < vals->n; ++i)
    {
        s += vals->vals[i];
    }
    vals->sum = s;
    pthread_exit((void *)(vals));
}

int main()
{
    int const thread_count = 24;
    size_t const size_vals = INT_MAX - INT_MAX % 24;
    printf("size_vals == %lu\n", size_vals);
    int * const vals = (int *)(malloc(sizeof(int) * size_vals));
    if(!vals)
    {
        return EXIT_FAILURE;
    }
    for(size_t i = 0; i < size_vals; ++i)
    {
        vals[i] = i + 1;
    }
    pthread_t * const thread_ids = (pthread_t *)(malloc(sizeof(pthread_t) * thread_count));
    if(!thread_ids)
    {
        return EXIT_FAILURE;
    }
    int rc;
    for(int i = 0; i < thread_count; ++i)
    {
        arr * const thread_data = (arr *)(malloc(sizeof(arr)));
        if(!thread_data)
        {
            return EXIT_FAILURE;
        }
        //thread_data->n = size_vals/thread_count;
        thread_data->n = size_vals;
        //thread_data->vals = vals + (i * thread_data->n);    // TODO : handle remainder case
        thread_data->vals = vals;
        rc = pthread_create(&thread_ids[i], NULL, sum, thread_data);
        if(rc)
        {
            return EXIT_FAILURE;
        }
    }
    long long sum = 0;
    void * ret;
    for(int i = 0; i < thread_count; ++i)
    {
        rc = pthread_join(thread_ids[i], &ret);
        arr * const thread_data = (arr *)(ret);
        sum += thread_data->sum;    // overflows when all do equal work, duh
    }
    printf("%lli\n", sum);
    free(thread_ids);
    free(vals);
    return EXIT_SUCCESS;
}
