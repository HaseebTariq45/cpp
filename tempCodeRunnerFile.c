#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

struct Connection {
    int startCity, endCity, cableCost;
};

struct UnionFind {
    int leader[MAX_SIZE], rank[MAX_SIZE];

    void initialize(int totalCities) {
        for (int i = 0; i < totalCities; i++) {
            leader[i] = i;
            rank[i] = 0;
        }
    }

    int findLeader(int city) {
        if (leader[city] != city)
            leader[city] = findLeader(leader[city]);
        return leader[city];
    }

    void mergeGroups(int cityA, int cityB) {
        int leaderA = findLeader(cityA);
        int leaderB = findLeader(cityB);

        if (leaderA != leaderB) {
            if (rank[leaderA] > rank[leaderB]) {
                leader[leaderB] = leaderA;
            } else if (rank[leaderA] < rank[leaderB]) {
                leader[leaderA] = leaderB;
            } else {
                leader[leaderB] = leaderA;
                rank[leaderA]++;
            }
        }
    }
};

bool compareConnections(Connection c1, Connection c2) {
    return c1.cableCost < c2.cableCost;
}

void findMinimumCableCost(int cityNetwork[MAX_SIZE][MAX_SIZE], int totalCities, int totalConnections) {
    Connection connections[totalConnections];
    int connectionCount = 0;

    for (int i = 0; i < totalCities; i++) {
        for (int j = i + 1; j < totalCities; j++) {
            if (cityNetwork[i][j] != 0) {
                connections[connectionCount].startCity = i;
                connections[connectionCount].endCity = j;
                connections[connectionCount].cableCost = cityNetwork[i][j];
                connectionCount++;
            }
        }
    }

    for (int i = 0; i < totalConnections - 1; i++) {
        for (int j = i + 1; j < totalConnections; j++) {
            if (compareConnections(connections[j], connections[i])) {
                Connection temp = connections[i];
                connections[i] = connections[j];
                connections[j] = temp;
            }
        }
    }

    UnionFind networkGroups;
    networkGroups.initialize(totalCities);

    int totalCost = 0;
    cout << "Cables to connect cities:\n";

    for (int i = 0; i < totalConnections; i++) {
        int cityA = connections[i].startCity;
        int cityB = connections[i].endCity;

        if (networkGroups.findLeader(cityA) != networkGroups.findLeader(cityB)) {
            cout << "City " << cityA << " - City " << cityB << " : " << connections[i].cableCost << endl;
            totalCost += connections[i].cableCost;
            networkGroups.mergeGroups(cityA, cityB);
        }
    }

    cout << "Total cost of cables: " << totalCost << endl;
}

int main() {
    int totalCities = 5;
    int totalConnections = 7;

    int cityNetwork[MAX_SIZE][MAX_SIZE] = {
        {0, 12, 0, 0, 0},
        {12, 0, 18, 0, 0},
        {0, 18, 0, 25, 0},
        {0, 0, 25, 0, 30},
        {0, 0, 0, 30, 0}
    };

    cout << "\nMinimum cable-laying cost to connect all cities:\n";
    findMinimumCableCost(cityNetwork, totalCities, totalConnections);

    return 0;
}
