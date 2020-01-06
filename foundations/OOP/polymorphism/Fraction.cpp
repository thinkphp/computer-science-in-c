#include <iostream>

class Base {
  
      public:

      int numarator, 
          numitor; 

      public: 
             Base(int a = 2, int b = 3) {

                  numarator = a;
                  numitor = b;                  
             };
      public:  
             void read() {

                 std::cin>>numarator>>numitor;
             }; 

             public: virtual int getNumarator() {return numarator;};

             public: virtual int getNumitor() {return numitor;};

             public: void display() {

                  std::cout<<getNumarator()<<"/"<<getNumitor();
             };

             ~Base() {
                   std::cout<<"Object destroyed!";
             }; 
};

class D: public Base {


             public:void read() {

                 std::cout<<"baga Fractia";

                 std::cin>>numarator>>numitor;
             }; 

             public: virtual int getNumarator() {return numarator + 1;};

             public: virtual int getNumitor() {return numitor + 1;};

 
};

	
int main() {

    D F;
    F.read();  
    F.display();
 
    return(0);
}
