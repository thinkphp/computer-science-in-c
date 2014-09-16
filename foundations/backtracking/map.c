#include <stdio.h>
#define max 10

//function prototypes
void read(const char*);
void solve();
void write(const char*);
void matrix();

void back();
void init();
int solution();
int isValid();
int have_next();
void printSolution(); 

FILE *fin,*fout;
int nodes, edges;
int mat[max][max];

int stack[max],level;

int main() {
    
    read("map.in");
    matrix();
    solve();
    write("map.out");

    return(0); 
}

void read(const char *filename) {
     //local variables
     int i,j;
     fin = fopen(filename, "r");

     fscanf(fin,"%d %d",&nodes,&edges); 

     for(;edges;edges--) {

        fscanf(fin,"%d",&i);
        fscanf(fin,"%d",&j);
        mat[i][j] = 1;
        mat[j][i] = 1;
     }

     fclose(fin);
};

void matrix() {
     int i,j;
     for(i=1;i<=nodes;i++) {
         for(j=1;j<=nodes;j++) {
             printf("%d ", mat[i][j]);
         }
             printf("\n");
     }
}

void solve() {

     level = 1;
     stack[level] = 1;
     level = 2;
     back();
};

void write(const char *filename) {

    int i;
   
    fout = fopen(filename, "w");

    for(i=1;i<=nodes;i++) {

        fprintf(fout, "country %d -> color %d\n", i, stack[i]);
    }

    fclose(fout);
};

void init() {

   stack[ level ] = 0;
}
 

void back() {

     int HS;     

     init();

  while(level > 0) {

     do{}while((HS=have_next()) && !isValid());

     if( HS ) {
         if(solution()) {
            printSolution(); 
            break; 
         } else {
            level = level + 1;
            init();
         }
     } else {
         level = level - 1;
     }
 }
          
};

int isValid() {
    int i;

    for(i=1;i<=level-1;i++) {

        if(mat[i][level] == 1 && stack[i] == stack[level]) {
           return 0;
        }
    }

    return 1;
};

int solution() {

    return level == nodes;//nodes = number of countries
};

void printSolution() {
    int i;

    for(i=1;i<=nodes;i++) {

        printf("country %d -> color %d\n", i, stack[i]);
    }
};

int have_next() {

    //because we have four colors
    if(stack[level] < 4) {
       stack[level]++; 
       return 1; 
    }

    return 0;
}