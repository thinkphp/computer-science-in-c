#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[]) {

  float a, b, c, x1, x2;

  cout<<"Enter coefficients: a,b,c = ?";

  cin>>a>>b>>c;

  float S = -b/a,

        P = c/a,

        delta = b * b - 4 * a * c;

  cout<<"delta = "<<delta<<", Summa = "<<S<<" P = "<<P<<"\n";

  if( delta >= 0 )

  if( S > 0 ) {

      if( P > 0 ) {

        cout << " x1, x2 > 0 ";

      } else if( P < 0 ) {

        cout << "x1 < 0, x2 > 0, | x2 | > | x1 | ";

       //p = 0
      } else {

        cout << "x1 = 0, x2 > 0";
      }

  } else if( S < 0 ) {

    if(P > 0) {

      cout << "x1 < 0, x2 < 0";

    } else if( P < 0 ) {

      cout << "x1 > 0, x2 < 0 , | x1 | < | x2 |";

    //p = 0
    } else {

        cout << "x1 = 0, x2 < 0";
    }

  }


  //verification
  cout<<"\nVerification!\n";

  if( delta > 0 ) {

     x1 = (-b +sqrt(delta)) / (2 * a);

     x2 = (-b -sqrt(delta)) / (2 * a);

     cout<<"x1 = "<<x1<<", x2 = "<<x2<<" \n";

  } else if(delta == 0) {

     x1 = x2 = -b / 2 * a;

     cout<<"x1 = x2 = "<<x1;

  } else {

     float realPart = - b / 2 * a,

           imaginaryPart = sqrt(-delta) / 2 * a;

     cout<<"Roots are in Complex Numbers!\n";

     cout<<"x1 = "<<realPart<<" + "<<imaginaryPart<<" * i"<<"\n";

     cout<<"x2 = "<<realPart<<" - "<<imaginaryPart<<" * i"<<"\n";

  }


  return 0;
}
