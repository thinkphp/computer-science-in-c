#include <stdio.h>
#include <malloc.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define SIZE 500001

typedef struct node {
        int info;
        struct Node *next;
} Node;

Node *base, 
     *curr, 
     *p, 
     *p1;

const int MAXINT = 2147483647;

int main( void ) {

    int n, i, vec[SIZE];

    freopen(FIN, "r", stdin);
    freopen(FOUT, "w", stdout);

    scanf("%d", &n);

    for(i = 0; i < n; ++i) scanf("%d", &vec[i]);

    base = (Node*)malloc(sizeof(Node));
    base->info = MAXINT;
    base->next = NULL; 

    for(i = 0; i < n; ++i) {

        curr = (Node*)malloc(sizeof(Node));

        curr->info = vec[ i ];

        if(curr->info < base->info) {

           curr->next = base;

           base = curr;
  
        } else {

           p = base;

           p1 = p->next;

           while(p1 != NULL && p1->info < curr->info) {

                 p = p->next;  

                 p1 = p1->next;
           } 

           p->next = curr;
           curr->next= p1; 
        }

    }

    p = base;

    while(p->info != MAXINT) {

          printf("%d ", p->info); 

          p = p->next; 
    } 


 return(0);  
};