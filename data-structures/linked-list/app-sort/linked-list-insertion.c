#include <stdio.h>
#include <malloc.h>
#include <string.h>

const int bigMark = 9999;

//number of persons
int n;

//file I/O
FILE *fin, *fout;

//struct Node
struct Node {
       char   firstname[30];
       char   secondname[30];
       int    age;
       char   type[20];
       int    salary;
       float  mark;
       struct Node *next;
};

//get a pointer from Node
struct Node *head;

//function prototypes
void readAndSortByInsertion(const char *);
void write(const char *);


//main function
int main() {

    readAndSortByInsertion("c:\\students.in");
    write("c:\\students.out");

    return (0);
};

void readAndSortByInsertion(const char *filename) {

     struct Node *p,*c,*p1,*p2;
     int i;

     char   firstname[30];
     char   secondname[30];
     int    age;
     char   type[20];
     int    salary;
     float  mark;


     p = (struct Node*)malloc(sizeof(struct Node));
     p->mark = bigMark;
     p->next = NULL;
     head = p;

     fin = fopen(filename, "r");
   
     fscanf(fin,"%d",&n);

     for(i = 1; i <= n; i++) {

         fscanf(fin,"%s",&firstname);  
         fscanf(fin,"%s",&secondname);  
         fscanf(fin,"%d",&age);  
         fscanf(fin,"%s",&type);  
         fscanf(fin,"%d",&salary);  
         fscanf(fin,"%f",&mark);

            c = (struct Node*)malloc(sizeof(struct Node));
            strcpy(c->firstname, firstname);
            strcpy(c->secondname, secondname);
            c->age = age;
            strcpy(c->type, type);    
            c->salary = salary;
            c->mark = mark;
         
         if(mark < head->mark) {

            c->next = head;
            head = c;
 
         } else {
 
           p1 = head;
           p2 = head->next; 
            
           while(mark > p2->mark) {
                 p1 = p2;
                 p2 = p2->next;
           } 

           
           p1->next = c;
           c->next = p2;
 
         }                  
     }

     fclose( fin );
};

void write(const char *filename) {

     fout = fopen(filename, "w");

     struct Node *c = head;

     int count = 1;

     while( c && c->mark != bigMark) {

            printf("%d. %s %s %d %s %d %f\n", count, c->firstname, c->secondname, c->age, c->type, c->salary, c->mark);

            fprintf(fout, "%d. %s %s %d %s %d %f\n", count++, c->firstname, c->secondname, c->age, c->type, c->salary, c->mark);

            c = c->next;
     }

     fclose(fout);
};
