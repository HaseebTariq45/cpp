#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream file1("File1.txt");
    ifstream file2("File2.txt");
    ofstream file3("File3.txt");
    if (!file1.is_open()) {
        cout << "Error opening File1.txt" << endl;
        return 1;
    }

    if (!file2.is_open()) {
        cout << "Error opening File2.txt" << endl;
        return 1;
    }

    if (!file3.is_open()) {
        cout << "Error creating/opening File3.txt" << endl;
        return 1;
    }

    string line;
    while (getline(file1, line)) {
        file3 << line << endl;
    }

    while (getline(file2, line)) {
        file3 << line << endl;
    }

    file1.close();
    file2.close();
    file3.close();

    cout << "Files merged successfully into File3.txt!" << endl;

    return 0;
}
