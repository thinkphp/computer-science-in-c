/*
Premiul:

La o festivitate de premiere, dirigintele clasei
are n (n<=100) obiecte de valori necunoscute mai mici de 100 lei.
Stiind ca elevului, care a obtinut premiul 1, ii va inmana m obiecte,
realizati un program care identifica valoarea maxima
a premiului 1 si obiectele alese.

 n = 8, m = 4

 3, 7, 8, 1, 6, 8, 9, 5

 9,8,8,7,6,5,3

 output:

 32
 8,7,8,9

 Metoda Greedy:

 sortare in ordine DESC

 for(int i = 1; i <= m; ++i)

 s = s + a[i]

*/

#include <iostream>

int val[100],
     n,m;

using namespace std;

//sortare prin metoda bulelor
void sortare() {
     int finished = 0, swapped, size = n;

     while(!finished) {
         swapped = 0;
         for(int i = 1; i <= n - 1; ++i) {
           if(val[i]<val[i+1]) {
              int tmp = val[i];
              val[i] = val[i+1];
              val[i+1] = tmp;
              swapped = 1;
           }
         }
         if(swapped) size--;
         else finished = 1;
     }
}

void solve() {

     int s = 0;

     sortare();

     for(int i = 1; i <= m; ++i) {

        s += val[i];

        cout<<val[i]<<" ";
     }

     cout<<endl;

     cout<<"valoarea maxima = "<<s;
}

int main(int argc, char const *argv[]) {

  cout<<"n=? m=?";
  cin>>n>>m;

  for(int i = 1; i <= n; ++i) cin>>val[i];

  solve();

  return 0;
}
