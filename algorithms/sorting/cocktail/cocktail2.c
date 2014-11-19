#include <stdio.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define MAXN 500005

int arr[ MAXN ],
    n;

//functions prototype
void read();
void cocktail();
void write();
void swap(int,int);

int main() {

    read();

    cocktail();

    write();

  return(0);
};

void read() {

     int i;

     freopen(FIN, "r", stdin);

     scanf("%d", &n); 
 
     for(i = 0; i < n; i++) scanf("%d", &arr[ i ]);

     fclose( stdin );
};

void cocktail() {

     int i,

         j,

         start = 0,

         end = n,

         swapped = 0;

     while(start < end) {

           for(i = start + 1; i < end; i++) {

               if(arr[ i ] < arr[ i - 1 ]) {

                   swap(i, i - 1);

                   swapped = i;   
               }
           }            

           end = swapped;

           for(i = end - 1; i >= start; i--) {

               if(arr[ i + 1] < arr[ i ]) {

                   swap(i, i + 1);

                   swapped = i;   
               }
           }                   

           start = swapped;    
     } 
     
};

void swap(a, b) {

     int aux;

         aux = arr[ a ]; 

         arr[ a ] = arr[ b ];

         arr[ b ] = aux; 
}

void write() {

     int i;

     freopen(FOUT, "w", stdout);
 
     for(i = 0; i < n; i++) printf("%d ", arr[ i ]);

     fclose( stdout );
};

