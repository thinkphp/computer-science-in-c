### Queue Data Structure in C++

# Usage

* >g++ queue.cpp -o q.exe
* >./q

# Sample

  typedef struct node {
 
       int data;
       node *next;
         
  } Node;

  Node *front, *end; 

  int main() {

    push(front,end,1);
    push(front,end,2);
    push(front,end,3);
    pop(front);
    pop(front);
    pop(front);
    pop(front);

    return 1; 
  } 