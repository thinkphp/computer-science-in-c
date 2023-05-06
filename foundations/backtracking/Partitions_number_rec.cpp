#include <iostream>
#include <fstream>
#define FIN "partitiinumar.in"
#define FOUT "partitiinumar.out"
#define DIM 100

using namespace std;

ifstream fin( FIN );

ofstream fout( FOUT );

int n,

    sum,

    stack[ 101 ];

void solve(int level) {

     if(sum == n) {

       for(int i = 1; i < level; ++i) {

         fout<<stack[i]<<" ";

       }

       fout<<endl;

     } else {

        if(level==1) stack[level] = 0;
        
        else stack[level] = stack[level-1] - 1;

        while(stack[level] + sum < n) {

              stack[level]+=1;

              sum += stack[level];

              solve(level+1);

              sum -= stack[level];
        }
     }
}

int main(int argc, char const *argv[]) {

  sum = 0;
  
  fin>>n;
  
  solve(1);    
  
  return 0;

}



