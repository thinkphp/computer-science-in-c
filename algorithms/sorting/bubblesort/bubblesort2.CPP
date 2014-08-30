#include <iostream.h>
#include <conio.h>
#include <fstream.h>

/*

 Sorting by exchanging -> bubblesort

*/

//prototypes
void read();
void display();
void bubblesort();
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
     cout<<"Bubble Sort:\n\------------\n\nInput";

     //read from file
     read();

     //display on screen
     display();

     //do sorting method insertion sort
     bubblesort();

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

void bubblesort() {

     int i,
	 j,
	 xor;

     for(i = 0; i < n - 1; i++) {

	 for(j = i + 1; j < n; j++) {

	     if(v[ i ] > v[ j ]) {

		xor = v[i]^v[j];

		v[i] = xor^v[i];

		v[j] = xor^v[j];
	     }
	 }
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
