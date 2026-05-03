#include <iostream>
#define SIZE 10

using namespace std;

int mat[SIZE][SIZE], n, m;

void fill(int x, int y, int oldColor, int newColor) {

          if(x < 0 || y < 0 || x >= n || y >= m ) return;

          if(mat[x][y] != oldColor) return;

          mat[x][y] = newColor; 

          fill(x+1, y, oldColor, newColor);
          fill(x-1, y, oldColor, newColor);
          fill(x, y+1, oldColor, newColor);
          fill(x, y-1, oldColor, newColor);

}


void printMatrix() {
     for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
     }
}

int main(int argc, char const *argv[])
{
   n = 5;
   m = 6;

   int temp[5][6] = {
        {1, 1, 1, 2, 2, 2},
        {1, 1, 0, 2, 2, 2},
        {1, 0, 0, 2, 3, 3},
        {1, 1, 0, 3, 3, 3},
        {1, 1, 1, 3, 3, 3}
    };

      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            mat[i][j] = temp[i][j];
        }        
     }
    printMatrix();

    int startX = 0, startY = 3;
    int newColor = 9;
    int oldColor = mat[startX][startY];
        
    cout<<"Fill Algorithm:\n";

    fill(startX, startY, oldColor, newColor);
    printMatrix();    

    return 0;
}
