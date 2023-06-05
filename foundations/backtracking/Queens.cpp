#include <cstdio>
#include <fstream>
#include <cmath>
#include <vector>
#define FIN "damesah.in"
#define FOUT "damesah.out"
   
using namespace std;
   
class Dame {
   
public:
      Dame(int n): N(n), Stack(n+1), numSols(0), one(0) {} 
   
void print() {

     for(int i = 1; i <= N; ++i) printf("%d ", Stack[ i ]);
   
     printf("\n");
}
   
int solution(int level) {
     
     return level == N;    
}
   
int successor(int level) {
   
    if(Stack[ level ] < N) {
       Stack[ level ]++;
       return 1;
    } 
   
    return 0;  
}
   
int valid(int level) {
   
    for(int i = 1; i < level; i++) 
   
        if(Stack[ i ] == Stack[ level ] || level - i == fabs(Stack[i]-Stack[level]) ) return 0;
   
    return 1;
}
   
void init(int level) {
   
     //init to zero
     Stack[ level ] = 0;
}
   
void back(int level) {

   if(level == N + 1) {

            numSols++; 

            if(!one) { print(); one = 1; }

   } else {
   
     init(level);
  
      while(successor(level))
          
         if(valid(level))
     
            back(level + 1);  
   }
                  
}
   
void gen() {
   
     back(1); 
     printf("%d", numSols);
}   
        
private: 
vector<int> Stack;
int         N, level, numSols, one;
   
};//end class
   
int main() {
   
 int n;
   
 ifstream in(FIN);
 freopen(FOUT, "w", stdout);
  
 in>>n; 
 //n = 4; 
 in.close();
   
 Dame d(n);
      d.gen();
     
 fclose( stdout );
   
 return(0);
};
