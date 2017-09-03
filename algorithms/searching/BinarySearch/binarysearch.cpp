#include <iostream>
#include <vector>
#define SIZE 500005
#define BINARY_SEARCH_NOT_FOUND -1

using namespace std;

int BinarySearch(const vector<int> &arr, const int key) {

    if(arr.empty()) return BINARY_SEARCH_NOT_FOUND;

    int middleIndex = arr.size()/2;

    int middleValue = arr[ middleIndex ];

    if(key < middleValue) {  

       return BinarySearch(vector<int>(arr.begin(), arr.begin() + middleIndex), key);

    } else if( key > middleValue ) {

       int r = BinarySearch(vector<int>(arr.begin() + middleIndex + 1, arr.end()), key);

           return r == -1 ? r : r + middleIndex + 1;

    } else {

       return middleIndex; 
    }
};

int main() {

    int arr[] = {1,2,3,4,5,6,7,8,9};

    cout<<BinarySearch(vector<int>(arr, arr + sizeof(arr)/sizeof(int)), 10); 

 return(0);
};