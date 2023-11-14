#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    cin>>n;
    
    vector<int> arr(n);
    int sum=0;
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    
    float mean=float(sum/n);
    
    float std_dev=0;
    
    for(int i=0;i<n;i++){
        std_dev+=(float(arr[i])-mean)*(float(arr[i])-mean);
    }
    
    std_dev/=n;
    
    std_dev=sqrt(std_dev);
    
    printf("%.1f",std_dev);
    return 0;
}
