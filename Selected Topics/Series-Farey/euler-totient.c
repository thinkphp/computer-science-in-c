#include <iostream>
#include <vector>
using namespace std;
void compute_phi(vector<int>&phi,int n) {
  int sum = 0;
  for(int i = 1; i<=n; ++i)phi[i] = i;
  for(int i = 2; i <= n; ++i) {
      if(phi[i] == i) {
          for(int j = i; j <= n; j+=i) {
              phi[j] = phi[j] / i * (i - 1);
          }
      }
      sum+=phi[i];
  }
  cout<<(sum<<1)+1;
}
int main(int argc, char const *argv[]) {

  int n;
  cin>>n;
  vector<int>PHI(n);
  compute_phi(PHI,n);
  printf("%s\n","Euler's totient");
  for(int i = 1; i <= n; ++i) {
    printf("phi(%d) = %d\n",i,PHI[i]);
  }

  return 0;
}
