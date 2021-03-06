#include <stdio.h>
#define FIN "activity2.in"
#define FOUT "activity.out"

#define SIZE 100

typedef struct activity {

        int start,
            end,
            key;

} activity;

activity spectacle[ SIZE ];

int number_of_spectacles;

int sol[SIZE],

    countSol;

void sort();
void greedy();

int main() {

    int it;

    freopen(FIN,"r",stdin); 

    scanf("%d", &number_of_spectacles);

    for(it = 1; it <= number_of_spectacles; it++) {

        scanf("%d %d",&spectacle[it].start, &spectacle[it].end);  

        spectacle[it].key = it;
    }

    for(it = 1; it <= number_of_spectacles; it++) {

        printf("%d ", spectacle[it].key); 
    }

    printf("\n");

    for(it = 1; it <= number_of_spectacles; it++) {

        printf("%d ", spectacle[it].start); 
    }

    printf("\n");

    for(it = 1; it <= number_of_spectacles; it++) {

        printf("%d ", spectacle[it].end); 
    }

    //sorting
    sort();  

    printf("\n---------------------------------\n");

    for(it = 1; it <= number_of_spectacles; it++) {

        printf("%d ", spectacle[it].key); 
    }

    printf("\n");

    for(it = 1; it <= number_of_spectacles; it++) {

        printf("%d ", spectacle[it].start); 
    }

    printf("\n");

    for(it = 1; it <= number_of_spectacles; it++) {

        printf("%d ", spectacle[it].end); 
    }

    printf("\n---------------------------------\n");

    greedy();


    for(it = 1; it <= countSol; it++) {

        printf("%d ", spectacle[sol[it]].key); 
    }

    printf("\n");

    for(it = 1; it <= countSol; it++) {

        printf("%d ", spectacle[sol[it]].start); 
    }

    printf("\n");

    for(it = 1; it <= countSol; it++) {

        printf("%d ", spectacle[sol[it]].end); 
    }


    printf("\n---------------------------------");
    printf("\nMax sol -> %d", countSol);    
    printf("\n---------------------------------\n");
};

void sort() {

     activity temp;

     int i, swapped = 1;

     while(swapped) {

           swapped = 0;

           for(i = 1; i < number_of_spectacles; i++) {

                   if(spectacle[i].end > spectacle[i+1].end) {

                       temp = spectacle[i];

                       spectacle[i] = spectacle[i+1];

                       spectacle[i+1] = temp;

                       swapped = 1;  
                   } 
           }  
     }
     
};

void greedy() {

     int i, j = 1;

     sol[ j ] = 1; 

     for(i = 2; i <= number_of_spectacles;i++) {

             if(spectacle[i].start >= spectacle[sol[j]].end) {

                    j++;
                    sol[j] = i;
             }

        countSol = j; 
     }
       
};