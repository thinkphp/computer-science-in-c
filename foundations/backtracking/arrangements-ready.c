#include <stdio.h>
#define SIZE 100

int stack[SIZE],
    level,
    n,
    k;  

void init() {
  
     stack[level] = 0;
};

void print() {

    int i;

    for(i = 1; i <= k; i++) printf("%d ", stack[i]); 

    printf("\n"); 

};

int successor() {

    if(stack[level] < n) {

       stack[level]++;

       return 1;   
    }

    return 0; 
};

int valid() {

    int i;

    for(i = 1; i < level; i++)  

        if(stack[i] == stack[level]) return 0;

    return 1;  
};

int solution() {

    return level == k;
};

void back() {

     int hs,is;

     level = 1;

     while(level > 0) {

         hs = 1; is = 0;

         while(hs && !is) {

               hs = successor();

               if( hs ) is = valid(); 
         }

         if( hs ) {

             if( valid() ) 

                  if(solution()) print();

                      else 

                                 { level++; init(); }

         } else level--;
     }
};

int main() {

    scanf("%d", &n);
    scanf("%d", &k);
    back();

 return(0);
}