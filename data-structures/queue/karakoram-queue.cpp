#include <iostream>
#include <cstring>

using namespace std;

class Queue {

      public:
      Queue(int size) {

        capacity = size;
        container = new string[size];
        rear = -1;
        front = 0;
        count = 0;
      }

      ~Queue() {
        delete [] container;
      }

      void enqueue(string data) {
          if(isFull()) {
            cout<<"The Queue is full.";
            return;
          }
          cout<<"Added to Queue: "<< data<<endl;
          rear++;
          container[rear] = data;
          count++;
      }

      int isFull() {
        if(count == capacity) return 1;
        else
                              return 0;
      }

      int size() {
        return count;
      }

      int isEmpty() {
        if(count == 0) return 1;
                   else
                       return 0;
      }

      string dequeue() {
          if(isEmpty()) {
            cout<<"Stack is Empty";
            return "";
          }
          else {
          string data = container[front];
          cout<<"Dequeue: "<<data<<endl;
          front++;
          count--;
          return data;
          }
      }

      void display() {
        cout<<"\n-----\n";
        for (size_t i = front; i <= rear; i++) {
          cout<<container[i]<<"\n";
        }
        cout<<"\n-----\n";
      }

      private:
      int capacity;
      string *container;
      int rear;
      int front;
      int count;
};

int main(int argc, char const *argv[]) {

  //create a queue 14 eight thousanders
  Queue q(100);
  q.enqueue("Everest-Sagarmatha (Himalaya range)");
  q.enqueue("K2 (Karakoram range)");
  q.enqueue("Annapurna (Himalaya range)");
  q.enqueue("Nanga Parbat (Karakoram range)");
  q.enqueue("Broad Peak (Karakoram range)");
  q.enqueue("Gasherbrum I - Hidden Peak (Karakoram range)");
  q.enqueue("Gasherbrum II (Karakoram range)");
  q.enqueue("Kangchenjunga (Karakoram range)");
  q.enqueue("Shishapangma (Himalaya range)");
  q.enqueue("Dhaulagiri (Himalaya range)");
  q.enqueue("Lhotse (Himalaya range)");
  q.enqueue("Makalu (Himalaya range)");
  q.enqueue("Cho Oyu (Himalaya range)");
  q.enqueue("Manaslu");
  q.display();
  q.dequeue();
  q.dequeue();
  q.dequeue();
  q.enqueue("Annapurna");
  q.enqueue("K2");
  q.enqueue("Everest - Sagarmatha");
  q.display();
  cout<<"SIZE = "<<q.size()<<endl;
  q.dequeue();
  q.dequeue();
  q.dequeue();
  q.dequeue();
  q.dequeue();
  q.dequeue();
  q.dequeue();
  q.dequeue();
  q.dequeue();
  q.dequeue();
  cout<<"SIZE = "<<q.size()<<endl;
  q.display();
  return 0;
}
