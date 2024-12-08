#include<iostream>
using namespace std;
class Node
{
    int vertex;
    int weight;
    Node* next;
    Node(int vertex, int weight) : vertex(vertex), weight(weight), next(nullptr) {}
};
class Graph
{
    int vertices;
    Node** adjlist;
    public:
    Graph(int vertices) : vertices(v) 
    {
        adjlist = new Node*[vertices + 1];
        for (int i = 0; i <= vertices; i++)
        {
            adjlist[i] = nullptr;
        }
        
    }
};
int main()
{

    return 0;
}