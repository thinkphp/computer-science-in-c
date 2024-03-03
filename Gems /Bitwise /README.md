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

Nu in acelasi mod se face reprezentarea numrelor intregi negative. Pentru aceasta este necesara efectuarea urmatorilor pasi:

1) determinarea reprezentarii interne a numarului ce reprezinta valoarea absoluta a numarului initial. Acesta are bitul de semn egal cu zero.

2) se calculeaza complementul fata de 1 a reprezentarii obtinute la pasul anterior. adica bitul 1 devine 0, iar bitul 0 devine 1.

3) se aduna 1 (adunarea se face in baza 2) la valoarea obtinuta.


Exemplu:

Pentru determinarea reprezentarii numarului -8 se procedeaza felul urmator:

- reprezentarea valorii absolute a numarului 8 este: 0000 1000

- complementul fata de 1 este 1111 0111
 
- reprezentarea obtinuta dupa adunarea cu 1 este: 1111 1000

 Deci reprezentarea valorii -8 pe 8 biti este: 11111000

Dupa cum observam, bitul de semn este 1 ceea ce ne indica faptul ca avem de a face cu un numar negativ.

Putem trage concluzia ca numerele intregi care se pot reprezenta pe 8 biti sunt cuprinse intre: 1000 0000 si 0111 1111, adica -128(10) si 127(10).


Asa cum am spus si la inceputul cursului, numerele intregi se pot reprezenta in cod complementar, avand la dispozitie 16, 32, sau 64 de biti. Mecanismul
este acelasi, insa valorile numerelor cresc.


#### Operatori la nivel de bit.

Operatorii pe biti se pot aplica datelor ce fac parte din tipurile intregi. Operatiile se efectueaza asupra bitilor din reprezentarea interna a numerelor.

1) Operatorul de negatie

2) Operatorul de conjunctie

3) Operatorul de disjunctie

4) Operatorul "sau exclusiv"

5) Operatorul Shift left

6) Operatorul Shift right

### Operatii la nivel de biti.

1) Transformarea unui bit in 1

2) Trasnformarea unui bit in 0

3) Testarea valorii unui bit

4) Testarea valorilor ultimilor biti


### References

https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/

### Problem Set

https://www.pbinfo.ro/probleme/2711/puterebiti

https://www.pbinfo.ro/probleme/2708/verifparitate

https://www.pbinfo.ro/probleme/2577/getbit

https://www.pbinfo.ro/probleme/2580/setbit0

https://www.pbinfo.ro/probleme/2581/setbit1

https://www.pbinfo.ro/probleme/2589/setlast2

https://www.pbinfo.ro/probleme/2590/removelast2

https://www.pbinfo.ro/probleme/2624/invbits

https://www.pbinfo.ro/probleme/2910/bitswap

https://www.pbinfo.ro/probleme/2672/primulbit
