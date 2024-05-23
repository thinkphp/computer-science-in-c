### Queue Data Structure in C++

# Usage

* >g++ queue.cpp -o q.exe
* >./q
```
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
```

```
int main(int argc, char const *argv[]) {
 
  Queue q(100);
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  q.enqueue(4);
  q.enqueue(5);
  q.display();
  q.dequeue();
  q.dequeue();
  q.display();
  q.enqueue(7);
  q.enqueue(8);
  q.display();
  q.dequeue();
  q.display();
  return 0;
}
```
  
## Examples on Ideone

* https://ideone.com/IAhrkr
* https://ideone.com/yjtvIG

### Problem Set

https://www.hackerrank.com/domains/data-structures?filters%5Bsubdomains%5D%5B%5D=queue
