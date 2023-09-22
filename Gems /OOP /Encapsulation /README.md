# An example of encapsulation

https://ideone.com/2Pgn3o

```
Multime set;
  char str[50] = "MayAnnCampeneraVergara";
  int i = 0;
  while(str[i] != '\0') {
    set = set + str[i];
    i++;
  }

for(int i = 0; i < 256;++i) if(set.check(i)) cout<<(char)i<<" ";
```
