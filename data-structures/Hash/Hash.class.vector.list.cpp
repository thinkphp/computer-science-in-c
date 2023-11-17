#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

#define P 1000001

class HashMap
{
public:
    HashMap()
    {
        data.resize(P);
    }

    void add(int el)
    {
        int hash = h(el);
        (&data[hash])->push_back(el);
    }

    void remove(int el)
    {
        int hash = h(el);
        auto l = &data[hash];
        auto it = find(l->begin(), l->end(), el);
        if (it != l->end())
        {
            // cout << "found " << el << endl;
            l->erase(it);
        }
    }

    bool contains(int el)
    {
        int hash = h(el);
        auto l = &data[hash];
        auto it = find(l->begin(), l->end(), el);
        return it != l->end();
    }

    // void print()
    // {
    //     cout << "HashMap: ";
    //     for (int i = 0; i < data.size(); i++)
    //     {
    //         auto l = data[i];
    //         if (!l.empty())
    //         {
    //             for (auto el : l)
    //             {
    //                 cout << el << " ";
    //             }
    //         }
    //     }
    //     cout << endl;
    // }

private:
    int h(int el)
    {
        return el % P;
    }

    vector<list<int>> data;
};

int main()
{
    ifstream in("hashuri.in");
    ofstream out("hashuri.out");

    int n, query, el;
    in >> n;

    HashMap map;
    for (int i = 0; i < n; i++)
    {
        in >> query >> el;
        if (query == 1)
        {
            map.add(el);
            // map.print();
        }
        else if (query == 2)
        {
            map.remove(el);
            // map.print();
        }
        else
        {
            out << (map.contains(el) ? "1\n" : "0\n");
        }
    }
}
