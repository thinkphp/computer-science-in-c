#include <iostream>
#define BigNumber 32000

using namespace std;

struct Node {
       int data;
       Node* next;
};

int i, n;
Node *head, *ptr,
     *c,*c1;

int main(int argc, char const *argv[]) {

  cout<<"n = ";
  cin>>n;

  head = new Node;
  head->next = nullptr;
  head->data = BigNumber;

  for(i = 1; i <= n; ++i) {

      ptr = new Node;
      cout<<"num = ";
      cin>>ptr->data;

      //daca este primul din lista HEAD
      if(ptr->data <= head->data) {

            ptr->next = head;
            head = ptr;

      } else {

            c = head;

            c1 = head->next;

            while(c1->data < ptr->data) {
              c1 = c1->next;
              c = c->next;
            }

            c->next = ptr;
            ptr->next = c1;
      }
  }

  //display sorted numbers
  c = head;

  while(c->data!=BigNumber) {

    cout<<c->data<<" ";
    c = c->next;

  }

  return 0;
}
