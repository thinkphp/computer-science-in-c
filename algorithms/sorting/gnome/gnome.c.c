#include <stdio.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define SIZE 500005

int arr[SIZE],
    n;

void read() {
     int i;
     freopen(FIN, "r", stdin);
     scanf("%d", &n);
     for(i = 0; i < n; ++i) scanf("%d", &arr[i]);
};

void gnome() {

     int pos = 0;

     while(pos < n) {
           if(pos == 0 || arr[pos] >= arr[pos-1]) pos++;
                       else {
                            int tmp = arr[pos];
                                arr[pos] = arr[pos-1];
                                arr[pos-1] = tmp;
                                pos--;   
                       }
     } 
};

void write() {
     int i;
     freopen(FOUT, "w", stdout);
     for(i = 0; i < n; ++i) printf("%d ", arr[i]);
};

int main() {
    read();
    gnome();
    write(); 
    return(0);
};