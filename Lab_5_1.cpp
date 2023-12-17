#include <iostream>
using namespace std;

// Определение структуры узла списка 
struct Node {
    int data; // Значение узла
    Node* next; // Указатель на следующий узел 
    // Конструктор для узла 
    Node (int value) {
        data = value;
        next = nullptr;
    }
};
// Функция для добавления значения в конец списка 
void append(Node** headRef, int value) {
    Node* newNode = new Node(value);
    if (*headRef == nullptr) {
        *headRef = newNode;
    } else {
        Node* current = *headRef;
        while (current -> next != nullptr) {
            current = current -> next;
        }
        current -> next = newNode;
    }
}
// Функция для печати списка 
void printList(Node* head) {
    while (head != nullptr) {
        cout << head -> data << " ";
        head = head -> next;
    }
    cout << endl;
}
// Функция для слияния двух упорядоченных списков 
Node* mergeLists(Node* list1, Node* list2) {
    if (list1 == nullptr) {
        return list2;
    }
    if (list2 == nullptr) {
        return list1;
    }
    Node* mergedList = nullptr;
    // Определение головы списка 
    if (list1 -> data <= list2 -> data) {
        mergedList = list1;
        list1 = list1 -> next;
    } else {
        mergedList = list2;
        list2 = list2 -> next;
    }
    Node* temp = mergedList;
    // Слияние списков 
    while (list1 != nullptr && list2 != nullptr) {
        if (list1 -> data <= list2 -> data) {
            temp -> next = list1;
            list1 = list1 -> next;
        } else {
            temp -> next = list2;
            list2 = list2 -> next;
        }
        temp = temp -> next;
    }
    // Добавление оставшихся элементов (если они имеются)
    if (list1 != nullptr) {
        temp -> next = list1;
    }
    if (list2 != nullptr) {
        temp -> next = list2;
    }
    return mergedList;
}
int main() {
    // Создание и заполнение первого списка
    Node* list1 = nullptr;
    append(&list1, 1344);
    append(&list1, 3221);
    append(&list1, 5651);
    append(&list1, 7345);
    append(&list1, 9012);
    // Создание и заполнение второго списка 
    Node* list2 = nullptr;
    append(&list2, 1001);
    append(&list2, 4044);
    append(&list2, 5101);
    append(&list2, 1589);
    append(&list2, 1945);
    // Печать исходных списков 
    cout << "Первый список: ";
    printList(list1);
    cout << "Второй список: ";
    printList(list2);
    // Слияние списков 
    Node* mergedList = mergeLists(list1, list2);
    // Печать объединенного списка 
    cout << "Объединенный список: ";
    printList(mergedList);

    return 0;
}