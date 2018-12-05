#include <bits/stdc++.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define L 1000000

using namespace std;

struct IO {

       char *buff, *p, *s;

       IO() {

         buff = new char[L + 10];

         s = buff + L; 

         load(); 
 
       }

       void operator >> (int &x) {       

            while(*p <'0' || *p > '9') { if(++p == s) load(); }

            x = 0;

            while(*p >= '0' && *p <= '9') { x = x * 10 + *p - '0'; if(++p == s) load(); }
       } 

       void load() {

            p = buff; 
 
            memset(buff, 0, L);

            fread(buff, 1, L, stdin);
       }
};

void cb(vector<int> &v) {

     float shrinkFactor = 1.3;

     int swapped = 0;

     int gap = v.size(); 

     while(gap > 1 || swapped) {

           swapped = 0;
  
           if(gap > 1) gap = gap / shrinkFactor;

           for(int i = 0; i + gap < v.size(); ++i) {

               if(v[i] > v[i+gap]) {    

                   int holder = v[i];
                       v[i] = v[i+gap];
                       v[i+gap] = holder;
                       swapped = 1; 
                }
           }  
     }
       
}

int main() {

    int n, nat;
    vector<int> v;

    freopen(FIN, "r", stdin);

    freopen(FOUT, "w", stdout);
 
    IO fin;

    fin>>n;

    for(;n;n--) {
          
         fin>>nat;

         v.push_back(nat);  
    }

    cb(v);  

    for(auto it:v) printf("%d ", it);    

return(0);
}
