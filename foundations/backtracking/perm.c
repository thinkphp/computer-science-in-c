#include <stdio.h>
#define max 10

//function prototypes
void read(const char*);
void solve();

void back();
void init();
int solution();
int isValid();
int have_next();
void printSolution(const char*); 

FILE *fin,*fout;
int n,
    stack[max],
    level;

int main() {
    
    fout = fopen("perm.out", "w");
    read("perm.in");
    solve(); 
    fclose(fout);

    return(0); 
}

void read(const char *filename) {

     fin = fopen(filename, "r");

     fscanf(fin, "%d %d", &n); 

     fclose(fin);
};


void solve() {

     level = 1;
     stack[level] = 1;
     level = 2;
     back();
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
            printSolution("perm.out"); 
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

        if(stack[i] == stack[level]) {
           return 0;
        }
    }

    return 1;
};

int solution() {

    return level == n;
};

void printSolution(const char *filename) {

    int i;

    for(i = 1; i <= n; i++) {

        printf("%d ", stack[i]);

        fprintf(fout, "%d ", stack[ i ]);
    }

    printf("\n");

    fprintf(fout,"\n");    
};

int have_next() {

    //because we have four colors
    if(stack[level] < n) {
       stack[level]++; 
       return 1; 
    }

    return 0;
}
