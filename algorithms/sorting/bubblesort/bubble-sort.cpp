#include <iostream.h>
#include <conio.h>
#include <fstream.h>

int* read(int n);
int* readFromFile();
void writeToFile(int *p);

void display(int *p);
void bubblesort(int *p);

fstream fin("c:\\bubble.in",ios::in),
	fout("c:\\bubble.out",ios::out);

int n, *p;

void main() {

     int *p;

     clrscr();

     p = readFromFile();

     cout<<"Input:\n";
     display(p);

     bubblesort(p);

     cout<<"\n\nOutput:\n";
     display(p);

     writeToFile(p);

     cout<<"\n\n\nPress any key for exit!";
     getch();
}


int* readFromFile() {

     int *v = new int[30];

     fin>>n;

     for(int i=0;i<n;i++) {

	 fin>>*(v+i);

     }

     fin.close();

  return v;
}

void display(int *v) {

     cout<<"\n";

     for(int i=0;i<n;i++) {

	 cout<<*(v+i)<<" ";
     }
}

void bubblesort(int *p) {

     int i,
	 j,
	 swapped = 1,
	 xor;

     for(j = n - 1; j > 0 && swapped; j--) {

         swapped = 0;

	 for(i = 0; i < j; i++) {

	    if( *(p+i) > *(p+i+1)) {

		xor = p[i]^p[i+1];

		*(p+i) = xor^p[i];

		p[i+1] = xor^p[i+1];

		swapped =1;

	    }   
	 }
     }

}

void writeToFile(int *p) {

     for(int i=0;i<n;i++) {

	 fout<<p[i]<<" ";
     }

     fout.close();
}

