#include <iostream>
#include <fstream>
#include <vector>
#define pb push_back
#define FIN "algsort.in"
#define FOUT "algsort.out"

using namespace std;

class Container {

      public:
      Container(vector<int> _arr):vec(_arr){n = vec.size();};
      void sorted() {
           int gaps, gap, i, j;

           for(gaps = n/2; gaps > 0; gaps/=2) {
               gap = gaps;
               for(i = gap; i < n; ++i) {
                   int aux = vec[i];
                    for(j = i - gap; j >= 0 && vec[j] > aux; j-=gap) {
                        vec[j+gap] = vec[j]; 
                    }
                        vec[j+gap] = aux;
               } 
           }

      };
      void print() {
           ofstream fout(FOUT);
           for(vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) fout<<*it<<" "; 
      };
      private:
      vector<int> vec;
      int n; 
};

int main() {

    int n,
        item;
    ifstream fin(FIN);
    vector<int> vec; 
     
    fin>>n;
    for(int i = 0; i < n; ++i) fin>>item, vec.pb(item);

    Container container( vec );
    container.sorted();
    container.print();

    return(0); 
};