#include <stdio.h>
#include <malloc.h>
#define FIN "submultimi.in"
#define FOUT "submultimi.out"


typedef struct node {
    int info;
    struct node *next;
} Stack;

void push(Stack**head, int value){
     Stack*q=(Stack*)malloc(sizeof(Stack));
     q->info = value;
     q->next = *head;
     *head = q;
}

int isEmpty(Stack*head) {
  if(head==NULL) return 1;
  return 0;
}

void pop(Stack**head) {
     Stack*q;
     q = *head;
     if(isEmpty(*head)) return;
     (*head) = (*head)->next;
     free(q);
}


int top(Stack**head){
    if(!isEmpty(*head))
    return (*head)->info;
    return -1;
}

void topPlusPlus(Stack**head) {

     (*head)->info = (*head)->info + 1;
}

void write(Stack*head) {

     while(head){
       printf("%d ", head->info);
       head = head->next;
     }
}

int main(int argc, char const *argv[]) {

  Stack*head=NULL;
  int n;

  freopen(FIN, "r",stdin);
  freopen(FOUT,"w",stdout);

  scanf("%d",&n);
  push(&head,1);
  while(!isEmpty(head)) {
        write(head);
        printf("\n");
        if(top(&head) < n) push(&head,top(&head)+1);
        else {
             pop(&head);
             if(!isEmpty(head)) topPlusPlus(&head);
        }
  }
  return 0;
}
