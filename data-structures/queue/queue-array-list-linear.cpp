#include <iostream>
class Queue {

      //access public
      public:
      //constructor of the class
      Queue(int size) {
        arr = new int[size];//allocate memory for the arr
        capacity = size;
        front = 0;
        rear = -1;
        count = 0;
      }

      //method member
      void enqueue(int data) {

           if(this->isFull()) {
             std::cout<<"The queue is full.";
             return;
           }
           std::cout<<"Added to Queue: "<<data<<"\n";
           rear = (rear + 1) % capacity;
           arr[rear] = data;
           count++;
      }

      int dequeue() {

          if(isEmpty()) {
              std::cout<<"The queue is empty.";
              return -1;
          }

          int data = arr[ front ];

          std::cout<<"Remove from Queue:"<<data<<"\n";

          front = (front + 1) % capacity;

          count--;

          return data;
      }

      bool isFull() {
        return count == capacity;
      }

      bool isEmpty() {
        return count == 0;
      }

      int size(){
        return count;
      }

      //destructor of the class
      ~Queue() {
        delete [] arr;
      }

      void display() {
        //print each element of the Queue

        if(isEmpty()) {
          std::cout<<"The Queue is Empty!";
          return;
        }
        for (int i = front; i <= rear; i++) {
            std::cout<<arr[i]<<" ";
        }
        std::cout<<"\n";
      }

      //data members are private access
      private:
      int *arr;
      int capacity, //the maximum size of the queue
          front, //the index of the front element of the queue
          rear, //the index of the back or bottom of the queue
          count; //the number of the elements of the queue
};
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
