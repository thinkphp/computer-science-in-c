/**
 * Author     : Adrian Statescu <mergesortv@gmail.com>, <http://thinkphp.ro>
 * Description: Hamilton Path
 */
#include <iostream>
#include <fstream>
#include <vector>
#define FIN "hamilton.in"
#define FOUT "hamilton.out"
#define DIM 50

using namespace std;

//Backtracking in Action
//I'm trying to make use of a vector Container to hold my Matrix. 
//Configure the vector container to be multidimensional
vector< vector<int> > Matrix(DIM, vector<int>(DIM));
int Stack[ DIM ];
int nodes,
    edges,
    level;

     ofstream fout(FOUT);
             
void readGraph() {

     int a,b;

     ifstream fin(FIN);

     fin>>nodes>>edges;

     for(; edges-- ;) {

         fin>>a>>b; 
         Matrix[a][b] = 1;
         Matrix[b][a] = 1;
     }
    
     fin.close();
};

void printMatrix() {

     for(int i = 1; i <= nodes; i++) {

         for(int j = 1; j <= nodes; j++) {

             cout<<Matrix[i][j]<<" ";  
         }

         cout<<endl;
     }
};

void init() {

     Stack[ level ] = 1;
};

int solution() {

    return level == nodes;
}

void printSolution() {

     for(int i = 1; i <= nodes; i++) fout<<Stack[ i ]<<" ";

     fout<<endl;
};

int isValid() {

    if( Matrix[ Stack[ level - 1 ] ] [ Stack[ level ] ] == 0) return 0;

    else {

         for(int i = 1; i < level; i++) 

            if(Stack[ i ] == Stack[ level ]) return 0;

         if(level == nodes && Matrix[ Stack[ 1 ] ][ Stack[ level ] ] == 0) return 0; 
    } 

    return 1;
}

int haveNext() {

    if(Stack[ level ] < nodes) {

       Stack[ level ]++;
       return 1; 
    } 

    return 0;
}

void Solve() {

 int HN;

 level = 1;

 Stack[ level ] = 1;

 level = 2;

 init();

 while(level > 0) {

       do{}while((HN = haveNext()) && !isValid());

       if( HN ){

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

 fout.close();
}

int main() {
  
 readGraph();
 Solve();

 return(0);
};
