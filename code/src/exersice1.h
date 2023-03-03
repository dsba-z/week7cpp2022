#ifndef EXERCISE1
#define EXERCISE1

#include <iostream>
#include <vector>
#include <random>
#include <map>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;

typedef std::vector<int> VecInt;
using MapInt = std::map<int, size_t>;

VecInt generateVector(size_t n, int rangeStart, int rangeEnd);

void printVec(const VecInt& vecInt);

MapInt creatMap(const VecInt& vec);

bool query(const std::map<int, size_t>& m, int k, size_t& element);

void increaser(std::map<int, size_t>& m, int k);

void negat(std::map<int, size_t>& m);

void printMap(const MapInt& mapInt);

#endif