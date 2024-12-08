#include <iostream>
#include <fstream>  

using namespace std;

int main() {
    ofstream file1("File1.txt", ios::app);

    if (!file1.is_open()) {
        cout << "Error opening File1.txt" << endl;
        return 1;
    }

    string data;
    cout << "Enter the data you want to append to File1.txt: \n";
    getline(cin, data);

    file1 << data << endl;

    file1.close();

    cout << "Data appended successfully to File1.txt!" << endl;

    return 0;
}
