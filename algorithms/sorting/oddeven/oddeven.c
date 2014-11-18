#include <stdio.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define MAXN 500001
 
int arr[ MAXN ],
 
    n;
 
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

         aux,

         i;
 
     while( !swap ) {
 
             swap = 1;
 
             for(i = 0; i < n - 1; i+=2) {
 
                 if(arr[ i ] > arr[i + 1]) {
 
                    aux = arr[ i ];            

                    arr[ i ] = arr[ i + 1 ];            

                    arr[i + 1] = aux;

                    swap = 0;
                 }
             }
 
             for(i = 1; i < n - 1; i+=2) {
 
                 if(arr[ i ] > arr[i + 1]) {
 
                    aux = arr[ i ];            

                    arr[ i ] = arr[ i + 1 ];            

                    arr[i + 1] = aux;

                    swap = 0;
                 }
             }
     } 
};
 
int main() {
 
    read();

    oddeven();

    write();
 
    return(0);
}