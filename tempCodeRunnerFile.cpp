#include <iostream>
using namespace std;

const int MAX = 100;

struct Edge {
    int src, dest, weight;
};

struct DisjointSet {
    int parent[MAX], rank[MAX];

    void init(int V) {
        for (int i = 0; i < V; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int i) {
        if (parent[i] != i)
            parent[i] = find(parent[i]);
        return parent[i];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

bool compare(Edge e1, Edge e2) {
    return e1.weight < e2.weight;
}

void kruskal(int graph[MAX][MAX], int V, int E) {
    Edge edges[E];
    int edgeCount = 0;

    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (graph[i][j] != 0) {
                edges[edgeCount].src = i;
                edges[edgeCount].dest = j;
                edges[edgeCount].weight = graph[i][j];
                edgeCount++;
            }
        }
    }

    for (int i = 0; i < E - 1; i++) {
        for (int j = i + 1; j < E; j++) {
            if (compare(edges[j], edges[i])) {
                Edge temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }
        }
    }

    DisjointSet ds;
    ds.init(V);

    int mstWeight = 0;
    cout << "Cables to lay down for connecting cities:\n";

    for (int i = 0; i < E; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;

        if (ds.find(u) != ds.find(v)) {
            cout << "City " << u << " - City " << v << " : " << edges[i].weight << endl;
            mstWeight += edges[i].weight;
            ds.unionSets(u, v);
        }
    }

    cout << "Total cable-laying cost: " << mstWeight << endl;
}

int main() {
    int V = 5;
    int E = 7;

    int graph[MAX][MAX] = {
        {0, 10, 0, 0, 0},
        {10, 0, 15, 0, 0},
        {0, 15, 0, 20, 0},
        {0, 0, 20, 0, 25},
        {0, 0, 0, 25, 0}
    };

    cout << "\nMinimum cable-laying cost to connect all cities:\n";
    kruskal(graph, V, E);

    return 0;
}
