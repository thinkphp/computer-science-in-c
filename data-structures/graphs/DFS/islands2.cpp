#include <bits/stdc++.h>
#define COLS 5
#define ROWS 5

using namespace std;

int check(int M[][COLS],int i, int j, bool visited[][COLS]) {

    return i >=0 && i < ROWS &&
           j >= 0 && j < COLS &&
           M[i][j] && !visited[i][j];
}

void DFS(int M[][COLS], int i, int j, bool visited[][COLS]) {

     static int dx[] = {-1,-1,-1,0,0,1,1,1};
     static int dy[] = {-1,0,1,-1,1,-1,0,1};

     visited[i][j] = true;

     for(int k = 0; k < 8; ++k)

         if(check(M, i + dx[k], j + dy[k], visited)) {

              DFS(M, i + dx[k], j + dy[k], visited);
         }


}

int countIslands(int M[][COLS]) {

    bool visited[ROWS][COLS];

    memset(visited, 0, sizeof(visited));

    int count = 0;

    for(int i = 0; i < ROWS; ++i) {

        for(int j = 0; j < COLS; ++j) {

            if(M[i][j] && !visited[i][j]) {

              DFS(M, i, j, visited);

              count++;
            }
        }
    }


    return count;
}

int main(int argc, char const *argv[]) {

  int M[][COLS] = {{1,1,0,0,0},
                   {0,1,0,0,1},
                   {1,0,0,1,1},
                   {0,0,0,1,0},
                   {1,1,1,0,1}};

   cout<<"Number of the islands = "<<countIslands(M);

  return 0;
}
