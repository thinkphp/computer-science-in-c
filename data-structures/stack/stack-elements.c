#include <stdio.h>
#include <malloc.h>

typedef struct elem{
  char name[50];
  int code;
} Element;

typedef struct node{
  Element elem;
  struct node*next;
} Stack;

void push(Stack**head, Element el){
    Stack *q = (Stack*)malloc(sizeof(Stack));
    q->elem = el;
    q->next = *head;
    *head = q;
}

void pop(Stack**head){
     Stack*q = *head;
     if(isEmpty(*head)) return;
     *head = (*head)->next;
     free(q);
}

Element top(Stack**head) {
  Stack*q = *head;
  Element el = (*head)->elem;
  *head = (*head)->next;
  free(q);
  return el;
}

int isEmpty(Stack*head) {
    if(head == NULL) return 1;
    else
    return 0;
}

void create(Stack**head) {
    Stack*q;
    Element e;
    *head = NULL;
    int n, i;
    printf("%s", "How many elements do you want N = ");
    scanf("%d", &n);
    for(i = 0; i < n; ++i) {
      q = (Stack*)malloc(sizeof(Stack));
      printf("Element#%d:\n", i + 1);
      printf("%s:", "Name=");
      //scanf("%s",q->elem.name);
      printf("%s:", "Code=");
      //scanf("%d",&q->elem.code);
      scanf("%s %d",e.name, &e.code);
      q->elem = e;
      q->next = *head;
      *head = q;
    }
}

void write(Stack*head) {
  while(head) {
    printf("(%s, %d)\n", head->elem.name, head->elem.code);
    head = head->next;
  }
}

void strcp(char str1[50],char str2[]) {
     int i = 0;
     while(str2[i]!='\0'){
       str1[i] = str2[i];
       i++;
     }
     str1[i] = '\0';
}

int main(int argc, char const *argv[]) {
  Stack*head;
  create(&head);
  write(head);
  Element el = top(&head);
  printf("(%s,%d)\n", el.name, el.code);
  strcp(el.name,"adrian");
  el.code = 1234;
  push(&head,el);
  write(head);
  return 0;
}
