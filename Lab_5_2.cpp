#include <iostream>
using namespace std;

// Структура для представления узла односвязного списка
struct Node {
    int data;
    Node* next;
    // Конструктор 
    Node(int value) : data(value), next(nullptr) {}
};
// Функция для вывода содержимого списка
void printList(Node* head) {
    while (head) {
        cout << head -> data << " ";
        head = head -> next;
    }
    cout << endl;
}
// Функция для слияния двух упорядоченных списков
Node* mergeSortedLists(Node* list1, Node* list2) {
    Node dummy(0); // Фиктивный узел 
    Node* current = &dummy;
    while (list1 && list2) {
        if (list1 -> data < list2 -> data) {
            current -> next = list1;
            list1 = list1 -> next;
        } else {
            current -> next = list2;
            list2 = list2 -> next;
        }
        current = current -> next;
    }
    // Добавляем оставшиеся элементы
    current -> next = list1 ? list1 : list2;

    return dummy.next; // Возвращаем начало объединенного списка
}
// Функция для реализации стека на основе односвязного списка 
class Stack {
private:
    Node* top;
public:
    // Конструктор 
    Stack() : top(nullptr) {}
    // Помещение элемента на вершину стека
    void push(int value) {
        Node* newNode = new Node(value);
        newNode -> next = top;
        top = newNode;
    }
    // Извлечение элемента с вершины стека
    void pop() {
        if (top) {
            Node* temp = top;
            top = top -> next;
            delete temp;
        }
    }
    // Вывод содержимого стека
    void printStack() {
        cout << "Стек: ";
        printList(top);
    }
};
int main() {
    // Пример слияния двух упорядоченных списков
    Node* list1 = new Node(1);
    list1 -> next = new Node(3);
    list1 -> next -> next = new Node(5);
    Node* list2 = new Node(2);
    list2 -> next = new Node(4);
    list2 -> next -> next = new Node(6);
    cout << "Результирующий список: ";
    printList(mergeSortedLists(list1, list2));
    // Пример реализации стека на основе односвязного списка 
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.printStack();
    stack.pop();
    stack.printStack();

    return 0;
}