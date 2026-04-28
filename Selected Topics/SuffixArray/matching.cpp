#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{

    string text = "proiectarea algoritmilor de Cormen MIT";

    string pattern = "algo";

	vector<int> SA;

	for(int i = 0; i < text.size(); ++i) {
		SA.push_back(i);
	}
	
	
	

	cout<<"text: "<<text<<endl;
	cout<<"Pattern: "<<pattern;

    cout<<endl;

	sort(SA.begin(), SA.end(), 
		[&](int a, int b){
			return text.substr(a) < text.substr(b);
		}
	);

	//for(int i = 0; i < SA.size(); ++i) {
	//	cout<<SA[i]<<" ";
	//}

	int left = 0;
	int right = SA.size() - 1;

	bool found = false;

	while(left <= right) {

         int middle = (left+right)>>1; 

         int pos = SA[middle];

         string suffix = text.substr(pos);

         string prefix = suffix.substr(0, pattern.size());

         if(pattern == prefix) {
         	cout<<"Found At index: "<<pos<<"\n";
         	found = true;
         	break;
         }

         if(prefix < pattern) {
         	left = middle + 1;
         } else {
         	right = middle - 1;
         }
	}

	if(!found) cout<<"Not Found!";
	
	return 0;
}
