//generarea permutarilor folosind metoda Backtracking rec
#include <iostream>

using namespace std;

int n, stack[100];

int accepted(int level) {
  
    for(int i = 1; i < level;++i) {
      
       if(stack[level] == stack[i]) {
      
         return 0;
      }
    }
  return 1;
}

void solve(int level) {
  
   if(level == n+1) {
    
      for(int i = 1; i <= n; ++i) {
        cout<<stack[i]<<" ";
      }
     cout<<endl;
     
   } else {
     
     for(int i = 1; i <= n; ++i) {
       
         stack[level] = i;
       
         if(accepted(level)) {
           
            solve(level+1);
         }
     }
   }
}

int main() {
//1 2 3
//2 3 1  
  
  n = 3;//n! = 1*2*3*4*.....*n 
  //n! permutari
  
  solve( 1 );
  
}
