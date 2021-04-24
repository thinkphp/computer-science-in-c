#include <iostream>

using namespace std;

typedef struct Element {
       int x,
           y;
} Cell;

Cell Moves[ 5 ] = {{0,0},{-1,0},{0,1},{1,0},{0,-1}};

int P[ 100 ];

int M[ 100 ][ 100 ] = {{0,0,0,0,0,0,0,0,0,0,0},
                       {0,0,0,1,0,0,0,0,0,0,0},
                       {0,0,0,1,0,0,0,0,0,0,0},
                       {0,0,0,1,1,0,0,0,0,0,0},
                       {0,0,0,0,1,1,1,0,0,0,0},
                       {0,0,0,0,0,0,1,0,1,1,1},
                       {0,0,0,0,0,0,1,1,1,0,0},
                       {0,0,0,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,1,0,0,0,0},
                       {0,0,0,0,0,0,1,1,1,0,0},
                       {0,0,0,0,0,0,0,0,1,0,0}};

typedef Cell stiva[ 100 ];

stiva stack;

int level,
    N;

void init() {

     P[level] = 0;
}

int succ() {

    if(P[level] < 4) {
       P[level] = P[level] + 1;
       stack[level].x = stack[level-1].x + Moves[ P[level] ].x;
       stack[level].y = stack[level-1].y + Moves[ P[level] ].y;
       return 1;
    } else
    return 0;
}

int valid() {

    if( M[ stack[ level ].x ][ stack[ level ].y ] == 0)
        return 0;

    for(int i = 1; i < level; ++i)

        if(stack[i].x == stack[level].x &&
           stack[i].y == stack[level].y)

           return 0;

    return 1;
}

int sol() {

  return stack[level].x == 1 ||
         stack[level].x == N ||
         stack[level].y == 1 ||
         stack[level].y == N;
}

void print() {

     for(int i = 1; i <= level; ++i) {

             cout<<"["<<stack[i].x<<","<<stack[i].y<<"] ";
     }
}

void bk() {

     int hs,
         iv;

     level = 2;
     init();

     while(level > 0) {

               hs = 1;
               iv = 0;

               while(hs == 1 && iv == 0) {

                     hs = succ();

                     if( hs ){

                       iv = valid();
                     }
               }

               if( hs ) {

                  if( sol() ) {

                    print();

                  } else {

                    level++;
                    init();
                  }

               } else
                 level--;

     }
}

int main(int argc, char const *argv[]) {

  N = 10;
  level = 1;
  stack[level].x = 1;
  stack[level].y = 3;
  bk();
  cout<<endl;
  for(int i = 0 ; i <= N; ++i) {
      for(int j = 0; j <= N; ++j) {
        cout<<M[i][j]<<" ";
      }
      cout<<endl;
  }
  return 0;
}
