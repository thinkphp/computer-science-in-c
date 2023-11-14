#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N, temp, mode = 0;
    double mean = 0.0, median = 0.0;
    cin >> N;
    
    vector<int> arr;
    for(int i = 0; i < N; i++){
        cin >> temp;
        arr.push_back(temp);
        mean += temp;
    }
    
    sort(arr.begin(), arr.end());
    
    mean = mean / N;
    
    if(N % 2 == 0){
        median = (arr[N/2] + arr[N/2 - 1]) / 2.0;
    } else{
        median = arr[N/2 + 1];
    }
    
    int number = arr[0];
    mode = number;
    int count = 1, countMode = 1;
    for(int i = 1; i < N; i++){
        if(arr[i] == number){ //count occurrences of number
            count++;
        } else{ // now this is a different number
            if(count > countMode){
                countMode = count;
                mode = number;
            }
            count = 1;
            number = arr[i];
        }
    }
    
    cout << mean << endl;
    cout << median << endl;
    cout << mode << endl;
    
    return 0;
}
