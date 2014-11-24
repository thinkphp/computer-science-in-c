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

         swapped;

     do {

        swapped = 0; 

        for(i = start; i < end - 1; i++) {

            if(arr[ i ] > arr[ i + 1]) {

               swap(i, i + 1);
 
               swapped = 1; 
            } 
        } 

        if( !swapped ) break;

        end--;

        swapped = 0;         

        for(j = end - 1; j >= start; j--) {

            if(arr[ j ] > arr[ j + 1]) {

               swap(j, j + 1);
 
               swapped = 1; 
            }       
        }

        start++; 

     } while( swapped );
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

     scanf("%d", &n); 
 
     for(i = 0; i < n; i++) printf("%d ", arr[ i ]);

     fclose( stdout );
};

