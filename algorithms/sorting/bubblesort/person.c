#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct {
        char name[30]; 
        float mark;
} Element, *pElement;

Element arr[100];

FILE *fin, *fout;

void read(const char *filename);
void display();
void writeToFile(const char *filename);
void bubblesort();
void swapp();


//number of person
int n;

int main() {

    read("c:\\person.in"); 

    printf("Read Data:\n");
    display();

    bubblesort();

    printf("\n\nSorted Person after mark:\n\n");

    display();

    writeToFile("c:\\person.out");
    
    return (0); 
}

void read(const char *filename) {

     float mark;
     char name[20];     
       
     fin = fopen(filename, "r");
 
     fscanf(fin, "%d", &n);

     int i;

     i = 0;

     while(!feof(fin)) {

            fscanf(fin, "%s\t", &name);
            strcpy(arr[i].name, name);  

            fscanf(fin, "%f", &mark);
            arr[i].mark = mark;

            fscanf(fin,"\n");      
            i++;
     }     

     fclose(fin);
}


void display() {

     int i;

     for(i = 0; i < n; i++) {

         printf("%s %f\n", arr[i].name, arr[i].mark); 
     } 
}

void writeToFile(const char *filename) {

     int i, counter = 0;

     fout = fopen(filename, "w");

     for(i = 0; i < n; i++) {

         fprintf(fout, "%d. %s %f\n", ++counter, arr[i].name, arr[i].mark); 
     } 
 
     fclose(fout);
}

void bubblesort() {

     int i, j, swapped;

     for(i = 0; i <= n - 1 && swapped;i++) {

         swapped = 0;

         for(j = n - 1; j > i; j--) {

             if(arr[j].mark < arr[j-1].mark) {

                swapp(&arr[j], &arr[j-1]);  

                swapped = 1;
             }  
         }          
     }
}

void swapp(pElement px, pElement py) {

     Element temp;

     temp = *px;
     *px = *py;
     *py = temp; 
}
