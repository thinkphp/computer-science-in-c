/*
                _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . ___
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======

*/
#include <bits/stdc++.h>

struct Node {
   //camp of information
   int data;
   struct Node *next;

} *head = NULL;

void addToinkedList(int num) {

     if(head == NULL) {
        head = new Node;
        head->data = num;
        head->next = NULL;
     } else {
       struct Node *q;
       q = new Node;
       q->data = num;
       q->next = head;
       head = q;
     }

}

void removeFromLinkedList(int node) {

     if( node == head->data ) {
         struct Node *ptr;
         ptr = head;
         head = head->next;
         delete ptr;

     } else {

         struct Node *ptr,*del;
         ptr = head;
         while(ptr->next!=NULL && ptr->next->data != node) ptr=ptr->next;

         if (ptr->next == nullptr) {
                    std::cout << "Element " << node << " not found in the list.\n";
                    return;
          }
           del = ptr->next;
           ptr->next = del->next;
           delete del;
     }
}

void displayLinkedList(struct Node *head) {

    for(struct Node *q = head; q != nullptr; q = q->next) printf("%d ", q->data);

    printf("%s\n","");
}

void addAfterNode(int node, int value) {

     struct Node *c = head;

     while(c->data != node) c = c->next;

     struct Node *q = new Node;

     q->data = value;
     q->next = c->next;
     c->next = q;
}

void addBeforeNode(int node, int value) {

     if(head->data == node) {

       struct Node*q = new Node;
       q->data = value;
       q->next = head;
       head = q;

     } else {

       struct Node*q = new Node,
              *c;

       c = head;

       while( c->next->data != node ) c = c->next;

       q->data = value;
       q->next = c->next;
       c->next = q;
     }

}

int main(int argc, char const *argv[]) {

  int i, //this represents an iterator for loop
        arr[] = { 9, 8, 7, 6, 25, 4, 3, 23, -11, 0 },  // the main array

        n = sizeof(arr)/sizeof(arr[0]); // the length of the array

    for(i = 0; i < n; ++i) {

        addToinkedList( arr[ i ] );
    }

    displayLinkedList(head);

    removeFromLinkedList(-11);

    displayLinkedList(head);

    addBeforeNode(25, 777);

    displayLinkedList(head);

    addBeforeNode(0, 888);

    displayLinkedList(head);


    addAfterNode(888, 889);

    displayLinkedList(head);

    addAfterNode(9, 123);

    displayLinkedList(head);

    addAfterNode(123, 124);

    displayLinkedList(head);

    addAfterNode(124, 125);

    displayLinkedList(head);
    
  return 0;
}
