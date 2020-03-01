#include <bits/stdc++.h>
using namespace std;
int main()
{
    int s; // opponents
    int t; // opponents make a mistake per turn
    int n;
    scanf("%d", &n);
    s = n;
    // joe receives t/s dollars per turn
    // there are only s - t opponents remaining.
    // What is the maximum possible reward he can 
    // receuve in the best possible scenario
    
    // The maximum value obtainable is the sum of 
    // the harmonic series from 1 to n. 
    double sum{ 0.0 };
    while(s > 0)
    {
        sum += 1.0 / s;
        --s;
    }
    printf("%.12f", sum);
}
