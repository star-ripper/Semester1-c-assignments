#include <iostream>
#include <string>
#include <limits>

using namespace std;

const int numSubjects = 8;
const int numSemester = 12;

struct semester {
    string subjects[numSubjects];
    int marks[numSubjects];
};

struct student {
    string name = "";
    string rollNo = "";
    string department = "";
    string university = "";
    string city = "";
    string country = "";
    string contactInfo = "";
    semester semesters[numSemester];
    int subjectCount[numSemester];
    int semes;
};

int main() {
    int noStudents;
    while(true){
    cout << "Enter the number of students (Max is 10): ";
    cin >> noStudents;
    if(noStudents >= 1 && noStudents <= 10){
        break;
    }
    else{
        cout <<"Invalid Input try again\n";
    }
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    student data[10];

    for (int s = 0; s < noStudents; s++) {
        cout << "\n--- Enter details for Student " << s + 1 << " ---\n";

        cout << "Enter student name: ";
        getline(cin, data[s].name);

        cout << "Enter student roll number: ";
        getline(cin, data[s].rollNo);

        cout << "Enter student department: ";
        getline(cin, data[s].department);

        cout << "Enter student university: ";
        getline(cin, data[s].university);

        cout << "Enter student city: ";
        getline(cin, data[s].city);

        cout << "Enter student country: ";
        getline(cin, data[s].country);

        cout << "Enter phone number of student (Only in numbers): ";
        getline(cin, data[s].contactInfo);

        while (true) {
            cout << "Enter the number of semesters (Max is 12): ";
            cin >> data[s].semes;
            if (data[s].semes > 0 && data[s].semes <= numSemester) {
                break;
            } else {
                cout << "Invalid input. Try again.\n";
            }
        }

        cin.ignore();

        for (int i = 0; i < data[s].semes; i++) {
            while (true) {
                cout << "Enter the total subjects in semester " << i + 1 << " (Max is 8): ";
                cin >> data[s].subjectCount[i];
                cin.ignore();
                if (data[s].subjectCount[i] > 0 && data[s].subjectCount[i] <= numSubjects) {
                    break;
                } else {
                    cout << "Incorrect input. Please try again.\n";
                }
            }

            for (int j = 0; j < data[s].subjectCount[i]; j++) {
                cout << "Enter the subject: ";
                getline(cin, data[s].semesters[i].subjects[j]);
                cout << "Enter the marks gained in the subject: ";
                cin >> data[s].semesters[i].marks[j];
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    }

    for (int s = 0; s < noStudents; s++) {
        cout << "\n===== Student Info for Student " << s + 1 << " =====\n";
        cout << "Name: " << data[s].name << endl;
        cout << "Roll No: " << data[s].rollNo << endl;
        cout << "Department: " << data[s].department << endl;
        cout << "University: " << data[s].university << endl;
        cout << "City: " << data[s].city << endl;
        cout << "Country: " << data[s].country << endl;
        cout << "Phone Number: " << data[s].contactInfo << endl;

        for (int i = 0; i < data[s].semes; i++) {
            cout << "\n--- Semester " << i + 1 << " --------------\n";
            for (int j = 0; j < data[s].subjectCount[i]; j++) {
                cout << "Subject: " << data[s].semesters[i].subjects[j] << " - Marks: " << data[s].semesters[i].marks[j];
                if (data[s].semesters[i].marks[j] >= 70) {
                    cout << " [Pass]\n";
                } else {
                    cout << " [Fail]\n";
                }
            }
        cout << "-------------------------\n";
            
        }
    }

    return 0;
}
