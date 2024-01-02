#include <iostream>
 
class Node {
     private:
     int data;
     Node *next;
     public:
     Node(int value):data(value),next(nullptr) {}
     void setNext(Node *v) {
          this->next = v;
     }
     void setData(int v) {
       this->data = v;
     }
     int getData() {
       return this->data;
     }
     Node *getNext() {
       return this->next;
     }
};
 
void CreateList(Node *&head) {
     int nr, node;
     printf("%s\n", "nr = ");
     scanf("%d", &nr);
     while(nr--){
       printf("%s", "node = ");
       scanf("%d", &node);
       if(head == NULL) {
         head = new Node(node);
       } else {
         Node *c = new Node(node);
         c->setNext(head);
         head = c;
       }
     }
}
 
void DisplayList(Node *head) {
     while(head) {
       printf("%d ", head->getData());
       head = head->getNext();
     }
}
 
void mergeLists(Node *list1, Node *list2, Node *&merged) {
 
      Node *last;
 
      if(list1->getData() < list2->getData()) {
         merged = list1;
         last = list1;
         list1 = list1->getNext();
      }  else {
         merged = list2;
         last = list2;
         list2 = list2->getNext();
      }
 
      while(list1 != NULL && list2 != NULL) {
 
            if(list1->getData() < list2->getData()) {
               last->setNext(list1);
               last = list1;
               list1 = list1->getNext();
 
            } else {
               last->setNext(list2);
               last = list2;
               list2 = list2->getNext();
            }
      }
 
      if(list1 != NULL) {
        last->setNext(list1);
      } else {
        last->setNext(list2);
      }
}
 
int main(int argc, char const *argv[]) {
  Node *head1 = NULL,*head2 = NULL,*Head = NULL;
  CreateList(head1);
  CreateList(head2);
  mergeLists(head1, head2, Head);
  DisplayList(Head);
  return 0;
}
