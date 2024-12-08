#include <iostream>
#include <string>
using namespace std;

// Base class for user-related operations
class User {
public:
    int AdminId[100]{};
    string AdminName[100];
    string AdminEmail[100];
    string StudentName[100];
    int StudentId[100]{};
    string FacultyName[100];
    int FacultyId[100]{};
    string VAttendance[100];
    string StudentAttendance[100];
    string MFAttendance[100];
    int adminSize = 0;
    int studentSize = 0;
    int facultySize = 0;

    int handleIntegerInput() {
        int input;
        cout << "Enter your choice: ";
        while (!(cin >> input)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number: ";
        }
        return input;
    }
};

// Admin class for admin-related operations
class Admin : public User {
private:
    User* user;

public:
    Admin(User* u) : user(u) {}

    void adminMenu() {
        bool exit = false;
        while (!exit) {
            cout << "\n--- Admin Menu ---\n";
            cout << "1. Add User\n2. Delete User\n3. Update User\n4. View Users\n5. Faculty Attendance\n6. Exit\n";
            int choice = user->handleIntegerInput();

            switch (choice) {
            case 1:
                addUser();
                break;
            case 2:
                deleteUser();
                break;
            case 3:
                updateUser();
                break;
            case 4:
                viewUsers();
                break;
            case 5:
                facultyAttendanceMenu();
                break;
            case 6:
                cout << "Exiting Admin Menu.\n";
                exit = true;
                break;
            default:
                cout << "Invalid choice. Try again.\n";
            }
        }
    }

    void addUser() {
        cout << "\n1. Add Admin\n2. Add Student\n3. Add Faculty\n4. Exit\n";
        int choice = user->handleIntegerInput();

        switch (choice) {
        case 1: {
            cout << "Enter number of Admins to add: ";
            int count;
            cin >> count;
            cin.ignore();
            for (int i = user->adminSize; i < user->adminSize + count; i++) {
                cout << "Enter Admin Name: ";
                getline(cin, user->AdminName[i]);
                cout << "Enter Admin Email: ";
                getline(cin, user->AdminEmail[i]);
                cout << "Enter Admin ID: ";
                cin >> user->AdminId[i];
                cin.ignore();
            }
            user->adminSize += count;
            break;
        }
        case 2: {
            cout << "Enter number of Students to add: ";
            int count;
            cin >> count;
            cin.ignore();
            for (int i = user->studentSize; i < user->studentSize + count; i++) {
                cout << "Enter Student Name: ";
                getline(cin, user->StudentName[i]);
                cout << "Enter Student ID: ";
                cin >> user->StudentId[i];
                cin.ignore();
            }
            user->studentSize += count;
            break;
        }
        case 3: {
            cout << "Enter number of Faculties to add: ";
            int count;
            cin >> count;
            cin.ignore();
            for (int i = user->facultySize; i < user->facultySize + count; i++) {
                cout << "Enter Faculty Name: ";
                getline(cin, user->FacultyName[i]);
                cout << "Enter Faculty ID: ";
                cin >> user->FacultyId[i];
                cin.ignore();
            }
            user->facultySize += count;
            break;
        }
        case 4:
            cout << "Exiting Add User.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }

    void deleteUser() {
        cout << "\n1. Delete Admin\n2. Delete Student\n3. Delete Faculty\n";
        int choice = user->handleIntegerInput();

        switch (choice) {
        case 1:
            deleteAdmin();
            break;
        case 2:
            deleteStudent();
            break;
        case 3:
            deleteFaculty();
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }

    void deleteAdmin() {
        cout << "Enter Admin ID to delete: ";
        int id;
        cin >> id;
        for (int i = 0; i < user->adminSize; i++) {
            if (user->AdminId[i] == id) {
                cout << "Deleting Admin: " << user->AdminName[i] << "\n";
                user->AdminName[i] = "";
                user->AdminEmail[i] = "";
                user->AdminId[i] = 0;
                break;
            }
        }
    }

    void deleteStudent() {
        cout << "Enter Student ID to delete: ";
        int id;
        cin >> id;
        for (int i = 0; i < user->studentSize; i++) {
            if (user->StudentId[i] == id) {
                cout << "Deleting Student: " << user->StudentName[i] << "\n";
                user->StudentName[i] = "";
                user->StudentId[i] = 0;
                break;
            }
        }
    }

    void deleteFaculty() {
        cout << "Enter Faculty ID to delete: ";
        int id;
        cin >> id;
        for (int i = 0; i < user->facultySize; i++) {
            if (user->FacultyId[i] == id) {
                cout << "Deleting Faculty: " << user->FacultyName[i] << "\n";
                user->FacultyName[i] = "";
                user->FacultyId[i] = 0;
                break;
            }
        }
    }

    void updateUser() {
        cout << "Update functionality not implemented in this version.\n";
    }

    void viewUsers() {
        cout << "\n1. View Admins\n2. View Students\n3. View Faculty\n";
        int choice = user->handleIntegerInput();

        switch (choice) {
        case 1:
            for (int i = 0; i < user->adminSize; i++) {
                if (!user->AdminName[i].empty()) {
                    cout << "Admin Name: " << user->AdminName[i]
                         << ", Email: " << user->AdminEmail[i]
                         << ", ID: " << user->AdminId[i] << "\n";
                }
            }
            break;
        case 2:
            for (int i = 0; i < user->studentSize; i++) {
                if (!user->StudentName[i].empty()) {
                    cout << "Student Name: " << user->StudentName[i]
                         << ", ID: " << user->StudentId[i] << "\n";
                }
            }
            break;
        case 3:
            for (int i = 0; i < user->facultySize; i++) {
                if (!user->FacultyName[i].empty()) {
                    cout << "Faculty Name: " << user->FacultyName[i]
                         << ", ID: " << user->FacultyId[i] << "\n";
                }
            }
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }

    void facultyAttendanceMenu() {
        cout << "Faculty attendance functionality not implemented in this version.\n";
    }
};

// Main function
int main() {
    User user;
    Admin admin(&user);

    bool exit = false;
    while (!exit) {
        cout << "\n--- Main Menu ---\n";
        cout << "1. Admin\n2. Exit\n";
        int choice = user.handleIntegerInput();

        switch (choice) {
        case 1:
            admin.adminMenu();
            break;
        case 2:
            cout << "Exiting program. Goodbye!\n";
            exit = true;
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}
