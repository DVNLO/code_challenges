#include <bits/stdc++.h>
int main()
{
    char * a = NULL;
    size_t len_a = 0U;
    len_a = getline(&a, &len_a, stdin);
    if(len_a <= 0)
    {
        return EXIT_FAILURE;
    }
    len_a -= 1; // subtract delimiter
    char * b = NULL;
    size_t len_b = 0U;
    len_b = getline(&b, &len_b, stdin);
    if(len_b <= 0)
    {
        return EXIT_FAILURE;
    }
    len_b -= 1; // subtract delimiter
    size_t i = 0;
    while(a[i] == '0' && i < len_a)
    {
        ++i;
    }
    size_t j = 0;
    while(b[j] == '0' && j < len_b)
    {
        ++j;
    }
    if(len_a - i > len_b - j)
    {
        puts(">");
        return EXIT_SUCCESS;
    }
    else if(len_a - i < len_b - j)
    {
        puts("<");
        return EXIT_SUCCESS;
    }
    else
    {
        while(i < len_a && j < len_b)
        {
            if(a[i] > b[j])
            {
                puts(">");
                return EXIT_SUCCESS;
            }
            else if(a[i] < b[j])
            {
                puts("<");
                return EXIT_SUCCESS;
            }
            ++i;
            ++j;
        }
        puts("=");
        return EXIT_SUCCESS;
    }
}
