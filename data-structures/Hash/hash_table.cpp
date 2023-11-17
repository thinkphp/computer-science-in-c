#include <fstream>
#include <unordered_set>
using namespace std;

ifstream fin("hashuri.in");
ofstream fout("hashuri.out");

unordered_set<int> S;

int main()
{
    int n;
    fin >> n;

    for (int i = 1; i <= n; ++i)
    {
        int op, x;
        fin >> op >> x;
        if (op == 1)
            S.insert(x);
        else if (op == 2)
            S.erase(x);
        else
            fout << (S.find(x) != S.end()) << '\n';
    }
    return 0;
}
