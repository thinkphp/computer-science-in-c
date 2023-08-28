#include <iostream>
#include <cstring>

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

  Stack *stack = NULL,

        *stack2 = NULL;

  char const *str;

  str = "MayAnnCampanera";

  char const *str2 = argv[1];

  int len = strlen(str2);

  std::cout<<str2<<" LEN = "<<len<<"\n";

  int cnt = 0;

  while(str[cnt]!='\0') {

    cnt++;
  }
  for(int i = 0; i < cnt; ++i) push(&stack, str[i]);

  print(stack);

  std::cout<<std::endl;

  for(int i = 0; i < len; ++i) push(&stack2, str2[i]);

  print(stack2);
  
  return 0;
}
