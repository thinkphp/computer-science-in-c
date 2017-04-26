#include <cstdio>
#include <fstream>
#include <vector>
#define FIN "permutari.in"
#define FOUT "permutari.out"
 
using namespace std;
 
class Permut {
 
public:
       Permut(int n): N(n), Stack(n+1){} 
 
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
 
        if(Stack[ i ] == Stack[ level ]) return 0;
 
    return 1;
}
 
void init(int level) {
 
     //init to zero
     Stack[ level ] = 0;
}
 
void back(int level) {
 
   init(level);

   while(successor(level))
        
         if(valid(level))

              if(solution(level)) print();

                  else 

                     back(level + 1);  
                
}
 
void gen() {
 
     back(1); 
}   
      
private: 
vector<int> Stack;
int    N, level;
 
};//end class
 
int main() {
 
 int n;
 
 ifstream in(FIN);
// freopen(FOUT, "w", stdout);
 
 n = 3;
 in.close();
 
 Permut p(n);
        p.gen();
   
 fclose( stdout );
 
 return(0);
};