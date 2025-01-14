#include <iostream>
using namespace std;


class Node
{
public:
    int node;
    Node* next;
    Node(int node) : node(node), next(nullptr) {}
};


class Graph
{
    int totalNodes;
    Node** adjlist;


public:
    Graph(int totalNodes) : totalNodes(totalNodes)
    {
        adjlist = new Node*[totalNodes + 1];
        for (int i = 0; i <= totalNodes; i++)
        {
            adjlist[i] = nullptr;
        }
    }


    void addEdge(int src, int dest)
    {
        Node* newnode = new Node(dest);
        newnode->next = adjlist[src];
        adjlist[src] = newnode;
    }


    void displayGraph() {
        for (int i = 1; i <= totalNodes; i++) {
            cout << "Adjacency List of Graph node " << i << ": ";
            Node* temp = adjlist[i];
            while (temp) {
                cout << temp->node << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};


int main()
{
    Graph g(12);


    g.addEdge(1, 5);
    g.addEdge(1, 6);
    g.addEdge(2, 3);
    g.addEdge(2, 7);
    g.addEdge(3, 4);
    g.addEdge(3, 7);
    g.addEdge(4, 7);
    g.addEdge(5, 9);
    g.addEdge(6, 2);
    g.addEdge(6, 7);
    g.addEdge(6, 9);
    g.addEdge(7, 8);
    g.addEdge(7, 10);
    g.addEdge(7, 11);
    g.addEdge(8, 11);
    g.addEdge(8, 12);
    g.addEdge(9, 10);
    g.addEdge(10, 11);
    g.addEdge(11, 12);


    g.displayGraph();


    return 0;
}


