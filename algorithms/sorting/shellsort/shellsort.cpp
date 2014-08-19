#include <iostream.h>
#include <conio.h>
#include <fstream.h>

/**
 *
 * Sorting by shell technique
 *
 */

void read();
void display();
void shellsort();
void write();

fstream fin("c:\\file.in",ios::in),
	fout("c:\\file.out",ios::out);

//declare an array of integers
int v[30],
    //store the number of elements
    n;

//main function
void main() {

     //clear screen
     clrscr();

     //intput
     cout<<"\nShell Sort Method\n";
     cout<<"-------------------\n";
     cout<<"Input\n\n";

     //step 1 read from file
     read();

     //step 2 display on screen the input
     display();

     //step 3 shell sorting in action
     shellsort();

     //step 4 display the sorted array on screen and write output to the file.out
     cout<<"\n\nOutput";
     write();

     //finally, press any key for exit
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

void shellsort() {

     int dist[5] = {7,5,3,1};

     for(int i = 0; i < sizeof(dist)/2-1; i++) {

	 int d = dist[i];

	 for(int j = d; j < n; j++) {

		 int aux = v[j];

		 for(int k=j-d;(k>=0 && v[k] > aux); k -=d) {

			 v[ k + d ] = v[ k ];
		 }

		 v[k + d] = aux;
	 }

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
