#include <bits/stdc++.h>

using namespace std;

const long BigNum = 9999999;

struct Node {
      int info;
      struct Node *next;
};

struct Node *c,
            *c1,
            *head,
            *p;

int main(int argc, char const *argv[]) {

  int i,
      n;

  cout<<"numarul de elemente de sortat N = ";
  scanf("%d",&n);
  //presupunem ca tastam N = 7

  // -7 71 19 2 4 5

  head = (struct Node*)malloc(sizeof(struct Node)); //new Node
  head->info = BigNum;
  head->next = nullptr;//NULL

  for(i = 1; i <= n; i++) {

          printf("Node = ");
          //se creeaza spatiu in Heap
          p = (struct Node*)malloc(sizeof(struct Node));
          scanf("%d", &p->info);

         //daca p->info < head->info adica capul listei
         //-7 71 BIGNUMBER
          if(p->info < head->info) {

             p->next = head;

             head = p;

          } else {

             //capul listei
             c = head;

             //nodul urmator
             c1 = head->next;


             while(p->info > c1->info) {

               c = c->next;
               c1 = c1->next;
             }

             c->next = p;

             p->next = c1;

          }

  }

  //display(head);

  c = head;

  while(c && c->info != BigNum) {

    printf("%d ", c->info);

    c = c->next;

  }

  //head = new Node
  //head = (struct Node*)malloc(sizeof(struct Node))  <=> new Node


  return 0;
}
