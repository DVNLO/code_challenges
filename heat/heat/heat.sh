#!/bin/bash
for i in {0.."$1"}
do
    ( ./a.out & )
done
