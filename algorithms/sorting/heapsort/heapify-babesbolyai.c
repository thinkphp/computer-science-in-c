#include <stdio.h>

/*
Proprietatea de heap este regula pe care trebuie să o respecte fiecare nod din arbore. 
Spunem ca este "respectata" atunci cand regula este adevarată peste tot,
adica nu există niciun nod care o oncalca.
*/

//Regula la un max-heap: fiecare nod este mai mare sau egal cu copiii săi.
/*
Dacă regula este adevarata pentru toate nodurile, 
radacina este automat cel mai mare element din tot heap-ul.

        13
       /  \
     11    12
    /  \   /
   5    6 7

   Vector: {13, 11, 12, 5, 6, 7}

13 >= 11 si 13 >= 12
11 >= 5 si 11 >= 6
12 >= 7

*/
void heapify(int arr[], int n, int i) {
    
    while (1) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest])
            largest = left;
        if (right < n && arr[right] > arr[largest])
            largest = right;

        if (largest == i)
            break;                 // proprietatea de heap e respectata
        /*
        largest == i înseamna ca nodul i este mai mare sau egal cu ambii copii, 
        deci regula e adevarata pentru el. Presupunand că subarborii de sub el sunt deja heap-uri corecte 
        (conditia de la inceput), nu mai e nimic de reparat si iesim din structura repetitiva while.
        */

        int tmp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = tmp;

        i = largest;               // coboram în subarborele afectat
    }
}

void heapSort(int arr[], int n) {
    // construim max-heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // mutam maximul la sfarsit, apoi reparam heap-ul
    for (int i = n - 1; i > 0; i--) {
        int tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;

        heapify(arr, i, 0);        // heap-ul are acum i elemente
    }
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/* ============ Testbench simplu ============ */
 
/* returneaza 1 daca vectorul e sortat crescator */
int e_sortat(int arr[], int n) {
    for (int i = 1; i < n; i++)
        if (arr[i - 1] > arr[i])
            return 0;
    return 1;
}
 
void test(const char *nume, int arr[], int n) {
    heapSort(arr, n);
    if (e_sortat(arr, n))
        printf("OK    - %s\n", nume);
    else
        printf("EROARE - %s\n", nume);
}
 
int main(void) {
    int a[] = {12, 11, 13, 5, 6, 7};
    int b[] = {1, 2, 3, 4, 5};
    int c[] = {5, 4, 3, 2, 1};
    int d[] = {3, 3, 1, 1, 2};
    int e[] = {-5, 3, -1, 0};
    int f[] = {42};
 
    test("exemplu normal",   a, 6);
    test("deja sortat",      b, 5);
    test("sortat invers",    c, 5);
    test("duplicate",        d, 5);
    test("numere negative",  e, 4);
    test("un element",       f, 1);
 
    return 0;
}
 
