#include <iostream>
#include <cstring>
#define SIZE 100000

class Stiva {

      public:
      //constructor of the class
      Stiva() {
        summit = 0;
        container = new struct Node[SIZE];
      }

      //destructor of the class
      ~Stiva() {
        delete [] container;
      }

      void Push(int value) {

           if(summit == SIZE ) {
              std::cout<<"The stack is full.";
              return;
           } else {
              std::cout<<"Added!\n";
              if(summit == 0) {
                container[summit] = {value, value};
                summit++;
              } else {
                container[summit] = {value, max(container[summit-1].max_value, value)};
                summit++;
              }
           }
      }
      int max(int a, int b) {if(a>b) return a; else return b;}
      int Top() {
          if(!this->isEmpty()) return container[summit-1].value;
          return -1;
      }

      int Max() {
          if(!this->isEmpty()) return container[summit-1].max_value;
          return -1;
      }

      int isEmpty() {
        return summit == 0;
      }

      void Pop() {
           if(!this->isEmpty()) summit--;
      }

      void display() {
           for(int i = 0; i < summit; ++i) std::cout<<container[i].value<<"-"<<container[i].max_value<<"\n";
      }
      private:
      struct Node {
         int value,
             max_value;
      };
      struct Node *container;
      int summit;
};
