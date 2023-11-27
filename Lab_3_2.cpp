#include <iostream>
#include <vector>
using namespace std;

const int N = 4; // Количество вершин в четырехугольнике

// Функция для поиска оптимального пути и минимальной нагрузки 
void findOptimalPath(vector<vector<int>>& weights, vector<int>& optimalPath, int& minLoad) {

    // Создаем массив для хранения минимальных нагрузок 
    vector<vector<int>> dp(N, vector<int> (N, 0));

    // Инициализируем первую строку массива 
    dp[0][0] = weights[0][0];
    for (int j = 1; j < N; ++j) {
        dp[0][j] = dp[0][j - 1] + weights[0][j];
    }

    // Заполняем массив и находим минимальную нагрузку 
    for (int i = 1; i < N; ++i) {
        dp[i][0] = dp[i - 1][0] + weights[i][0];
        for (int j = 1; j < N; ++j) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1] + weights[i][j]);
        }
    }
    minLoad = dp[N - 1][N - 1]; // Минимальная нагрузка 

    // Восстанавливаем оптимальный путь 
    int i = N - 1, j = N - 1;
    optimalPath.push_back(N - 1);
    while (i > 0 || j > 0) {
        if (i == 0) {
            optimalPath.push_back(j - 1);
            --j;
        } else if (j == 0) {
            optimalPath.push_back(i - 1);
            --i;
        } else {
            if (dp[i - 1][j] < dp[i][j - 1]) {
                optimalPath.push_back(i - 1);
                --i;
            } else {
                optimalPath.push_back(j - 1);
                --j;
            }
        }
    }

    // Выводим оптимальный путь в обратном порядке 
    reverse(optimalPath.begin(), optimalPath.end());
}
int main() {

    // Пример входных данных (нагрузки на ребрах)
    vector<vector<int>> weights = {
        {1, 2, 3, 4},
        {3, 2, 1, 5},
        {2, 1, 4, 2},
        {4, 3, 2, 1}
    };
    vector<int> optimalPath;
    int minLoad;

    // Вызываем функцию поиска оптимального пути 
    findOptimalPath(weights, optimalPath, minLoad);

    // Выводим результат 
    cout << "Минимальная нагрузка: " << minLoad << endl;
    cout << "Оптимальный путь: ";
    for (int vertex : optimalPath) {
        cout << vertex << " ";
    }

    return 0;
}