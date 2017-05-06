#include <stdio.h>
#define SIZE 100

int stack[SIZE],
    level,
    n,
    k;

void init(){

     stack[level] = 0;
};

int valid() {

    int i;

    for(i = 1; i < level; i++) 

        if(stack[i] == stack[level]) return 0;

    return 1;
};

int succ() {

    if(stack[level]<n){

       stack[level]++;

       return 1;  
    }
    return 0;
};

int sol() {

    return level == k; 
};

void print() {

    int i;
 
    printf("x    | ");
    for(i = 1; i <= k; i++) printf("%d ", i);
    printf("\n----------------\n");
    printf("f(x) | ");
    for(i = 1; i <= k; i++) printf("%d ", stack[i]);
    printf("\n\n");           
};

void bt() {

    int hs,is;

    level = 1;

    while(level > 0) {

          hs = 1; is = 0;
 
          while(hs && !is) {

                hs = succ();

                if(hs) is = valid();                   
          } 

          if(hs) {

            if(sol()) print();

                else {level++;init();}                

          } else level--;  
    }

};

void printSet(char set, int n, int flag) {

     int i;

     if( flag ) printf("f : A -> B\n\n");

     printf("%c = {",set);

     for(i = 1; i <= n; i++) {

         printf("%d ",i);         
     }

     printf("}\n\n");
};

int main() {

    freopen("genAllInjective.out","w",stdout);

    printf("%s\n\n","Generating All The Injective Functions");
    //f : A -> B
    //A = {1,2}, B = {1,2,3}
    scanf("%d",&n);
    scanf("%d",&k);

    printSet('A',k, 1);
    printSet('B',n, 0);

    bt();    

return(0);
};