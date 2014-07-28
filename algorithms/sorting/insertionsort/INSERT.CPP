#include <iostream.h>
#include <conio.h>
#include <fstream.h>

/*

 Sorting Method Insertion Sort

*/

//prototypes
void read();
void display();
void sort();
void write();

fstream fin("c:\\file.in",ios::in),
	fout("c:\\file.out",ios::out);

//declare an array of integers
//global vector
int v[30],
    //store the number of elements
    //global variable
    n;

//main function
void main() {

     //clear screen
     clrscr();

     //input array
     cout<<"Input\n";

     //read from file
     read();

     //display on screen
     display();

     //do sorting method insertion sort
     sort();

     //output the result
     cout<<"\n\nOutput";

     //write to output File
     write();

     cout<<"\n\n\nPress any key for exit";
     getch();
}

void read() {

     fin>>n;

     for(int i=0;i<n;i++) {

	 fin>>v[i];
     }

     fin.close();
}

void sort() {

     //i for iteration
     int i,

	 //j for iteration
	 j,

	 //aux variable
	 aux;

     for(i=1; i < n; i++) {

	 aux = v[i];

	 for(j = i-1; j >= 0; j--) {

	     if(aux > v[j]) {

	       v[j+1] = v[j];

	     } else {

	       break;
	     }

	 }

         v[j+1] = aux;

     }
}

void write() {

     cout<<"\n";

     for(int i=0;i<n;i++) {

	 cout<<v[i]<<" ";
	 fout<<v[i]<<" ";
     }

     fout.close();
}

void display() {

     for(int i=0;i<n;i++) {

	 cout<<v[i]<<" ";
     }

}
