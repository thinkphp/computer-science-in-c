#include <bits/stdc++.h>
using namespace std;
void FastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int main()
{
    int t = 1;
    while(t--){
        long long n, k;
        cin >> n >> k;
        vector<long long>a(n);
        for(long long i = 0; i < n; ++i){
            cin >> a[i];
        }
        map<long long,long long>mp;
        bool ok = 0;
        for(long long i = 0; i < n; ++i){
            long long current = k - a[i];
            if(mp.find(current) != mp.end()){
                cout << mp[current] + 1 << " " << i + 1 << '\n';
                return 0;
            }
            mp[a[i]] = i;
        }
        if(ok == 0){
            cout << "IMPOSSIBLE" << '\n';
        }
    }
    return 0;
}
