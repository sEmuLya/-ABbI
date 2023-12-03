#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// Структура для представляения ребра графа 
struct Edge {
    int start, end, weight;
    Edge(int s, int e, int w) : start(s), end(e), weight(w) {}
};

class Graph {
public:
    int vertices;
    vector<Edge> edges;
    Graph(int v) : vertices(v) {}
    // Метод добавления ребра в граф 
    void addEdge(int start, int end, int weight) {
        edges.push_back(Edge(start, end, weight));
    }

    // Алгоритм Прима-Краскала 
    pair<vector<Edge>, int> primMST() {
        // Сортируем ребра по весу 
        sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b){
            return a.weight < b.weight;
        });
        vector<Edge> result; // Массив для хранения ребер минимального остовного дерева
        vector<bool> visited(vertices, false); // Массив для отслеживания посещенных вершин 
        priority_queue<Edge, vector<Edge>, function<bool(Edge, Edge)>> pq(
            [](const Edge& a, const Edge& b) {
                return a.weight > b.weight;
            }
        );
        // Начинаем с первой вершины 
        visited[edges[0].start] = true;
        // Добавляем все ребра, исходящие из первой вершины, в очередь с приоритетами 
        for (const Edge& edge : edges) {
            if (edge.start == edges[0].start) {
                pq.push(edge);
            }
        }
        while (!pq.empty()) {
            Edge currentEdge = pq.top();
            pq.pop();
            // Если вершина ещё не посещена, добавляем ребро в результат и помечаем вершину как посещенную
            if (!visited[currentEdge.end]) {
                visited[currentEdge.end] = true;
                result.push_back(currentEdge);
                // Добавляем все ребра, исходящие из текущей вершины, в очередь с приоритетами 
                for (const Edge& edge : edges) {
                    if (edge.start == currentEdge.end && !visited[edge.end]) {
                        pq.push(edge);
                    }
                }
            }
        }
        // Вычисляем общий вес минимального остовного дерева
        int totalWeight = 0;
        for (const Edge& edge : result) {
            totalWeight += edge.weight;
        }
        return make_pair(result, totalWeight);
    }
}; 
int main() {
    // Пример использования 
    Graph graph(4);
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 6);
    graph.addEdge(0, 3, 5);
    graph.addEdge(1, 3, 15);
    graph.addEdge(2, 3, 4);

    auto result = graph.primMST();

    cout << "Минимальное остовное дерево: " << endl;
    for (const Edge& edge : result.first) {
        cout << edge.start << " - " << edge.end << " : " << edge.weight << endl;
    }
    cout << "Длина минимального остовного дерева: " << result.second << endl;

    return 0;
}