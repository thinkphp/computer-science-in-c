#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int a,b,c,D;
    cin>>a>>b>>c;

    D = b*b - 4*a*c;     ///Discriminant of a quadratic equation

    if(D > 0)
    {
        cout<<"Real and Distinct"<<endl;
        cout<<((-b) - sqrt(D))/(2*a)<<" "<<((-b) + sqrt(D))/(2*a)<<endl;
    }

    else if(D==0)
    {
        cout<<"Real and Equal"<<endl;
        cout<<(-b)/(2*a)<<" "<<(-b)/(2*a)<<endl;
    }

    else if(D<0)
    {
        cout<<"Imaginary"<<endl;
    }
    return 0;
}
