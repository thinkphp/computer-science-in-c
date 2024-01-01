/*
Find the sum of given two numbers A and B. if numberofDigit(A)==numberofDigit(A+B) then print A+B else Print A

Input Format

input contain two numbers(A and B) separated by space
*/

#include <iostream>
#include <string>

using namespace std;

int number_of_digits(long long n) {
    return to_string(n).length();
}

void find_sum_or_a(long long A, long long B) {
    long long sum_result = A + B;
    int digits_A = number_of_digits(A);
    int digits_sum = number_of_digits(sum_result);

    if (digits_A == digits_sum) {
        cout << sum_result << endl;
    } else {
        cout << A << endl;
    }
}

int main() {
    long long A, B;

    // Input
    string input;
    getline(cin, input);

    size_t space_pos = input.find(' ');
    if (space_pos != string::npos) {
        // If input is separated by spaces
        A = stoll(input.substr(0, space_pos));
        B = stoll(input.substr(space_pos + 1));
    } else {
        // If input is on separate lines
        A = stoll(input);
        cin >> B;
    }

    // Output
    find_sum_or_a(A, B);

    return 0;
}
