#include <stdio.h>
#define size 100
#define FIN "hamiltonian_path.in"

int road[size][size], //matrix of roads
    stack[size], 
    level,start_node,
    n;//number of nodes

void readRoad();
void readRoadFromFile();
void writeRoad();   
void bt();
void init();
void print();
int valid();
int succ();
int sol();

int main() {

    //printf("Number of cities -> "); 
    //scanf("%d",&n);
    //readRoad();
 
    readRoadFromFile();    
    writeRoad(); 

    //start_node = 5; 
    bt();

 return(0);

};

void print() {

     int i;

     for(i = 1; i <= n; i++) printf("%d ", stack[i]);

     printf("%d", start_node);
     printf("\n");
};

void init() {

     stack[level] = 0; 
};

int succ() {
 
    if(stack[level] < n) {

       stack[level]++;

       return 1;

    } 

    return 0;
};

int valid() {

     int i;

        if(!road[ stack[level - 1] ][ stack[level] ]) return 0;

        else {

              for(i = 1; i < level; i++) if(stack[i] == stack[level]) return 0; 

              return 1;
        }       
};

int sol() {

    return (level == n) && (road[ start_node ][  stack[ level ] ] == 1);
};


void bt() {

     int hs, is;

     stack[1] = start_node;
  
     level = 2;

     init();

     while(level > 0) {

           hs = 1; is = 0;

           while(hs && !is) {

                 hs = succ();

                 if(hs) is = valid();
           } 

           if(hs) {

             if(sol()) print();

                else   {level++;init();}
 
           } else level--;
      
     }
     
};

void writeRoad() {


     int i,j;

     printf("\nMatrix of roads!\n");
     printf("\n-------------------\n");

     for(i = 1; i <= n; i++) {

         for(j = 1; j <= n; j++) {

             printf("%d ", road[i][j]);
         }
             printf("\n");
     }
     printf("-------------------\n");

};

void readRoadFromFile() {

     int edges, a, b;

     freopen(FIN, "r",stdin);

     scanf("%d %d %d", &n, &edges, &start_node);

     int i;

     while(edges--) { 

             
             scanf("%d %d", &a, &b);

             road[a][b] = 1;

             road[b][a] = 1;
     }

}

void readRoad() {

     int i, j;

     for(i = 1; i <= n; i++) {

         for(j = 1; j <= i - 1; j++) {

             printf("mat[%d][%d] ->", i, j);

             scanf("%d", &road[i][j]);

             road[j][i] = road[i][j];  
         }
     }
};