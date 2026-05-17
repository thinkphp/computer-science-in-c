#include <iostream>

struct Node {
    int info;
    struct Node* next;
};

struct Node*head1=NULL,
           *head2=NULL;

struct Node* mergedLinkedList(struct Node * list1, struct Node* list2) {

       struct Node* dummy = new Node,
                  *curr = dummy;

       while(list1 != NULL && list2 != NULL) {

            if(list1->info < list2->info) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }

            curr = curr->next;
       }

       curr->next = list1!=NULL ? list1 : list2;

       return dummy->next;
}

void push_back(struct Node**head, int val) {

     struct Node *c = new Node;
     c->info = val;
     c->next = NULL;

     if(*head == NULL) {
        *head = c;
        return;
     }
     struct Node *temp = *head;

     while(temp->next) {
       temp = temp->next;
     }

     temp->next = c;
}

void push_front(struct Node**head, int val) {
         struct Node *c = new Node;
         c->info = val;
         c->next = *head;
         (*head) = c;

}

void display(struct Node* head) {
  
    if(head == NULL) std::cout<<"Empty!";
     while(head) {
       std::cout<<head->info<<" ";
       head = head->next;
     }
}

 int main(int argc, char const *argv[]) {
/*
   push_front(&head1,1);
   push_front(&head1,5);
   push_front(&head1,8);
   push_front(&head2,2);
   push_front(&head2,4);
   push_front(&head2,7);
*/

   push_back(&head1,1);
   push_back(&head1,5);
   push_back(&head1,8);
   push_back(&head2,2);
   push_back(&head2,4);
   push_back(&head2,7);

   display(head1);
   std::cout<<std::endl;
   display(head2);

   struct Node *merged = mergedLinkedList(head1, head2);

   std::cout<<std::endl;

   display(merged);

   return 0;
 }
