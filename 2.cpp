#include <iostream>
#include <climits>
using namespace std;

const int MAX = 100;

void dijkstra(int graph[MAX][MAX], int V, int src) {
    int dist[MAX];
    bool visited[MAX];
    int parent[MAX];

    // Initialize distances to infinity and visited[] to false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
        parent[i] = -1;
    }

    // Distance to the source is 0
    dist[src] = 0;

    // Find the shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        int minDist = INT_MAX, u;

        // Find the vertex with the minimum distance from the set of unvisited vertices
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
            if (graph[u][v] && !visited[v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u; // Update parent to keep track of the shortest path
            }
        }
    }

    // Print the shortest distances and paths
    cout << "\nDistribution Center\tShortest Time\tPath\n";
    for (int i = 0; i < V; i++) {
        cout << "Center " << i << "\t\t" << dist[i] << "\t\t";
        int temp = i;
        // Print the path
        cout << "Path: ";
        string path = "";
        while (temp != -1) {
            path = to_string(temp) + " " + path;
            temp = parent[temp];
        }
        cout << path << "\n";
    }
}

int main() {
    int V = 4;
    int graph[MAX][MAX] = {
        {0, 5,  4, 0},
        {5, 0,  2, 6},
        {4, 2, 0, 3},
        {0, 6,  3,  0}
    };

    int src = 0;

    cout << "\nFastest Routes from Main Distribution Hub (Center " << src << "):\n";
    dijkstra(graph, V, src);

    return 0;
}
