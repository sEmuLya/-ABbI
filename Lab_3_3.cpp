#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Функция для оптимальной последовательности операций 
void optimalSequence(int n) {
    // Создаем массив для хранения оптимального количества операций 
    vector<int> dp(n + 1, INT_MAX);
    // Базовый случай: 0 операций для 0^0 
    dp[0] = 0;
    // Заполняем массив оптимальных значений 
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j * j <= i; ++j) {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }
    // Выводим оптимальное количество операций 
    cout << "Оптимальное количество операций: " << dp[n] << endl;
    // Восстанавливаем последовательность операций 
    cout << "Последовательность операций: ";
    while (n > 0) {
        int best_prev = 0;
        for (int j = 1; j * j <= n; ++j) {
            if (dp[n - j * j] < dp[n - best_prev * best_prev]) {
                best_prev = j;
            }
        }
        cout << best_prev << "^2 ";
        n -= best_prev * best_prev;
    }
}
int main() {
    int exponent;
    cout << "Введите степень числа: "; cin >> exponent;
    optimalSequence(exponent);
    return 0;
}