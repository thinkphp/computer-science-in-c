#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

void GnomeSort(vector<int> &arr) {

     int n = arr.size(), 
         pos = 0;

         while(pos < n) {
               if(pos == 0 || arr[pos] >= arr[pos-1]) pos++;
                        else {
                             int tmp = arr[pos];
                                 arr[pos] = arr[pos-1];
                                 arr[pos-1] = tmp;
                             pos--;
                        } 
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
    GnomeSort(arr);
    printVector(arr); 

 return(0);
};