/*
Lista Circulara Inlantuita:
--------------------------

Joc de copii:

Un numar de copii joaca de-a v-ati ascunselea si trebuie sa-l aleaga pe cel care sta la panda.
Ei folosesc o poezioara de genul: "Din oceanul Pacific / A iesit un peste mic / Si pe coada lui scria / Iesi afara dumneata!"
pe care o spun pe silabe, iar copilul la care se termina poezia iese afara din cerc. Se repeta procedeul pana cand ramane doar un copil.
Se cere scrierea unui program utilizand o lista circulara simplu inlantuita si care sa afiseze pe rand copilul ce iese.

Input:
Numar de copii: 5

Numele primei persoane: Maria
Nume copil 2:           Ionel
           3:             Dan
           4:            Magda
           5:           Marius

Numarul de silabe: 3

Output:

1 Iese din joc: Dan
2 Iese din joc: Maria
3 IEse din joc: Marius
4: Iese din joc Ionel

A castigat Magda

    Maria   <---    Marius    <--- Magda
                                        /\
       ||                               |
       \/                               |
       Ionel     ---- >  Dan ------>>   |


       Vom considera o lista simplu inlantuita, in care primul element introdus la primul

       Numele persoanelor se vor citi succesiv si se introduc in lista, pastrand structura
       de lista simplu liniar inlantuita.

       scanf("%s", (*head)->name)
       (*head)->next = *head;
       p = *head;
       in *head vom tine minte tot timpul primul element introdus si o variabila auxiliara "p"
       care fi intotdeuana ultimul element.

       //new in c++
       //q = (Pers*)malloc(sizeof(Pers)) //alocare dinamica a memoriei.

*/
#include <stdio.h>
#include <malloc.h>

typedef struct Node {

    char name[20];
    struct Node *next;

} Pers;

//pointer catre pointer **
void creare( Pers **head ){

      Pers *q, *p;
      int i, n;

      printf("Numarul de copii: ");
      scanf("%d", &n);

      *head = (Pers*)malloc(sizeof(Pers));//new
      printf("%s\n", "Numele primei persoane");
      scanf("%s",(*head)->name);

      /*
      in *head vom tine minte tot timpul primul element introdus si o variabila auxiliara "p"
      care fi intotdeuana ultimul element.
      */
      (*head)->next = *head;
      p = *head;

      for(int i = 2; i <= n; ++i) {
          printf("Urmatorul copil %d: ",  i);
          q = (Pers*)malloc(sizeof(Pers));
          scanf("%s", q->name);
          q->next = *head;
          p->next = q;
          p = q;
      }
}

int main(int argc, char const *argv[]) {
    int   k;
    Pers *head, *q, *prev;
    int contor = 0;

    // Creăm lista circulară
    creare( &head );
    printf("Numarul de silabe: ");
    scanf("%d", &k);

    // Algoritmul propriu-zis de eliminare
    while (head != head->next) {
        // Ne deplasăm până la nodul anterior celui ce trebuie eliminat
        prev = head;
        for (int i = 0; i < k - 2; ++i) {
            prev = prev->next;
        }
        q = prev->next;  // Nodul copil ce va fi eliminat
        printf("%d iese din joc: %s\n", ++contor, q->name);
        // Eliminăm nodul și refacem legăturile
        prev->next = q->next;
        free(q) ;
        // Mutăm head la următorul nod
        head = prev->next;
    }
    // Afișăm câștigătorul
    printf("\nA castigat %s\n", head->name);

    // Eliberăm ultimul nod rămas
    free(head);

    return 0;
}
