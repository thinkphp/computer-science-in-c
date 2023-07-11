#include <iostream>
 
using namespace std;
 
int board[9][9];
 
struct pos {
    int x, y;
};
 
pos find_empty(int bo[9][9])
{
    pos result;
    result.x = -1;
    result.y = -1;
 
    for(auto i = 0; i < 9; i++)
        for(auto j = 0; j < 9; j++)
            if(bo[i][j] == 0) {
                result.x = i;
                result.y = j;
                return result;
            }
 
    return result;
}
 
bool valid(int bo[9][9], int num, pos position)
{
    int i, j;
 
    // check row
    for(i = 0; i < 9; i++)
        if(bo[position.x][i] == num && position.y != i)
            return false;
 
    // check column
    for(i = 0; i < 9; i++)
        if(bo[i][position.y] == num && position.x != i)
            return false;
 
    // check box
    int box_x = position.y / 3, box_y = position.x / 3;
 
    for(i = box_y * 3; i < box_y * 3 + 3; i++)
        for(j = box_x * 3; j < box_x * 3 + 3; j++)
            if(bo[i][j] == num && i != position.x && j != position.y)
                return false;
 
    return true;
}
 
bool backtracking(int bo[9][9])
{
    int row, col, i;
 
    pos find = find_empty(bo);
 
    if(find.x == -1)
        return true;
 
    row = find.x;
    col = find.y;
 
    for(i = 1; i < 10; i++) {
        if(valid(bo, i, find)) {
            bo[row][col] = i;
 
            if(backtracking(bo))
                return true;
 
            bo[row][col] = 0;
        }
    }
 
    return false;
}
 
int main(void)
{
    int i, j;
 
    for(i = 0; i < 9; i++)
        for(j = 0; j < 9; j++)
            cin >> board[i][j];
 
    backtracking(board);
 
    for(i = 0; i < 9; i++) {
        for(j = 0; j < 9; j++)
           cout << board[i][j] << " ";
        cout << endl;
    }
 
    return 0;
}
