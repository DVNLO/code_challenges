#include <stdio.h>
#include <stdlib.h>
int main()
{
    float begin_c = -1000000.0;
    float const end_c = -1.0 * begin_c;
    while(begin_c <= end_c)
    {
        float const f = (9.0/5.0) * begin_c + 32.0;
        printf("%4.2f %4.2f\n", begin_c, f);
        begin_c += 1.0;
    }
    return EXIT_SUCCESS;
}
