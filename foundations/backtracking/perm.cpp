#include <iostream>
#include <fstream>

int stack[100];
int n;

using namespace std;

int ok(int level){
        for(int i=1;i<level;++i) {
          if(stack[level] == stack[i]){
            return 0;
          }
        }
        return 1;
}

void perm(int level) {
     if(level==n+1) {
        for(int i=1;i<=n;++i) {
          cout<<stack[i]<<" ";
        }
        cout<<"\n";
     } else {
       for(int i=1;i<=n;++i) {
         stack[level]=i;
         if(ok(level))


         perm(level+1);
       }
     }
}

int main(int argc, char const *argv[]) {

  n = 3;
  perm(1);

  return 0;
}
