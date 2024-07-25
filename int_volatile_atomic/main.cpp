// this program compiles to a assembly, demonstrating the
// effects of volatile keyword
int
main()
{
    volatile int i = 5;
    ++i;
    ++i;
    int j = i;
    return j;
}

// this program can be compared against the previous
// to demonstrate how optimizations change the assembly
// on a non-volatile int i
int
main()
{
    int i = 5;
    ++i;
    ++i;
    int j = i;
    return j;
}

// this program shows how atomic effects the assembly
// and how different these concepts are
#include <atomic>
int
main()
{
    std::atomic<int> i = 5;
    ++i;
    ++i;
    int j = i;
    return j;
}
