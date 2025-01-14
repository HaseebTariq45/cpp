#include <iostream>
using namespace std;

struct Edge {
    int src, dest, weight;
    Edge* next;
};

struct EdgeList {
    Edge* head;
};

Edge* createEdge(int src, int dest, int weight) {
    Edge* newEdge = new Edge;
    newEdge->src = src;
    newEdge->dest = dest;
    newEdge->weight = weight;
    newEdge->next = nullptr;
    return newEdge;
}

void insertEdge(EdgeList& list, int src, int dest, int weight) {
    Edge* newEdge = createEdge(src, dest, weight);
    if (!list.head || list.head->weight > weight) {
        newEdge->next = list.head;
        list.head = newEdge;
    } else {
        Edge* current = list.head;
        while (current->next && current->next->weight < weight) {
            current = current->next;
        }
        newEdge->next = current->next;
        current->next = newEdge;
    }
}

void printGraph(EdgeList& list) {
    cout << "Graph connections (source - destination : weight):\n";
    Edge* current = list.head;
    while (current) {
        cout<<"  "<< current->src << " - " << current->dest << " : " << current->weight << endl;
        current = current->next;
    }
    cout << endl;
}

int findParent(int parent[], int node) {
    if (parent[node] == node)
        return node;
    return findParent(parent, parent[node]);
}

void unionSets(int parent[], int rank[], int x, int y) {
    int xRoot = findParent(parent, x);
    int yRoot = findParent(parent, y);
    if (rank[xRoot] < rank[yRoot]) {
        parent[xRoot] = yRoot;
    } else if (rank[xRoot] > rank[yRoot]) {
        parent[yRoot] = xRoot;
    } else {
        parent[yRoot] = xRoot;
        rank[xRoot]++;
    }
}

void kruskal(EdgeList& list, int vertices) {
    int* parent = new int[vertices];
    int* rank = new int[vertices];
    for (int i = 0; i < vertices; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    Edge* mst = nullptr;
    Edge* tail = nullptr;
    int mstCost = 0;

    Edge* current = list.head;
    while (current) {
        int u = current->src;
        int v = current->dest;
        int uRoot = findParent(parent, u);
        int vRoot = findParent(parent, v);
        if (uRoot != vRoot) {
            if (!mst) {
                mst = createEdge(u, v, current->weight);
                tail = mst;
            } else {
                tail->next = createEdge(u, v, current->weight);
                tail = tail->next;
            }
            mstCost += current->weight;
            unionSets(parent, rank, uRoot, vRoot);
        }
        current = current->next;
    }

    cout << "Edges in the MST:\n";
    Edge* temp = mst;
    while (temp) {
        cout<<"  " << temp->src << " - " << temp->dest << " : " << temp->weight << endl;
        temp = temp->next;
    }
    cout << "Total cost of MST: " << mstCost << endl;

    delete[] parent;
    delete[] rank;
}

int main() {
    int vertices = 9;
    EdgeList edgeList = {nullptr};

    insertEdge(edgeList, 0, 1, 4);
    insertEdge(edgeList, 0, 7, 8);
    insertEdge(edgeList, 1, 2, 8);
    insertEdge(edgeList, 1, 7, 11);
    insertEdge(edgeList, 2, 3, 7);
    insertEdge(edgeList, 2, 8, 2);
    insertEdge(edgeList, 2, 5, 4);
    insertEdge(edgeList, 3, 4, 9);
    insertEdge(edgeList, 3, 5, 14);
    insertEdge(edgeList, 4, 5, 10);
    insertEdge(edgeList, 5, 6, 2);
    insertEdge(edgeList, 6, 7, 1);
    insertEdge(edgeList, 6, 8, 6);
    insertEdge(edgeList, 7, 8, 7);

    printGraph(edgeList);

    kruskal(edgeList, vertices);

    return 0;
}
