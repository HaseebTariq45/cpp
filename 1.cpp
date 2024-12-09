#include <iostream>
#include <climits>
using namespace std;

const int MAX = 100;

void primMST(int graph[MAX][MAX], int V) {
    int parent[MAX];
    int key[MAX];
    bool visited[MAX];

    // Initialize the key values and visited array
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        visited[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    // Prim's algorithm to find the MST
    for (int count = 0; count < V - 1; count++) {
        int minKey = INT_MAX, u;

        // Find the vertex with the minimum key value that hasn't been visited
        for (int v = 0; v < V; v++) {
            if (!visited[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        visited[u] = true;

        // Update the key values of adjacent vertices
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Display the result in a readable format
    cout << "\nMinimum Cost Power Distribution Network:\n";
    cout << "--------------------------------------------\n";
    cout << "Edge\t\t\tCost\n";
    cout << "--------------------------------------------\n";

   int t[] = {0};
    // Print the edges of the MST
    for (int i = 1; i < V; i++) {
        cout << "(" << parent[i] << " - " << i << ")\t\t" << graph[i][parent[i]] << endl;
        
    }
}

int main() {
    int V = 4;

    // Graph with 5 vertices
     int graph[MAX][MAX] = {
        {0, 5,  4, 0},
        {5, 0,  2, 2},
        {4, 2, 0, 3},
        {0, 2,  3,  0}
    };


    primMST(graph, V);

    return 0;
}
