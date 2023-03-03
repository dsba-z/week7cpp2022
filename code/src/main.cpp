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
using MapBool = std::map<int, bool>;
using SetInt = std::set<int>;
using SupaMap = std::multimap<int, size_t>;
// Generating random numbers:
bool query(const MapInt& m, int k, size_t& element)
{
    MapInt::const_iterator f = m.find(k);
    if (f == m.end())
    {
        return false;
    }
    else
    {
        // element = (*f).second; the same as 
        element = f->second;
        return true;
    }
}

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
void modifyMap(MapInt& map, int x)
{
    for (MapInt::iterator i = map.begin(); i != map.end(); i++)
        i->second += x;
}

void eraseMap(MapInt& map)
{
    for (MapInt::iterator i = map.begin(); i != map.end();)
    {   
        if (i->second <= 5)
            i = map.erase(i);
        else 
            i++;
    }
}

// Exersize 2
MapBool fillMap(const MapInt& map, int r, int q)
{
    MapBool map2;
    for (int i(r); i <= q; i++)
        map2.insert({i, map.find(i) == map.end() ? false : true});
    // {
    //     if (map.find(i) == map.end())
    //         map2.insert({i, false});
    //     else
    //         map2.insert({i, true});
    // }
    // another method

    return map2;
}
// complexity O(log(n))

SetInt MapToSet(const MapBool& m)
{
    SetInt setic;
    for (std::pair<int, bool> i: m)
    {    
        if (i.second)
            setic.insert(i.first);
    }    

    return setic;
}

void printSet(const SetInt& set)
{
    for (int i:set)
        cout << i << '\t';
}

bool isInSet(const SetInt& set, int value)
{
    return set.find(value) == set.end() ? false : true;
}

// exirsize 3

SupaMap CreateSupaMap(const VecInt& vector)
{   
    SupaMap supaMapishe;
    for (int i(0); i < vector.size(); i++)
        supaMapishe.insert({vector[i], i});
    
    return supaMapishe;
}

void printRange(SupaMap mm, int start, int end)
{   
    SupaMap::iterator lower = mm.lower_bound(start);
    SupaMap::iterator upper = mm.lower_bound(end);
    for (; lower != upper; lower++)
        cout << lower->first << '\t' << lower->second << '\n';     
}

void printRange(std::multimap<int, size_t> mm, int key)
{
    for (std::pair<SupaMap::iterator, SupaMap::iterator> range = mm.equal_range(key); range.first != range.second; range.first++)
        cout << range.first->first << '\t' << range.first->second << '\n';
}

int main()
{
    
    cout << "Enter three integers: n, r, q\n";
    int n(100);
    int r(1);
    int q(50);
    
    // cin >> n >> r >> q;

    VecInt vector = generateVector(n, r, q);

    std::multiset<int> sett(vector.begin(), vector.end());
    SupaMap supaMapishe = CreateSupaMap(vector);

    printVec(vector);

    // createMap(vector);

    MapInt map = createMap(vector);
    printMap(map);
    cout << '\n';
    size_t element(0);
    if (query(map, 1, element))
        cout << element << '\n';
    else
        cout << "we do not have such element:(\n";
    // for (int i:sett)
    // {
    //     cout << i << '\t';

    // }
    
    // modifyMap(map, 20);
    // eraseMap(map);
    // printMap(map);

    MapBool map2 = fillMap(map, r, q);
    SetInt setic = MapToSet(map2);
    printSet(setic);
    if (isInSet(setic, 43))
        cout << "\nyes\n";
    printRange(supaMapishe, 10, 20);
    printRange(supaMapishe, 15);
    return 0;
}
