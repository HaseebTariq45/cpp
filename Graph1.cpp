#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class graph
{
    public:
    unordered_map<int , list<int>> adj;
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }
    void Print()
    {
        for(auto i: adj){
            cout<<i.first <<"->";
            for(auto j: i.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
};
int main()
{
    graph g;
    
        g.addEdge(1,2);
    
    cout<<"\nPrinting Graph:\n";
    g.Print();
    
    return 0;
}