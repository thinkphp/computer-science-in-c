/*
 * Adrian Statescu
 * Implement a Stack based on Linked List;
 * MIT License
 */
#include <iostream>

using namespace std;

typedef struct StackNode {
       int data;
       struct StackNode *link;  
} StackNode;

class Stack {

      private:
      StackNode *Top = NULL;

      public: 
      void push(int val){

           StackNode *temp = new StackNode;
                      temp->data = val;
                      temp->link = NULL;

           if(Top == NULL) {

              Top = temp;

           } else {

              temp->link = Top;
              Top = temp;  
           }


      };

      int pop(){

          int val;

          if(isEmpty()) { 

             return -1;
          }

          else if(Top->link == NULL) {

                  val = Top->data;
                  delete Top;
                  Top = NULL;
                  return val;                     

          } else {

              StackNode *temp;
                         val = Top->data;
                         temp = Top;  
                         Top = Top->link;
                         delete temp;                   

                         return val;
                          
          }
      };

      int top() {

          if(!isEmpty()) return Top->data;
      };
     
      int isEmpty(){

          if(Top == NULL) return 1;

                   else 
                            return 0;
      }

        
};

int main() {

    Stack *stack = new Stack;
    stack->push(1);
    stack->push(2);
    stack->push(3);
    stack->push(4);
    stack->push(5);
    stack->pop();  
    cout<<stack->top();     

return(0);
}