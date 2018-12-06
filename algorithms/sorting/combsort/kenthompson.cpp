#include <bits/stdc++.h>
#include <algorithm>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define b 1000000

using namespace std;

typedef vector<int>::iterator I;
typedef void (*fnPtr)(vector<int>, I, I);

struct IO {

       char *B, *E, *p;

       IO() {

         B = new char[b + 10];
         E = B + b;
         load();
 
       }

       void operator >>(int &x) {
 
            while(*p < '0' || *p > '9') if(++p == E) load(); 

            x = 0;

            while(*p >= '0' && *p <= '9') { 

                  x = x * 10 + *p - '0'; 

                  if(++p == E) load(); 
            }
       } 

       void load() {

            p = B;

            memset(B,0,b);

            fread(B,1,b,stdin);

       }
};

void cs(vector<int> v, I first, I last) {

     float shrinkFactor = 1.3;

     int swapped = 0;

     int gap = v.size(); 

     I n = last;

     while(gap > 1 || swapped) {

           swapped = 0;

           if(gap > 1) gap = gap / shrinkFactor;

           for(I it = first; it + gap < n; ++it) {

                  if(*it > *(it+gap)) {

                      swap(*it, *(it+gap)); 

                      swapped = 1;
                  }
           } 
     }   
    
}

int main() {

    vector<int> v; 

    fnPtr f = cs;

    freopen(FIN, "r", stdin);

    freopen(FOUT, "w", stdout);

    int n, x;

    IO fin; 

    fin>>n;
 
    for(n;n--;) {

        fin>>x;

        v.push_back(x);
    }

    f(v, v.begin(), v.end());

    for(auto it:v) cout<<it<<" "; 

return(0);
}
