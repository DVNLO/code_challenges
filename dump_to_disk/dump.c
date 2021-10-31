#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
    size_t const cells = 100U * 1000U * 10U * 10U; 
    size_t const cell_record_sz = 128;
    size_t const bytes = cells * cell_record_sz;
    printf("calloc(cells, cell_record_sz) == calloc(%lu, %lu) == %lu\n", 
            cells, cell_record_sz, bytes);
    void * data = malloc(bytes);
    if(!data)
    {
        return EXIT_FAILURE;
    }
    int const sample_count = 32;
    clock_t const start_t = clock();
    for(int i = 0; i < sample_count; ++i)
    {
        FILE * const f = fopen("data.out", "wb");
        if(!f)
        {
            printf("unable to open file\n");
            return EXIT_FAILURE;
        }
        fwrite(data, cell_record_sz, cells, f);
        int rc = fclose(f);
    }
    clock_t const end_t = clock();
    clock_t const total_t = end_t - start_t;
    printf("clocks() = end_t - begin_t == %ld\n", total_t);
    double const seconds = total_t / (CLOCKS_PER_SEC * (double)(sample_count));
    printf("%f seconds\n", seconds);
    printf("%f GB\\s\n", bytes / (1E9 * seconds));
    return EXIT_SUCCESS; 
}

