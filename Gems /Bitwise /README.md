### Bitwise 

i) Reprezentarea interna a numerelor intregi

Reprezentarea in memorie a numerelor intregi se face printr-o secventa de cifre 0 si 1. Aceasta secventa poate avea o lungime de 8, 16, 32 sau 64 de biti.

Forma de memorare a intregilor se numeste cod complementar. In functie de lungimea reprezentarii se stabileste domeniul valorilor care pot fi stocate.

Modul de reprezentare (in cod complementar) va fi prezentat in cele ce urmeaza, folosind reprezentarea pe o lungime de 8 biti, valabila pentru tipul char 
in c/c++.
```
 _ _ _ _ _ _ _ _
| | | | | | | | |
 _ _ _ _ _ _ _ _ 
 7 6 5 4 3 2 1 0

bit de semn:
- 0 pentru numar positiv
- 1 pentru numar negativ
```

Se observa ca numerotarea pozitiilor se face de la dreapta la stanga (de la 0 la 7), pozitia 7 fiind bit de semn (0 pentru numerele pozitive si 1 pentru numerele negative). Rezulta ca doar 7 biti (pozitiile 0 - 6) se folosesc pentru reprezentarea valorii absolute a numarului. 

Numerele intregi pozitive se convertesc in baza 2 si se face completarea cu cifre 0 nesemnificative, pana la completarea celor 7 biti.

Exemplu:

Sa determinam forma de reprezentare a numarului intreg 5.

5(10) = 101(2)

Vorfi necesare 4 cifre de 0 nesemnificative, pentru completarea primilor 7 biti, iar pozitia 7 (bitul 8) va fi 0 deoarece numarul este pozitiv.

```
 _   _   _   _   _  _   _   _
|0 | 0 | 0 | 0 | 0| 1 | 0 |1 |
 
 7   6   5   4   3  2   1  0
```



### References

https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/
