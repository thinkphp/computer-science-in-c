#include <stdio.h>
#include <stdbool.h>

void shuffle(int vec[], int n) {

    int i, 
        r, 
        temp;

    for(i = 0; i < n; ++i) {

        srand(time(NULL));
        r = rand() % (i+1);

        temp = vec[ i ];
        vec[ i ] = vec[ r ];
        vec[ r ] = temp;        
    }

};

bool isSorted(int vec[], int n) {

     int i;

     for(i = 1; i < n; ++i) {

         if(vec[i] < vec[i-1]) return false;
     }

     return true;
};

void bogoSort(int vec[], int n) {

    while(!isSorted(vec, n)) {

         shuffle(vec, n);
    }  

};


void bubbleSort(int vec[], int n) {

     int i,
         finished = 0, 
         swapped;
      
     while(!finished) {
            swapped = 0;
            for(i = 0; i < n-1; ++i) {
                if(vec[i]>vec[i+1]) {
                   int temp = vec[i];
                       vec[i] = vec[i+1];
                       vec[i+1] = temp;
                       swapped = 1;    
                }
            }
            if(swapped) n--;
                else    finished = 1; 
     } 
};

int main(int argc, int *argv[]) {

 if(argc < 2) {
    printf("Error: Must provide one argument!");
    exit(1); 
 } 

 int i, vec[ argc - 1 ];

     for(i = 1; i < argc; ++i) {

         vec[ i - 1 ] = atoi(argv[ i ]);
     }
 
     //bubblesort(vec, argc-1); 
     bogoSort(vec, argc - 1);  

     printf("Done Sorting...\nOutput is: "); 

     for(i = 0; i < argc - 1; ++i) { 
    
         printf("%d ", vec[ i ]);
     }

 return(0);
};