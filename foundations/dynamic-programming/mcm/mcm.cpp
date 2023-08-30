#include <iostream>
#define SIZE 505

//Matrix Chain Multiplication

int dim[ SIZE ], n;

long cost[ SIZE ][ SIZE ];

void mcm(int n, int dim[ 10 ]) {

      int j;

      for(int i = 1; i <= n; i++) cost[i][i] = 0;

      for(int k = 1; k <= n - 1; ++k)

          for(int i = 1; i <= n - k; i++) {

               j = i + k;

               cost[i][j] = 1LL<<50;

               for(int q = i; q <= j - 1; q++) {

                 long m = cost[i][q] + cost[q+1][j] + dim[i] * dim[q+1] * dim[j+1];

                 if(cost[i][j]>m) {

                   cost[i][j] = m;

                   cost[j][i] = 1;
                 }
               }
      }

      std::cout<<cost[1][n];
}

int main(int argc, char const *argv[]) {

        //freopen("podm.in","r",stdin);

        //freopen("podm.out","w",stdout);


  std::cin>>n;

  for(int i = 1; i <= n + 1; i++) std::cin>>dim[i];
  
  //test: 10 1 10 1 10
  mcm( n, dim);

  return 0;
}
