#include <stdio.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define SIZE 500005

int arr[ SIZE ],
    n;

//9 8 7 6 5 4 3 2 1

void read();
void shell();
void write();

int main() {

 read();
 shell();
 write(); 

 return(0);
};

void read(){

     int i;
  
     freopen(FIN, "r", stdin);

     scanf("%d", &n);

     for(i = 0; i < n; i++) scanf("%d", &arr[ i ]); 
};

void shell(){

     int i, j, k, d, aux, dist, gap = n;
  
     for(d = gap/2; d > 0; d/=2) {

         dist =  d ;

         for(i = dist; i < n; i++) {
           
             aux = arr[ i ];

             for(j = i - dist; j >= 0 && arr[ j ] > aux; j -= dist) {

                 arr[ j  + dist ] = arr[ j ];
             }  

                 arr[ j  + dist ] = aux;           
         } 
           
     }
      
};

void write(){

     int i;
  
     freopen(FOUT, "w", stdout);

     for(i = 0; i < n; i++) printf("%d ", arr[ i ]); 
};

