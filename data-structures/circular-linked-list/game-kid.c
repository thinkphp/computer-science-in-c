#include <bits/stdc++.h>
typedef struct Node {
    char name[50];
    struct Node *next;
} Node;

void create(Node**head) {
    Node *p,*q;
    int n;
    printf("%s","Number of children=");
    scanf("%d",&n);
     *head = (Node*)malloc(sizeof(Node));
     printf("%s","name=");
     scanf("%s",(*head)->name);
     (*head)->next = NULL;
     p = *head;
     for(int i = 2; i <= n; ++i) {
        q = (Node*)malloc(sizeof(Node));
        printf("%s","name=");
        scanf("%s", q->name);
        q->next = *head;
        p->next = q;
        p = q;
     }
}

int main(int argc, char const *argv[]) {

  Node *head, *q;
  int silabe = 2, count = 0;

  create(&head);

  while(head!=head->next) {
    for(int i = 0; i < silabe-2;++i) head = head->next;
    printf("count. %d Exit %s\n", ++count, head->next->name);
    q = head->next;
    head->next = head->next->next;
    head = head->next;
    free(q);
  }
  printf("The winner is: %s\n", head->next->name);

  return 0;
}
