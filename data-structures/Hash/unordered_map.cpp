#include <fstream>
#include <unordered_map>

using namespace std;

ifstream cin("hashuri.in");
ofstream cout("hashuri.out");

unordered_map <int,bool> v;

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int x, nr;
        cin >> x >> nr;
        if(x == 1)
            v[nr] = 1;
        else if(x == 2)
            v[nr] = 0;
        else
            cout << v[nr] << '\n';
    }
    return 0;
}
