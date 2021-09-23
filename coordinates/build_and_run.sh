#! /bin/bash
gcc -O3 -std=c99 ./inplace.c -lm -lrt -lpthread && ./a.out ;

