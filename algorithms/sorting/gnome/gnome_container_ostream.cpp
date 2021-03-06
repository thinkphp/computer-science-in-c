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

      void gnome() {

           int pos = 0;
           while(pos < n) {
                 if(pos == 0 || vec[pos] >= vec[pos-1]) pos++;
                    else _swap(pos, pos-1), pos--; 
           }
      };

      void sorted() {
           gnome();
      };
       
      friend ostream &operator<<(ostream &stream, const Container obj) {

           vector<int> vec = obj.vec;

           for(vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) stream<<*it<<" "; 
      };
  
      private:
      vector<int> vec;
      int n;  

      void _swap(int a, int b) {
            int tmp = vec[a];
                vec[a] = vec[b];
                vec[b] = tmp;  
      }
};

int main() {
  int n, elem;
  vector<int> arr;
  ifstream fin(FIN);
  ofstream fout(FOUT);

  fin>>n;    
  for(int i = 0; i < n; ++i) fin>>elem, arr.pb(elem);
  Container container(arr);
  container.sorted(); 
  fout<<container;
  
  return(0);  
};