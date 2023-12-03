#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int>> distanceMatrix;
public:
    Graph(int v) : vertices(v), distanceMatrix(v, vector<int> (v, 0)) {}

    void addEdge(int u, int v, int weight) {
        distanceMatrix[u][v] = weight;
        distanceMatrix[v][u] = weight;
    }

    vector<pair<int, int>> findAllEdges() {
        vector<pair<int, int>> edges;
        for (int i = 0; i < vertices; ++i) {
            for (int j = i + 1; j < vertices; ++j) {
                if (distanceMatrix[i][j] != 0) {
                    edges.push_back({i, j});
                }
            }
        }
        return edges;
    }
};

int main() {
    // Пример использования программы 
    int numVertices = 4;
    Graph graph(numVertices);
    
    // Заполним матрицу расстояний графа (пример)
    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 2, 4);
    graph.addEdge(1, 2, 1);
    graph.addEdge(1, 3, 5);
    graph.addEdge(2, 3, 3);

    // Получим массив всех рёбер 
    vector<pair<int, int>> edges = graph.findAllEdges();

    // Выведем массив всех рёбер 
    cout << "Массив всех рёбер: " << endl;
    for (const auto& edge : edges) {
        cout << edge.first << " - " << edge.second << endl;
    }

    return 0;
}