Desigur! Poți inițializa un șir de caractere direct la momentul alocării memoriei folosind funcția `malloc` și funcția `memcpy` pentru a copia datele. Alternativ, poți folosi și inițializarea directă în momentul alocării. Iată câteva metode alternative:

### Metoda 1: Utilizarea `memcpy`
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    const char *source = "Hello, World!";
    size_t length = strlen(source) + 1; // +1 pentru caracterul null terminator
    char *ptr = (char *)malloc(length * sizeof(char)); // Alocă memorie pentru string
    
    if (ptr == NULL) {
        printf("Alocarea memoriei a eșuat\n");
        return 1;
    }

    memcpy(ptr, source, length); // Copiază string-ul în memoria alocată
    printf("%s\n", ptr); // Afișează conținutul string-ului
    free(ptr); // Eliberează memoria alocată
    return 0;
}
```

### Metoda 2: Inițializare Directă în Momentul Alocării
Dacă șirul de caractere este cunoscut la compilare, poți aloca memoria și copia datele într-o singură linie folosind inițializarea directă.

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    const char *source = "Hello, World!";
    size_t length = strlen(source) + 1; // +1 pentru caracterul null terminator
    char *ptr = (char *)malloc(length * sizeof(char)); // Alocă memorie pentru string
    
    if (ptr == NULL) {
        printf("Alocarea memoriei a eșuat\n");
        return 1;
    }

    // Inițializarea directă în momentul alocării
    sprintf(ptr, "%s", source); // Copiază string-ul în memoria alocată folosind sprintf

    printf("%s\n", ptr); // Afișează conținutul string-ului
    free(ptr); // Eliberează memoria alocată
    return 0;
}
```

### Metoda 3: Utilizarea `strdup`
`strdup` este o funcție care alocă memorie și copiază un șir de caractere într-o singură operație.

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    const char *source = "Hello, World!";
    char *ptr = strdup(source); // Alocă memorie și copiază string-ul

    if (ptr == NULL) {
        printf("Alocarea memoriei a eșuat\n");
        return 1;
    }

    printf("%s\n", ptr); // Afișează conținutul string-ului
    free(ptr); // Eliberează memoria alocată
    return 0;
}
```

**Explicații suplimentare:**

- **Metoda 1:** `memcpy` copiază un bloc de memorie de la o locație la alta. Este utilă pentru copierea string-urilor când știi dimensiunea exactă.
- **Metoda 2:** `sprintf` este o funcție care permite copierea și formatarea string-urilor într-o zonă de memorie alocată. Este flexibilă și eficientă.
- **Metoda 3:** `strdup` este o funcție convenabilă care combină alocarea memoriei și copierea string-urilor într-o singură operație. Este disponibilă în multe implementări de C standard, dar nu în toate, deci verifică disponibilitatea în mediul tău de dezvoltare.


### Practice

* https://ideone.com/5EyYWy

* https://ideone.com/Afe9a9


### Ideaone

https://ideone.com/thinkphp/string
