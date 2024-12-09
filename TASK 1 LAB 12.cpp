#include <iostream>
#include <climits>
using namespace std;

const int MAX = 100;

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
        int minKey = INT_MAX, u;

        // Find the minimum key value from the set of vertices not yet included in MST
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
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the MST
    cout << "Edge \tCost\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << "\n";
    }
}

int main() {
    int V;

    // Scenario Context: Enter the number of neighborhoods (nodes)
    cout << "Enter the number of neighborhoods: ";
    cin >> V;

    int graph[MAX][MAX];

    // Scenario Input: Costs of power lines between neighborhoods
    cout << "Enter the cost matrix (0 if no power line exists between two neighborhoods):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    cout << "\nMinimum Cost Power Distribution Network:\n";
    primMST(graph, V);

    return 0;
}
