#include <iostream>
#include <fstream>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define MAXN 500005

using namespace std;

//prototypes
void read();
void display();
void insertion();
void write();

//input
ifstream fin(FIN);

//output
ofstream fout(FOUT);

//declare an array of integers
//global vector
int v[ MAXN ],
    //store the number of elements
    //global variable
    n;

//main function
int main() {

     read();

     insertion();

     write();

    return(0);
}

void read() {

     fin>>n;

     for(int i = 0; i < n; i++) {

	 fin>>v[ i ];
     }

     fin.close();
}

void insertion() {

     int i,j,aux;

     int li,ls,middle;

     //binary search

     for(i = 1; i < n; i++) {

	 aux = v[i];

	 li = 0;

	 ls = i - 1;

	 while(li <= ls) {

	       middle = (li+ls)/2;

	       if(aux < v[ middle ]) {

		  ls = middle - 1;

	       } else{

		  li = middle + 1;
	       }
	 }

	 for(j = i - 1; j >= li; j--) {

	     v[ j + 1 ] = v[ j ];
	 }

	 v[ li ] = aux;
     }
}

void write() {

     cout<<"\n";

     for(int i=0;i<n;i++) {

	 fout<<v[i]<<" ";
     }

     fout.close();
}
