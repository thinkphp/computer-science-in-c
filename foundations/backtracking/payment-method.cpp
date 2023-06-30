#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int n , S, v[10], x[10], found = false;

void display(int level) {
  
     found = true;
     
     for(int i = 1; i <= level;++i) {
       
       cout<<x[i]<<" ";
     }
}

void back(int level, int sum) {

     if(level<=n) {
       
        for(int i = 0; i <= (S - sum)/v[level] && !found; ++i) {
          
           x[level] = i;
           
           if(sum + x[level]*v[level] == S) {

              display(level);

           } else back(level+1,sum + v[level]*x[level]);
        }
     }
}

int main()
{
    cin >> n >> S;
    for(int i = 1 ; i <= n ; ++i)
        cin >> v[i];
    back(1, 0);
    return 0;
}
