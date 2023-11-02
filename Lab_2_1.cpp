#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int Size_Array = 10; // Размерность массива 

// Объявляем рекурсивную функцию для поиска максимального элемента массива
int Max_Element(int arr[], int start, int end) {
    if (start == end) {
        return arr[start];
    } else {
        int mid = (start + end) / 2;
        int max1 = Max_Element(arr, start, mid); // рекурсивный вызов для первой половины массива
        int max2 = Max_Element(arr, mid + 1, end); // рекурсивный вызов для второй половины массива 
        return max(max1, max2); // возвращаем максимум из двух полученных значений 
    }
}
int main() {
    setlocale(LC_ALL, "ru");
    int arr[Size_Array];
    // Заполнение массива случайными числами 
    srand(time(nullptr));
    for (int i = 0; i < Size_Array; i++) {
        arr[i] = rand() % 101;
    }
    // Вывод исходного массива 
    cout << "Исходный массив: ";
    cout << "[ ";
    for (int i = 0; i < Size_Array; i++) {
        cout << arr[i] << " ";
    }
    cout << "]";
    cout << endl;
    // Вызов рекурсивной функции для поиска максимального элемента массива 
    int maxValue = Max_Element(arr, 0, Size_Array - 1);
    // Поиск номера элемента с максимальным значением 
    int maxIndex = 0;
    for (int i = 0; i < Size_Array; i++) {
        if (arr[i] == maxValue) {
            maxIndex = i;
            break;
        }
    }
    // Вывод результата
    cout << "Максимальный элемент массива: " << maxValue << endl;
    cout << "Индекс максимального элемента массива: " << maxIndex << endl;
}