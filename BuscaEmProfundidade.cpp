#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Estrutura para representar um grafo direcionado usando lista de adjacências
class Graph {
    int V; // Número de vértices

    // Vetor de listas de adjacências 
    vector<vector<int>> adj;

    void DFSUtil(int v, vector<bool>& visited); // Função auxiliar para busca em profundidade

public:
    Graph(int V); // Construtor

    void addEdge(int v, int w); // Adiciona uma aresta ao grafo

    void DFS(); // Executa a busca em profundidade no grafo
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::DFSUtil(int v, vector<bool>& visited) {
    // Marca o vértice atual como visitado e printa na tela
    visited[v] = true;
    cout << v << " ";

    // Recorrer para todos os vértices adjacentes não visitados
    for (int i = 0; i < adj[v].size(); ++i) {
        int adjacent = adj[v][i];
        if (!visited[adjacent])
            DFSUtil(adjacent, visited);
    }
}

void Graph::DFS() {
    // Marca todos os vértices como não visitados
    vector<bool> visited(V, false);

    // Chama a função auxiliar recursiva para imprimir a busca em profundidade
    for (int v = 0; v < V; ++v) {
        if (!visited[v])
            DFSUtil(v, visited);
    }
}

int main() {
    // Grafo
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


    cout << "Busca em Profundidade : ";
    g.DFS();

    return 0;
}