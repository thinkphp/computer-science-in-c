#include <stdio.h>
#define SIZE 100

int stack[ SIZE ],
    level,
    n,
    m;

int init() {

    stack[level] = 0;
};

void print() {

     int i;

     printf("x      | ");
     for(i = 1; i <= n; i++) printf("%d ",i);
     printf("\n---------------\n");
     printf("f(x)   | ");
     for(i = 1; i <= n; i++) printf("%d ", stack[i]);

     printf("\n\n");
};

int succ() {

   if(stack[level] < m) {

      stack[level]++;

      return 1; 
   }
   return 0;
};

int surjective() {

    int i,j,flag;

    for(i = 1; i <= m; i++) {

        for(j = 1, flag = 0; j <= n && !flag; j++) {

                if(stack[j] == i) flag = 1;
        }  

        if(!flag) return 0;         
    }  
    return 1; 
};

int valid() {

    if(level == n) {

       if(!surjective()) return 0;
    } 

    return 1; 
};

int sol() {

    return level == n;
};

void bt() {

     int hs, is;

     level = 1;

     init();

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

void printSet(int n){

     int it;
     printf("\n{");
     for(it = 1; it <= n; it++) {
         printf("%d ",it);
     }
     printf("}\n");
};

int main() {
    
    freopen("Generating.All.Surjective.Functions.out", "w",stdout);
 
    printf("%s\n","Generating All The Surjective Functions:\n");
    
    //f : A -> B
    //A = {1,2,3}, B = {1,2} {(1,1,2),{1,2,1},(1,2,2),{2,1,1},(2,1,2)}

    printf("Domain -> card(A) ");
    scanf("%d",&n);
    printSet(n);
    printf("CoDomain -> card(B) ");
    scanf("%d",&m);
    printSet(m);
    printf("\n");
    bt();    

return(0);
};