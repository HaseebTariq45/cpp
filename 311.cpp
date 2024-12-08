#include <iostream>
#include <iomanip>
#include <queue>
using namespace std;

class Graph {
public:
    bool** AjdMatrix;
    int numOfV;

    // Constructor
    Graph(int numOfV) {
        this->numOfV = numOfV;
        AjdMatrix = new bool*[numOfV];
        for(int i = 0; i < numOfV; i++) {
            AjdMatrix[i] = new bool[numOfV];
            for(int j = 0; j < numOfV; j++) {
                AjdMatrix[i][j] = false;
            }
        }
    }

    void addEdge(int i, int j) {
        AjdMatrix[i][j] = true;
        AjdMatrix[j][i] = true;
    }

    void Print() {
        cout << "Adjacency Matrix Representation:\n";
        cout << "    ";
        for(int j = 0; j < numOfV; j++) {
            cout << "V" << j << " ";
        }
        cout << "\n";

        cout << "    ";
        for(int j = 0; j < numOfV; j++) {
            cout << "-- ";
        }
        cout << "\n";

        for(int i = 0; i < numOfV; i++) {
            cout << "V" << i << " | ";
            for(int j = 0; j < numOfV; j++) {
                cout << AjdMatrix[i][j] << " ";
            }
            cout << "\n";
        }
    }

    void bfs(int s) {
        // Create a queue for BFS
        queue<int> q;  
        
        
        bool* visited = new bool[numOfV];
        for(int i = 0; i < numOfV; i++) {
            visited[i] = false; 
        }

       
        visited[s] = true;
        q.push(s);

        // Store the order of BFS traversal
        cout << "BFS Traversal Order: ";
        while (!q.empty()) {
           
            int curr = q.front();
            q.pop();
            cout << curr << " ";

          
            for (int x = 0; x < numOfV; x++) {
                if (AjdMatrix[curr][x] && !visited[x]) {
                    visited[x] = true;
                    q.push(x);
                }
            }
        }
        cout << endl; 

       
        delete[] visited;
    }

    
};

int main() {
     Graph g(10);  

 
    g.addEdge(0, 1);  
    g.addEdge(0, 4);  
    g.addEdge(1, 2);  
    g.addEdge(1, 5);  
    g.addEdge(2, 3);  
    g.addEdge(3, 4);  
    g.addEdge(5, 0);  
    g.addEdge(6, 1);  
    g.addEdge(7, 3);  
    g.addEdge(7, 8);  
    g.addEdge(4, 7);  
    g.addEdge(8, 9);  
    
    g.Print();    
    cout << endl;
    g.bfs(1); // Start BFS from vertex 0

    return 0;
}
