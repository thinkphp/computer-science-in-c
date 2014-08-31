#include <stdio.h>
#include <malloc.h>
#include <string.h>

const long bigNum = 99999;

struct Node {
       char  name[20];
       float mark;
       struct Node *next;       
};

struct Node arr[100], 

       *c,

       *c1,

       *head,

       *p;

//for file input output
FILE *fin, *fout;

//number of the persons
int n;

//prototypes
void readFromFile(const char *filename);
void display();
void display2();
void sort();
void writeToFile(const char *filename);

int main() {

     readFromFile("c:\\persons.in"); 

     display();

     printf("Sorted:\n");

     sort();

     display2();

     writeToFile("c:\\persons.out");

     return (0);
};


void display() {

     int i;

     for(i = 0; i < n; i++) {

         printf("%s %f\n",arr[i].name, arr[i].mark);
     }

}

void display2() {

     c = head;

     while(c && c->mark != bigNum) {

           printf("%s %f\n",c->name, c->mark);
           c = c->next;
     }

}

void readFromFile(const char *filename) {

     int i;       
     char name[20];
     float mark;

     fin = fopen(filename, "r");

     fscanf(fin,"%d",&n);

     for(i = 0; i < n; i++) {

           fscanf(fin,"%s %f\n",&name, &mark);

           strcpy(arr[i].name, name);

           arr[i].mark = mark;
     }    


     fclose(fin);
}

void sort() {

     int i;

     head = (struct Node*) malloc(sizeof(struct Node));
     head->mark = bigNum;
     head->next = NULL;

     for(i = 0; i < n; i++) {

         p = (struct Node*) malloc(sizeof(struct Node));
         p->mark = arr[i].mark;
         strcpy(p->name, arr[i].name);

         //if is the first then insert onto head
         if(p->mark < head->mark) {

            p->next = head;
            head = p;    

         //otherwise is between elements
         } else {

           c = head;
           c1 = head->next;  
         
           while(p->mark > c1->mark) {

                 c = c->next;

                 c1 = c1->next;
           }   

           c->next = p;

           p->next = c1;

         }                            
     }
}

//write the output
void writeToFile(const char *filename) {

     fout = fopen(filename, "w");

     c = head;

     while(c && c->mark != bigNum) {

           fprintf(fout,"%s %f\n", c->name, c->mark);
           c = c->next;
     }

     fclose(fout);

}