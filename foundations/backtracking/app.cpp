#include <iostream>

using namespace std;

struct Element {
       int x,
           y;
};

//vector of movements
Element Dist[ 9 ] = { {0,0}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1} };

typedef struct Element Element;

typedef Element stack[ 100 ];

stack st;

int p[ 100 ];

int level, N;

void init() {

     p[ level ] = 0;
}

int succ() {

    if(p[level] < 8) {

        p[level] += 1;
        st[level].x = st[level-1].x + Dist[p[level]].x;
        st[level].y = st[level-1].y + Dist[p[level]].y;
        return 1;
    }

    return 0;
}

int valid() {

    if(st[level].x < 1 || st[level].x > N || st[level].y < 1 || st[level].y > N) {

      return 0;
    }

    for(int i = 1; i < level; ++i) {

       if(st[i].x == st[level].x && st[i].y == st[level].y) {

         return 0;
       }
    }
    return 1;
}

int sol() {

    return level == (N * N);
}

void print() {

     for(int i = 1; i <= N*N; i++) {
         cout<<st[i].x<<","<<st[i].y<<" ";
         for(int j = 1; j <= N; ++j) {
             if(i == j * N) cout<<endl;
         }

     }

}

void bk() {

     level = 2;

     init();

     while(level > 0) {
           int hs = 1,
               iv = 0;

               while(hs && !iv) {
                     hs = succ();
                     if(hs) {
                       iv = valid();
                     }
               }

               if(hs) {
                 if(sol()) {
                   print();
                   break;
                   cout<<endl;
                 } else {
                   level++;
                   init();
                 }
               } else {
                 level--;
               }
     }
}

int main(int argc, char const *argv[]) {

    //5 x 5 chessboard
    N = 5;
    level = 1;
    st[level].x = 1;
    st[level].y = 1;
    bk();

  return 0;
}
