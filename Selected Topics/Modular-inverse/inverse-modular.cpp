#include <iostream>
#include <fstream>
#define FIN "inversmodular.in"
#define FOUT "inversmodular.out"

struct pair {

       long x, 
            y;  

       pair(long _x, long _y): x(_x), y(_y) {}
};

pair euclid_extended(long a, long b) {

     pair prev(1,0); 
     pair curr(0,1);
     
     long q, r;

     while(b) {
      
       q = a / b;
       r = a % b;

       pair old = curr;
 
       curr.x = prev.x - q * curr.x;
       curr.y = prev.y - q * curr.y;

       prev = old;

       a = b;
       b = r;  
     }       

     return prev; 
 
};


int main(int argc, char *argv[]) {

    std::ifstream fin(FIN); 
    std::ofstream fout(FOUT); 

    unsigned long a, 
                  n;

    fin>>a>>n; 

    pair sol = euclid_extended(a, n);

    fout << ((sol.x > 0) ? (sol.x) : (n + sol.x));
     

 return(0);

}
