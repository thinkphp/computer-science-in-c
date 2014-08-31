#include <iostream>

const long bigNum = 9999;

using namespace std;

typedef struct Node {
        long data;
        Node *next;
} Node;

Node *newNode,
     *c,
     *c1,
     *head;

int main() {
    int n;

    cout<<"n=";cin>>n;

    head = new Node;
    head->data = bigNum;
    head->next = NULL; 

    for(int i = 1; i <= n; i++) {

        newNode = new Node;
        cout<<"Node=";
        cin>>newNode->data; 

        if(newNode->data < head->data) {

           newNode->next = head;
           head = newNode;

        } else {

           c = head;
           c1 = head->next;

           while( newNode->data > c1->data ) {
                  c = c->next;
                  c1 = c1->next;
           }           

           newNode->next = c1;
           c->next = newNode;  
        }

    }

    c = head;

    while(c && c->data != bigNum) {

          cout<<c->data<<" ";

          c = c->next;
    }

    return 1;
}