#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>

typedef struct
{
    int * vals;
    size_t n;
    int sum;
} 
arr;

void * sum(void * arg)
{
    arr * vals = (arr *)(arg);
    int s = 0;
    for(size_t i = 0; i < vals->n; ++i)
    {
        s += vals->vals[i];
    }
    vals->sum = s;
    pthread_exit((void *)(vals));
}

int main()
{
    size_t const size_vals = 1008;
    int * vals = (int *)(malloc(sizeof(int) * size_vals));
    if(!vals)
    {
        return EXIT_FAILURE;
    }
    for(size_t i = 0; i < size_vals; ++i)
    {
        vals[i] = i + 1;
    }
    int thread_count = 24;
    pthread_t * thread_ids = (pthread_t *)(malloc(sizeof(pthread_t) * thread_count));
    if(!thread_ids)
    {
        return EXIT_FAILURE;
    }
    int rc;
    for(int i = 0; i < thread_count; ++i)
    {
        arr * thread_data = (arr *)(malloc(sizeof(arr)));
        if(!thread_data)
        {
            return EXIT_FAILURE;
        }
        thread_data->n = size_vals/thread_count;
        thread_data->vals = vals + (i * thread_data->n);    // TODO : handle remainder case
        rc = pthread_create(&thread_ids[i], NULL, sum, thread_data);
        if(rc)
        {
            return EXIT_FAILURE;
        }
    }
    int sum = 0;
    void * ret;
    for(int i = 0; i < thread_count; ++i)
    {
        rc = pthread_join(thread_ids[i], &ret);
        arr * thread_data = (arr *)(ret);
        sum += thread_data->sum;
    }
    printf("%i\n", sum);
    free(thread_ids);
    free(vals);
    return EXIT_SUCCESS;
}
