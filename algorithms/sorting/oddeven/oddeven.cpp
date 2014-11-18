/**
 *  Odd-Even Sort Algorithm for 40 points.
 */
#include <cstdio>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define MAXN 500001

class Sort {

     public:  

     int arr[ MAXN ],

         n;

     Sort() {

     }
  
     void read() {

          int i;

          freopen(FIN, "r", stdin);

          scanf("%d", &n);

          for(i = 0; i < n; i++) scanf("%d", &arr[ i ]); 
 
          fclose( stdin );
     };

     void write() {
 
          int i;

          freopen(FOUT, "w", stdout);

          for(i = 0; i < n; i++) printf("%d ", arr[ i ]);       

          fclose( stdout );
     };

     void oddeven() {

          int swap = 0, 
              i;

          while( !swap ) {

             swap = 1;

             for(i = 0; i < n - 1; i+=2) {

                 if(arr[ i ] > arr[i + 1]) {

                    swapped(i, i + 1);
                    swap = 0; 
                 }
             } 

             for(i = 1; i < n - 1; i+=2) {

                 if(arr[ i ] > arr[i + 1]) {

                    swapped(i, i + 1);

                    swap = 0; 
                 }
             }        
         }
     }

     private: 

     void swapped(int a,int b) {

          int aux;  
                    aux = arr[ a ];             

                    arr[ a ] = arr[ b ];             

                    arr[ b ] = aux;
     }
};


int main() {

    Sort ob;

    ob.read();
    ob.oddeven();
    ob.write();

    return(0);
}