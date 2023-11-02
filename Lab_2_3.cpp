#include <iostream>
#include <vector>
using namespace std; 

int b, k; // Количество строк (столбцов) доски и начальное положение коня
vector <vector<int>> board;
// Функция для проверки, что позиция (x, y) находится на доске
bool isValid(int x, int y) {
    return (x >= 0 && x < b && y >= 0 && y < b);
}
// Рекурсивная функция для заполнения матрицы номеров ходов коня 
void fillBoard(int x, int y, int move, int& q1) {
    board[x][y] = move;
    // Возможные варианты ходов коня 
    int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
    if (move >= b * b && q1 == 0) {
        q1 = 1;
        for (int i = 0; i < b; i++) {
            for (int j = 0; j < b; j++) {
                cout << board[i][j] << "\t";
            }
        cout << endl;
        } 
    cout << endl;
    board[x][y] = 0;
    return;
    }
    // Пробуем сделать каждый из возможных ходов 
    for (int i = 0; i < 8; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        if (isValid(newX, newY) && !board[newX][newY]) {
            // Проверяем, что новая позиция находится на доске и не была посещена ранее 
            fillBoard(newX, newY, move + 1, q1);
        }
    } 
    board[x][y] = 0;
}

int main() {
    setlocale(LC_ALL, "RUS");
    int k1;
    int move = 1;
    int q1 = 0;
    cout << "Введите количество строк (столбцов) доски: "; cin >> b;
    cout << "Введите начальное положение коня (номер строки доски): "; cin >> k;
    cout << "Введите начальное положение коня (номер столбца доски): "; cin >> k1;
    cout << "Матрица номеров ходов коня: " << endl;
    board.resize(b, vector<int>(b, 0)); // инициализируем матрицу -1
    fillBoard(k, k1, 1, q1); // Запускаем рекурсивную функцию 
    // Выводим матрицу номеров ходов коня 
    // cout << "Матрица номеров ходов коня: " << endl;
    if (q1 == 0) {
        cout << "Неверное начальное положение коня! ";
    }
    cout << endl;
    return 0;
}