#include <stdio.h>
#include <malloc.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"

void read();
void sort();
void _mergesort(int,int);
void write();

int *arr,
     size; 

int main() {

    read();

    sort();

    write();

    return(0);
};


void read() {

     int i;

     freopen(FIN, "r", stdin);

     scanf("%d", &size);

     arr = (int*)malloc(sizeof(int) * size);

     for(i = 0; i < size; i++) scanf("%d", arr + i); 

     fclose( stdin ); 
};

void sort(){

     _mergesort(0, size - 1);
}

void _mergesort(int left,int right){

     if(right > left) {

        int middle = (left + right) >> 1;

        _mergesort(left, middle);

        _mergesort(middle + 1, right);

        int i,

            j,

            k,

            *temp;

            temp = (int*)malloc( sizeof(int) * (right - left + 1) );

            for(i = left; i <= right; i++) temp[ i - left ] = arr[ i ];

            for( i = k = left, j = middle + 1; i <= middle && j <= right; k++ ) 
 
              if(temp[ i - left ] < temp[ j - left ]) arr[ k ] = temp[ i++ - left ];
 
                                                 else
 
                                                       arr[ k ] = temp[ j++ - left ];
          while( i <= middle )
 
            arr[ k++ ] = temp[ i++ - left ];       
           
 
          while( j <= right )
 
            arr[ k++ ] = temp[ j++ - left ];
 
          free( temp ); 
     } 
};

void write() {

     int i;

     freopen(FOUT, "w", stdout);

     for(i = 0; i < size; i++) printf("%d ", *(arr + i)); 

     free( arr );  

     fclose( stdout ); 
};
