#include <stdio.h>
#include <malloc.h>
#define MAX 50
 
struct Node {
 
       int info;
       struct Node *next;
};
 
struct Node *head, *ind, *c;
 
void readGraph(const char*);
void displayMatrix();
int connex();
int have_degree();
void dfs(int);
int add();
void cycle(struct Node *);
 
int mat[MAX][MAX], visited[ MAX ];
 
int num_vertices, num_edges;
 
FILE *fin, *fout;
 
//main program
int main() {
 
    readGraph("eulerian.in");
 
    if( connex() ) {
 
          if( have_degree() ) {
 
             head = (struct Node*)malloc(sizeof(struct Node));
             head->info = 1;
             head->next = 0;
 
             while( add() );
 
             c = head;
             while( c ) {
                   printf("%d ", c->info);
                   c = c->next;
             }
 
          } else {
 
           printf("The Graph does n respect the conditions for parity");
 
          }
 
    } else {
 
           printf("The Graph is not connex");
    }
 
    return(0);
};
 
//@param filename from where we can read the graph onto matrix of adjacence
//@return Void.
void readGraph(const char *filename) {
 
     int i,j;
 
     scanf("%d %d", &num_vertices, &num_edges);
 
     for(;num_edges; num_edges--) {
 
          scanf("%d %d",&i,&j);
          mat[i][j] = mat[j][i] = 1;
     }
 
}
 
//display the matrix adjacence for debug
//@param void
//@return void
void displayMatrix() {
 
     int i,j;
 
     for(i=1;i<=num_vertices;i++) {
 
         for(j=1;j<=num_vertices;j++) {
 
             printf("%d ", mat[i][j]);
         }
             printf("\n");
     }
}
 
//chech if the graph is odd or not
int have_degree() {
 
    int sum,i,j,not = 1;
 
    for(i = 1; i <= num_vertices; i++) {
 
        sum = 0;
 
        for(j = 1; j <= num_vertices; j++) {
 
            sum += mat[i][j];
        }
 
        if(sum&1) not = 0;
 
        if(!not) return not;
    }
    return not;
}
 
//check whether the graph is connex or not
int connex() {
    int i;
 
    dfs(1);
 
    for(i=1;i<=num_vertices;i++)
 
        if(!visited[i])
 
            return 0;
 
    return 1;
}
 
//Depth First Search Traversal
void dfs(int node) {
 
     int j;
 
     visited[ node ] = 1;
 
     for(j = 1; j <= num_vertices; j++) {
 
         if(mat[ node ][ j ]) {
 
                if(!visited[ j ]) {
 
                    dfs( j );
                }
         }
     }
}
 
int add() {
 
    int node, i, found = 0;
 
    struct Node *ind;
 
    ind = head;
 
    while(ind && !found) {
 
          for(i = 1; i <= num_vertices; i++) {
 
              if(mat[ind->info][ i ] == 1) found = 1;
          }
 
          if( !found ) ind = ind->next;
    }
 
 
    if( ind ) {
 
       cycle( ind );
 
       return 1;
    }
 
    return 0;
};
 
void cycle(struct Node *p) {
 
     struct Node *newnode, *nextnode, *basenode;
 
     int node;
 
     basenode = p;
     nextnode = p->next;
 
     do{
     node = 1;
 
     while(mat[ basenode->info ][ node ] == 0) node++;
 
     mat[basenode->info][ node ] = 0;
     mat[ node ][ basenode->info ] = 0;
 
     newnode = (struct Node*)malloc(sizeof(struct Node));
     newnode->info = node;
     newnode->next = NULL;
 
     basenode->next = newnode;
     basenode = newnode;
     }while(newnode->info != p->info);
 
     basenode->next = nextnode;
};
