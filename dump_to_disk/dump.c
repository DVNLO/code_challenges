#include <stdlib.h>
#include <stdio.h>
int main()
{
    FILE * const f = fopen("data.out", "wb");
    if(!f)
    {
        return EXIT_FAILURE;
    }
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
    size_t objects_written_count = fwrite(data, cell_record_sz, cells, f);
    printf("wrote %lu of %lu cells\n", objects_written_count, cells);
    int rc = fclose(f);
    return rc; 
}

