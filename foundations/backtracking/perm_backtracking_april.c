#include <stdio.h>
#define FIN "permutari.in"
#define FOUT "permutari.out"

int Stack[100],N;

void print() {

     int i;

     for(i = 1; i <= N; ++i) printf("%d ", Stack[ i ]);
 
     printf("\n");
}
 
 int successor(int level) {
 
    if(Stack[ level ] < N) {

       Stack[ level ]++;

       return 1;
    } 
 
    return 0;  
}
 
int valid(int level) {

    int i;

    for(i = 1; i < level; i++) 
 
        if(Stack[ i ] == Stack[ level ]) return 0;
 
    return 1;
}
 
 
void back(int level) {

   int i;

   if(level == N + 1) print(); 

   else

         for(i = 0; i < N; i++) {
 
             Stack[level] = i;

             if(successor(level))

                 if(valid(level))

                         back(level + 1);  

         }
        
                
}
 
int main() {
     
     freopen(FIN, "r", stdin);      
     freopen(FOUT, "w", stdout);      
     scanf("%d",&N);
     back(1); 

   return 0;
}   
