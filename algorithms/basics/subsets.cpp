#include <iostream>
 
using namespace std;
 
int stack[100], n;
 
void subsets(int level) {
     if( level <= n ) {
         for(int i = stack[level-1]+1; i <= n; ++i) {
             stack[level] = i;
             for(int j = 1; j <= level;++j)
             cout<<stack[j]<<" ";
             cout<<endl;
             subsets(level+1);
         }
     }
}
 
int main() {
	n = 3;
	subsets(1);
}
