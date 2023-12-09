#include <iostream>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define MAX 500005

using namespace std;

class Quicksort {

      public:
      //constructorul clasei fara parametri
      Quicksort() {

        cout<<"Apelare constructor clasa si citire din data din FILE"<<endl;
        read_data();
      }

      void solve() {
            cout<<"Algoritmul Quick Sort in Action!";
            cout<<"Output: algsort.out";
            //face call la o metoda privata
            _quicksort(0, n - 1);
      }

      void read_data() {

          //pentru scriere freopen("numefiser", "w", stdout)
          //fclose( stdout );
          //pentru citire din fisier freopen("numefisier", "r", stdin);
          //fclose( stdin );
          //citim din fisier
          freopen(FIN, "r", stdin);

          scanf("%d", &n);

          for(int i = 0; i < n; i++) {

              scanf("%d", &vec[i]);
          }

          fclose( stdin );
      }

      void print() {
          freopen(FOUT, "w", stdout);
          for(int i = 0; i < n; ++i) {
            cout<<vec[i]<<" ";
          }
          fclose(stdout);
      }

      private:
        int n,
            vec[MAX];

        void _quicksort(int low, int high) {

            int i, j,
                PIVOT;
            i = low;
            j = high;

            //pivot
            PIVOT = vec[(low + high) >> 1];

            while( i <= j ) {

               while(vec[i]<PIVOT) {
                 i++;
               }

               while(vec[j]>PIVOT) {
                 j--;
               }
               //interschimbare (i,j)
               if(i <= j ) {
                 int temp = vec[i];
                     vec[i] = vec[j];
                     vec[j] = temp;
                 i++;
                 j--;
               }
            }

            if( low < j ) _quicksort(low, j);
            if( i < high ) _quicksort(i, high);
        }

};


int main(int argc, char const *argv[]) {

  //am creat un obiect de tip Quicksort
  Quicksort q;

  q.solve();
  q.print();

  return 0;
}
