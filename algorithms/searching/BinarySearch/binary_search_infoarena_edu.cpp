#include <bits/stdc++.h>
#define FIN "cautbin.in"
#define FOUT "cautbin.out"

using namespace std;

//returns the largest index such that arr[i] == key
// or -1 whether the key is not in the array
int binary_search0(int *arr, int lo, int hi, int key) {

    if(lo > hi) {
      return -1;
    }

    int middle = (lo+hi)>>1;

    if(arr[middle] == key) {

          if(middle < hi) {

               if(arr[middle+1] == key) {

                  return binary_search0(arr, middle+1, hi, key);

               } else {

                 return middle;
               }
          } else {

            return middle;
          }
    } else if(arr[middle] < key) {

          return binary_search0(arr, middle+1, hi, key);

    } else {

          return binary_search0(arr, lo, middle-1, key);
    }
}

//returns the largest index such as arr[i]<=key; such an index it will always exist.
int binary_search1(int *arr, int lo, int hi, int key) {


      if(lo > hi) {

        return -1;
      }

      int middle = (lo + hi) / 2;

      if(arr[middle] <= key) {

               if(middle < hi) {

                     if(arr[middle+1] > key) {

                       return middle;

                     } else {

                       return binary_search1(arr, middle + 1, hi, key);
                     }

               } else {

                 return middle;
               }

      } else {

        return binary_search1(arr, lo, middle-1, key);
      }

}

//returns the smallest index such as arr[i]>=key; such an index it will always exist.
int binary_search2(int *arr, int lo, int hi, int key) {

    if(lo > hi) {

      return -1;
    }

    int middle = (lo + hi) / 2;

    if(arr[middle] >= key) {

             if(lo < middle) {

                   if(arr[middle-1] < key) {

                     return middle;

                   } else {

                     return binary_search2(arr, lo, middle-1, key);
                   }

             } else {

               return middle;
             }

    } else {

      return binary_search2(arr, middle+1, hi, key);
    }
}

int main(int argc, char const *argv[]) {

  ifstream fin(FIN);
  ofstream fout(FOUT);

  typedef int (*fnPointer)(int*, int, int, int);

  int length;
  fin>>length;
  int array[length];

  for(int i = 0; i < length; ++i) fin>>array[i];

  fnPointer fn[ 3 ] = {binary_search0,binary_search1,binary_search2};

  int numOps;

  fin>>numOps;

  while(numOps--) {

    int op, value;

    fin>>op>>value;

    int index = fn[op](array, 0, length-1, value);

    if(index == -1) {

      fout<<index<<"\n";

    } else {

      fout<<index+1<<"\n";
    }
  }

   fin.close();
   fout.close();

   return 0;
 }
