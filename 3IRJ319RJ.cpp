#include <iostream>
#include <climits>
using namespace std;

const int MAX = 100;

void dijkstra(int graph[MAX][MAX], int V, int src) {
    int dist[MAX];
    bool visited[MAX];
    int parent[MAX];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int minDist = INT_MAX, u;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && dist[v] < minDist) {
                minDist = dist[v];
                u = v;
            }
        }

        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !visited[v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "Distribution Center\tShortest Time\tPath\n";
    for (int i = 0; i < V; i++) {
        cout << i << "\t\t" << dist[i] << "\t\t";
        int temp = i;
        while (temp != -1) {
            cout << temp << " ";
            temp = parent[temp];
        }
        cout << "\n";
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

    int src = 0;

    cout << "\nFastest Routes from Main Distribution Hub:\n";
    dijkstra(graph, V, src);

    return 0;
}
