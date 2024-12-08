#include <iostream>
using namespace std;

struct player {
    string name;
    int score;
    player* next;
};

player* head = NULL;

void addPlayer(const string& name, int score) {
    player* newplayer = new player;
    newplayer->name = name;
    newplayer->score = score;
    newplayer->next = NULL;
    
    if (head == NULL) {
        head = newplayer;
    } else {
        player* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newplayer;
    }
}

void updatescore(const string& name, int score) {
    player* current = head;
    while (current != NULL) {
        if (current->name == name) {
            current->score = score;
            return;
        }
        current = current->next;
    }
    cout << "Player not found.\n";
}

void removePlayer(const string& name) {
    player* current = head;
    player* previous = NULL;
    
    if (current != NULL && current->name == name) {
        head = current->next;
        delete current;
        return;
    }

    while (current != NULL && current->name != name) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        cout << "Player not found.\n";
        return;
    }

    previous->next = current->next;
    delete current;
}

void displayAllPlayers() {
    if (head == NULL) {
        cout << "No players in the game.\n";
        return;
    }
    
    player* current = head;
    cout << "Displaying Leaderboard:\n";
    while (current != NULL) {
        cout << "Name: " << current->name << ", Score: " << current->score << endl;
        current = current->next;
    }
}

void findPlayers(const string& name) {
    player* current = head;
    while (current != NULL) {
        if (current->name == name) {
            cout << "Player found. Name: " << current->name << ", Score: " << current->score << endl;
            return;
        }
        current = current->next;
    }
    cout << "Player not found.\n";
}

void displayTopScorer() {
    if (head == NULL) {
        cout << "No players in the game.\n";
        return;
    }

    player* current = head;
    player* top = head;
    while (current != NULL) {
        if (current->score > top->score) {
            top = current;
        }
        current = current->next;
    }
    cout << "Top scorer's name: " << top->name << ", Score: " << top->score << endl;
}

void averageScore() {
    if (head == NULL) {
        cout << "No players in the game.\n";
        return;
    }

    player* current = head;
    int totalScore = 0, count = 0;
    while (current != NULL) {
        totalScore += current->score;
        count++;
        current = current->next;
    }
    
    double average = (totalScore) / count;
    cout << "Average score of all players: " << average << endl;
}

int main() {
    addPlayer("Haseeb", 10);
    addPlayer("Munawar", 20);
    addPlayer("Abdullah", 30);

    cout << endl;

    updatescore("Haseeb", 40);

    cout << endl;

    findPlayers("Haseeb");

    cout << endl;

    displayTopScorer();

    cout << endl;

    displayAllPlayers();

    cout << endl;

    removePlayer("Munawar");

    cout << endl;

    displayAllPlayers();

    cout << endl;

    averageScore();

    return 0;
}
