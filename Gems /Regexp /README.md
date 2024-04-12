#### Regular Expressions:

Problem Set

Jabber ID https://codeforces.com/contest/21/problem/A 

* https://ideone.com/ct6Dky

```
// C++ program to demonstrate working of regex_match()
#include <iostream>
#include <regex>
 
using namespace std;
int main()
{
	string a = "GeeksForGeeks";
 
	// Here b is an object of regex (regular expression)
	regex b("(Geek)(.*)"); // Geek followed by any character
 
	// regex_match function matches string a against regex b
	if ( regex_match(a, b) )
		cout << "String 'a' matches regular expression 'b' \n";
 
	// regex_match function for matching a range in string 
	// against regex b
	if ( regex_match(a.begin(), a.end(), b) )
		cout << "String 'a' matches with regular expression "
				"'b' in the range from 0 to string end\n";
 
	return 0;
}
 
```
