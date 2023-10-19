#include <iostream>
#include <vector>
using namespace std;
class Matrix {

private:
    int rows_;
    int cols_;
    //matrice
    int data_[100][100];
    //vector<vector<int>>
public:
    Matrix(int rows, int cols) {
        rows_=rows,
        cols_=cols;
    }

    // Supraîncărcare operator adunare
    Matrix operator+(const Matrix& other) {
     Matrix result(rows_, cols_);
        for (int i = 0; i < rows_; ++i) {
            for (int j = 0; j < cols_; ++j) {
                result.data_[i][j] = data_[i][j] + other.data_[i][j];
            }
        }
        return result;
        }
        void Read_Matrix(){
            for(int i=0; i<rows_; i++)
                for(int j=0; j<cols_; j++) {
                    cin>>data_[i][j];
                }
        }
        void Display_Matrix() {
         for(int i=0; i<rows_; i++) {
                for(int j=0; j<cols_; j++) {
                    cout<<data_[i][j]<<" ";
                }
            cout<<"\n";
         }
       }

};

int main() {
    int rows, cols;

    cout << "Introduceti dimensiunile matricelor (randuri si coloane): ";
    cin >> rows >> cols;

    Matrix matrix1(rows, cols);
    Matrix matrix2(rows, cols);
    matrix1.Read_Matrix();
    matrix2.Read_Matrix();
    Matrix sum = matrix1 + matrix2;
    cout << "Suma celor doua matrici:\n";
    sum.Display_Matrix();

    return 0;
}
