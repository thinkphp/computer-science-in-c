#include <stdio.h>
#define size 100

int arr[] = {0,1,82,70,3,5,94,23,2,11}, 

    n; 

void create_heap() {

     int i, j;

     for(i = 2; i <= n; i++) {

         j = i;

         while(j > 1) {

               if(arr[ j ] >= arr[ j / 2 ])  {

                  int aux = arr[j]; arr[j] = arr[j/2]; arr[j/2] = aux;

                  j /= 2;

               } else j = 1;//or break
         }
     }
};

int eliminate() {

    int i, 

        j, 

        x = arr[1];

        arr[ 1 ] = arr[ n ]; 

    n--;

    i = 1;

    while(i <= n) {

          if( 2 * i <= n ) {

              j = 2 * i;

              if(j + 1 <= n && arr[j + 1] >= arr[ j ]) j++;

              if(arr[ i ] <= arr[ j ]) {

                     int aux = arr[i]; arr[i] = arr[j]; arr[j] = aux; 

                     i = j;

              } else break;

          } else break;
    }
   
    return x;     
};

void add_to_heap() {

     int i,item;//add to heap

     printf("What to add -> ");
     scanf("%d", &item);  

     n++;//increase the length of the heap

     arr[ n ] = item; //the last item is this

     i = n;  

     while( i > 1) {

           if(arr[i] >= arr[i/2]) {

              int aux = arr[i];

                  arr[i] = arr[i/2]; 

                  arr[i/2] = aux;

                  i/=2;

           } else break;
     }
};

void print() {

     int i;

     for(i = 1; i <= n; i++) printf("%d ",arr[i]);

     printf("\n");
};

int main() {
    
        n = sizeof(arr)/sizeof(arr[0]);
        
        create_heap();

        print();

        int x; 

        x = eliminate();

        printf("%d\n", x);

        print();

        x = eliminate();

        printf("%d\n", x);

        print();

        add_to_heap();

        print();
  return(0);
};