#include <iostream>

using namespace std;

// first name space
namespace CHRONO {

  namespace SYSTEM_CLOCK {

     void now() {
       cout<<"inside function now for Namespace CHRONE";
     }

     void to_time_t() {

        cout << "Inside function to_time_t" << endl;
     }

     void get_func1() {
         cout << "Inside function get_func1()" << endl;
     }

     void get_func2() {
         cout << "Inside function get_func2()" << endl;
     }
  }
}


namespace CHRONO2 {

  namespace SYSTEM_CLOCK {

    void now() {
      cout<<"inside function now for Namespace CHRONE2";
    }

     void to_time_t() {

        cout << "Inside function to_time_t din Namespace CHRONO2" << endl;
     }

     void get_func1() {
         cout << "Inside function get_func1()  din Namespace CHRONO2" << endl;
     }

     void get_func2() {
         cout << "Inside function get_func2()   din Namespace CHRONO2" << endl;
     }
  }
}

// second name space
int main () {

   //:: operator de rezolutie
   CHRONO::SYSTEM_CLOCK::to_time_t();
   CHRONO::SYSTEM_CLOCK::get_func1();
   CHRONO::SYSTEM_CLOCK::get_func2();
   CHRONO::SYSTEM_CLOCK::now();

   CHRONO2::SYSTEM_CLOCK::to_time_t();
   CHRONO2::SYSTEM_CLOCK::get_func1();
   CHRONO2::SYSTEM_CLOCK::get_func2();
   CHRONO2::SYSTEM_CLOCK::now();
   return 0;
}
