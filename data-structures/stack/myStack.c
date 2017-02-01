#include <stdio.h>
#include <malloc.h>

typedef struct Stack {
       int data;
        struct Stack *link;
} Stack;

void push(Stack**head,int data)
{
     Stack *node = (Stack*)malloc(sizeof(Stack)); 
            node->data = data;
            node->link = (*head); 
            (*head) = node;     
};

int top(Stack**stack) {
 
    if(isEmpty(*stack) == 0) {printf("Stack is empty!");return;}

    Stack *s = (*stack);

    int data = (*stack)->data;
 
    (*stack) = (*stack)->link;

    free(s); 

    return data;
}

int pop(Stack**stack) {
 
    Stack *s = (*stack);

    if(isEmpty(*stack) == 0) return;

    (*stack) = (*stack)->link;

    free(s); 
}

int isEmpty(Stack *stack){

    if(stack == NULL) return 0;

       else 
                      return 1;   
};

void printStack(Stack *stack){

     if(isEmpty(stack) == 0) return;  

     while(stack){

           printf("%d\n",stack->data);

           stack = stack->link;
     } 
}

Stack *stack = NULL;

int main() {

    push(&stack,1); 
    push(&stack,2);
    push(&stack,3);
    push(&stack,4);
    push(&stack,5);
    printStack(stack);
    pop(&stack);
    pop(&stack);
    printStack(stack);
}