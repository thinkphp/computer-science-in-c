### Stack Data Structure in C++ (LIFO = Last In First Out)

# Usage
  >g++ stack.cpp -o s.exe
  >./s
>
##  Examples

Stack Data Structure implemented as a Simply Linked List: create(&stack) push(&stack, value); pop(&stack), top(&stack), isEmpty(stack) https://ideone.com/IVK6hn 

Template Stack https://ideone.com/xBQQ0l | https://onlinegdb.com/eq7znIo2A | https://onlinegdb.com/CTVkOlbUF | https://ideone.com/a9GQbt

Stack implemented as STL vector<string> container https://ideone.com/axo91k

Stack implemented as STL vector<int> container  https://ideone.com/wInWMa

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

### Problem Set
* https://www.hackerrank.com/challenges/balanced-brackets/problem
* https://www.infoarena.ro/problema/nrpits
* https://www.pbinfo.ro/probleme/3533/oop-3 Sources: https://ideone.com/cMWjH0 | https://onlinegdb.com/aCDFiF1Q5z
