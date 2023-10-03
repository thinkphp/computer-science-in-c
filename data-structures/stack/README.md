### Stack Data Structure in C++

# Usage
  >g++ stack.cpp -o s.exe
  >./s
>
##  Examples

https://ideone.com/YuuY7q

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
