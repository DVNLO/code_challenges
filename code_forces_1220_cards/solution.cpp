#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    char * buffer = new char[n + 1];
    scanf("%s", buffer);
    unsigned char_counts[5] = { 0 };    // [ z, e, r, o, n ]
    for(size_t i = 0; i < n; ++i)
    {
        switch(buffer[i])
        {
            case 'z':
                ++char_counts[0];
                break;
            case 'e':
                ++char_counts[1];
                break;
            case 'r':
                ++char_counts[2];
                break;
            case 'o':
                ++char_counts[3];
                break;
            case 'n':
                ++char_counts[4];
                break;
            default:
                puts("domain error");
                exit(EXIT_FAILURE);
                break;
        }
    }
    unsigned ones_count = min(char_counts[3], // 'o'
                                min(char_counts[4], // 'n'
                                    char_counts[1]));   // 'e'
    char_counts[3] -= ones_count;
    char_counts[4] -= ones_count;
    char_counts[1] -= ones_count;
    unsigned zero_count = 0;
    for(size_t i = 1; i < 4; ++i)
        zero_count = min(char_counts[i - 1], char_counts[i]);
    size_t const size = 2 * (ones_count + zero_count + 1);
    char * ret = new char[size];
    size_t i = 0;
    while(ones_count)
    {
        ret[i] = '1';
        ++i;
        ret[i] = ' ';
        ++i;
        --ones_count;
    }
    while(zero_count)
    {
        ret[i] = '0';
        ++i;
        ret[i] = ' ';
        ++i;
        --zero_count;
    }
    ret[i] = 0; // interesting example of character spacing
                // because with each character we include a space
                // at the end of the output we can append a null-terminator.
    printf("%s\n", ret);
}
