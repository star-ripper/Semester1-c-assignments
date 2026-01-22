#include <iostream>
#include <string>
#include <vector>

using namespace std;

string forceStop = "Exit";
vector<string> name;
vector<string> registrationNumber;
vector<string> degreeTitle;
vector<string> completeDegree;
vector<int> obtainedMarks;
int totalMarks;

int completion;
int main() {
    cout << "Here we will be entering student records\n";
    while (true) {
        cout << "If you want to exit, type 'Exit'. Otherwise, press enter to continue.\n";
        string exitTitle;
        cin >> exitTitle;
        if (exitTitle == forceStop) {  // If the input is 'Exit', break the loop
            break;
        }

        // Input for name
        cout << "Enter the name of the Student: ";
        cin.ignore();  // Ignore leftover newline from previous input
        string inputName;
        getline(cin, inputName);

        // Input for registration number
        cout << "Enter the registration number of the student: ";
        string inputRegNum;
        getline(cin, inputRegNum);

        // Input for degree title
        cout << "Enter the degree title of the student: ";
        string inputDegree;
        getline(cin, inputDegree);

        // Input for obtained marks
        int inputObtMarks;
        cout << "Enter the obtained marks of the student: ";
        cin >> inputObtMarks;

        // Clear the input buffer before the next string input
        cin.ignore(); // Ignore the leftover newline character

        // Check if degree is completed
        while (completion != 1 && completion != 2) {  // This loop is to see if the degree is complete or not
            cout << "Enter 1 if the degree is completed and 2 if not: ";
            cin >> completion;
            switch (completion) {
            case 1:
                completeDegree.push_back("Yes");
                break;
            case 2:
                completeDegree.push_back("No");
                break;
            default:
                cout << "Invalid input, try again\n";
                break;
            }
        }

        // Reset completion variable for the next iteration
        completion = 0;



        // Add the inputs to vectors
        name.push_back(inputName);
        registrationNumber.push_back(inputRegNum);
        degreeTitle.push_back(inputDegree);
        obtainedMarks.push_back(inputObtMarks);
    }
            // Input for total marks for the student
        cout << "Enter the total Marks: ";
        cin >> totalMarks;

    // Print all records
    cout << "Student Records:\n";
    cout<<"Name\t"<<"   "<<"REG Number\t"<<"    "<<"Degree\t"<<"    "<<"Comp\t"<<"    "<<"ObtainedMarks\t"<<"    "<<"TotalMarks\n";
        cout << "---------------------------------------------------------------------------\n";
    for (int i = 0; i < name.size(); i++) {
       cout<<name[i]<<"\t"<<"          ";
       cout<<registrationNumber[i]<<"\t"<<"         ";
       cout<<degreeTitle[i]<<"\t"<<"         ";
       cout<<completeDegree[i]<<"\t"<<"         ";
       cout<<obtainedMarks[i]<<"\t"<<"                ";
       cout<<totalMarks<<"\n";
     
    }

    return 0;
}