#include <bits/stdc++.h>

struct Node {

   int data;
   struct Node *next;

};

void create_list( int arr[], int n, struct Node *&head ) {

     struct Node *c;

     for( int i = 0; i < n ; ++i ) {

         if( head == NULL ) {

             head = (struct Node*)malloc(sizeof(struct Node));
             head->data = arr[ i ];
             head->next = NULL;

         } else {

            c = new Node();
            c->data = arr[ i ];
            c->next = head;
            head = c;

         }
     }
}
void display( struct Node *head ) {
  while( head ) {
    printf("%d ", head->data );
    head = head->next;
  }
  printf("\n");
}

struct Node* reverse(struct Node*head) {
     struct Node *curr,*next,*prev;
     curr = head;
     next = NULL;
     prev = NULL;
     while(curr) {
       next = curr->next;
       curr->next = prev;
       prev = curr;
       curr = next;
     }
     return prev;
}

bool isPrime(int nr) {
     if(nr <= 1) return false;
     if(nr == 2 || nr == 3) return true;
     bool prime = true;
     int i = 2;
     while(i * i <= nr && prime == true) {
       prime = (nr % i) != 0;
       i += 1;
     }
     return prime;
}

void remove_primes(struct Node*&head) {

    struct Node *q,*last;
    q = new Node();
    q->next = head;
    last = q;

    while(head) {
      if(isPrime(head->data) == false || head->data < 0) {
        struct Node*remove;
        last->next = head->next;
        head = head->next;
        free(remove);
      //otherwise the number is not prime, pass by
      } else {
        head = head->next;
        last = last->next;
      }
    }

    head = q->next;
    delete q;
}

int main(int argc, char const *argv[]) {

  int arr[] = { 7919, 1, 2, 3, 4, 5, 6, 7, 8, 9,-1,-3,-4 },

      n = sizeof(arr)/sizeof(arr[0]);

  struct Node *head = NULL;
  create_list(arr, n, head);
  head = reverse(head);
  display(head);
  remove_primes(head);
  display(head);

  return 0;
}
