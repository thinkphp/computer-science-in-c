```cpp
#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  vector<int> v(n);
  for(auto &x: v) {
    cin>>x;
  }
  for(vector<int>::iterator it = v.begin(); it!=v.end(); it++) cout<<*it<<" ";
  cout<<endl;
  for(auto &x: v) {
    cout<<x<<" ";
  }
  return 0;
}
```
