#include <iostream>

using namespace std;

template <class Type>
class Queue {

      public:
      //constructor of the class
      Queue(int size) {
            std::cout<<"Constructor of the class is called."<<"\n";
            arr = new int[ size ];
            capacity = size;
            rear = -1;
            front = 0;
            count = 0;
      }
      ~Queue(){
        std::cout<<"Destructor of the class is called."<<"\n";
        delete [] arr;
      }

      void enqueue(Type data) {

           if(this->isFull()) {

             std::cout<<"The Queue is Full."<<"\n";
             return;
           }

           std::cout<<"Added to Queue: "<<data<<"\n";

           rear = (rear + 1) % capacity;

           arr[rear] = data;

           count++;
      }

      int dequeue() {

          if(this->isEmpty()) {
            std::cout<<"The queue is empty.";
            return -1;
          }

          Type data = arr[front];

          std::cout<<"Dequeue: "<<data<<"\n";

          front = ( front + 1 ) % capacity;

          count--;

          return data;
      }

      int isEmpty() {
          return count == 0;
      }

      int isFull() {
          return count == capacity;
      }

      int size() {
          return count;
      }

      void display() {
           if(isEmpty()) {
              std::cout<<"The Queue is empty.";
              return;
           }
           std::cout<<"front="<<front<<" rear = "<<rear<<" count="<<count<<"\n";

           if(front<=rear)

           for(int i = front; i <= rear; ++i) {
               std::cout<<(Type)arr[i]<<" ";
           }else {

           for(int i = front; i <= capacity-1; ++i) {
               std::cout<<arr[i]<<" ";
           }
           for(int i = rear; i < front; ++i) {
             std::cout<<arr[i]<<" ";
           }
         }
           std::cout<<"\n";
      }

      private:
      int *arr;
      int front,
          rear,
          count,
          capacity;
};

int main(int argc, char const *argv[]) {

  Queue<int> q(100);
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  q.display();
  q.dequeue();
  q.enqueue(4);
  q.display();
  q.dequeue();
  q.display();
  q.dequeue();
  q.display();

  Queue<char> q2(100);
  q2.enqueue('A');
  q2.enqueue('B');
  q2.enqueue('C');
  q2.display();
  q2.dequeue();
  q2.display();

  return 0;
}
