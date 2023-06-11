#include<bits/stdc++.h>
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

void permute(string str, int lo, int hi, set<string> &str2) {

     if(lo == hi) str2.insert(str);
     else {
          for(int i = lo; i <= hi; ++i) {
             swap(str[lo], str[i]);
             permute(str, lo+1, hi, str2);
             swap(str[lo], str[i]);
          }
     }
}

int main(int argc, char const *argv[]) {
  fio;
  string s;
  set<string> ans;
  cin>>s;
  permute(s, 0,s.length()-1,ans);
  cout<<ans.size()<<"\n";
  for(auto x: ans) cout<<x<<"\n";
  return 0;
}
