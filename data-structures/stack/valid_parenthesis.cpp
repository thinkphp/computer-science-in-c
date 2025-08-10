#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

int isValid(string s){

	unordered_map<char, char> match = {
		{')','('}, {']','['}, {'}','{'}
	};

	stack<int> st;

	for(char c:s){
		if(match.count(c)) {
           if(st.empty() || match.at(c) != st.top()) {
           	return false;
           }
           st.pop();
		} else {

			st.push(c);
		}
	}
return st.empty();
}

int main(int argc, char const *argv[])
{
	cout<<"Valid Paranthesis Problem\n";
    string s = "[{(}]";
	cout<<isValid(s);
	return 0;
}
