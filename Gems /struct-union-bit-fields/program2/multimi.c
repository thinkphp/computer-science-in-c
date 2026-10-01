#include <stdio.h>
#define SIZE 100

typedef struct {

	int card;
	short set[SIZE];
} Set;

int belongs(int elem, Set X) {

	for(int i = 0; i < X.card; ++i) {

		if(X.set[i] == elem) return 1;		
	}

	return 0;
}

void read(Set *p) {

     printf("Enter the card of the set: ");
     scanf("%d",&p->card);

     for(int i = 0; i < p->card; ++i) scanf("%hd", &p->set[i]);
}

void display(char name[], Set p) {

	printf("%s \n", name);

	for(int i = 0; i < p.card; ++i) { 

		if(p.set[i])printf("%d ", p.set[i]);
	}	

		printf("\n");

}

int main(int argc, char const *argv[])
{

	Set A,B,I,D,R;
	A.card = 0;
	B.card = 0;
	D.card = 0;
	I.card = 0;
	

	read(&A);
	read(&B);

	R = B;	
	

	display("First Set:",A);
	display("Second Set: ",B);

	for(int i = 0; i < A.card; ++i) {

		if(belongs(A.set[i], B)) I.set[I.card++] = A.set[i];
		else {
			D.set[D.card++] = A.set[i];
			R.set[R.card++] = A.set[i];
		}
	}

	display("Intersection: ",I);
	display("Difference: ",D);
	display("Union: ",R);
	
	return 0;
}