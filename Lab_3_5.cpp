#include <iostream>
#include <vector>
using namespace std;

// Структура для предмета 
struct Item {
    int weight;
    int value;
};
// Функция для решения задачи о рюкзаке с использованием динамического программирования
void knapsack(int maxWeight, const vector<int>& weights, const vector<int>& values) {
    int n = weights.size();
    // Создаем двумерный массив для хранения результатов подзадач
    vector<vector<int>> dp(n + 1, vector<int> (maxWeight + 1, 0));
    // Заполняем массив
    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= maxWeight; ++w) {
            // Предмет не может быть взят, если его вес больше текущего веса рюкзака 
            if (weights[i - 1] > w) {
                dp[i][w] = dp[i - 1][w];
            }
            else {
                // Максимизируем полезность, выбирая максимум между включением и исключением предмета
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            }
        }
    }
    // Восстанавливаем решение, определяя, какие предметы были выбраны
    int result = dp[n][maxWeight];
    int remainingWeight = maxWeight;
    vector<int> selectedItems;
    for (int i = n; i > 0 && result > 0; --i) {
        if (result != dp[i - 1][remainingWeight]) {
            selectedItems.push_back(i - 1);
            result -= values[i - 1];
            remainingWeight -= weights[i - 1];
        }
    }
    // Выводим результат 
    cout << "Максимальная полезность: " << dp[n][maxWeight] << endl;
    cout << "Выбранные предметы: ";
    for (int i = selectedItems.size() - 1; i >= 0; --i) {
        cout << selectedItems[i] + 1 << " ";
    }
    cout << endl;
}
int main() {
    int maxWeight;
    cout << "Введите максимальный вес рюкзака: "; cin >> maxWeight;
    vector<int> weights = {2, 3, 4, 5};
    vector<int> values = {3, 4, 5, 6};

    knapsack(maxWeight, weights, values);

    return 0;
}
