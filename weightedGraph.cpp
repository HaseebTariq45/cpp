#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    int w;
    Node* next;
    Node(int data,int w) : data(data),w(w), next(nullptr) {}
};
class Graph{

    int totalnodes;
    Node** adjlist;
    public:
    Graph(int totalnodes) : totalnodes(totalnodes){
        adjlist = new Node*[totalnodes+1];
        for (int i = 0; i <= totalnodes; i++)
        {
            adjlist[i] = nullptr;
        }
    }
    void addEdge(int src, int dest, int w){
        Node* temp = adjlist[src];
        while (temp)
        {
                if (temp->data==dest)
            {
                cout<<"\n Edge already Exists between"<< src << " and "<<dest<<"."<<endl;
            }
            temp = temp->next;
        }
        
        Node* newnode = new Node(dest,w);
        newnode->next = adjlist[src];
        adjlist[src] = newnode;
    }
    void display(){
        for (int i = 1; i <= totalnodes; i++)
        {
            cout<<"Adjacency list of graph node "<<i<<" :   ";
            Node* temp = adjlist[i];
            while (temp)
            {
                cout << "(" << temp->data << ", " << temp->w << ")  ";
                temp = temp->next ;
            }
            cout<<endl;
        }

    }
    
    void hasEdge(int src, int dest){
        Node* temp = adjlist[src];
       while(temp){
            if (temp->data == dest) {
                cout<<"\nEdge found";
                return;
            }
            else{
                cout<<"\nEdge not Found";
            }
            temp = temp->next;
        }
    }
    void remove(int src, int dest){
    Node* temp = adjlist[src];
    Node* prev = nullptr;

    while (temp && temp->data!=dest)
    {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp)
    {
        if(prev){
            prev->next = temp->next;
        }
        else
        {
            adjlist[src] = temp->next;
        }
        cout<<"\nEdge Removed successfully!!!!!";
        delete temp;
    }
    else
    {
        cout<<"\nNo edge found";
    }
    
}
};
int main()
{
    Graph g(12);
    g.addEdge(1, 5, 10); // Adding weighted edge
    g.addEdge(1, 6, 20);
    g.addEdge(2, 3, 5);
    g.addEdge(2, 7, 15);
    g.addEdge(3, 4, 30);
    g.addEdge(3, 7, 25);
    g.addEdge(4, 7, 50);
    g.addEdge(5, 9, 40);
    g.addEdge(6, 2, 60);
    g.addEdge(6, 7, 35);
    g.addEdge(6, 9, 45);
    g.addEdge(7, 8, 55);
    g.addEdge(7, 10, 65);
    g.addEdge(7, 11, 75);
    g.addEdge(8, 11, 85);
    g.addEdge(8, 12, 95);
    g.addEdge(9, 10, 100);
    g.addEdge(10, 11, 110);
    g.addEdge(11, 12, 120);

    cout << "\nDisplaying Graph with weights:\n";
    g.display();

    cout << "\nChecking if edge exists:\n";
    g.hasEdge(10, 15);
    g.hasEdge(11, 12);

    g.remove(11, 12);
    g.remove(11, 17);
}
