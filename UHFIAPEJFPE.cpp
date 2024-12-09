#include <iostream>
#include <climits> // For INT_MAX
using namespace std;

const int MAX = 100; // Define a maximum size for the graph

void primMST(int graph[MAX][MAX], int V) {
    int parent[MAX]; // Array to store the MST
    int key[MAX];    // Key values to pick minimum weight edge
    bool visited[MAX]; // Array to track visited vertices

    // Initialize all keys as INFINITE and visited as false
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        visited[i] = false;
    }

    // Start with the first vertex
    key[0] = 0;        // Include the first vertex in the MST by setting its key to 0
    parent[0] = -1;    // First vertex has no parent

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
        // Find the minimum key value from the set of vertices not yet included in MST
        int minKey = INT_MAX, u;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        // Mark the picked vertex as visited
        visited[u] = true;

        // Update key and parent arrays for adjacent vertices
        for (int v = 0; v < V; v++) {
            // Update the key only if graph[u][v] exists, v is not visited,
            // and graph[u][v] is smaller than key[v]
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the MST
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << "\n";
    }
}

int main() {
    int V; // Number of vertices in the graph

    cout << "Enter the number of vertices: ";
    cin >> V;

    int graph[MAX][MAX];

    cout << "Enter the adjacency matrix (use 0 for no edge):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    primMST(graph, V);

    return 0;
}
