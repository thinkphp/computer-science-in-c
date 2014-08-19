#include <iostream.h>
#include <conio.h>
#include <fstream.h>

/*

 Sorting by insertion technique

*/

//prototypes
void read();
void display();
void insertion();
void write();

//input
ifstream fin("c:\\file.in");

//output
ofstream fout("c:\\file.out");

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
     cout<<"Sorting by Insertion:\n\---------------------\n\nInput";

     //read from file
     read();

     //display on screen
     display();

     //do sorting method insertion sort
     insertion();

     //output the result
     cout<<"\n\nOutput";

     //display on screen
     display();

     //write to output File
     write();

     cout<<"\n\n\nPress any key for exit\nhttp://thinkphp.ro";
     getch();
}

void read() {

     fin>>n;

     for(int i=0;i<n;i++) {

	 fin>>v[i];
     }

     fin.close();
}

void insertion() {

     int i,j,aux;

     //walk from one position
     for(i=1;i<n;i++) {

	 //hold the item
	 aux = v[i];

	 //j is less with one
	 j = i - 1;

	 while(j>=0 && v[j]>aux) {

	       v[j+1] = v[j];

	       j--;
	 }

	 v[j+1] = aux;
     }
}

void write() {

     cout<<"\n";

     for(int i=0;i<n;i++) {

	 fout<<v[i]<<" ";
     }

     fout.close();
}

void display() {

     cout<<"\n";

     for(int i=0;i<n;i++) {

	 cout<<v[i]<<" ";
     }

}
