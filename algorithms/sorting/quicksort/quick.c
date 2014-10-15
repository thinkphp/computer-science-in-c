#include <stdio.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define MAXN 500005

int n, 
    arr[ MAXN ];

FILE *fin,
     *fout;

//function prototype;
void read();
void write();
void quicksort(int,int);

int main() {

    read();

    quicksort(0, n - 1);

    write();

   return(0); 
};

void read() {

     int i;
 
     fin = fopen(FIN, "r");

     fscanf(fin, "%d", &n);

     for(i = 0; i < n; i++) {

         fscanf(fin, "%d", &arr[ i ]);
     }
      
     fclose( fin ); 
}

void write() {

     int i;

     fout = fopen(FOUT, "w");

     for(i = 0; i < n; i++) {

         fprintf(fout, "%d ", arr[ i ]);
     }

     fclose( fout ); 
}

void quicksort(int li, int ls) {

     int i,
         j,
         x,p;

     i = li;
     j = ls;

     p = arr[ (li + ls) >> 1 ];


     while(i <= j) {

           while( arr[ i ] < p) {

                  i++;
           } 

           while( arr[ j ] > p) {

                  j--;
           } 

           if( i <= j ) {

               x = arr[ i ] ^ arr[ j ]; arr[ i ] = x ^ arr[ i ]; arr[ j ] = x ^ arr[ j ];

               i++; j--;  
           }
     }

     if(i < ls) quicksort(i, ls);

     if(li < j) quicksort(li, j);

}
