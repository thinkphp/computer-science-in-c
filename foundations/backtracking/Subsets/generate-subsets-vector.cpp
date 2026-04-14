#include <iostream>
#include <vector>

using namespace std;

void generate(vector<int>&nums, int index, vector<int>&current, vector<vector<int>>& Result) {

              Result.push_back(current);

              for(int i = index; i < nums.size(); ++i) {

              	      current.push_back(nums[i]);

              	      generate(nums, i + 1, current, Result);

              	      current.pop_back(); 
              }
}



int main(int argc, char const *argv[])
{
    vector<vector<int>> Result;

    vector<int> current = {};

    vector<int> nums = {1,2,3};

    generate(nums, 0, current, Result);

    for(auto subset: Result) {

    	for(int i = 0; i < subset.size(); ++i) {

    		cout<<subset[i]<<" ";
    	}
    	cout<<endl;
    }
	return 0;
}
