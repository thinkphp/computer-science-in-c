### Stack Data Structure in C++

# Usage
  >g++ stack.cpp -o s.exe
  >./s
>
##  Examples

create(&stack) https://ideone.com/IVK6hn 
template stack https://ideone.com/xBQQ0l
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
