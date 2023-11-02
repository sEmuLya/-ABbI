#include <iostream> 
using namespace std;

// Рекурсивная функция для перемещения дисков 
// С первого штыряка на третий штыряк, используя вспомогательный второй штыряк 

void moveDisks(int n, int from, int to, int aux) {
    if (n == 1) {
        cout << "|" << " " << "Переместить диск 1 со стержня " << from << " на стержень " << to << "  " << "|" << endl;
        return;
    }
    moveDisks(n - 1, from, aux, to);
    cout << "|" << " " << "Переместить диск " << n << " cо стержня " << from << " на стержень " << to << "  " << "|" << endl;
    moveDisks(n - 1, aux, to, from);
}
int main () {
    setlocale(LC_ALL, "ru");
    int n;
    cout << "Введите количество дисков: "; 
    cin >> n;
    cout << " _______________________________________________" << endl;
    moveDisks(n, 1, 3, 2);
    cout << " -----------------------------------------------" << endl;
    cout << endl;
    cout << "Программа звершила работу. ";
    return 0;
}