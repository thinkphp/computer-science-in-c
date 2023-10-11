#include <stdio.h>
#include <malloc.h>

typedef struct person {
        char name[50];
        struct person *next;
        struct person *prev;
} Person;

void create(Person**head) {

     Person *p,*q;
     int count;

     printf("%s", "Number of the kids:");
     scanf("%d", &count);

       *head = (Person*)malloc( sizeof( Person ) );
       printf("Name=");
       scanf("%s", (*head)->name);
       (*head)->next = *head;
       (*head)->prev = *head;
       p = *head;


      for (size_t i = 0;  i < count - 1; i++) {

           q = (Person*)malloc( sizeof( Person ) );
           printf("Name=");
           scanf("%s", q->name);
           //here I am doing the links
           q->next = *head;
           q->prev = p;
           (*head)->prev = q;
           p->next = q;
           p = q;
      }
}

void display(Person*head) {

     Person *temp = head;

     do {

         printf("%s ", head->name);

         head = head->next;

     } while( temp != head );
}

int main(int argc, char const *argv[]) {

  Person *head=NULL, *q;
  int number_of_syllables,
      count,
      sense = 1;//may be either 1 , either -1
  create(&head);
  /*
  Remove the first element from the Doubly Linked List
  q = head;
  head->next->prev = head->prev;
  head->prev->next = head->next;
  head = head->next;
  free(q);
  */
  display(head);

  printf("%s:", "Number of syllables");
  scanf("%d", &number_of_syllables);

   while(head!=head->next) {

      for(int i = 0; i < number_of_syllables-1; ++i)

            if(sense + 1) {
               head = head->next;
            } else {
               head = head->prev;
            }

      printf("%d#Out of game: %s\n",++count, head->name);

      //remake the links
      q = head;
      head->prev->next = head->next;
      head->next->prev = head->prev;

      if(sense+1) {
        head = head->next;
      } else {
        head = head->prev;
      }

      free(q);

      sense *= -1;
  }

  printf("The winner is ... %s\n", head->name);

  free(head);

  return 0;
}
