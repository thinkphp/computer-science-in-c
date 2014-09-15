/*
 * Backtracking for Salesman.
 */
#include <stdio.h>
#define MAX 20

//function prototypes
void init();
void back();
int solution();
void printSolution();
int isValid();
int has_next();
void read();
void matrix();

int level;

int stack[ MAX ];

int mat[ MAX ][ MAX ];
int num_nodes,num_edges;

int main() {

    read(); 
    matrix();

    level = 1;
    stack[level] = 1;

    level = 2;//go 
    back();

    return(0);
}


void back() {

     int HS;

     init();

     while(level > 0) {

           do{}while((HS=has_next()) && !isValid()); 

           if( HS ) {

             if(solution()) {

                printSolution();

             } else {

                level = level + 1;
                init(); 

             }

           } else {

             level = level - 1;
           }
     }
}


void init() {

     stack[ level ] = 0;      
};

int solution() {

    return level == num_nodes;
};

void printSolution() {

     int i;

     for(i = 1; i <= num_nodes; i++) printf("%d ", stack[i]);

     printf("\n");
};

int isValid() {

    int i;

    if(mat[ stack[ level - 1 ] ][ stack[ level ] ] == 0) return 0;

    else 

         for(i = 1; i < level; i++) 

             if(stack[ i ] == stack[ level ]) return 0;

         if(level == num_nodes && !mat[1][ stack[ level ] ]) return 0;  
    
    return 1;
};

int has_next() {

    if(stack[ level ] < num_nodes) {
       stack[ level ]++;

       return 1; 
    }
    return 0;
};

void read() {

     int i, j;

     freopen("voyage.in", "r", stdin);
     freopen("voyage.out", "w", stdout);

     scanf("%d", &num_nodes);
     scanf("%d", &num_edges);

     for(; num_edges; num_edges--) {

           scanf("%d %d", &i, &j);
           mat[i][j] = 1;
           mat[j][i] = 1; 
     }
};

void matrix() {
     int i,j;
     for(i=1;i<num_nodes;i++) {
         for(j=1;j<num_nodes;j++) {
             printf("%d ",mat[i][j]);
         }
             printf("\n");
     }

}

