#include <iostream>
#include <fstream>
#define FIN "hamilton.in"
#define FOUT "hamilton.out"
#define DIM 50

using namespace std;

int mat[ DIM ][ DIM ], 
    Stack[ DIM ], 
    N, M, level;

void readGraph() {

     int a,b;

     ifstream fin(FIN);

     fin>>N>>M;

     for(; M-- ;) {

         fin>>a>>b; 
         mat[ a ][ b ] = 1;
         mat[ b ][ a ] = 1; 
     }
    
     fin.close();
};

void printMatrix() {

     for(int i = 1; i <= N; i++) {

         for(int j = 1; j <= N; j++) {

             cout<<mat[i][j]<<" ";  
         }

         cout<<endl;
     }
}

void init() {
 
     Stack[ level ] = 0;
}

int have_succesor() {

    if(Stack[ level ] < N) {

       Stack[ level ]++; 
       return 1;
    }

    return 0;
};

int is_valid() {

    if( mat[ Stack[ level - 1 ] ][ Stack[ level ] ] == 0) {

       return 0;

    } else 
       
       for(int i = 1; i < level; i++)
 
           if(Stack[ i ] == Stack[ level ]) return 0;

       if(level == N && !mat[ 1 ][Stack[level]]) return 0;

    return 1;
};

void printSolution() {

     for(int i = 1; i <= N; i++) cout<<Stack[ i ]<<" "; 
     cout<<endl;
};

int solution() {

    return level == N;
}

void back() {
     
     int HS;

     while(level > 0) {

           do{}while((HS = have_succesor()) && !is_valid()); 

           if(HS) {

             if(solution()) printSolution();
                    else {
                         level = level + 1;
                         init();
                    } 
           } else {

             level = level - 1; 
           }         
     }

};

int main() {
  
 readGraph();
 Stack[ 1 ] = 1;
 level = 2;
 init(); 
 back();
 
 return(0);
};
