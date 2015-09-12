#include <fstream>
#define FIN "hanoi.in"
#define FOUT "hanoi.out"

using namespace std;

ofstream fout(FOUT);
ifstream fin(FIN);

void hanoi(int n, char a, char b, char c) {

    if(n == 1) fout<<a<<""<<b<<" ";

    else {

         hanoi(n - 1, a, c, b);

         fout<<a<<""<<b<<" ";

         hanoi(n - 1, c, b, a);
    } 
};

int main() {

 char a, 
      b, 
      c;

 int N;

 a = 'a'; b = 'b'; c = 'c';

 fin>>N;

 fin.close();

 hanoi(N, a, b, c);

 fout.close();

 return(0);
};