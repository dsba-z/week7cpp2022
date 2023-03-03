#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <map>
#include <algorithm>
#include "exersice1.h"
#include "exersice2.h"

int main()
{
    cout << "Enter three integers: n, r, q\n";
    int n = 100;
    int r = -50;
    int q = 50;
    size_t s = 3;

    // cin >> n >> r >> q;
    VecInt vecInt = generateVector(n, r, q);
    printVec(vecInt);

    cout << std::endl;

    MapInt mapInt = creatMap(vecInt);
    printMap(mapInt);

    cout << '\n';

    query(mapInt, 1, s);
    cout << s << '\n';

    increaser(mapInt, 3);
    cout << '\n';
    printMap(mapInt);

    // negat(mapInt);

    cout << '\n';
    printMap(mapInt);

    cout << '\n';

    MapBool mapBool= fillMap(mapInt, r, q);

    SetInt setInt = transformation(mapBool);

    printSet(setInt);

    return 0;
}