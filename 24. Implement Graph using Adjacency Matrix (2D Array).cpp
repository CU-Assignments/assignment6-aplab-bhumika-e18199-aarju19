#include <iostream>
#include <vector>

class Graph {
private:
    int vertices;
    std::vector<std::vector<int>> adjMatrix;

public:
    Graph(int v) : vertices(v) {
        adjMatrix.resize(v, std::vector<int>(v, 0));
    }

    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    void display() {
        std::cout << "Adjacency Matrix:\n";
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                std::cout << adjMatrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    std::cout << "24. Implement Graph using Adjacency Matrix (2D Array)\n\n";

    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.display();
    
    return 0;
}
