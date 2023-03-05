#ifndef exersice2
#define exersice2

#include <iostream>
#include <vector>
#include <random>
#include <map>
#include <algorithm>
#include <set>

using std::cout;
using std::cin;
using std::endl;

typedef std::vector<int> VecInt;
using MapInt = std::map<int, size_t>;
using MapBool = std::map<int, bool>;
using SetInt = std::set<int>;

MapBool fillMap(const MapInt& mapInt, int r, int q);

SetInt transformation(const MapBool& mapBool);

void printSet(const SetInt& setInt);

#endif