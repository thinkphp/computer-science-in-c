#include <iostream>
#include <fstream>
#include <functional>
#include <vector>
#define FIN "algsort.in"
#define FOUT "algsort.out"

using namespace std;

typedef vector<int>::iterator MyIterator;

template <typename I, typename OP>
void selectionmin(I first, I last) {    

     OP o = OP();

     for(I curr = first; curr != last; ++curr) {

         I min = curr, 

                  next = curr;  

         next++;

         while(next != last) {

            if( o(*next,*min) ) {

               min = next;
            }

            next++;
         }
          
         if(curr != min) iter_swap(curr, min);
     }  
}


int main() {

    vector<int> vec;

    int i, n, elem;

    freopen(FIN, "r", stdin);
    freopen(FOUT, "w", stdout);

    cin>>n;

    for(i = 0; i < n; ++i) cin>>elem, vec.push_back(elem);

    selectionmin<MyIterator, less<>>(vec.begin(), vec.end());

    for(MyIterator it = vec.begin(); it != vec.end(); ++it) cout<<*it<<" ";  
  
return(0);
}
