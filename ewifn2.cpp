#include <iostream>
#include <climits>
using namespace std;

const int MAX = 100;

void dijkstra(int graph[MAX][MAX], int V, int src) {
    int dist[MAX];       // Array to hold the shortest distances from src to all vertices
    bool visited[MAX];   // Array to track visited vertices
    int parent[MAX];     // Array to store the shortest path tree

    // Initialize distances to infinity and visited[] to false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
        parent[i] = -1;  // Initialize parent as -1 (no parent yet)
    }

    // Distance to the source is 0
    dist[src] = 0;

    // Find the shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Find the vertex with the minimum distance from the set of unvisited vertices
        int minDist = INT_MAX, u;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && dist[v] < minDist) {
                minDist = dist[v];
                u = v;
            }
        }

        // Mark the chosen vertex as visited
        visited[u] = true;

        // Update the distance value of adjacent vertices of the chosen vertex
        for (int v = 0; v < V; v++) {
            // Update dist[v] only if:
            // - There's an edge from u to v (graph[u][v] > 0)
            // - v is not visited
            // - The new path through u is shorter than the current dist[v]
            if (graph[u][v] && !visited[v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u; // Update parent to keep track of the shortest path
            }
        }
    }

    // Print the shortest distances and paths
    cout << "Vertex\tDistance\tPath\n";
    for (int i = 0; i < V; i++) {
        cout << i << "\t" << dist[i] << "\t\t";
        // Print the path
        int temp = i;
        while (temp != -1) {
            cout << temp << " ";
            temp = parent[temp];
        }
        cout << "\n";
    }
}

int main() {
    int V; // Number of vertices in the graph
    int src; // Source vertex

    cout << "Enter the number of vertices: ";
    cin >> V;

    int graph[MAX][MAX];

    cout << "Enter the adjacency matrix (use 0 for no edge):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    cout << "Enter the source vertex: ";
    cin >> src;

    dijkstra(graph, V, src);

    return 0;
}
