#include<iostream>
#include<string.h>
#include <typeinfo>
#define size 10
using namespace std;
template <class Type>
//Stiva noastra propriu_zisa este Container
class Stack {
private:
	int varf_s;
	Type Container[size];
public:
	//constructor
	Stack()
	{
		cout<< "Se initializeaza stiva: \n";
		varf_s=0;
	}
	//destructor
	~Stack()
	{
		cout<< "Acesta este destructorul"<<"\n" ;
	}
	//metode membre
	void push(Type);
  Type pop();
};
 
// Inainte de a explicita fiecare functie trebuie sa scriem sablonul:
//													template<class Type>
template <class Type>
//			name_class<Type> operator de rezolutie (argumentul metodei)
//		  |
	void Stack<Type>::push(Type value)
//	 |
//	este void pt ca doar adauga in container
// La noi Value este de tip Type
{
	if(varf_s==size) {
		cout<<"Stiva este plina"<< "\n";
		return;
	}
	else {
		cout<< "Add to stack value: " << value<< "\n";
	}
 
  Container[varf_s] = value;
 
	varf_s++;
}
template <class Type> Type Stack<Type>::pop()
{
	if(varf_s == 0) {
      Type out;
      cout<< "Stiva este goala.\n";
      return out;
	}
  varf_s--;
  cout<< "Scot din stiva cointainer: "<<Container[varf_s]<< "\n";
	return Container[varf_s];
}
 
int main()
{
	//declaram o stiva de string
  Stack<string> stack_s;
  stack_s.push("Ubuntu");
  stack_s.push("Suze");
  stack_s.push("RedHat");
  stack_s.push("Debian");
	stack_s.push("Fedora");
  stack_s.pop();
	stack_s.pop();
	stack_s.pop();
  stack_s.pop();
  stack_s.pop();
	stack_s.pop();//aici stiva va fi goala
  stack_s.pop();
 
  //declaram o stiva de int
  cout<<endl;
  Stack<int> stack_int;
  stack_int.push(1);
	stack_int.push(2);
  stack_int.push(3);
  stack_int.pop();
  stack_int.pop();
  stack_int.pop();
 
  cout<<endl;
	//declaram o stiva de double
	Stack<double> stack_d;
	stack_d.push(45.78);
	stack_d.push(23.78);
	stack_d.push(23.11);
  stack_d.pop();
	stack_d.pop();
  stack_d.pop();
	stack_d.pop();
 
  cout<<endl;
	//declaram o stiva de float
	Stack<float> stack_f;
	stack_f.push(45.78);
	stack_f.push(23.78);
	stack_f.push(23.11);
	stack_f.pop();
	stack_f.pop();
	stack_f.pop();
	stack_f.pop();
 
  cout<<endl;
	//declaram o stiva de caractere
	Stack<char> stack_c;
	stack_c.push('A');
	stack_c.push('B');
	stack_c.pop();
	stack_c.pop();
	stack_c.pop();
 
  return(0);
}
