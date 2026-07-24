#include  <iostream>

using namespace std;

//             100     3 =>6,12,24,48,96=>
//                         2  4  8 16 32 + 1=33
int Divide(int a, int b) {

	int dividend = a, divisor = b, multiply, result = 0; 

	while(dividend >= divisor) {

		int temp = divisor;

		multiply = 1;

		while((temp << 1) <= dividend) {

			temp<<=1;

			multiply<<=1;
		}

		dividend-=temp;

		result+=multiply;
	}

	return result;
}

int main(int argc, char const *argv[])
{
	int a, b;

    cout<<"dividend = ";
	cin>>a;

    cout<<"Diviser =";
	cin>>b;

	cout<<Divide(a,b);
	return 0;
}
