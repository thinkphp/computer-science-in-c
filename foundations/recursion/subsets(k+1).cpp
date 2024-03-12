#include <iostream>
#define SIZE 100
using namespace std;

int sol[ SIZE ], n, v[SIZE];

void read_vector() {

    cout<<"n=";
    cin>>n;
    for(int i = 1; i <= n; ++i) cin>>v[i];
}

void gen_subsets(int k) {

    if(k == n + 1) {

       for(int i = 1; i<=n; ++i) cout<<v[i]<<" ";
       cout<<endl;

    } else {

       for(int b = 1; b >= 0; --b) {
         v[k] = b;
         gen_subsets(k+1);
       }
    }
}

int main(int argc, char const *argv[]) {
  read_vector();
  gen_subsets(1);
  return 0;
}
