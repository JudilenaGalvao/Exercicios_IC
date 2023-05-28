#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Estrutura para representar um grafo direcionado usando lista de adjacências
class Graph {
    int V; // Número de vértices
   
    vector<vector<int>> adj; // Vetor de listas de adjacências para representar o grafo

public:
    Graph(int V); // Construtor

    void addEdge(int v, int w); // Adiciona uma aresta ao grafo

    void BFS(int start); // Executa a busca em largura a partir de um vértice
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::BFS(int start) {
    // Marcar todos os vértices como não visitados
    vector<bool> visited(V, false);

    // Criar uma fila para a busca em largura
    queue<int> queue;

    // Marcar o vértice atual como visitado
    visited[start] = true;
    queue.push(start);

    while (!queue.empty()) {
        // Desenfileira um vértice da fila e printa na tela
        int current = queue.front();
        cout << current << " ";
        queue.pop();

        // Ver se um adjacente ainda não foi visitado, se não ele marca como visitado e enfileira
        for (int i = 0; i < adj[current].size(); ++i) {
            int adjacent = adj[current][i];
            if (!visited[adjacent]) {
                visited[adjacent] = true;
                queue.push(adjacent);
            }
        }
    }
}

int main() {
    //Grafo
    Graph g(11);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);
    g.addEdge(4, 7);
    g.addEdge(4, 8);
    g.addEdge(6, 9);
    g.addEdge(6, 10);

    cout << "Busca em Largura a partir do vértice 0: ";
    g.BFS(0);

    return 0;
}