#include <iostream>
 
typedef struct stack{
  char ch;
  struct stack *link;
} Stack;
 
void push(Stack**head, char c) {
     Stack *node = new Stack;
     node->ch = c;
     node->link = (*head);
     (*head) = node;
};
 
void print(Stack *p) {
     while(p) {
       printf("%c", p->ch);
       p = p->link;
     }
};
 
int main(int argc, char const *argv[]) {
 
  Stack *stack = NULL;
 
  char const *str;
 
  str = "MayAnnCampanera";
 
  int cnt = 0;
 
  while(str[cnt]!='\0') {
 
    cnt++;
  }
  for(int i = 0; i < cnt; ++i) push(&stack, str[i]);
 
  print(stack);
 
 
 
  return 0;
}
