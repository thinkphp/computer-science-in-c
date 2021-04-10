#include <iostream>

using namespace std;

void divide(int lo, int hi, int &m) {

    m = (lo + hi) >> 1;
}

//solve recursively
void searchbin(int vec[], int left, int right, int x, int &pos) {

    int middle;

    if(left <= right) {

        //truncate the interval
        divide(left, right, middle);

        //compare the middle element
        if( vec[ middle ] == x) { pos = middle; }

        else if(x < vec[middle]) searchbin(vec, left, middle - 1, x, pos);

                       else
                                 searchbin(vec, middle + 1, right, x, pos);
    }

}

//solve recursively
int binsearch(int vec[], int lo, int hi, int x) {

    if(lo > hi) return -1;

    int m;

    m = (lo + hi) >> 1;

    if(vec[ m ] == x) return m + 1;

    else if(vec[ m ] > x) return binsearch(vec, lo, m - 1, x);

                  else

                          return binsearch(vec, m + 1, hi, x);
}

//solve iteratively
int _searchbin(int vec[], int left, int right, int x) {

     int pos = -1,
         m;

     while(left <= right) {

            m = (left + right) >> 1;
            
           if(vec[ m ] == x) {

                   pos = m;
                   break;
           }

           else if(vec[m] > x) {

                   right = m - 1;

           } else {

                   left = m + 1;
           }
     }

     return pos + 1;
}

int main(int argc, char const *argv[]) {

  int vec[] = {17,33,73,75,78,90,91,92,100},
      n,
      r,
      pos = -1;
  n = sizeof(vec)/sizeof(vec[0]);

  searchbin(vec, 0, n - 1, 91, pos);

  if(pos == -1) cout<<"Not Found!";

         else

               cout<<"Found [recursively] on position: " << pos+1;

  cout<<endl;
  r = binsearch(vec, 0, n - 1, 91);
  cout<<"[recursive] Find at position: "<<r<<endl;

  r = _searchbin(vec, 0, n - 1, 91);
  cout<<"[iterative] Find at position: "<<r<<endl;
  return 0;
}
