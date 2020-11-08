#!/bin/bash
# b for benchmark

echo "=============BENCHMARK 1=============="
g++ -std=c++11 benchmark.cpp -o b
time ./b
rm ./b

echo
echo

echo "=============BENCHMARK 2=============="

g++ -std=c++11 -pthread benchmarkThread.cpp -o b
time ./b
rm ./b

