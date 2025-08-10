#include <iostream>
#include <stack>
#include <unordered_map>
#include <cassert>

using namespace std;

int isValid(string s){

	unordered_map<char, char> match = {
		{')','('}, {']','['}, {'}','{'}
	};

	stack<char> st;

	for(char c:s){
		if(match.count(c)) {
           if(st.empty() || match.at(c) != st.top()) {
           	return false;
           }
           st.pop();
		} else if (c == '(' || c == '[' || c == '{'){

			st.push(c);
		}
	}
return st.empty();
}

void runTests()
{
    #define EXPECT(expr, val) \
        do { \
            bool actual = (expr); \
            if (actual != (val)) { \
                std::cerr << "FAIL (" __FILE__ ":" << __LINE__ << ") " \
                          << #expr << " expected " << (val) << " got " << actual << '\n'; \
                assert(false); \
            } \
        } while (0)

    // 1. Basic true / false
    EXPECT(isValid(""), true);
    EXPECT(isValid("()"), true);
    EXPECT(isValid("()[]{}"), true);
    EXPECT(isValid("{[()]}"), true);
    EXPECT(isValid("([)]"), false);
    EXPECT(isValid("((("), false);

    // 2. Single-character edge cases
    EXPECT(isValid("("), false);
    EXPECT(isValid("]"), false);

    // 3. Deep nesting (balanced)
    const std::string deep(10000, '(');
    const std::string deepClose(10000, ')');
    EXPECT(isValid(deep + deepClose), true);

    // 4. Non-bracket noise
    EXPECT(isValid("a(b[c]d)e"), true);
    EXPECT(isValid("x{y(z)"), false);

    // 5. Unicode / UTF-8 chars that should be ignored
    EXPECT(isValid("(\u2764)"), true);   // ❤ inside
    EXPECT(isValid("{[💻]}"), true);      // laptop emoji
      
    #undef EXPECT
    std::cout << "All tests passed!\n";
}

int main(int argc, char const *argv[])
{
	cout<<"Valid Parantheses Problem\n";
    //string s = "[{(}]";
	//cout<<isValid(s);

	runTests();
	return 0;
}
