#include <stdio.h>
#include <malloc.h>
 
const long bigNum = 99999;
 
struct Node {
       int info;
       struct Node *next; 
} Node;
 
struct Node *c,*c1,*head,*p;
 
int main() {
 
    int i,n;
 
    printf("n=");
    scanf("%d",&n); 
 
    head = (struct Node*) malloc(sizeof(struct Node));
 
    head->info = bigNum;
 
    head->next = NULL;
 
    for(i=1;i<=n;i++) {
 
        printf("Node=");
 
        p = (struct Node*)malloc(sizeof(struct Node));
 
        scanf("%d",&p->info);
 
        if(p->info < head->info) {
 
           p->next = head;
 
           head = p; 
 
        }  else {
 
           c = head;
           c1 = head->next;
 
           while(p->info > c1->info) {
 
                 c = c->next;
                 c1 = c1->next;
           }
 
           c->next = p;
           p->next = c1;
        }
 
    }//endfor
 
    c = head;
 
    while(c && c->info != bigNum) {
 
          printf("%d ",c->info);
 
          c = c->next;
    }
 
    return (0); 
}
