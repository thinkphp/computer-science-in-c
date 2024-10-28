# Understanding C++ struct

În C, structurile (struct) sunt tipuri de date compuse care permit gruparea mai multor variabile de tipuri diferite într-o singură unitate, dar NU sunt un concept al programării orientate pe obiecte, deoarece C este un limbaj procedural, nu orientat pe obiecte.

Iată principalele diferențe:

1. În C:
```c
// Definirea unei structuri în C
struct Student {
    char nume[50];
    int varsta;
    float medie;
};

int main() {
    // Declararea și inițializarea în C
    struct Student s1;  // Trebuie să folosim cuvântul 'struct'
    strcpy(s1.nume, "Ion");
    s1.varsta = 20;
    s1.medie = 9.5;
    
    // SAU folosind un typedef
    typedef struct Student Student;
    Student s2;  // Acum putem folosi direct Student
    
    return 0;
}
```

2. În C++:
```cpp
// Definirea unei structuri în C++
struct Student {
    string nume;  // Putem folosi string și alte tipuri C++
    int varsta;
    float medie;
};

int main() {
    // În C++ nu mai este nevoie de cuvântul 'struct'
    Student s1;
    s1.nume = "Ion";
    s1.varsta = 20;
    s1.medie = 9.5;
    
    return 0;
}
```

Diferențe cheie între struct în C și C++:

1. Sintaxă:
   - C: Necesită cuvântul cheie 'struct' la declarare (sau typedef)
   - C++: Nu necesită 'struct' la declarare

2. Funcționalități:
   - C: Doar date membre
   - C++: Poate avea și funcții membre, constructori, destructori

3. Acces membri:
   - C: Toți membrii sunt publici
   - C++: Poate specifica nivel de acces (public, private, protected)

4. Tipuri de date:
   - C: Tipuri de date de bază și array-uri
   - C++: Toate tipurile C++ (inclusiv string, vector etc.)

5. Inițializare:
   - C: Mai restrictivă, necesită funcții precum strcpy pentru șiruri
   - C++: Mai flexibilă, permite atribuire directă

Există și în C care nu este un limbaj orientat pe obiecte. În C++, structurile au fost extinse pentru a suporta caracteristici OOP, dar originea lor este în programarea procedurală.

#### References

https://www.w3schools.com/cpp/cpp_structs.asp
