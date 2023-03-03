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

MapBool fillMap(const MapInt& mapInt, int r, int q)
{
    MapBool mapBool;
    for (int i = r; i < q; i++)
    {
        // if (mapInt.find(i) != mapInt.end())
        //     mapBool.insert({i, true});
        // else 
        //     mapBool.insert({i, false});
        mapBool.insert({i, mapInt.find(i) != mapInt.end() ? true : false});
    }

    return mapBool;
}

SetInt transformation(const MapBool& mapBool)
{
    SetInt setInt;

    for (MapBool::const_iterator it = mapBool.begin(); it != mapBool.end(); it++)
    {
        if (it->second)
            setInt.insert(it->first);
    }

    return setInt;
}

void printSet(const SetInt& setInt)
{
    for (int c : setInt)
        cout << c << '\t';
    cout << endl;
}

