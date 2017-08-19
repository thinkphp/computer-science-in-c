#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

void sortVector(vector<int> &arr) {
     int n = arr.size();

     bool swapped, 
          finished = false;  

    while(!finished) {
           swapped = false;
           for(int i = 0; i < n - 1; ++i) {

               if(arr[i] > arr[i+1]) {

                  arr[i] += arr[i+1];
                  arr[i+1] = arr[i] - arr[i+1];
                    arr[i] = arr[i] - arr[i+1];
                    swapped = true;
               }
           }  
           if( swapped ) n--;
               else finished = true; 
    }
}

void printVector(vector<int> arr) {

     cout<<endl;
     for(vector<int>::iterator it = arr.begin(); it != arr.end(); ++it) 

         cout<<*it<<" ";
};

//compiled with 
int main(int argc, const char *argv[]) {

    vector<int> arr;

    if( argc > 1) {

        for(int i = 1; i < argc; ++i) arr.push_back(atoi(argv[i]));

    } else vector<int> arr{9,8,7,6,5,4,3,2,1,0};
    
    printVector(arr); 
    sortVector(arr);
    printVector(arr); 

 return(0);
};