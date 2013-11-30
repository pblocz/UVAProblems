#! /bin/bash

g++ -DSHIFT test-bench.cpp -o shift
g++ -DMULT test-bench.cpp -o mult
g++  test-bench.cpp -o std
