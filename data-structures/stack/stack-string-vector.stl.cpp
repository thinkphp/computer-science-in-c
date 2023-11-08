#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Creating a stack for strings
class Stack {

   public:
     Stack(int capacity) {
          this->capacity = capacity;
     }
     void push(string data) {
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

     string top() {
         return container.back();
     }

     int size() {
       return container.size();
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
       for(string n:container) {
         cout<<n<<"\n";
       }
     }
   private:
     vector<string> container;
     int capacity;
};

int main(int argc, char const *argv[]) {
  Stack stack(100);
  stack.push("Annapurna");
  stack.push("Everest");
  stack.push("K2");
  cout<<"Size = "<<stack.size()<<endl;
  cout<<"Peak = "<<stack.top()<<endl;
  stack.push("Nanga Parbat");
  stack.display();
  cout<<"Size = "<<stack.size()<<endl;
  cout<<"Peak = "<<stack.top()<<endl;
  stack.display();
  stack.pop();
  stack.pop();
  stack.display();
  cout<<"Size = "<<stack.size()<<endl;
  cout<<"Peak = "<<stack.top()<<endl;
  return 0;
}
