#include <iostream>


using namespace std;

int matrix[2][101], ord[101], n, count = 1;

void sort() {
     int finished = 0, size = n, swapped;
     while(!finished) {
       swapped = 0;
       for(int i = 1; i < size; ++i) {
         if(matrix[1][ord[i]] > matrix[1][ord[i+1]]) {
            int temp = ord[i];
            ord[i] = ord[i+1];
            ord[i+1] = temp;
            swapped = 1;
         }
       }
       if(swapped) size--;
       else finished = 1;
     }
}

int main(int argc, char const *argv[]) {
  int hour1, min1, hour2, min2;
  cout<<"Number of Spectacles = ";
  cin>>n;
  for(int i = 1; i <= n; ++i) {
      ord[i] = i;
      cin>>hour1>>min1>>hour2>>min2;
      matrix[ 0 ][ i ] = hour1 * 60 + min1;
      matrix[ 1 ][ i ] = hour2 * 60 + min2;
  }

  for(int i = 1; i <= n; ++i) {

      cout<<ord[i]<<" "<<matrix[0][i]<<" "<<matrix[1][i]<<"\n";
  }

  for(int i = 1; i <= n; ++i) {

      cout<<ord[i]<<" ";
  }

  sort();

  cout<<endl;

  for(int i = 1; i <= n; ++i) {

      cout<<ord[i]<<" ";
  }

  cout<<endl;

  int curr = matrix[1][ord[1]];

  cout<<ord[1]<<" ";

  for(int i = 2; i <= n; ++i) {

      if(matrix[0][ord[i]] >= curr) {

        cout<<ord[ i ]<<" ";

        curr = matrix[ 1 ][ ord[ i ] ];

        count++;
      }
  }

  cout<<"Count = "<<count;

  return 0;
}
