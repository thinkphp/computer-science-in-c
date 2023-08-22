#include <iostream>

using namespace std;

typedef struct Human {
	 int age,
	     salary;
} Student;

double an(int n) {
	   return 1./n+1;
}

double bn(int n) {
	   return (double)1/n+1;
}

double cn(int n) {
	   return (double)2 * n;
}

double dn(int n) {
	   return (double)2 * n + 1;
}

double en(int n) {
	   return n;
}

typedef double(*Sir)(int);

void display(Sir sir, int n) {
     double s = 0;
     for(int i = 1; i <= n; ++i) cout<<sir(i)<<" ", s += sir(i);
     cout<<" Sum = "<<s;
		 cout<<endl;
}

int main(int argc, char const *argv[])
{
	Student *arr[100];
	Student vec[100];
	//am declarat un vector de pointers catre tipul de baza Student

	arr[0] = new Student;
	arr[0]->age = 10;
	arr[0]->salary = 10;

	vec[0].age = 10;
	vec[0].salary = 10;

	cout<<arr[0]->age<< " - "<<arr[0]->salary<<endl;
	cout<<vec[0].age<< " - "<<vec[0].salary;

  int n;
	cout<<"\nn=";
  cin>>n;
  display(an, n);
	display(bn, n);
	display(cn, n);
	display(dn, n);
	display(en, n);
	return 0;
}
