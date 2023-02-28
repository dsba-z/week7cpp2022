#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <map>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;


typedef std::vector<int> VecInt;
// typedef std::map<int, size_t> MapInt;
using MapInt = std::map<int, size_t>;
// Generating random numbers:


VecInt generateVector(size_t n, int rangeStart, int rangeEnd)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distr(rangeStart, rangeEnd - 1);     
    
    VecInt vec;

    for (size_t i = 0; i < n; i++)
        vec.push_back(distr(gen));

    return vec;
}


// consider using range-based loops for printing
void printVec(const VecInt& vecInt)
{
    for (int c : vecInt)
        cout << c << '\t';
}

MapInt creatMap(const VecInt& vec)
{
    MapInt mapp;
    for (int i : vec)
    {
        if (mapp.count(i) != 0)
            mapp[i]++;
        else 
            mapp[i] = 1;
    }
    
    return mapp;
}

void printMap(const MapInt& mapInt)
{
    for (std::pair<int, size_t> i : mapInt)
        cout << i.first << '\t' << i.second << '\n';

    int max = 0;
    VecInt vecInt;

    for (std::pair<int, size_t> i : mapInt)
    {   
        vecInt.push_back(i.first);
        if (i.second > max)
            max = i.second;
    }

    for (int i = max; i > 0; i--)
    {
        for (int j : vecInt)
        {
            if (mapInt.at(j) >= i)
                cout << '#';
            else
            cout << ' ';
        }
        cout << endl;
    }
    
    for (int i : vecInt)
        cout << i;
}

int main()
{

    cout << "Enter three integers: n, r, q\n";
    int n = 10;
    int r = 1;
    int q = 5;

    // cin >> n >> r >> q;
    VecInt vecInt = generateVector(n, r, q);
    printVec(vecInt);

    cout << std::endl;

    MapInt mapInt = creatMap(vecInt);
    printMap(mapInt);

    return 0;
}
