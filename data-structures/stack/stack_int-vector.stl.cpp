#include <iostream>
#include <vector>

using namespace std;

//Creating a stack for integers
class Stack {

   public:
     Stack(int capacity) {
          this->capacity = capacity;
     }
     void push(int data) {
          if(isFull()) {
            cout<<"Full Stack"<<endl;
            return;
          }
          cout<<"Added to Stack: "<<data<<"\n";
          container.push_back(data);
     }

     void pop() {
          if(isEmpty()) {
            cout<<"Empty Stack!";
            return;
          }
          cout<<"Pop: "<<container.back()<<endl;
          container.pop_back();
     }

     int top() {
         return container[container.size()-1];
     }

     bool isEmpty() {
          return container.empty();
     }

     bool isFull() {
          return capacity == container.size();
     }

     void display() {
       if(isEmpty()){
         cout<<endl<<"Empty Stack. Nothing to show!"<<endl;
         return;
       }
       for(int n:container) {
         cout<<n<<"\n";
       }
     }
   private:
     vector<int> container;
     int capacity;
};

int main(int argc, char const *argv[]) {
  Stack stack(100);
  stack.push(1);
  stack.push(2);
  stack.push(3);
  stack.push(4);
  stack.pop();
  stack.pop();
  stack.pop();
  stack.pop();
  stack.pop();
  stack.display();
  return 0;
}
