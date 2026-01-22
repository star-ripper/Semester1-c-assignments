#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int main() {
    int i;
    string fileName = "Practice.txt";
    cout << "1. Continue from last time\n2.Delete last and rewrite it\n";
    cout << "These choices are irrelevant for those who are using for first time"<<endl;
    cout << "Input choice: ";
    cin >> i;
    ofstream outFile;

    if (i == 1)
        outFile.open(fileName, ios::app);  // append mode
    else if (i == 2)
        outFile.open(fileName);  // overwrite mode
    else
        return 0;

        
    string inputLine;
    while (true) {
       int check;
        cout << "Do you want to add another line?\n";
        cout << "1. Yes\n2. No\n";
        cin >> check;
        if (check != 1 &&  check != 2) {
            cout << "Invalid input.\n";
            continue;
        }
        if (check == 2) break;
       cout << "Add a line here"<<endl;
        cin.ignore();
        getline(cin, inputLine);
        outFile << inputLine << endl;

    cout << endl;
    }

    outFile.close();
    ifstream inFile(fileName);

    if (!inFile.is_open()) {
        cerr << "Error: Could not open file.\n";
        return 1;
    }
    string line;
    char ch;
    int countChr = 0;
    int countLine = 0;
    while (inFile.get(ch)) {
        if (ch == ' ') {
            continue;
        } 

        countChr++;
    }
    inFile.clear();
    inFile.seekg(0, ios::beg);
    int countWords = 0;
    string word;
    while (inFile >> word) {
        countWords++;
    }



    inFile.clear();
    inFile.seekg(0, ios::beg);

    while (getline(inFile, line)) {
        countLine++;
    }
    cout << "Total non-space characters are: "<< countChr << endl;
    cout << "Total words are: "<< countWords << endl;
    cout << "Total Lines are: "<< countLine << endl;
}


