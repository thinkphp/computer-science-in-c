#include <iostream.h>
#include <conio.h>

void* readMatrix(int n,int m) {

      int (*adr)[10];

      adr = new int[10][10];

      for(int i=0;i<n;i++) {

	  for(int j=0;j<m;j++) {

	      cout<<"mat["<<i<<"]["<<j<<"]=";cin>>adr[i][j];
	  }
      }

   return adr;
}

void* sumMatrix(int n,int m, int (*adr1)[10],int (*adr2)[10]) {

      int (*adr)[10];

      adr = new int[10][10];

      for(int i=0;i<n;i++) {

	  for(int j=0;j<m;j++) {

	      adr[i][j] = adr1[i][j] + adr2[i][j];

	  }
      }

      return adr;
}

void displayMatrix(int n,int m, int (*adr)[10]) {

      for(int i=0;i<n;i++) {

	  for(int j=0;j<m;j++) {

	      cout<<adr[i][j]<<" ";
	  }

	  cout<<"\n";
      }
}


void main() {

     int n, m;

     int (*adr1)[10];

     int (*adr2)[10];

     int (*adr)[10];

     adr = new int[10][10];

     clrscr();

     cout<<"n=";cin>>n;

     cout<<"m=";cin>>m;

     adr1 = (int(*)[10])readMatrix(n,m);

     adr2 = (int(*)[10])readMatrix(n,m);

     adr = (int(*)[10])sumMatrix(n,m,adr1,adr2);

     cout<<"Display first matrix"<<"\n";
     displayMatrix(n,m,adr1);

     cout<<"Display second matrix"<<"\n";
     displayMatrix(n,m,adr2);

     cout<<"Sum:"<<"\n";
     displayMatrix(n,m,adr);

     cout<<"Press any key for exit";
     getch();
}