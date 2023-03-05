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


bool query(const std::map<int, size_t>& m, int k, size_t& element)
{
    if (m.count(k) > 0)
    {
        element = m.at(k);
        return true;
    }

    else
        return false;
}


void increaser(std::map<int, size_t>& m, int k)
{
    for (std::map<int, size_t>::iterator it = m.begin(); it != m.end(); it++)
        it->second += k;

}


void negat(std::map<int, size_t>& m)
{
    for (std::map<int, size_t>::iterator it = m.begin(); it != m.end();)
    {
        if (it->first < 0)
            it  = m.erase(it);
        else 
            it++;
    }
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