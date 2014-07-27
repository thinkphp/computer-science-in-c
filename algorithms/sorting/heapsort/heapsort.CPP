#include <iostream.h>
#include <conio.h>
#include <fstream.h>

//Prototypes Main Functions
void read();
void display();
void write();
void sort();
void heap();
void _minHeap(int i, int m);

fstream fin("c:\\file.in",ios::in),
	fout("c:\\file.out",ios::out);

int n, v[30];

void main() {

     clrscr();

     read();

     cout<<"\nInput:\n";
     display();

     heap();

     sort();

     cout<<"\nOutput:\n";
     display();

     //write to file sorted array
     write();

     cout<<"\n\n\nPress any key for exit!";
     getch();
}


void read() {

     fin>>n;

     for(int i=1;i<=n;i++) {

	 fin>>v[i];

     }

     fin.close();

}

void display() {

     cout<<"\n";

     for(int i=1;i<=n;i++) {

	 cout<<v[i]<<" ";
     }
}

void heap() {

     cout<<"\n";

     for(int i=n/2;i>=1;i--) {

	     _minHeap(i,n);
     }
}

void _minHeap(int node, int m) {

     int value = v[node], base = 2*node, ready = 0;

     while(base<=m && !ready) {

	  if(base < m && v[base+1] > v[base]) {

	     base++;
	  }

	  if(value < v[base]) {

             //swap two variables without using a temp variable
             //xor for the win
	     int xor=v[node]^v[base];

		 v[node] = xor^v[node];

		 v[base] = xor^v[base];

		 node = base;

		 base = base * 2;

	  } else {

		 ready = 1;
	  }
     }
}

void sort() {

     for(int i=n;i>1;i--) {

	     int xor = v[i]^v[1];

		 v[i] = xor^v[i];

		 v[1] = xor^v[1];

	     _minHeap(1,i-1);
     }
}

void write() {

     for(int i=1;i<=n;i++) {

	 fout<<v[i]<<" ";
     }

     fout.close();
}
