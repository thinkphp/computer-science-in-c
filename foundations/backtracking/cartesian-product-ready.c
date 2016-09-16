#include <stdio.h>

int stack[100], 
    sets[100], 
    level,
    num;

void init() {

     stack[ level ] = 0;
};

int successor() {

    if(stack[level] < sets[level]) {
 
       stack[level]++;

       return 1;          
    }

    return 0;
};

int valid() {

    return 1; 
};

int solution() {

    return level == num; 

};

void print() {

    int i;
    printf("(");
    for(i = 1; i <= num; i++) printf("%d ", stack[i]);
    printf(")");
    printf(" ");
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

           if(hs) {

             if(solution()) {

               print(); 

             } else {

               level++;init(); 

             }

           } else level--;
     }
     
};

int main() {

    int i; 

    printf("Numbers of sets -> ");

    scanf("%d",&num);

    for(i = 1; i <= num; i++) scanf("%d", &sets[i]);

//num = 2

//sets[1] = 3
//sets[2] = 3
//A = {1,2,3}, B = {1,2,3}
//->AxB = {(1,1),(1,2),(1,3),(2,1),{2,2,},(2,3),{3,1},(3,2),(3,3)}

    back();
  

return(0);
}