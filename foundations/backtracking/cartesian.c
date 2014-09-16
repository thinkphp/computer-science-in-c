#include <stdio.h>
#define MAX 10

//function prototypes
void init();
void back();
int solution();
void printSolution();
int isValid();
int has_next();

int level, n, k;

int stack[ MAX ], V[MAX];

int main() {
    int i;
    printf("Number of sets=");
    scanf("%d",&n);
 
    for(i=1;i<=n;i++) {
        printf("V[%d]=",i);
        scanf("%d",&V[i]);
    }

    back();

    return(0);
}


void back() {

     int HS;

     level = 1;
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


     stack[level] = 0;      
};

int solution() {

    return level == n;
};

void printSolution() {

     int i;

     for(i=1;i<=n;i++) printf("%d ", stack[i]);

     printf("\n");
};

int isValid() {

    return 1;
};

int has_next() {

    if(stack[level] < V[level]) {
       stack[level]++;
       return 1;  
    }
    return 0;

};
