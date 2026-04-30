#include <bits/stdc++.h>

using namespace std;

//Time Complexity O(sqrt(n)) Space O(n)
class SQRTDecomposition {

      private:
      vector<int> arr; //original vector;
      vector<int> block; //sume pe block;
      int n, B;//size and block size 
      public:
      SQRTDecomposition(vector<int>& input) {

          arr = input;
          n = input.size();
          B = sqrt(n)+1;
          block.resize(B + 5, 0);

          build();
          
      }

      void build() {

      	   for(int i = 0; i < n;++i) {

      	   	   block[ i / B ] += arr[i]; 
      	   }

      } 

      void update(int pos, int value) {

              block[pos/B] -= arr[pos];
              arr[pos] = value;
              block[pos/B] += arr[pos];   
      }

      int query(int left, int right) {

           int sum = 0;

           //mergem pana la capatul blocului din stanga
           while(left <= right && left % B != 0) { 
           	     sum += arr[left];
           	     left++;
           }	     

           //blocul complet
           while(left + B - 1 <= right) {
                 sum += block[left/B];	
                 left+=B;
           }
           //restul din dreapta

           while(left<=right) {
           	 sum+=arr[left];
           	 left++;
           }

           return sum;

      }

};

int main(int argc, char const *argv[])
{

	//ios::sync_with_stdio(false);

    //cin.tie(nullptr);

    int n;

    cout<<"n:";
    cin >> n;

    vector<int> v(n);

    for (auto &x : v) cin >> x;
	
    SQRTDecomposition sd( v );

    int q;

    cout<<"Queries = "; 
    cin >> q;

    while (q--) {
        int type;
        cout<<"Type: Query/Update: 1/2";
        cin >> type;

        if (type == 1) {
            int l, r;
            cout<<"Interval: l,r";
            cin >> l >> r;
            cout << sd.query(l, r) << "\n";
        } 
        else {
            int pos;
            long long val;
            cout<<"pos=?;val=?";
            cin >> pos >> val;
            sd.update(pos, val);
        }
    }
	return 0;
}
