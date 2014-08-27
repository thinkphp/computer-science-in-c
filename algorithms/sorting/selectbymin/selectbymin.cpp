#include <iostream.h>
#include <conio.h>
#include <fstream.h>

/*

 Sorting Method Selection by Min

*/

void read();
void display();
void sort();
void write();

fstream fin("c:\\select.in",ios::in),
	fout("c:\\select.out",ios::out);

//declare an array of integers
int v[30],
    //store the number of elements
    n;

//main function
void main() {

     clrscr();

     cout<<"Input\n";

     read();

     display();

     sort();

     cout<<"\n\nOutput";

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

     //a var named i and onother var named j to iterate
     int i,
	 j,
	 //the minim item
	 min,
	 //position of the min
	 posMin;

     for(i=0;i<n-1;i++) {

	 min = v[i];
	 posMin = i;

	 for(j=i+1;j<n;j++) {

	     if(v[j]<min) {

		min = v[j];
		posMin = j;

	     }

	 }

       v[posMin] = v[i];

       v[i] = min;

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
