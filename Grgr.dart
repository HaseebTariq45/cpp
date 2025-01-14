#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node(int data) : data(data) , next(nullptr) {}
};

class Graph{
    int totalnodes;
    Node** adjlist;
    public:
    Graph(int totalnodes) : totalnodes(totalnodes){
       adjlist = new Node*[totalnodes+1];
       for(int i-0;i<=totalnodes;i++){
        adjlist[i] = nullptr;
       }
    }
    void addEdge(int src, int dest){
        Node* temp = adjlist[src];
        while (temp) {
            if(temp->data==dest){
                cout<<"\nEdge already Exists";
                return;
            }
            temp = temp->next;
        }
        Node* newnode = adjlist[dest];
        newnode->next = adjlist[src];
        adjlist[src] = newnode;
    }
    void hasEdge(int src, int dest){
        Node* temp = adjlist[src];
        while(temp){
            if (temp->data == dest) {
                cout<<"\nEdge found";
                return;
            }
            else {
                cout<<"\n Edge not found!!!";
            }
            temp = temp->next;
        }
    }
    void removeEdge(int src, int dest){
        Node* temp = adjlist[src];
        Node* prev = nullptr;

        while (temp && temp->data != dest) {
            prev = temp;
            temp = temp->next;
        }
        if (temp) {
            if(prev) prev->next = temp->next;
            else adjlist[src] = temp->next;
            cout<<"\nEdge removed sucessfully!!!!!";
            delete temp;
        }
        else {
            cout<<"\nEdge not found!!!";
        }
    }

};
int main()
{
    Graph g(12);
    g.addEdge(1, 5);
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
    cout<<"\nDisplaying\n";
    g.display();
    cout<<"Seeing if has Edge\n";
    g.hasEdge(10,15);
    cout<<endl;
    g.hasEdge(11,12);
    g.remove(11,12);
    g.remove(11,17);
}
