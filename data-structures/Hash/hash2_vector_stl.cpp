#include <fstream>
#include <vector>
using namespace std;

ifstream fin("hashuri.in");
ofstream fout("hashuri.out");

#define MOD 666013

vector<int> H[MOD];

int hash_func(int x) {
  return x % MOD;
}

int caut(int x)
{
    int h = hash_func(x);
    for (auto it:H[h]) {
        if (it == x) {
            return 1;
        }
    }
    return 0;
}

void _insert(int x)
{
    int h = hash_func(x);
    if (caut(x) == 0) {
        H[h].push_back(x);
    }
}

void _delete(int x) {
    int h = hash_func(x);
    for (int i = 0; i < H[h].size(); ++i) {
        if (H[h][i] == x) {
            H[h].erase(H[h].begin() + i);
            break;
        }
    }
}

int main()
{
    int n;
    fin >> n;

    for (int i = 1; i <= n; ++i)
    {
      	int op, x;
      	fin >> op >> x;
      	if (op == 1) {
            _insert(x);
      	}
      	if (op == 2) {
            _delete(x);
        }
        if (op == 3) {
            fout << caut(x) << '\n';
        }
    }
    return 0;
}
