#include <iostream>
#include <vector>
using namespace std;

int findMaxPathSum(const vector<vector<int>>& triangle) {
    int n = triangle.size();

    // Создаем копию треугольника для хранения промежуточных результатов 
    vector<vector<int>> dp(triangle);

    // Начинаем с предпоследнего ряда и двигаемся вверх
    for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; j <= i; ++j) {
            // Выбираем максимальное значение из двух соседних элементов в следующем ряду 
            // и прибавляем его к текущему элементу 
            dp[i][j] += max(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }

    // Максимальное значение будет в вершине треугольнике 
    return dp[0][0];
}
vector<int> findOptimalPath(const vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<vector<int>> dp(triangle);
    for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; j <= i; ++j) {
            dp[i][j] += max(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }
    vector<int> optimalPath;
    int i = 0, j = 0;

    // Собираем оптимальный путь 
    while (i < n - 1) {
        optimalPath.push_back(triangle[i][j]);
        if (dp[i + 1][j] > dp[i + 1][j + 1]) {
            // Переходим к следующему уровню, выбирая больший из двух соседних элементов
            ++i;
        } else {
            ++i;
            ++j;
        }
    }

    // Добавляем последний элемент 
    optimalPath.push_back(triangle[n - 1][j]);
    return optimalPath;
}
int main() {

    // Пример входных данных 
    vector<vector<int>> triangle = {
        {10},
        {2, 11},
        {4, 2, 1},
        {4, 7, 7, 4},
        {1, 0, 2, 10, 5}
    };
    int maxSum = findMaxPathSum(triangle);
    vector<int> optimalPath = findOptimalPath(triangle);

    // Вывод результатов 
    cout << "Максимальная сумма: " << maxSum << endl;
    cout << "Оптимальный путь: ";
    for (int vertex : optimalPath) {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}