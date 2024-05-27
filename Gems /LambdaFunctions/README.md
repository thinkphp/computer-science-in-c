### Lambda Function

```
auto add = [&] (int x1, int y1, int x2, int y2) {
        ii a = mp(x1, y1);
        ii b = mp(x2, y2);
        if (b < a) swap(a, b);
        s.insert(mp(a, b));
    };
```

https://chatgpt.com/share/e3c3982c-7560-4257-8d9f-5d486615a960
