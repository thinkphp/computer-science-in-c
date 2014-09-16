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

int stack[ MAX ];

int main() {

    printf("n=");
    scanf("%d",&n);
    printf("k=");
    scanf("%d",&k);

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

     if(level>1) stack[level] = stack[level-1];

        else 
                 stack[level] = 0;      
};

int solution() {

    return level == k;
};

void printSolution() {

     int i;

     for(i=1;i<=k;i++) printf("%d ", stack[i]);
     printf("\n");
};

int isValid() {

    int i;
    for(i=1;i<level;i++) 
        if(stack[i] == stack[level]) return 0;

    return 1; 
};

int has_next() {

    if(stack[level] < n - k + level) {
       stack[level]++;
       return 1;  
    }
    return 0;

};
