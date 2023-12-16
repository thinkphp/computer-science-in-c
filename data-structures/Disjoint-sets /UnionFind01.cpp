/*
                _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . ___
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='

*/
#include <iostream>
#include <fstream>
#define FIN "disjoint.in"
#define FOUT "disjoint.out"

typedef unsigned long ulong;

using namespace std;

class UnionFind {

      public:
      UnionFind(ulong num):numElements( num ),
                           parent( new ulong[num + 1] ),
                           height( new ulong[ num + 1 ] )
      {

              for(int i = 1; i <= numElements; ++i) {

                  parent[ i ] = i;

                  height[ i ] = 1;
              }
      }

      ~UnionFind() {
          delete [] parent;
          delete [] height;
      }

      void unionSets(ulong x, ulong y) {

           ulong rootX = getRoot( x ) ;

           ulong rootY = getRoot( y ) ;

           if(height[ rootX ] > height[ rootY ]) {

              parent[ rootY ] = rootX;

           } else if(height[ rootX ] < height[ rootY ]) {

              parent[ rootX ] = rootY;

           } else {

              parent[rootY] = rootX;

              height[ rootX ] += 1;
           }
      }

      ulong sameSets(ulong x, ulong y) {

        ulong rootX = getRoot( x ) ;

        ulong rootY = getRoot( y ) ;

        updatePathRoot(x, rootX);

        updatePathRoot(y, rootY);

        return rootX == rootY;
      }

      private:
      ulong numElements,
            *parent,
            *height;

      ulong getRoot(ulong node) {

            ulong root = parent[ node ];

            while(root != parent[root]) {

                  root = parent[root];
            }
            return root;
      }

      void updatePathRoot(ulong node, ulong root) {

           if(node == root && root == parent[ node ]) return;
      }
};

int main(int argc, char const *argv[]) {

  ifstream fin(FIN);
  ofstream fout(FOUT);

  #ifndef NDEBUG

  if(!fin || !fout) {

     cerr<<"Error Opening File";
     return -1;
  }

  #endif

  ulong numElements, //number of elements
        numOps, //number of operations
        type, //the type of the oparation
        x, //element x
        y; //element y

  fin>>numElements>>numOps;

  UnionFind uf( numElements );

   while(numOps--)
   {

        fin>>type>>x>>y;

        switch(type)
        {
                    case 1:
                    uf.unionSets(x,y);
                    break;

                    case 2:
                    fout<<(uf.sameSets(x,y) ? "DA": "NU")<<"\n";
                    break;
        }
  }
  return 0;

}
