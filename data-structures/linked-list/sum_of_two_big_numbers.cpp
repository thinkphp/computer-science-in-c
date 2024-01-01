#include <bits/stdc++.h>
#include <string>

using namespace std;

struct Node {

  int data;
  struct Node *next;

};

struct Node* reverse(struct Node *&head) {
  struct Node *curr, *next, *prev;
  curr = head;
  next = nullptr;
  prev = nullptr;
  while(curr){
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }

  return prev;
}


void create_list(const string &num, struct Node *&head) {
  for(auto i: num){
     if(head == NULL) {
       head = new Node();
       head->data = i - '0';
       head->next = nullptr;
     } else {
       struct Node *c = new Node();
       c->data = i - '0';
       c->next = head;
       head = c;
     }
  }
}

void display(struct Node*head) {

     while(head) {
       printf("%d", head->data);
       head = head->next;
     }

     printf("\n");
}

void addTwoLists(struct Node *head1, struct Node *head2, struct Node *&sumList) {

     struct Node *list,
                 *dummyHead,
                 *p = head1,
                 *q = head2;

     list = new Node();
     list->data = 0;
     list->next = NULL;

     dummyHead = list;

     int carry = 0;

     while( p || q ) {

       int x,
           y;
       if(p!=nullptr) x = p->data;
          else x = 0;
       if(q!=nullptr) y = q->data;
          else y = 0;
        int sum = x + y + carry;
        carry = sum / 10;

        dummyHead->next = new Node();
        dummyHead->next->data = sum % 10;

        if(p) p = p->next;
        if(q) q = q->next;

        dummyHead = dummyHead->next;
     }

     if(carry>0) {
       dummyHead->next = new Node();
       dummyHead->next->data = carry;
     }

    sumList = list->next;
}

int main(int argc, char const *argv[]) {

  struct Node *head1 = NULL,
              *head2 = nullptr,
              *headSum = nullptr;

  char num1[100],
       num2[100];

  printf("Big Number1 = ");
  scanf("%s",&num1);
  printf("Big Number2 = ");
  scanf("%s",&num2);

  create_list(num1,head1);
  create_list(num2,head2);
  //display( head1  );
  //display( head2  );
  addTwoLists( head1, head2, headSum );
  //display(reverse(head1));
  //display(reverse(head2));
  printf("Sum = ");
  display( reverse(headSum) ) ;

  return 0;
}
