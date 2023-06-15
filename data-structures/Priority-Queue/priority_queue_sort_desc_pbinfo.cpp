#include <bits/stdc++.h>
#define filein "sortare.in"
#define fileout "sortare.out"
using namespace std;

// Implement Priority Queue using Linked List
//
// Analysis Time Complexity:
// - push O(n)
// - pop O(1)
// - peek O(1)
/*
In a Linked List implementation, the entries are sorted
in decending order based on their priority. The hightest
priority element is always added to the front of the priority
queue, which is formed using linked list.
The functions like push() - enqueue(), pop() - dequeue() and peek()
are using to implement a priority queue using a linked list and
are explained as follow:
- push() or enqueue() - this function is used to add new item or entries or data into the Queue.
- pop() or dequeue() - this function is used to remove items or entries or data or elements with highest priority from the queue.
- peek() - this function is used to get the element with the highest priority in the queue without removing it from the queue.
*/

ifstream fin(filein);
ofstream fout(fileout);

typedef struct Node {
        int data;
        int priority;
        struct Node *next;
} Node;

Node* create(int data, int priority) {
      Node *new_node = (Node*)malloc(sizeof(Node));
            new_node->data = data;
            new_node->priority = priority;
            new_node->next = NULL;
      return new_node;
}

void push(Node**h, int data, int priority) {

     Node*head = (*h);
     Node*temp = create(data, priority);

     // special case: if the priority of the head is
     // lesser than priority of the new element
     if((*h)->priority < priority) {
         temp->next = (*h);
         (*h) = temp;
     } else {
         while(head->next != NULL && head->next->priority > priority) {
              head = head->next;
         }
         temp->next = head->next;
         head->next = temp;
     }
}

void pop(Node**head) {

     Node*temp = (*head);
     (*head) = (*head)->next;
     free(temp);
};

int peek(Node**head) {

    return (*head)->data;
};

int isEmpty(Node**head) {

    return (*head) == NULL;
}

int main(int argc, char const *argv[]) {

    int arr[1000], n;
    
    fin>>n;   
    
    for(int i = 0; i < n; ++i) {

        fin>>arr[i];
    }
    
    
  Node *pq = create( arr[0], arr[0] );

  for(int i = 1; i < n; ++i) {

      push( &pq, arr[i], arr[i] );
  }

  while(!isEmpty(&pq)) {
      
      fout<<peek(&pq)<<" ";
      
      pop(&pq);
  }

  return 0;
}
