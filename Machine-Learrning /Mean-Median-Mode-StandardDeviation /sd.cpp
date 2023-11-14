#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N;
    cin >> N;
    vector<int> v(N, 0);
    
    float m = 0;
    for(int n=0; n<N; n++){
        cin >> v[n];
        m += v[n]; 
    }
    m = m / N;
    
    float s = 0;
    for(int n=0; n<N; n++){        
        s += pow(v[n] - m, 2); 
    }    
    
    float sd = sqrt(s / N);
    printf("%0.1f", sd);
    
    
    return 0;
}
