#include <iostream>
#include <fstream>
#define filein "partitiimultime.in"
#define fileout "partitiimultime.out"

using namespace std;

ifstream fin(filein);
ofstream fout(fileout);

int n, stack[100];

int getMax(int level) {
	int max = 0;
	for(int i = 1; i <= level-1;++i) {
		if(stack[i]>max) {
			max = stack[i];
		}
	}
	return max;
}

void partition(int level) {
     if(level == n + 1) {
         int maxi = getMax(n+1);
     	 for(int i = 1; i <= maxi; ++i) {

             for(int j = 1; j <= n; ++j) {
                 if(stack[j]== i) {
                     fout<<j<<"";
                 }
             }
             fout<<"*";
         }
         fout<<endl;
     } else {
         stack[level] = 0;
         while(stack[level]<getMax(level)+1) {
               stack[level] += 1;
               partition(level+1);
         }
     }
}

int main(int argc, char const *argv[]) {

  fin>>n;
  partition(1);

  return 0;
}
