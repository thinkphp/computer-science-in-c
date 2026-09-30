#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <ctype.h>
#define SIZE 30

typedef struct CELL{

	char word[SIZE];
	struct CELL *next;
} CELL;

CELL *head = NULL, 
     *aux = NULL;

int my_isalpha(char c) {
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}     

int main(int argc, char const *argv[])
{

	char c;

    char word[ SIZE ]; 

    int k = 0;   

    word[0]='\n';

    char end[4] = "?!.";

    do {

    	scanf("%c", &c);

    	if( my_isalpha( c ) ) {

    		word[k++] = c;

    		word[k] = '\0';

    	} else {

        if(k > 0) {

    		CELL *newCell = (CELL*)malloc(sizeof(CELL));

    		strcpy(newCell->word, word);

    		newCell->next = NULL;    	

    		if(head == NULL) {
    			head = newCell;
    			aux = newCell;
    		} else {
    			aux->next = newCell;
    			aux = newCell;
    		}

    		k = 0;

    		word[0] = '\0';
    	}	

    	}

    } while(!strrchr(end, c));


	CELL*curr = head;

	while(curr!=NULL) {
		printf("%s\n", curr->word);
		curr = curr->next;
	}

	while(head) {
		CELL *temp = head;
		head = head->next;
		free(temp);
	}
	return 0;
}