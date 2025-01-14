#include<iostream>
using namespace std;
class Graph{
    int totalnodes;
    int** adjMatrix;

    public:
    Graph(int totalnodes) : totalnodes(totalnodes){
        adjMatrix = new int*[totalnodes+1];
        for (int i = 0; i < totalnodes; i++)
        {
            adjMatrix[i] = new int[totalnodes+1]();
        }
        
    }
    void addEdge(int src, int dest){
        if(adjMatrix[src][dest]==1){
            cout<<"Already Exists";
        }
        else{
            adjMatrix[src][dest] == 1;
            cout<<"Entered "<<src<<" "<<dest<<": in Graph ";
        }
    }
    void display()
    {
        cout<<"\nADjecency matrix ";
        for (int i = 0; i < totalnodes; i++)
        {
            for (int j = 0; j < totalnodes; j++)
            {
                cout<<adjMatrix[i}[j]<<" ";
            }
            cout<<endl;
            
        }
        
    }
};