#include <iostream.h>
#include <conio.h>
#include <fstream.h>


//prototypes functions
void  read();
void  display();
void  write();
void  sort();
int  _divimp(int li,int ls);
void _merge(int li,int middle, int ls);

int n,

    v[100];

fstream fin("c:\\file.in",ios::in),

	fout("c:\\file.out",ios::out);

void main() {


     //firstly, clear screen
     clrscr();

     //read the vector
     read();

     //display the vector
     cout<<"Input:";
     display();

     //method merge sort in action
     sort();

     //display the sorted array
     cout<<"\nOutput:";
     display();

     //write to file.out
     write();

     //press any key for exit
     cout<<"\nPress any key for exit!";
     getch();
}

void read() {

     int i;

     fin>>n;

     for(i = 0; i < n; i++) {

	 fin>>v[i];
     }

     fin.close();
}

void display() {

     int i;

     cout<<"\n";

     for(i = 0; i < n; i++) {

	 cout<<v[i]<<" ";
     }

     cout<<"\n";
}

void sort() {

    _divimp(0,n-1);

}

int _divimp(int li,int ls){

     int middle;

     if(li == ls) {

	return v[li];

     } else {

       middle = (li+ls)/2;

       _divimp(li,middle);

       _divimp(middle+1,ls);

       _merge(li,middle,ls);

      return 1;
    }
}

void _merge(int li, int middle, int ls) {


     int i = li, j = middle + 1;

     int x[30], k = 0;


     while(i <= middle && j <= ls) {

	   if(v[i]<v[j]) {

	      x[k++] = v[i++];

	   } else {

	      x[k++] = v[j++];
	   }

     }

     if(i<=middle) {

	for(int p=i;p<=middle;p++) {

	    x[k++] = v[p];
	}


     } else {

	for(int p=j;p<=ls;p++) {

	    x[k++] = v[p];
	}

     }

     k = 0;

     for(int r=li;r<=ls;r++) {

	 v[r] = x[k++];
     }

}

void write() {

     int i;


     for(i = 0; i < n; i++) {

	 fout<<v[i]<<" ";
     }

     fout.close();

}