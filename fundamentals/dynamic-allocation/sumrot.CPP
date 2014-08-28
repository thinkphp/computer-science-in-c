#include <iostream.h>
#include <conio.h>

int* read(int n);
void display(int n,int *p);
void rotate(int n, int *p);
long sum(int n,int *p,int k);
void free(int *p);

int v[20], n;


void main() {

     int *p;

     clrscr();
     cout<<"n=";
     cin>>n;

     p = read(n);

     display(n,p);

     cout<<sum(n, p, n-1);

     free(p);

     cout<<"\nPress any key for exit!";
     getch();

}
void free(int *p) {

     delete p;

}

int* read(int n) {

     int *v;

     v = new int[10];

     for(int i=0;i<n;i++) {

	 cout<<"v["<<i<<"]=";

	 cin>>*(v+i);
     }

   return v;
}

void display(int n,int *p) {

     for(int i = 0; i < n; i++) {

	 cout<<* ( p + i );
     }

     cout<<"\n";
}

long sum(int n,int *p,int k){

     long termen;

     if(k==0){

	return 0;

     }

     rotate(n,p);

     termen = 0;

       for(int i = 0; i < n; i++) {

	   termen = termen * 10 + p[i];
       }

       cout<<termen<<"\n";


   return termen + sum(n, p, k - 1);


}


void rotate(int n, int *v) {

     int aux = v[n-1];

     for(int k=n-1;k>=1;k--) {

	v[k] = v[k-1];

     }

     v[k] = aux;
}