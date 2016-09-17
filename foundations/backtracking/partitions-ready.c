#include <stdio.h>
#define SIZE 100

int stack[SIZE],
    level,
    n; 

int init() {

    stack[level] = 0;
};

int successor() {

    if(stack[level] < stack[level-1] + 1) {

       stack[level]++;

       return 1;
    }
    return 0;
};

int valid() {

    return 1;
};

int solution() {

    return level == n; 
};

void print() {

    int max = stack[1], i, j;

    for(i = 2; i <= n; i++) {

        if(stack[i] > max) max = stack[i];
    } 

    for(j = 1; j <= max; j++) {

        printf("{");

        for(i = 1; i <= n; i++) {

            if(stack[i] == j) {

                printf("%d ", i);
            }
        }       
        printf("},");
    }

    printf("\n");
};

void back() {

     int hs, is;

     level = 1;

     init();

     while(level > 0) {

           hs = 1; is = 0; 

           while(hs && !is) {

 
                 hs = successor();

                 if( hs ) {

                     is = valid();
                 }               
           }

           if( hs ) {

              if(solution()) print();

                     else  {level++; init();}

           } else level--;
     } 

};

//n = 3; A = {1,2,3} -> one partition -> {1,3},{2}  <-> 1 2 1 

int main() {

    scanf("%d",&n);

    back();
 
 return(0);
}

