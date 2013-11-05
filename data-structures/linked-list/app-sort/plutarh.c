#include <stdio.h>
#include <malloc.h>
#include <string.h>

int n;

struct Node {

       char   firstname[30];
       char   secondname[30];
       int    age;
       char   type[20];
       int    salary;
       float  mark;
       struct Node *next;
};

struct Node *head;

void read(const char *);
void display();
void write(const char *);
struct Node* swapp(struct Node*,struct Node*);
void bubblesort();

FILE *fin, *fout;

int main() {
 
     read("c:\\data.in");

     display(); 

     bubblesort();

     printf("\n\n%s\n\n", "Sorted Persons by mark ->");

     display(); 

     write("c:\\data.out");

     return(0); 
}

void read(const char *filename) {

     int i;
 
     char firstname[30];
     char secondname[30];
     int age;
     char type[20];
     int salary;
     float mark;

     struct Node *new;

     fin = fopen(filename, "r");

     fscanf(fin, "%d", &n);

     for(i=1;i<=n;i++) {

         fscanf(fin,"%s\t%s\t%d\t%s\t%d\t%f\n", &firstname, &secondname, &age, &type, &salary, &mark);

         new = (struct Node*)malloc(sizeof(struct Node));

         strcpy(new->firstname,firstname);
         strcpy(new->secondname,secondname);
         new->age = age;
         strcpy(new->type,type);          
         new->salary = salary;
         new->mark = mark;

         new->next = head;
         head = new;
     }

     fclose( fin );
}

void write(const char *filename) {

     struct Node *c;

     fout = fopen(filename, "w");

     c = head;

     fprintf(fout,"Sorted by Mark\n");
     fprintf(fout,"----------------\n");

     while(c) {

           fprintf(fout,"%s %s %d %s %d %f\n",c->firstname, c->secondname, c->age, c->type, c->salary, c->mark);

           c = c->next;
     }

     fclose( fout );
}

void display() {

     struct Node *c;

     c = head;

     while(c) {

           printf("%s %s %d %s %d %f\n",c->firstname, c->secondname, c->age, c->type, c->salary, c->mark);

           c = c->next;
     }
}

void bubblesort() {

     struct Node *top, *p, *q;

     top = (struct Node*)malloc(sizeof(struct Node));
     
     top->next = head;

     int swapped = 1;

     do {

        swapped = 0;

        q = top;

        p = top->next;

        while(p->next) {

              //I want to sort by mark or salary, whatever you want.
              if(p->mark < p->next->mark) {
                 
                 q->next = swapp(p, p->next); 
                 swapped = 1;
              } 

              q = p;

              if(p->next) p = p->next;
        }

        head = top->next;

     }while( swapped );
}

struct Node* swapp(struct Node* node1,struct Node* node2) {

       node1->next = node2->next;
       node2->next = node1;

    return node2;  
}