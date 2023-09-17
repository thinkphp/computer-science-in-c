#include <iostream>
class Matrix {
private:
  int mat[100][100];
  int n, m;
public:
  Matrix(int a, int b) {
    n = a;
    m = b;
  }
  Matrix operator*(Matrix mat);
  int& operator()(int a, int b) {
    return mat[a][b];
  }
  void display() {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j)
            std::cout<<mat[i][j]<<" ";
         std::cout<<std::endl;
     }
  }
};

Matrix Matrix::operator*(Matrix mat2) {
       Matrix prod(3,3);
       for(int i = 0; i < n; ++i)
           for(int j = 0; j < m; ++j) {
             for(int k = 0; k < m; ++k)
                 prod.mat[i][j] += mat[i][k] * mat2.mat[k][j];
           }
       return prod;
};

class Vector2 {
      private:
      int v[100], //the data are private
          n;//the size of the vector
      public:
        Vector2(int size) {
          n = size;
        }
        int& operator[](int index);
        void sort();
        void swap(int*a,int*b) {
           int aux;
           aux = *a;
           *a = *b;
           *b = aux;
        }
};

int& Vector2::operator[](int index) {
    return v[index];
}

void Vector2::sort() {

     int finished = 0,
         swapped, size = n;

     while(!finished) {
       swapped = 0;
       for(int i = 0; i < size - 1; ++i) {
         if(v[i] > v[i+1]) {
           swap(&v[i], &v[i+1]);
           swapped = 1;
         }
       }

       if(swapped) size--;else finished = 1;
     }
}

class Vector {
      private:
      int v[100];
      public:
        void set(int index, int value);
        int get(int index);
};

void Vector::set(int index, int value) {
  v[index] = value;
}
int Vector::get(int index) {
  return v[index];
}

int main(int argc, char const *argv[]) {

  Vector arr;
  arr.set(0,1);
  arr.set(0,2);
  //std::cout<<arr.get(0);

  //Vector2 vec(10);
  //for(int i = 0; i < 10; ++i) std::cin>>vec[i];
  //vec.sort();
  //for(int i = 0; i < 10; ++i) std::cout<<vec[i]<<" ";


  Matrix mat1(3,3),
         mat2(3,3);

  for(int i = 0; i < 3; ++i)
      for(int j = 0; j < 3; ++j)
          std::cin>>mat1(i,j);

          for(int i = 0; i < 3; ++i)
              for(int j = 0; j < 3; ++j)
                  std::cin>>mat2(i,j);

  std::cout<<"Matrix 1:\n";
  mat1.display();
  std::cout<<"Matrix 2:\n";
  mat2.display(); 
  Matrix prod(3,3);
  prod = mat1 * mat2;
  std::cout<<"Matrix Multplication:\n";
  prod.display();
  return 0;
}
