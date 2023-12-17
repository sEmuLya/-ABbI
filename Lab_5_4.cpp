#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Функция для топологической сортировки 
void topologicalSort(vector<vector<int>>& graph) {
    int V = graph.size();
    // Подсчет входящих степеней вершин 
    vector<int> inDegree(V, 0);
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (graph[i][j] == 1) {
                inDegree[j]++;
            }
        }
    }
    // Очередь для хранения вершин с нулевой входящей степенью 
    queue<int> q;
    for (int i = 0; i < V; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    // Топологическая сортировка 
    vector<int> result;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(u);
        for (int v = 0; v < V; ++v) {
            if (graph[u][v] == 1) {
                if (--inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }
    }
    // Вывод результата топологической сортировки 
    cout << "Результат топологической сортировки:\n";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
}
int main() {
    // Пример матрицы смежности графа
    vector<vector<int>> graph = {
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0}
    };

    topologicalSort(graph);

    return 0;
}