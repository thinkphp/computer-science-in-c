#include <stdio.h>
#include <malloc.h>
#include <string.h>

//number of the persons
int n;

//struct Element
struct Node {
       char  name[20];
       float mark;
       struct Node *next;       
};

//head is null firstly
struct Node *head = NULL;

//input output File
FILE *fin, *fout;

//prototypes
void readFromFile(const char *filename);
void write(const char *filename);
void display();
void bubblesort();
struct Node* swapp(struct Node*,struct Node*);

//main function that send SUCCESS to the OS
int main() {

     //read the data from file.in onto linked list
     readFromFile("c:\\mark.in"); 

     //display the data
     display();

     //bubble sort in action
     bubblesort();

     //display a message sorted
     printf("%s\n","Sorted:");

     //display the sorted linked list
     display();

     //write the sorted linked list to the file.iut
     write("c:\\mark.out");

     //return SUCCESS
     return (0);
};


void display() {

      struct Node *p;

      p = head;

      while( p ) {

           printf("%s %lf", p->name, p->mark);

           printf("\n");

           p = p->next;
      }
}

void readFromFile(const char *filename) {

     int i;
     char name[20];
     float mark;

     struct Node *p;

     fin = fopen(filename, "r");

     fscanf(fin,"%d", &n);

     for(i = 1; i <= n; i++) {

           fscanf(fin,"%s %f\n",&name, &mark);

           p = (struct Node*) malloc(sizeof(struct Node));

           strcpy(p->name, name);

           p->mark = mark;

           p->next = head;

           head = p;
     }

     fclose(fin);
}


void write(const char *filename) {

      struct Node *p;

      fout = fopen("file.out","w");

      int counter = 0;

      p = head; 

      while( p ) {

           fprintf(fout,"%d. %s %1f", ++counter, p->name, p->mark);

           fprintf(fout, "\n");

           p = p->next;           
      }

      fclose(fout);
}


void bubblesort() {
 
     struct Node *p, *q, *top;

     top = ( struct Node* ) malloc( sizeof( struct Node ) );

     top->next = head;

     int swapped = 1;

     do {

        swapped = 0;

        q = top;

        p = top->next;

        while( p->next ) {

             if( p->mark < p->next->mark ) {

                 q->next = swapp(p, p->next);
 
                swapped = 1;
             }

          q = p;

          if( p->next ) p = p->next;
               
        }

     } while( swapped );

     head = top->next;

     free(top);
}

struct Node* swapp(struct Node *node1,struct Node *node2) {

     node1->next = node2->next;

     node2->next = node1; 

    return node2;
}
