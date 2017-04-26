#include <cstdio>
#include <fstream>
#include <vector>
#define FIN "permutari.in"
#define FOUT "permutari.out"
 
using namespace std;
 
class Permut {
 
public:
       Permut(int n): N(n), Stack(n+1){} 
 
void printSolution() {
 
     for(int i = 1; i <= N; ++i) printf("%d ", Stack[ i ]);
 
     printf("\n");
}
 
int solution() {
 
     return level == N;    
}
 
int haveNext() {
 
    if(Stack[ level ] < N) {
       Stack[ level ]++;
       return 1;
    } 
 
    return 0;  
}
 
int isValid() {
 
    for(int i = 1; i < level; i++) 
 
        if(Stack[ i ] == Stack[ level ]) return 0;
 
    return 1;
}
 
void init() {
 
     //init to zero
     Stack[ level ] = 0;
}
 
void back() {
 
   int HN, is;

   level = 1; 

   init();
 
   while(level > 0) {   
  
     HN = 1; is = 0;

     while(HN && !is){

           HN = haveNext();

           if(HN) is = isValid();
     }
 
     if( HN ) {
 
         if( solution() ) {
 
             printSolution();
 
         } else {
 
            level++;
 
            init();
         }
 
     } else {
 
       level--; 
     }
 
   }
}
 
void gen() {
 
     back(); 
}   
      
private: 
vector<int> Stack;
int    N,
    level; 
 
};//end class
 
int main() {
 
 int n;
 
 ifstream in(FIN);
 freopen(FOUT, "w", stdout);
 
 n = 3;
 in.close();
 
 Permut p(n);
        p.gen();
   
 fclose( stdout );
 
 return(0);
};