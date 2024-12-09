#include <iostream>
#include <climits>
using namespace std;

const int MAX_SIZE = 100;

void findShortestPaths(int roadNetwork[MAX_SIZE][MAX_SIZE], int totalLocations, int startLocation) {
    int shortestTime[MAX_SIZE];
    bool isLocationVisited[MAX_SIZE];
    int previousLocation[MAX_SIZE];

    for (int i = 0; i < totalLocations; i++) {
        shortestTime[i] = INT_MAX;
        isLocationVisited[i] = false;
        previousLocation[i] = -1;
    }

    shortestTime[startLocation] = 0;

    for (int count = 0; count < totalLocations - 1; count++) {
        int minTime = INT_MAX, currentLocation;

        for (int location = 0; location < totalLocations; location++) {
            if (!isLocationVisited[location] && shortestTime[location] < minTime) {
                minTime = shortestTime[location];
                currentLocation = location;
            }
        }

        isLocationVisited[currentLocation] = true;

        for (int adjacentLocation = 0; adjacentLocation < totalLocations; adjacentLocation++) {
            if (roadNetwork[currentLocation][adjacentLocation] && !isLocationVisited[adjacentLocation] &&
                shortestTime[currentLocation] != INT_MAX &&
                shortestTime[currentLocation] + roadNetwork[currentLocation][adjacentLocation] < shortestTime[adjacentLocation]) {
                shortestTime[adjacentLocation] = shortestTime[currentLocation] + roadNetwork[currentLocation][adjacentLocation];
                previousLocation[adjacentLocation] = currentLocation;
            }
        }
    }

    cout << "Location\tShortest Time\tPath\n";
    for (int i = 0; i < totalLocations; i++) {
        cout << i << "\t\t" << shortestTime[i] << "\t\t";
        int temp = i;
        while (temp != -1) {
            cout << temp << " ";
            temp = previousLocation[temp];
        }
        cout << "\n";
    }
}

int main() {
    int totalLocations = 5;
    int roadNetwork[MAX_SIZE][MAX_SIZE] = {
        {0, 15, 25, 0, 0},
        {15, 0, 10, 20, 0},
        {25, 10, 0, 15, 35},
        {0, 20, 15, 0, 30},
        {0, 0, 35, 30, 0}
    };

    int startLocation = 0;

    cout << "\nFastest Delivery Routes:\n";
    findShortestPaths(roadNetwork, totalLocations, startLocation);

    return 0;
}
