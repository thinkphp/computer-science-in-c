#include <iostream>
#include <fstream>
#include <vector>
#define pb push_back
#define FIN "algsort.in"
#define FOUT "algsort.out"

using namespace std;

typedef vector<int>::iterator I;

class Container {

      public:
      Container(I _first, I _last):first(_first),last(_last){};
      void sorted() {
           _bubblesort();
      };
      void print() {
           ofstream fout( FOUT );
           for(I it = first; it != last; ++it) fout<<*it<<" "; 
      };
      private:
      I first, 
        last;
      void _bubblesort() {
           bool finished = 0, 
                swapped;
           I _last = last - 1;

           while(!finished) {
                  swapped = false;
                  for(I it = first; it != _last; ++it) {
                      if(*it > *(it+1)) {
                         swap(*it, *(it+1));
                         swapped = true;    
                      }
                  } 
                  if(swapped) _last--;
                    else      finished = true;  
           }
      };  
       
};

int main() {

    int item, 
        n; 
    vector<int> vec; 
    ifstream fin( FIN );
    fin>>n;
    for(int i = 0; i < n; ++i) fin>>item, vec.pb(item);
    Container container(vec.begin(), vec.end());
    container.sorted(); 
    container.print();
    //or
    //for(auto v:vec) cout<<v<<" ";  
 
 return(0);
};
