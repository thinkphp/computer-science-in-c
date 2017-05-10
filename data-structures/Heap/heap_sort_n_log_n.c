#include <stdio.h>
#define size 100
#define FIN "heap.in"
#define FOUT "heap.out"
#define SIZE 500005

int arr[SIZE],

    n; 

void create_heap() {

     int i, j;

     for(i = 2; i <= n; i++) {

         j = i;

         while(j > 1) {

               if(arr[ j ] <= arr[ j / 2 ])  {

                  int aux = arr[j]; arr[j] = arr[j/2]; arr[j/2] = aux;

                  j /= 2;

               } else j = 1;//or break
         }
     }
};

int eliminate() {

    int i, 

        j, 

        x = arr[ 1 ];

        arr[ 1 ] = arr[ n ]; 

    n--;

    i = 1;

    while(i <= n) {

          if( 2 * i <= n ) {

              j = 2 * i;

              if(j + 1 <= n && arr[j + 1] <= arr[ j ]) j++;

              if(arr[ i ] >= arr[ j ]) {

                     int aux = arr[i]; arr[i] = arr[j]; arr[j] = aux; 

                     i = j;

              } else break;

          } else break;
    }
   
    return x;     
};

void print() {

     int i;

     for(i = 1; i <= n; i++) printf("%d ",arr[i]);

     printf("\n");
};

int main() {

        int i,

            it,

            len; 

        freopen(FIN, "r", stdin); 

        freopen(FOUT, "w", stdout); 
    
        scanf("%d",&n); 

        len = n;
 
        for(i = 1; i <= n; i++) scanf("%d", &arr[i]);
        
        create_heap();

        for(it = 1; it <= len; it++ ) {

            printf("%d ", eliminate());
        }

        print();

  return(0);
};
