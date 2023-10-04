### Stack Data Structure in C++

# Usage
  >g++ stack.cpp -o s.exe
  >./s
>
##  Examples

LIFO: create(&stack) push(&stack, value); pop(&stack), top(&stack), isEmpty(stack) https://ideone.com/IVK6hn 

Template stack https://ideone.com/xBQQ0l

Generating Subsets https://ideone.com/qZsiMY

Reverse Sentence https://ideone.com/8eSpBP

Reverse a word rely on a stack implemented as a simply linked list https://ideone.com/jLlCx6
```
int main(int argc, char const *argv[]) {
  Stack*head;
  create(&head);
  write(head);
  Element el = top(&head);
  printf("(%s,%d)\n", el.name, el.code);
  strcp(el.name,"adrian");
  el.code = 1234;
  push(&head,el);
  write(head);
  return 0;
}
```
