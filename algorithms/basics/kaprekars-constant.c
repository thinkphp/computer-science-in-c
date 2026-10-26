#include <stdio.h>

/*
# Problema „Constanta lui Kaprekar”

Se consideră un număr natural `n` format din exact 4 cifre, dintre care cel puțin două sunt diferite.

Se aplică următorul algoritm:

1. Se formează cel mai mare număr posibil folosind cifrele lui `n`, ordonate descrescător.
2. Se formează cel mai mic număr posibil folosind aceleași cifre, ordonate crescător.
3. Se scade numărul mai mic din cel mai mare.
4. Se repetă operațiile folosind rezultatul obținut, până când se ajunge la numărul `6174`.

**Cerință:** Scrieți un program C++ care citește numărul `n` și afișează fiecare pas al algoritmului, până la obținerea constantei lui Kaprekar `6174`, precum și numărul total de pași efectuați.

**Date de intrare:** Se citește un număr natural `n`, cu exact 4 cifre și cel puțin două cifre distincte.

**Date de ieșire:** Se afișează, pe câte o linie, fiecare scădere efectuată, iar la final numărul total de pași.

**Exemplu**

Date de intrare:
```
3524
```

Date de ieșire:
```
5432 - 2345 = 3087
8730 - 0378 = 8352
8532 - 2358 = 6174
Numar de pasi: 3
```

**Observație:** Numerele trebuie tratate ca având întotdeauna 4 cifre. De exemplu, `0378` trebuie păstrat cu zero la început atunci când se afișează. ...inc language
*/
int main(int argc, char const *argv[])
{

	int n, 
	    digits[4], 
	    small, 
	    great, 
	    steps = 0;

        printf("N = ");
	    scanf("%d", &n);

	    while( n != 6174 ) {

	    	//extragem cele 4 cifre
	    	for(int i = 0; i < 4; ++i) {
	    		digits[i] = n % 10;
	    		n /= 10; 
	    	}

            //sorting using BubbleSort
	    	for(int i = 0; i < 3; i++) {
	    		int swapped = 0;
	    		for(int j = 0; j < 3 - i; ++j) {
	    			if(digits[j] > digits[j+1]) {
	    				int temp = digits[j];
	    				digits[j] = digits[j+1];
	    				digits[j+1] = temp;
	    				swapped = 1;
	    			}
	    		}
	    		if(!swapped) break;
	    	}

	    	small = great = 0;

	    	for(int i = 0; i < 4; ++i) small = small * 10 + digits[i];

	    		for(int  i = 3; i >= 0; --i) great = great * 10 + digits[i];

	    			n = great - small;

	    		steps++;

	    		printf("%04d - %04d = %04d\n", great, small, n);
	    }

	    printf("steps = %d", steps);
	
	return 0;
}
