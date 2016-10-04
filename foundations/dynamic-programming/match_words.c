/*   
 *   Adrian Statescu <mergesortv@gmail.com>
 *
 *   Match words
 *   Solved using Dynamic Programming Technique.  
 * 
 *   Problem 6.2 page 320 Basic C Programming
 * 
 *   Intr-un fisier se gaseste un text, structurat pe mai multe linii, format
 *   din cuvinte cu litere mici ale alfabetului englez, separate prin spatiu si/sau
 *   marcaje de sfarsit de linie. Scrieti un program care sa determine cea mai lunga
 *   insiruire de cuvinte din text, in ordinea in care acestea apar in textul dat, construita
 *   astfel incat, pentru oricare doua cuvinte consecutive, ultimele doua litere din primul cuvant
 *   sa coincida cu primele doua litere din urmatorul cuvant.
 * 
 *   INPUT: words.in se gasesc cel mult 1000 de cuvinte(fiecare din maximum 15 charactere si minimum doua caractere)
 *          separate prin spatii sau prin caracterul sfarsit de linie.
 *   OUTPUT: In fisierul words.out trebuie scrise, pe prima linie, numarul maxim de cuvinte ce formeaza sirul cerut, pe 
 *          urmatoarele linii, cuvintele acestui sir, in ordine, cate unul pe o linie
 */

#include <stdio.h>
#define FIN "match_words.in"
#define FOUT "match_words.out"
#define MAXSIZE 500

    typedef char String[100]; //define a datatype            
    String v[ MAXSIZE ]; //array of words
    int L[ MAXSIZE ], iMax, next[ MAXSIZE ];
    int i, j, n = 0;//this variable holds the number of words.


int matchWords(String s1, String s2) {

    return s1[strlen(s1)-2] == s2[0] && s1[strlen(s1)-1] == s2[1];   
}

//main function
int main() {


    //firstly we read the words in an array
    FILE *f = fopen(FIN, "r");
    //firstly we read the words in an array
    FILE *fout = fopen(FOUT, "w");


         //while not end of file do
         while(!feof(f)) {

                //read from file
                fscanf(f, "%s", &v[ n++ ]);
         }        

         //close the handler
         fclose(f);

    L[ n - 1 ] = 1;
    iMax = n - 1;
    next[ n - 1 ] = n;      

    for(i = n - 2; i >= 0; i--) {

        L[ i ] = 1;
        next[ i ] = n;

        for(j = i + 1; j < n; j++) {
            
            if(matchWords(v[i], v[j])) {

                L[ i ] = 1 + L[ j ];  

                next[ i ] = j;
            } 

            if(L[ i ] > L[ iMax ]) iMax = i;
        }         
    }

    fprintf(fout, "Max Length -> %d\n", L[iMax]);

    while( iMax != n ) {

       fprintf(fout, "%s\n", v[ iMax ]);

       iMax = next[ iMax ];
    }

 return(0);
}