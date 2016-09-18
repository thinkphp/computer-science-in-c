#include <stdio.h>

typedef struct element {

       int x,
           y;

} cell;

cell Moves[100] = {{0,0},{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};

cell stack[100];

int  level,
     n, 
     p[100];


void init() {

     p[level] = 0;  
}

int successor() {

    if(p[level] < 8) {

       p[level]++; 

       stack[level].x = stack[level-1].x + Moves[p[level]].x;

       stack[level].y = stack[level-1].y + Moves[p[level]].y;   

       return 1; 

    } else 

      return 0;
};

int valid() {

    int i;

    if(stack[level].x < 1 || stack[level].y < 1 || stack[level].x > n || stack[level].y > n) return 0;

    for(i = 1; i < level; i++) 

        if(stack[i].x == stack[level].x && stack[i].y == stack[level].y) return 0;

    return 1;
};

int solution() { return level == n * n; }

void print() {

     int i;
 
     for(i = 1; i <= n * n; i++) printf("(%d,%d) ", stack[i].x, stack[i].y);

     printf("\n"); 
}

void back() {

     int is,hs;

     level = 2;

     init();

     while(level > 0) {

           hs = 1; is = 0;

           while(hs && !is) {

                 hs = successor();

                 if( hs ) is = valid();  
           } 

           if(hs) {

              if(solution()) {print();break;}

                   else 
                            {level++;init();}

           } else level--;
           
     }
}

int main() {

    n = 8;
    stack[1].x = 1;
    stack[1].y = 1;
    back();

    return(0);
}