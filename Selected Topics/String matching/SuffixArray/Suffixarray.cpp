#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    string text = "banana";
    string pattern = "ana";

    vector<int> SA;

    // construim suffix array
    for(int i = 0; i < text.size(); i++) {
        SA.push_back(i);
    }

    sort(SA.begin(), SA.end(),
        [&](int a, int b) {
            return text.substr(a) < text.substr(b);
        });

    // binary search
    int left = 0;
    int right = SA.size() - 1;

    bool found = false;

    while(left <= right) {

        int mid = (left + right) / 2;

        int pos = SA[mid];

        string suffix = text.substr(pos);

        string prefix = suffix.substr(0, pattern.size());

        if(prefix == pattern) {

            cout << "Gasit la index: "
                 << pos << '\n';

            found = true;
            break;
        }

        if(prefix < pattern)
            left = mid + 1;
        else
            right = mid - 1;
    }

    if(!found)
        cout << "Pattern negasit\n";

    return 0;
}
