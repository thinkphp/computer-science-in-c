#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define SIZE 30

typedef struct CELL {
        char word[SIZE];
        int count;
        struct CELL *next;
} CELL;

CELL *head = NULL,

     *aux = NULL;

char end[4] = "?!.";      

int is_letter(char c) {

	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int main( int argc, char const *argv[] )
{
    char ch;
    char word[ SIZE ];
	int k = 0;
	word[ 0 ] = '\0';

	do {
		if( scanf("%c", &ch) != 1) break;

		if(is_letter(ch)) {

			word[k++] = ch;

			word[k] = '\0';
			//it means we have a successor of the word

		} else {

			if(k > 0) {
				   
				   CELL *tmp = head;

				   while(tmp!= NULL && strcmp(tmp->word, word) != 0) {
				   	
                          tmp = tmp->next;
				   }

				   if(tmp) {

				   	tmp->count++;

				   } else {
				  
                      CELL *q = (CELL*)malloc(sizeof(CELL));
                      if(q == NULL) {printf("malloc");return 1;}
                      strcpy(q->word, word);
                      q->next = NULL;
                      q->count = 1;

                      if(head == NULL) {
                   	     head = q;
                   	     aux = q;
                      } else {
                   	     aux->next = q;
                   	     aux = q;
                      }

                   }

                   k = 0;
                   word[ 0 ] = '\0';

			}

		}
		

	} while( !strrchr( end, ch ) );

	CELL *curr = head;

	while(curr) {

		printf("%s - %d\n", curr->word, curr->count);

		curr = curr->next;

	}

	//free memory	
	while(head) {

          CELL *tmp = head;
          head = head->next;
          free(tmp);
	}
	printf("\n%s\n", "Free Memory Linked list");


	return 0;
}