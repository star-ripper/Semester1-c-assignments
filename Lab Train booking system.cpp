#include<iostream>

struct seat {
    int choice;
    int row;
    int column;
};

using namespace std;
int main() {
    cout << "---------------------------------------------------------------\n";
    cout << "Welcome to train seat reservation\n";
    cout << "\nThe number - represents unreserved seats and X represents reserved seats\n";
    cout << "\nPlease Choose a seat to reserve\n" << endl;
    cout << "---------------------------------------------------------------\n";

    seat trainSeat[8][4] = {
        {{1},{0}, {0},{0} },
         {{0},{0}, {0},{0} },
          {{0},{0}, {1},{1} },
           {{0},{0}, {0},{0} },
            {{0},{1}, {0},{0} },
             {{1},{0}, {0},{0} },
              {{0},{0}, {1},{0} },
               {{1},{1}, {1},{1} },
    };
 
    cout <<"   |  " << "1 " << "2 " << "  " << "3 " << "4" << endl;
    cout << "   |----------------" << endl;

    for (int i = 0;i < 8;i++) {
        cout << i+1 << "  |  ";
        for (int j = 0;j <4;j++) {
            if (trainSeat[i][j].choice == 0) {
                cout << "-";
                cout << "";
            }
            else
                cout << "X";
            if (j == 1) {
                cout << "   ";
            }
        }
        cout << endl;
    }
    seat train;

    while (true) {
        cout << "Type the row number: ";
        cin >> train.row;
        if (train.row > 8 || train.row<1) {                                                    //check to see if row is viable
            cout << "You have entered incorrect value try again\n";
            continue;
        }
        cout << endl;

        cout << "Type the coloumn: ";                                                          //check to see if cloumn is viable
        cin >> train.column;
        cout << endl;
        if (train.column > 4 || train.row < 1) {
            cout << "You have entered incorrect value try again\n";
            continue;
        }
        if (trainSeat[train.row-1][train.column-1].choice == 1) {                              //checking if already booked
            cout << "This seat is already booked try again\n";
            continue;
        }
        trainSeat[train.row-1][train.column-1].choice = { 1 };
            
        cout << "   |  " << "1 " << "2 " << "  " << "3 " << "4" << endl;
        cout << "   |----------------" << endl;
        for (int i = 0;i < 8;i++) {
            cout << i + 1 << "  |  ";
            for (int j = 0;j < 4;j++) {
                if (trainSeat[i][j].choice == 0) {
                cout << "-";
                cout << "";
            }
            else
                cout << "X";
            if (j == 1) {
                cout << "   ";
            }
        }
            
            cout << endl;
        }

        cout << "Do you wish to book another\n";
        int check;
        while (true) {
            cout << "Type 1 for Yes\n" << "Type 2 for No\n";
            cin >> check;
            if (check == 1 || check == 2) {
                break;
            }
            else {
                cout << "You have entered incorrect value try again\n";
                continue;
            }
        }
        if (check == 1) {
            continue;
        }
        
        break;
    };
        
    
    
}