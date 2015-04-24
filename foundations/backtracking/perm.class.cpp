#include <cstdio>
#include <fstream>
#include <vector>
#define FIN "perm.class.in"
#define FOUT "perm.class.out"
#define DIM 50

using namespace std;

class Permut {

public:
       Permut(int n): N(n), vec(n+1), Stack(n+1){} 

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

     int HN;

   while(level > 0) {   

     do{}while((HN=haveNext()) && !isValid());

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

     level = 1;
 
     Stack[ level ] = 1;

     level = 2;

     init();

     back(); 
}   
     

vector<int> vec,
            Stack;
int    N,
    level; 
};

int main() {

 int n;

 ifstream in(FIN);
 freopen(FOUT, "w", stdout);

 in>>n;

 in.close();

 Permut p(n);
        p.gen();

  
 fclose( stdout );

 return(0);
};