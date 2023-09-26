#include <stdio.h>
#include <malloc.h>

typedef struct Node {
  int info;
  struct Node *next;
} Package;

void add_to_pack(Package**head, int nr, int *n) {
      Package *q = (Package*)malloc(sizeof(Package));
      q->info = nr;
      q->next = *head;
      *head = q;
      (*n)++;
}

void writeCards(Package*head) {
      while(head) {
        printf("%d ", head->info);
        head = head->next;
      }
}

void change(Package**head, int i1,int i2) {
  Package*p,*q;
  int min, max, aux;
  min = i1 < i2 ? i1 : i2;
  max = i1 + i2 - min;

  p = *head;
  while(p && min) {
    p = p->next;
    min--;
  }
  q = p;
  while(q && max) {
    q = q->next;
    max--;
  }
  if(q && p!=q) {
    aux = p->info;
    p->info = q->info;
    q->info = aux;
  }
}

void shuffle(Package**head) {
     srand(time(NULL));
     int count = rand()%100;
     int c1, c2;
     for(int i = 0; i < count; ++i) {
        c1 = rand()%53;
        c2 = rand()%53;
        if(c1-c2) change(head,c1,c2);
     }
}

int take_card(Package**head,int *n) {
    if(n) {
       int info = (*head)->info;
       Package*q;
       q = (*head);
       (*head) = (*head)->next;
       (*n)--;
       free(q);
       return info;
     } else {
       printf("Empty Package!");
       return -1;
     }
}

void transfer(int nr, char number[40],char colors[40]) {
     int i = nr;

     if(i < 52) {

        i = nr%13;

        if(i>=0 && i<=8) {

          printf(" %d ", i + 2);

        }  else {

           switch(i) {
             case 9: number = "AS"; break;
             case 10: number = "VALET"; break;
             case 11: number = "DAMA"; break;
             case 12: number = "POPA"; break;
           }
           printf(" %s", number);
        }
     }

     i = nr / 13;

     switch(i) {
       case 0: colors = "TREFLA"; break;
       case 1: colors = "CARO"; break;
       case 2: colors = "CUPA"; break;
       case 3: colors = "PICA"; break;
       default: colors = "JOKER";
     }
           printf(" %s  |", colors);
}

int main(int argc, char const *argv[]) {

  Package *head = NULL;
  int np = 5, nc = 8, nr, n = 0;

  for(int i = 0; i < 54; ++i)
      add_to_pack(&head, i, &n);
  printf("%s:\n", "Package");
  writeCards(head);
  printf("\n\n");
  shuffle(&head);
  printf("%s:\n", "Shuffle");
  writeCards(head);

  char number[40], color[40];

  for(int i = 0; i < np; ++i) {

      printf("\nPlayer number %d: \n", i+1);

      for(int j = 0; j < nc; ++j) {

          nr = take_card(&head,&n);

          transfer(nr, number, color);
      }

      printf("\n");
  }

printf("\n%s:\n", "The Remaining Pack Card");
writeCards(head);
printf("\n");
  return 0;
}
