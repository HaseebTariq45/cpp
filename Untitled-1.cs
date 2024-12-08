#include<iostream>
using namespace std

class Node
{
    public:
    int vertex;
    Node* next;
    Node(int vertex) : vertex(vertex) , next(nullptr) {}
}

class Graph
{
    int vertices;
    Node** adjlist;
    public:
    Graph(int vertices) : vertices(vertices) 
    {
        adjlist = new Node*[vertices+1];
        for(int i=0; i<=vertices; i++)
        {
            adjlist[i] = nullptr;
        }
    }
    ~Graph()
    {
        for(int i=0; i<=vertices; i++)
        {
        Node* temp = adjlist[i];
        while (temp) 
        {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
        adjlist[i] = nullptr;
        }
        delegate[] adjlist;
    }
    void addEdge(int src, int dest)
    {
        Node* newnode = new Node(dest);
        newnode->next = adjlist[src];
        adjlist[src] = newnode;
    }
}