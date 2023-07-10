/**
 *  Dynamic Programming - Triangle Problem
 *  2
 *  3 5
 *  6 3 4
 *  5 6 1 4
 *
 *  The new Triangle
 *  C[i,j] = max(T[i,j]+C[i+1,j], T[i,j] + C[i+1,j+1])
    where i apartine [1,n-1]
 *  17
 *  15 14
 *  12 9 8
 *   5 6 1 4
 */
#include <bits/stdc++.h>
#define FIN "triangle.in"
#define FOUT "triangle.out"
#define SIZE 101

using namespace std;

int i,n,Tri[ SIZE ][ SIZE ],
      C[ SIZE ][ SIZE ],
      Road[ SIZE ][ SIZE ];

ifstream fin(FIN);
ofstream fout(FOUT);

int main( int argc, char const *argv[] ) {

    fin>>n;

    for( int i = 1; i <= n; ++i )

        for(int j = 1; j <= i; ++j)

            fin>>Tri[i][j];

    for( int i = 1; i <= n; ++i ) {

        for(int j = 1; j <= i; ++j) {

                    cout<<Tri[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int j = 1; j <= n; ++j) C[n][j] = Tri[n][j];

    for(int i = n - 1; i >= 1; i--) {

        for(int j = 1; j <= i; ++j) {

            if(C[i+1][j] < C[i+1][j+1]) {

                C[i][j] = Tri[i][j] + C[i+1][j];

                Road[i][j] = j;

            } else {

                C[i][j] = Tri[i][j] + C[i+1][j+1];

                Road[i][j] = j+1;
            }
        }
    }

    fout<<C[1][1]<<"\n";

    int i,j;
    i = j = 1;
    while(i<=n) {
      fout<<Tri[i][j]<<" ";
      j = Road[i][j];
      i++;
    }

    return 0;
}
