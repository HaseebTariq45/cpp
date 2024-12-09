#include <iostream>
#include <climits>
using namespace std;

const int MAX_SIZE = 100;

void findMinimumSpanningTree(int network[MAX_SIZE][MAX_SIZE], int totalNodes) {
    int parentNode[MAX_SIZE];
    int edgeWeight[MAX_SIZE];
    bool isNodeIncluded[MAX_SIZE];

    for (int i = 0; i < totalNodes; i++) {
        edgeWeight[i] = INT_MAX;
        isNodeIncluded[i] = false;
    }

    edgeWeight[0] = 0;
    parentNode[0] = -1;

    for (int count = 0; count < totalNodes - 1; count++) {
        int minWeight = INT_MAX, currentNode;

        for (int node = 0; node < totalNodes; node++) {
            if (!isNodeIncluded[node] && edgeWeight[node] < minWeight) {
                minWeight = edgeWeight[node];
                currentNode = node;
            }
        }

        isNodeIncluded[currentNode] = true;

        for (int adjacentNode = 0; adjacentNode < totalNodes; adjacentNode++) {
            if (network[currentNode][adjacentNode] && !isNodeIncluded[adjacentNode] &&
                network[currentNode][adjacentNode] < edgeWeight[adjacentNode]) {
                parentNode[adjacentNode] = currentNode;
                edgeWeight[adjacentNode] = network[currentNode][adjacentNode];
            }
        }
    }

    cout << "Connection \tCost\n";
    for (int i = 1; i < totalNodes; i++) {
        cout << parentNode[i] << " - " << i << "\t\t" << network[i][parentNode[i]] << "\n";
    }
}

int main() {
    int totalNodes = 5;

    int network[MAX_SIZE][MAX_SIZE] = {
        {0, 12, 18, 0, 0},
        {12, 0, 8, 20, 0},
        {18, 8, 0, 14, 22},
        {0, 20, 14, 0, 16},
        {0, 0, 22, 16, 0}
    };

    cout << "\nOptimal Network Configuration:\n";
    findMinimumSpanningTree(network, totalNodes);

    return 0;
}
