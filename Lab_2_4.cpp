#include <iostream>
#include <vector>
using namespace std;

const int Size = 10; // Размер доски

void PrintBoard(vector<vector<bool>> & board) {
    for (int i = 0; i < Size; ++i) {
        for (int j = 0; j < Size; ++j) {
            cout << (board[i][j] ? "Q" : ". ");
        }
        cout << endl;
    }
    cout << endl;
}
bool isSafe(int row, int col, vector<vector<bool>> & board) {
    // Проверяем вертикаль, горизонталь и диагонали 
    for (int i = 0; i < row; ++i) {
        if (board[i][col]) {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j]) {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j < Size; --i, ++j) {
        if (board[i][j]) {
            return false;
        }
    }
    return true;
}
void solveNQueens(int row, vector<vector<bool>> & board) {
    if (row == Size) {
        PrintBoard(board);
        return;
    }
    for (int col = 0; col < Size; ++col) {
        if (isSafe(row, col, board)) {
            board[row][col] = true; // Расставляем ферзя 
            solveNQueens(row + 1, board);
            board[row][col] = false; // Возвращаем ячейку назад 
        }
    }
}
void solveNQueens() {
    vector<vector<bool>> board(Size, vector<bool>(Size, false));
    solveNQueens (0, board);
}
int main () {
    solveNQueens();
    return 0;
}