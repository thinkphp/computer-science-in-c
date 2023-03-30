#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct Stack {
    int capacity;
    char *arr;
    int top;
};

struct Stack* createStack(unsigned capacity) {
     struct Stack *s = (struct Stack*)malloc(sizeof(struct Stack));
            s->capacity = capacity;
            s->top = -1;
            s->arr = (char*)malloc(capacity * sizeof(char));
            return s;
};

int isFull(struct Stack *stack) {
    return stack->top == stack->capacity - 1;
};

int isEmpty(struct Stack *stack) {
    return stack->top == -1;
};

void push(struct Stack* stack, int data) {
      if(isFull(stack)) {
        return;
      }
      stack->arr[++stack->top] = data;
}

char pop(struct Stack *stack) {
      if(isEmpty(stack)) {
        printf("isEmpty");
        return 0;
      }
      return stack->arr[stack->top--];
}

char* reverse(char *p, int n) {

      struct Stack *stack = createStack(n);

             for(int i = 0; i < n; ++i) {
                push(stack, p[i]);
             }

             for(int i = 0; i < n; ++i) {
                 printf("%c", pop(stack));
             }             
};

int main(int argc, char const *argv[]) {
  char str[100] = "MayAnnCampanera";
  int n = strlen(str);
  reverse(str,n);
  return 0;
}
