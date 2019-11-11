#include <cstdio>
#include <cstdlib>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    char * buffer = new char[n + 1];
    scanf("%s", buffer);
    unsigned ftos{ 0U };
    unsigned stof{ 0U };
    for(int i = 1; i < n; ++i)
    {
        if(buffer[i - 1] == 'S' 
            && buffer[i] == 'F')
            ++stof;
        else if(buffer[i - 1] == 'F'
                && buffer[i] == 'S')
            ++ftos;
        else
            continue;
    }
    if(stof > ftos)
        puts("YES");
    else
        puts("NO");
}
