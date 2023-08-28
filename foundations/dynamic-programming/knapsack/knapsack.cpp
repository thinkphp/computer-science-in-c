#include <iostream>
#define DIM 5001
#define FIN "rucsac.in"
#define FOUT "rucsac.out"

/*
          C[i]+C[i-1][j-G[i]], G[i]<=j
C[i][j] =
          C[i-1][j], else
*/

typedef struct object {
    int weight,
        value;
} Object;

int N, Gmax;
Object arr[DIM];
int C[DIM][DIM], P[DIM][DIM];

int main(int argc, char const *argv[]) {

  freopen(FIN, "r", stdin);

  freopen(FOUT, "w", stdout);

  std::cin>>N>>Gmax;

  for(int i = 1; i <= N; ++i) std::cin>>arr[i].weight>>arr[i].value;

  for(int i = 1; i <= N; ++i) std::cout<<arr[i].weight<<" "<<arr[i].value<<std::endl;

  for(int i = 1; i <= N; ++i) {

    for(int j = 1; j <= Gmax; ++j) {

        if(arr[i].weight <= j && (arr[i].value + C[i-1][j-arr[i].weight]) > C[i-1][j]) {

          C[i][j] = arr[i].value + C[i-1][j-arr[i].weight];

        } else {

          C[i][j] = C[i-1][j];
        }
    }
  }



  std::cout<<C[N][Gmax];
  
  return 0;
}
