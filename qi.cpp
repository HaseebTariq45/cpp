#include <iostream>
using namespace std;

#define INF 1e9

class Node {
public:
    int vertex, weight;
    Node* next;
    Node(int vertex, int weight) : vertex(vertex), weight(weight), next(nullptr) {}
};

class Graph {
    int vertices;
    Node** adjlist;

public:
    Graph(int vertices) : vertices(vertices) {
        adjlist = new Node*[vertices + 1];
        for (int i = 0; i <= vertices; i++) {
            adjlist[i] = nullptr;
        }
    }

    ~Graph() {
        for (int i = 0; i <= vertices; i++) {
            Node* temp = adjlist[i];
            while (temp) {
                Node* next = temp->next;
                delete temp;
                temp = next;
            }
        }
        delete[] adjlist;
    }

    void addEdge(int src, int dest, int weight) {
        Node* newNode = new Node(dest, weight);
        newNode->next = adjlist[src];
        adjlist[src] = newNode;
    }

    void dijkstra(int src, int target) {
        int* distance = new int[vertices + 1];
        bool* visited = new bool[vertices + 1];
        int* parent = new int[vertices + 1];

        for (int i = 1; i <= vertices; i++) {
            distance[i] = INF;
            visited[i] = false;
            parent[i] = -1;
        }
        distance[src] = 0;

        for (int count = 1; count <= vertices; count++) {
            int u = -1;
            for (int i = 1; i <= vertices; i++) {
                if (!visited[i] && (u == -1 || distance[i] < distance[u])) {
                    u = i;
                }
            }

            if (u == -1 || distance[u] == INF) break;
            visited[u] = true;

            Node* temp = adjlist[u];
            while (temp) {
                int v = temp->vertex;
                int weight = temp->weight;
                if (!visited[v] && distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                    parent[v] = u;
                }
                temp = temp->next;
            }
        }

        if (distance[target] == INF) {
            cout << "Vertex " << target << " is unreachable from vertex " << src << "." << endl;
        } else {
            cout << "Shortest distance from vertex " << src << " to vertex " << target << ": " << distance[target] << endl;
            cout << "Path: ";
            printPath(target, parent);
            cout << endl;
        }

        delete[] distance;
        delete[] visited;
        delete[] parent;
    }

    void printPath(int vertex, int* parent) {
        if (parent[vertex] == -1) {
            cout << vertex;
            return;
        }
        printPath(parent[vertex], parent);
        cout << " -> " << vertex;
    }
};

int main() {

    Graph g(7);

    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 4);
    g.addEdge(2, 4, 3);
    g.addEdge(2, 5, 10);
    g.addEdge(3, 4, 2);
    g.addEdge(4, 2, 1);
    g.addEdge(4, 5, 2);
    g.addEdge(4, 6, 8);
    g.addEdge(4, 7, 4);
    g.addEdge(6, 5, 6);
    g.addEdge(7, 5, 6);

    g.dijkstra(1, 5);

    return 0;
}
