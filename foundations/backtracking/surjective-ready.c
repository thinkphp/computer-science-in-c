#include <stdio.h>
#define SIZE 100

int stack[SIZE],
    level,
    N,
    M;

void init() {

     stack[ level ] = 0;
};

int successor() {

    if(stack[ level ] < M ) {
 
       stack[level] = stack[ level ] + 1;

       return 1;          

    } else {

       return 0;
    }
};

int surjective() {

    int i,
        j,
        flag;

    for(j = 1; j <= M ; j++) {

        for(i = 1, flag = 0; i <= N && !flag; i++)
          
            if( j == stack[i] ) flag = 1;
   
        if(!flag) return 0;  
    }
   
    return 1;
    
};

int valid() {

   if(level == N) 

   if(!surjective()) return 0;

   return 1;
      
};

int solution() {

    return level == N; 

};

void print() {

    int i;

    printf("x    | "); 
    for(i = 1; i <= N; i++) printf("%d ",i);
    printf("\n-------------\n"); 
    printf("f(x) | "); 
    for(i = 1; i <= N; i++) printf("%d ",stack[i]);
    printf("\n\n"); 

};

void back(){

     int hs, is; 

     level = 1;

     init(); 

     while(level > 0) {

           hs = 1; is = 0;

           while(hs && !is) {

                 hs = successor();

                 if(hs) is = valid();
           }           

           if( hs ) {

             if( solution() ) {

               print(); 

             } else {

               level++; 

               init(); 
             }

           } else level--;
     }
     
};

int main() {

    int i; 

//N = 3
//M = 2
//A = {1,2,3}
//B = {1,2}
// f : A -> B, display all the surjectives functions.

    printf("First SET -> ");
    scanf("%d",&N);
    printf("Second SET ->");
    scanf("%d",&M);
    printf("\n"); 


    freopen("surjective.out","w",stdout);

    back();
  

return(0);
}