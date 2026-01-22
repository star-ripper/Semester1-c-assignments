#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct student {
    string name;
    int rollNumber;
    string department;
    float GPA;
    bool isScholarship;
};

vector<int> rollNumbercheck; 

// Function declarations
void addrecord(student hostelSpace[3][5][2], vector<int>& rollNumbercheck);
void viewAllRecords(student hostelSpace[3][5][2]);
void menu(student hostelSpace[3][5][2]);
void studentSearch(student hostelSpace[3][5][2]);
void academicSummary(student hostelSpace[3][5][2]);

int main() {
    student hostelSpace[3][5][2];

    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 2; k++) {
                hostelSpace[i][j][k] = { "", 0, "", 0.0, false };
            }
        }
    }

    menu(hostelSpace); // Start the menu
    return 0;
}

void addrecord(student hostelSpace[3][5][2], vector<int>& rollNumbercheck) {
    int h, r, b;
    student s;

    // Get and check roll number
    while (true) {
        cout << "Enter roll number: ";
        cin >> s.rollNumber;

        bool exists = false;
        for (int i = 0; i < rollNumbercheck.size(); i++) {
            if (rollNumbercheck[i] == s.rollNumber) {
                exists = true;
                break;
            }
        }

        if (exists) {
            cout << "Roll number already exists. Try another.\n";
        }
        else {
            rollNumbercheck.push_back(s.rollNumber);
            break;
        }
    }

    cout << "Enter name: ";
    cin.ignore();
    getline(cin,s.name);
    cout << "Enter department: ";
    getline(cin,s.department);
    cout << "Enter GPA: ";
    cin >> s.GPA;

    int scholarshipInput;
    while (true) {
        cout << "Is on scholarship? (1 = Yes / 0 = No): ";
        cin >> scholarshipInput;
        if (scholarshipInput == 1 || scholarshipInput == 0) {
            s.isScholarship = (scholarshipInput == 1);
            break;
        }
        else {
            cout << "Incorrect input, try again\n";
        }
    }

    cout << "\nEnter hostel number (1-3): ";
    cin >> h;
    h = h - 1;

    if (!s.isScholarship) {
        cout << "\nEnter room number (1-5): ";
        cin >> r;
        r = r - 1;
    }
    else {
        while (true) {
            cout << "\nEnter room number (1-3): ";
            cin >> r;
            if (r >= 1 && r <= 3) {
                r = r - 1;
                break;
            }
            else {
                cout << "Scholarship students can only be in room 1 to 3\n";
            }
        }
    }

    cout << "Enter bed number (1-2): ";
    cin >> b;
    b = b - 1;

    hostelSpace[h][r][b] = s;

    cout << "Student added successfully to Hostel " << h + 1 << ", Room " << r + 1 << ", Bed " << b + 1 << endl;
}

void viewAllRecords(student hostelSpace[3][5][2]) {
    for (int i = 0; i < 3; i++) {
        cout << "Hostel " << i + 1 << endl;
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 2; k++) {
                cout << "|Room " << j + 1 << "|, |Bed " << k + 1 << "|\t";
                cout << "|Roll#: " << hostelSpace[i][j][k].rollNumber << "|\t";
                cout << "|Name: " << hostelSpace[i][j][k].name << "|\t";
                cout << "|Department: " << hostelSpace[i][j][k].department << "|\t";
                cout << "|GPA: " << hostelSpace[i][j][k].GPA << "|\t";
                cout << "|Scholarship: " << (hostelSpace[i][j][k].isScholarship ? "Yes" : "No") << "|\n";
            }
        }
        cout << endl;
    }
}

void menu(student hostelSpace[3][5][2]) {
    int choice;
    while (true) {
        cout << "\n--- MENU ---\n";
        cout << "1. Add Record\n";
        cout << "2. View All Records\n";
        cout << "3. Seach student by roll Number\n";
        cout << "4. Academix Summery\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            addrecord(hostelSpace, rollNumbercheck);
        }
        else if (choice == 2) {
            viewAllRecords(hostelSpace);
        }
        else if (choice == 3) {
            studentSearch(hostelSpace);
        }
        else if (choice == 4) {
            academicSummary(hostelSpace);
        }
        else if (choice == 5) {
            break;
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }
    }
}
void studentSearch(student hostelSpace[3][5][2]) {
    int viewRollNumber;
    cout << "Enter the roll Number you want to search: ";
    cin >> viewRollNumber;
    for(int a = 0; a < 50;a++){
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 2; k++) {
                    if (hostelSpace[i][j][k].rollNumber == viewRollNumber) {
                        cout << "|Room " << j + 1 << "|, |Bed " << k + 1 << "|\t";
                        cout << "|Roll#: " << hostelSpace[i][j][k].rollNumber << "|\t";
                        cout << "|Name: " << hostelSpace[i][j][k].name << "|\t";
                        cout << "|Department: " << hostelSpace[i][j][k].department << "|\t";
                        cout << "|GPA: " << hostelSpace[i][j][k].GPA << "|\t";
                        cout << "|Scholarship: " << (hostelSpace[i][j][k].isScholarship ? "Yes" : "No") << "|\n";
                        return;
                   }
                }
            }
        }
        cout << "There exists no student\n";
    }
}
void academicSummary(student hostelSpace[3][5][2]) {
    int totalStudents = 0;
    float totalGPA = 0.0;
    int scholarshipCount = 0;
    int above3GPA[3] = { 0, 0, 0 };

    for (int h = 0; h < 3; h++) {
        for (int r = 0; r < 5; r++) {
            for (int b = 0; b < 2; b++) {
                student& s = hostelSpace[h][r][b];
                if (s.rollNumber != 0) {
                    totalStudents++;
                    totalGPA += s.GPA;
                    if (s.isScholarship)
                        scholarshipCount++;
                    if (s.GPA > 3.0)
                        above3GPA[h]++;
                }
            }
        }
    }

    cout << "\n--- Academic Summary ---\n";
    cout << "Total Students: " << totalStudents << endl;
    cout << "Average GPA: " << (totalStudents > 0 ? totalGPA / totalStudents : 0.0) << endl;
    cout << "Scholarship Holders: " << scholarshipCount << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Hostel " << i + 1 << " students with GPA > 3.0: " << above3GPA[i] << endl;
    }
}

