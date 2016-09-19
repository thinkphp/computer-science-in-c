#include <stdio.h>
#define FIN "maze.in"

typedef struct element {

       int x,
           y;

} cell;

cell Moves[5] = {{0,0},{1,0},{0,1},{-1,0},{0,-1}};

cell stack[100];

int  level,
     n,m,
     p[100], 
     L[10][10];


void init() {

     p[level] = 0;
}

int successor() {

    if(p[level] < 4) {

       p[level]++; 

       stack[level].x = stack[level-1].x + Moves[p[level]].x;

       stack[level].y = stack[level-1].y + Moves[p[level]].y;   

       return 1; 

    } else 

      return 0;
};

int valid() {

    int i;

    if(L[stack[level].x][stack[level].y] == 0) return 0;

    for(i = 1; i < level; i++) 

        if(stack[i].x == stack[level].x && stack[i].y == stack[level].y) return 0;

    return 1;
};

int solution() { 

    return stack[level].x == 1 || stack[level].x == n || stack[level].y == 1 || stack[level].y == m;

};

void print() {

     int i;

     for(i = 1; i <= level; i++) printf("[%d %d]\n", stack[i].x, stack[i].y);

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

    int i,j;

    freopen(FIN, "r", stdin);

    scanf("%d %d", &n, &m);

    for(i = 1; i <= n; i++) {

        for(j = 1; j <= m; j++) {
    
            scanf("%d ", &L[i][j]);    
        } 
    }

    for(i = 1; i <= n; i++) {

        for(j = 1; j <= m; j++) {
    
            printf("%d ", L[i][j]);    
        } 

            printf("\n");    
    }


    level = 1;
    //start cell
    stack[level].x = 1;
    stack[level].y = 2;
    back();

    return(0);
}