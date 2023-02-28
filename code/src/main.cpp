#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <map>
#include <algorithm>
#include <set>

using std::cout;
using std::cin;
using std::endl;


typedef std::vector<int> VecInt;
using MapInt = std::map<int, size_t>;
// Generating random numbers:


VecInt generateVector(size_t n, int rangeStart, int rangeEnd)
{   
    VecInt vector;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distr(rangeStart, rangeEnd - 1);
    for (int i = 0; i <= n; i++)
    {
        vector.push_back(distr(gen));
    }
    // now use the function call distr(gen) whenever you need a new randon number
    // for example:
    // these will be two different random numbers
    // add many distr(gen) numbers to a vector

    return vector;
}

MapInt createMap(const VecInt& vector)
{
    MapInt map;
    for (int i:vector)
    {
        if (map.count(i) > 0)
            ++map[i];
        else
            map[i] = 1;
    }

    return map;
}

// consider using range-based loops for printing
void printVec(const VecInt& vecInt)
{
    for (int i:vecInt)
    {
        cout << i << '\t';
    }
}

void printMap(const MapInt& mapInt)
{
    for (std::pair<int, size_t> i:mapInt)
    {
        cout << i.first << '\t' << i.second << '\n';
    }
    size_t maxN(0);
    VecInt vec;
    for (std::pair<int, size_t> i:mapInt)
    {   
        vec.push_back(i.first);
        if (maxN <= i.second)
            maxN = i.second;
    }

    for (size_t i(maxN); i != 0; --i)
    {
        for (int j:vec)
        {
            if (mapInt.at(j) >= i)
            {
                cout << '#';
            }
            else
                cout << ' ';
        }
        cout << '\n';
    }

    for (int i:vec)
    {
        cout << i;
    }
}




int main()
{
    
    cout << "Enter three integers: n, r, q\n";
    int n(10);
    int r(1);
    int q(4);
    
    // cin >> n >> r >> q;

    VecInt vector = generateVector(n, r, q);

    std::multiset<int> sett(vector.begin(), vector.end());


    printVec(vector);

    // createMap(vector);

    // MapInt map = createMap(vector);
    // printMap(map);
    for (int i:sett)
    {
        cout << i << '\t';

    }

    cout << '\n';


    return 0;
}
