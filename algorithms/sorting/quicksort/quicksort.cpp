#include <iostream.h>
#include <conio.h>
#include <fstream.h>
#include <stdlib.h>


//prototypes
void readArray();
void readArrayFromFile();
void readArrayFromGeneratedFile();

void displayArray();
void sort();
int partition(int li,int ls, int &k);
void qs(int li,int ls);

void generate();
int pick_random(int a,int b);

int i,

    n,

    v[100],

    pos;

fstream f("c:\\input.in",ios::in),

	g("c:\\output.out",ios::out),

	igen("c:\\GENERATE.in",ios::in),

	ogen("c:\\GENERATE.in",ios::out);


void main() {


     //firstly, clear screen
     clrscr();

     //generate an input file with random integers
     //generate();

     //read an array of positive integers
     readArrayFromFile();

     //read an array of positive integers
     //readArrayFromGeneratedFile();


     cout<<"Input:";
     //display on screen
     displayArray();

     //do sorting
     sort();

     //display the sorted array
     cout<<"\nOutput:";
     displayArray();


     //press any key for exit
     cout<<"\nPress any key for exit!";
     getch();
}

void readArray() {

     cout<<"n=";
     cin>>n;

     for(i = 0; i < n; i++) {

	 cout<<"v["<<i<<"]=";
	 cin>>v[i];
     }

}

void displayArray() {

     cout<<"\n";

     for(i = 0; i < n; i++) {

	 cout<<v[i]<<" ";
     }

     cout<<"\n";
}

void sort() {

    qs(0, n-1);
}

int partition(int li,int ls, int &pos) {

     int i,j,i1,j1,aux;

     i = li;
     j = ls;
     i1 = 0;
     j1 = -1;

	   while(i < j) {

		 if(v[i]>v[j]) {

		    aux = v[i];
		    v[i] = v[j];
		    v[j] = aux;

		    aux = i1;
		    i1 = -j1;
		    j1 = -aux;
		 }


	     i = i + i1;
	     j = j + j1;
	   }

  pos = i;
}

void qs(int li,int ls) {


     if(li<ls){
	partition(li, ls, pos);
	qs(li,pos-1);
	qs(pos+1,ls);
     }
}

void readArrayFromFile() {

     f>>n;

     for(int i = 0; i < n; i++) {

	f>>v[i];
     }

}

void generate(){

     int r;

     randomize();

     int number_of_elements;

     number_of_elements = (rand()%10)+3;

     ogen<<number_of_elements<<"\n";

     for(int i = 1; i <= number_of_elements; i++) {

	r = pick_random(1, 100);

	ogen<<r<<" ";
     }

     ogen.close();
}

int pick_random(int start,int end) {


    return rand()%(end-start)+start;
}



void readArrayFromGeneratedFile() {

     igen>>n;

     for(int i = 0; i < n; i++) {

	 igen>>v[i];
     }

     igen.close();
}


