#include <stdio.h>
#include <iostream>
#define FIN "hamilton.in"
#define FOUT "hamilton.out"
#define SIZE 100


using namespace std;

int stack[ SIZE ], 
    level, 
    nodes, edges;

int mat[SIZE][SIZE];

void init() {

     stack[ level ] = 0;
};

int succ() {

    if(stack[level] < nodes) {

       stack[level]++;

       return 1;  

    } else return 0;

      
};

int valid() {

     int i;

     if( mat[ stack[ level - 1 ] ][ stack[ level ] ] == 0 ) {

       return 0;       

     } else {
 
   
         for(i = 1; i < level; i++) {
  
             if( stack[i] == stack[level] ) return 0;
         }

         return 1;
     }

};

int sol() {

    return level == nodes && mat[ 1 ][ stack[level] ];
};

void print() {

     int i;

     for(i = 1; i <= nodes; i++) printf("%d ", stack[ i ]);

     cout<<endl;  
};

void bk() {

     int hs, is;      


     while( level > 0 ) {

             hs = 1; is = 0;

             while(hs && !is) {

                   hs = succ();

                   if( hs ) is = valid();                       
             }

             if(hs) {

                if(sol()) {

                  print();
 
                } else {

                  level++;

                  init();  

                }

             } else level--;
     }
};

void printM() {

     for(int i = 1; i <= nodes; i++) {

         for(int j = 1; j <= nodes; j++) {

             cout<<mat[i][j]<<" ";  
         }

         cout<<endl;
     }
}

int main() {

    int a, 
        b;

    freopen(FIN, "r", stdin);

    scanf("%d %d", &nodes, &edges);

    while( edges-- ) {

        scanf("%d %d", &a, &b); 
        mat[a][b] = 1;
        mat[b][a] = 1; 
    }  

    //printM();

    stack[1] = 1;

    level = 2;

    init();
    
    bk();

return(0);
}