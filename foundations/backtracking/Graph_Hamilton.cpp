#include <iostream>
#define FIN "graph.in"
#define SIZE 50

using namespace std;

int mat[SIZE][SIZE], stack[SIZE],
nodes,
k,
start_node;

void loadGraph() {
    int i, j;
    freopen(FIN, "r",stdin);
     //citim numarul de noduri
     cin>>nodes;

     //citim muchiile (i,j)
     //de la i la j si de la j la i
     while(cin>>i>>j) {
       mat[i][j] = 1;
       mat[j][i] = 1;
     }
}

void displayGraph() {

     for(int i = 1; i <= nodes; i++) {
        for(int j = 1; j <= nodes; ++j) {
          printf("%d ", mat[i][j]);
        }

        printf("\n");
     }
}

void init() {
    //k = 2; stack[2] = 0
    stack[ k ] = 0;
}

int succ() {

    if(stack[k] < nodes) {//0 < 9 ?

       stack[k]++;//stack[k] = 1 + 1 = 2 (varful) stack[k] = 2
       return 1;
    }
    return 0;
}

int valid() {

    if(!mat[ stack[k-1] ] [ stack[k] ]) return 0;

    for(int i = 1; i < k ; ++i)

           if(stack[i] == stack[k]) return 0;

    return 1;
}

int sol() {

    return (k == nodes) && (mat[ start_node ][ stack[k] ] == 1);
}

void display_solution() {

     for(int i = 1; i <= nodes; ++i) printf("%d ", stack[i]);

     printf("%d", start_node);
     printf("\n");
}

//backtracking iterative
void bkt() {

     int h, v;

     k = 2;

     init();

     while(k > 1) {

           h = 1;
           v = 0;
           while(h && !v) {
               h = succ();
               if(h) v = valid();
           }

           if(h) {

             if(sol()) {
                display_solution();
                //k = 1;
             } else {
               k++;init();
             }

           } else k--;
     }

}

int main(int argc, char const *argv[]) {

  printf("%s","Nodul de start = ");
  scanf("%d", &start_node);

  loadGraph();
  printf("%s\n", "Graful neorientat");
  displayGraph();

  stack[1] = start_node;
  //k = 2;
  //stack[2] = 1;

  printf("%s\n","Drumuri hamiltoniene:");
  bkt();

  return 0;
}

//k=3; stack[k] :3
//k=2; stack[k] :2
                //muchie
//k=1; stack[k] :1 (varf)

//stack[k] = Varf

//node_start = 5

//stack[1] = 5

             //init()
//stack[2] = stack[2] + 1 = 0 + 1 = 1
