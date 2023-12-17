#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Функция для обхода графа в ширину 
vector<int> breadthFirstSearch (const vector<vector<int>>& adjacencyMatrix, int startVertex) {
    int numVertices = adjacencyMatrix.size();
    vector<bool> visited(numVertices, false); // Массив для отслеживания посещенный вершин
    vector<int> result; // Результат обхода в ширину 
    // Cоздаем очередь для выполнения обхода в ширину 
    queue<int> q;
    // Начинаем с начальной вершины 
    q.push(startVertex);
    visited[startVertex] = true;
    while (!q.empty()) {
        int currentVertex = q.front();
        q.pop();
        result.push_back(currentVertex);
        // Обходим соседей текущей вершины 
        for (int neighbor = 0; neighbor < numVertices; ++neighbor) {
            if (adjacencyMatrix[currentVertex][neighbor] == 1 && !visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }

    return result;
}
int main() {
    // Пример использования 
    vector<vector<int>> adjacencyMatrix = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 1, 1},
        {0, 1, 1, 0, 1},
        {0, 0, 1, 1, 0}
    };
    int startVertex = 0; // Начальная вершина для обхода 
    vector<int> bfsResult = breadthFirstSearch(adjacencyMatrix, startVertex);
    // Выводим результат обхода 
    cout << "Результат выполнения алгоритма --> " << startVertex << ": ";
    for (int vertex : bfsResult) {
        cout << vertex << " ";
    }

    return 0;
}