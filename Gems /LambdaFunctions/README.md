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


Istoria **lambda calculus** (calcul lambda) este strâns legată de dezvoltarea matematicii și a teoriei computației, având o influență puternică asupra limbajelor moderne de programare, inclusiv asupra limbajului **C++**. Iată o scurtă istorie a lambda calculus și cum s-a transformat într-un concept important în informatică:

### 1. **Originea Lambda Calculus**
   - **Alonzo Church** a dezvoltat **lambda calculus** în anii 1930, ca parte a unei încercări de a formaliza noțiunea de **funcție matematică** și de a explora fundamentele logicii și matematicii. El dorea să găsească o teorie a funcțiilor care să fie independentă de aritmetică și bazată exclusiv pe operații logice.
   - În această perioadă, matematicienii încercau să stabilească fundamentele formale ale matematicii, iar Church a creat lambda calculus ca un model al calculului formal bazat pe funcții anonime (funcții fără nume), ceea ce reprezintă de fapt aplicarea unor funcții pe argumente.
   - Lambda calculus reprezintă o **teorie a calculului** bazată pe **funcții** și **aplicația funcțiilor** și s-a dovedit a fi echivalentă cu **mașina Turing** din punct de vedere al capacității de a reprezenta orice calcul computațional.

### 2. **Dezvoltarea Lambda Calculus**
   - **Anul 1936** este important în istoria lambda calculus, deoarece atunci Alonzo Church a publicat lucrările sale care demonstrează cum poate fi folosit lambda calculus pentru a rezolva probleme de calcul.
   - De asemenea, în acea perioadă, **Alan Turing** a dezvoltat conceptul de **mașină Turing**, un alt model de calcul, care, deși diferit, este echivalent din punct de vedere al capacității de a descrie orice proces de calcul. 
   - Această echivalență dintre lambda calculus și mașina Turing este cunoscută ca **teza Church-Turing**, care sugerează că orice problemă computațională poate fi rezolvată fie prin lambda calculus, fie printr-o mașină Turing.

### 3. **Influența în Informatică și Limbaje de Programare**
   - Lambda calculus a devenit baza multor teorii fundamentale în informatică, inclusiv în teoria limbajelor de programare funcționale. **Lisp**, creat în 1958 de John McCarthy, este unul dintre primele limbaje de programare care a încorporat concepte din lambda calculus, punând un accent puternic pe funcții și recursivitate.
   - Lambda calculus a inspirat direct limbajele de programare **funcționale** moderne precum **Haskell**, **ML**, **Scala**, și multe altele, unde funcțiile anonime (sau lambda functions) sunt o caracteristică centrală.
   - În timp, limbaje imperativ-procedurale precum **C++**, **Java**, **Python**, și **JavaScript** au introdus și ele conceptul de **funcții lambda** sau **funcții anonime** pentru a facilita programarea funcțională în cadrul paradigmelor lor.

### 4. **Lambda Calculus în C++**
   - **C++** a introdus **lambdas** în versiunea C++11, aducând caracteristici funcționale în acest limbaj imperativ și orientat pe obiecte. Lambdas în C++ sunt funcții anonime care pot fi create pe loc, fără a defini explicit o funcție sau un obiect funcțional.
   - Acest lucru facilitează programarea funcțională în C++ și permite dezvoltatorilor să scrie cod mai concis și modular. Lambda functions în C++ sunt utile mai ales în contexte precum algoritmi generici, funcții de callback, și operațiuni paralele.

Exemplu de lambda function în **C++**:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Lambda function that prints each element of the vector
    std::for_each(numbers.begin(), numbers.end(), [](int n) {
        std::cout << n << " ";
    });

    return 0;
}
```

### 5. **Lambda Calculus și Programarea Funcțională**
   - Lambda calculus este fundamentul teoretic pentru **programarea funcțională**, unde funcțiile sunt tratate ca entități de primă clasă. În programarea funcțională, funcțiile pot fi transmise ca argumente, returnate din alte funcții și stocate în variabile, la fel cum sunt și valorile primitive.
   - **Funcțiile lambda** în limbaje moderne precum **C++**, **Python**, **JavaScript** și altele, permit utilizatorilor să definească funcții mici și reutilizabile fără a fi necesar să le dea un nume.

### Concluzie
Lambda calculus este o teorie matematică dezvoltată de Alonzo Church pentru a formaliza funcțiile și calculul funcțional. În timp, a devenit un model esențial pentru teoria computației și a influențat multe limbaje de programare moderne, inclusiv **C++**, care folosește lambdas pentru a introduce elemente funcționale în cadrul său imperativ.
