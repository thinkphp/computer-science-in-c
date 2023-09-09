  #include <stdio.h>
  #include <string.h>
  #include <malloc.h>
  #include <ctype.h>

  typedef struct Node {
          char word[50];
          struct Node *next;
  } Node;

  Node *head,
       *head2;

  char end[3] = "?!.", word[50];

  int k = 0;

  char ch;

  int main(int argc, char const *argv[]) {

    do
    {
       scanf("%c", &ch);

       if(!isalpha(ch)) {

        if( k ) {

         Node *new_node = (Node*)malloc(sizeof(Node));
         strcpy(new_node->word, word);
         new_node->next = NULL;

         if(head == NULL) {

           head = new_node;

           head2 = new_node;

         } else {

            if(strcmp(head->word, new_node->word) > 0) {

              new_node->next = head;

              head = new_node;

            } else {

              Node *aux = head;

              while(aux->next && strcmp(aux->next->word, new_node->word) < 0) {

                  aux = aux->next;
              }

              if(aux->next) {

                new_node->next = aux->next;

                aux->next = new_node;

              } else {

                aux->next = new_node;
              }

            }
         }

         k = 0;
       }

       } else {

         word[k++] = toupper(ch); word[k] = '\0';

       }

    } while(!strrchr(end, ch));

    Node *temp;

    while(head) {

      temp = head;
      
      printf("%s ", head->word);

      head = head->next;

      free(temp);

    }
    return 0;
  }
