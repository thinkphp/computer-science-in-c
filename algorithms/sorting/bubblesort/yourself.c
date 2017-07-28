#include<stdio.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define SIZE 500005

int arr[ SIZE ],
    n;

void read() {
     int i;
     freopen(FIN, "r", stdin);
     scanf("%d", &n);
     for(i = 0; i < n; ++i) scanf("%d", &arr[i]);
};

void _swap(int i, int j) {

     int sxor = arr[i]^arr[j];

         arr[i] = sxor^arr[i];

         arr[j] = sxor^arr[j];
};

void bubblesort() {

     int i, 
         finished = 0, 
         changed, 
         last = n;

     while(!finished) {

            changed = 0;

            for(i = 0; i < last - 1; ++i) {

                if(arr[ i ] > arr[ i + 1]) {

                   _swap(i, i + 1);

                   changed = 1;
                }
            }    

            if( changed ) last--;

                else 

                    finished = 1;
     };
};


void write() {

     int i;

     freopen(FOUT, "w", stdout);

     for(i = 0; i < n; ++i) printf("%d ", arr[i]);

};

int main() {

 read();
 bubblesort();
 write();

 return(0);
};