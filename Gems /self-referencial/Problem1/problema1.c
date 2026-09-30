#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SIZE 50

typedef struct CELL{

	char word[ SIZE ];
	struct CELL *next;

} CELL;

char end[] = "?!.";
char word[SIZE];

int main(int argc, char const *argv[])
{

	CELL *head = NULL, *ptr;
	word[ 0 ] = '\0';
	int k = 0;
	char c;

    printf("Propozitia este: \n");

	do {
    //read a character
	scanf("%c", &c);

	if( isalpha(c) ) {

		word[k++] = c;

		word[k] = '\0'; 

	} else {

	 fprintf(stderr, "Am gasit un caracter care nu este litera: %c\n", c);

      if(k) {
        CELL *newCell = (CELL*)malloc(sizeof(CELL));
        strcpy(newCell->word, word);
        newCell->next = NULL;

        if(head == NULL) {
        	head = newCell;
        	ptr = newCell;
        } else {
        	ptr->next = newCell;
        	ptr = newCell;
        }

       } 

        k = 0;

        word[0] = '\0';	


	}

	} while(!strrchr(end, c));

    CELL *curr;

    curr = head;

    while(curr) {

    	printf("%s ", curr->word);

    	curr = curr->next;
    }  

    /*
    Free Memory
    */
    curr = head;

    while(curr) {
        free(curr);
    	curr = curr->next;
    }
	
	return 0;
}


