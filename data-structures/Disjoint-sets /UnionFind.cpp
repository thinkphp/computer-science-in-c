/*
 * Authors'name: Adrian Statescu Dumitru
 * Description: Disjoint Sets Forest. Union Find Data Structure
 * License: MIT use and distribute it as long as you kept it
 */
#include <iostream>
#include <fstream>
#define FIN "disjoint.in"
#define FOUT "disjoint.out"

using namespace std;

typedef unsigned int uint;
typedef unsigned long ulong;

class UnionFind {

      public:
      //constructor of the class
      UnionFind(int n):numElements(n),
                       parent( new ulong[n+1]),
                       height(new ulong[n+1])
      {

        for(int i = 1; i <= numElements; ++i) {

            parent[ i ] = i;
            height[ i ] = 1;
        }

      }

      int sameSets(ulong x, ulong y) {
        ulong rootX = getRoot( x ),
              rootY = getRoot( y );
              updatePathRoot(x, rootX);
              updatePathRoot(y, rootY);
        return rootX == rootY;
      }

      void unionSets(ulong x, ulong y) {

           ulong rootX = getRoot( x ),
                 rootY = getRoot( y );

           if(height[rootX] < height[ rootY ]) {
              parent[ rootX ] = rootY;

           } else if(height[ rootX ] > height[ rootY ]) {
              parent[ rootY ] = rootX;
           } else {
              parent[ rootY ] = rootX;
              height[ rootX ]+=1;
           }
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

           if(node == root && parent[ node ] == root) {
              return;
           }

          while(parent[node]!=root) {

              ulong prevParent = parent[node];

              parent[node] = root;

              node = prevParent;
          }


      }

};

int main(int argc, char const *argv[]) {

  ulong numElements,
        numOps,
        type,
        x,
        y;

  ifstream fin( FIN );
  ofstream fout( FOUT );

#ifndef NDEBUG
  if(!fin) {
    cerr<<"Error Opening File";
    return -1;
  }

  if(!fout) {
    cerr<<"Error Opening File";
    return -1;
  }
  #endif

  fin>>numElements>>numOps;

  UnionFind unionFind( numElements );

  while(numOps--) {

        fin>>type>>x>>y;

        switch(type) {

          case 1:
          unionFind.unionSets(x, y);
          break;

          case 2:
          fout<<(unionFind.sameSets(x, y) ? "DA": "NU")<<"\n";
          break;
        }
  }
  return 0;
}
