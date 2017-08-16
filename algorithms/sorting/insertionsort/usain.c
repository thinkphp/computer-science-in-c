#include <stdio.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define SIZE 500005

int arr[ SIZE ],
    n;

void read();
void write();
void sort();

int main() {
 
    read();
    sort();
    write();

    return(0);  
};


void read() {

     int i;

     freopen(FIN, "r", stdin);

     scanf("%d", &n);

     for(i = 0; i < n; i++) scanf("%d", &arr[i]);
};

void write() {

     int i;

     freopen(FOUT, "w", stdout);

     for(i = 0; i < n; i++) printf("%d ", arr[i]);
};

void sort() {

     int i,j,aux;

     for(i = 1; i < n; i++) {

         if(arr[i] > arr[i-1]) continue; 

         aux = arr[ i ];

         j = i - 1;

         while(j >= 0 && arr[j] > aux) {

               arr[j + 1] = arr[j--];
         }
   
         arr[j+1] = aux;  
     }
};