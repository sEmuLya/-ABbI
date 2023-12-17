#include <iostream>
#include <vector>
#include <limits>
using namespace std;

// Приведение матрицы по строкам и столбцам
void reduceMatrix(vector<vector<int>>& matrix) {
    int n = matrix.size();
    // Вычитаем минимальное значение из каждой строки 
    for (int i = 0; i < n; i++) {
        int minVal = numeric_limits<int>::max();
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] < minVal) {
                minVal = matrix[i][j];
            }
        }
        for (int j = 0; j < n; j++) {
            matrix[i][j] -= minVal;
        }
    }
    // Вычитаем минимальное значение из каждого стобца
    for (int j = 0; j < n; j++) {
        int minVal = numeric_limits<int>::max();
        for (int i = 0; i < n; i++) {
            if (matrix[i][j] < minVal) {
                minVal = matrix[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            matrix[i][j] -= minVal;
        }
    }
}
// Оценка нулей в дополнительной матрице
int evaluateZerous(const vector<vector<int>>& matrix, int row, int col) {
    int n = matrix.size();
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (matrix[row][i] == 0) {
            count++;
        }
        if (matrix[i][row] == 0) {
            count++;
        }
    }
    return count - 2; // Исключаем двойное учета
}
// Последовательное построение тура с выяснением необходимых "запретов" на элементы матрицы
void buildTour(vector<vector<int>>& matrix, vector<int>& tour, int index, int& minCost) {
    int n = matrix.size();
    if (index == 0) {
        // Проверяем, что последняя вершина соединяется с первой
        if (matrix[tour[index - 1]][tour[0]] != 0) {
            return;
        }
        // Подсчитываем стоимость тура 
        int cost = 0;
        for (int i = 0; i < n - 1; i++) {
            cost += matrix[tour[i]][tour[i + 1]];
        }
        cost += matrix[tour[n - 1]][tour[0]];
        // Обновляем минимальную стоимость и тур, если найден более оптимальный 
        if (cost < minCost) {
            minCost = cost;
        }
        return;
    }
    for (int i = 1; i < n; i++) {
        if (matrix[tour[index - 1]][i] != 0) {
            continue;
        }
        if (find(tour.begin(), tour.end(), i) != tour.end()) {
            continue;
        }
        int zeros = evaluateZerous(matrix, tour[index - 1], i);
        if (zeros > n - 1 - index) {
            continue;
        }
        tour[index] = i;
        buildTour(matrix, tour, index + 1, minCost);
        tour[index] = -1;
    }
}
// Проход по первой ветке решений 
void branchAndBound(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<int> tour(n, -1); // Инициализируем пустыми значениями
    tour[0] = 0; // Начинаем с вершины 0
    int minCost = numeric_limits<int>::max();
    buildTour(matrix, tour, 1, minCost);
    cout << "Оптимальный тур: ";
    for (int i = 0; i < n; i++) {
        cout << tour[i] << " ";
    }
    cout << endl;
    cout << "Минимальная стоимость: " << minCost << endl;
}

int main() {
    int n;
    cout << "Введите количество вершин: "; cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    cout << "Введите матрицу расстояний: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    // Этап 1: Приведение матрицы по строкам и столбцам
    reduceMatrix(matrix);
    // Этап 2: Оценка нулей в дополнительной матрице

    // Этап 3: Построение тура с выяснением необходимых "запретов"

    // Этап 4: Проход по первой ветке решений
    branchAndBound(matrix);

    return 0;
}