#include <iostream>
#include <vector>

using namespace std;

void generate(vector<int>& nums, int index, vector<int>& current, 
              int sum, int target) {

    // dacă suma este exact target → afișăm soluția
    if(sum == target) {
        for(int x : current)
            cout << x << " ";
        cout << endl;
        return;
    }

    // dacă depășim target → oprim (optimizare)
    if(sum > target) return;

    for(int i = index; i < nums.size(); ++i) {

        current.push_back(nums[i]);

        generate(nums, i + 1, current, sum + nums[i], target);

        current.pop_back();
    }
}

int main() {

    vector<int> nums = {1,2,3,4,5};
    
    vector<int> current;

    int target = 8; // suma dorită

    generate(nums, 0, current, 0, target);

    return 0;
}
