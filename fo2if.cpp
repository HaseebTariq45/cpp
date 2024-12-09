#include <iostream>
#include <climits>
using namespace std;

const int MAX = 100;

void primMST(int graph[MAX][MAX], int V) {
    int parent[MAX]; 
    int key[MAX];   
    bool visited[MAX]; 

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        visited[i] = false;
    }

    key[0] = 0;        
    parent[0] = -1;    

    for (int count = 0; count < V - 1; count++) {
        int minKey = INT_MAX, u;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    cout << "Edge \tCost\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << "\n";
    }
}

int main() {
    int V = 5;
    
    int graph[MAX][MAX] = {
        {0, 10, 20, 0, 0},
        {10, 0, 5, 15, 0},
        {20, 5, 0, 10, 30},
        {0, 15, 10, 0, 25},
        {0, 0, 30, 25, 0}
    };

    cout << "\nMinimum Cost Power Distribution Network:\n";
    primMST(graph, V);

    return 0;
}
