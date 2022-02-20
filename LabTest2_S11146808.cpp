#include <iostream>
using namespace std;
int Total_Price;
//four calculation functions
int Regular(int R[2][4], int NumOPeople, int MovieNum) {
    Total_Price = NumOPeople * R[0][MovieNum - 1];
    return Total_Price;
}
int Premium(int P[2][4], int NumOPeople, int MovieNum) {
    Total_Price = NumOPeople * P[0][MovieNum - 1];
    return Total_Price;
}
int Regular_Group(int R[2][4], int NumOPeople, int MovieNum) {
    Total_Price = NumOPeople * R[1][MovieNum - 1];
    return Total_Price;
}
int Premium_Group(int P[2][4], int NumOPeople, int MovieNum) {
    Total_Price = NumOPeople * P[1][MovieNum - 1];
    return Total_Price;
}
//Main Function
int main() {
    int x = 0, y = 0, i = 0, NumOPeople, MovieNum;
    int R[2][4] = { { 8,8,9,10 }, { 7,6,6,7 } }, P[2][4] = { { 14,18,12,15 },{ 10,10,10,11 } };
    string Movie[] = { "Never Say Never Again","A View to a Kill","For Your Eyes Only","You Only Live Twice" };
    char Preference;
    bool quit = false;

    cout << "\t\t\t\Price Per Person($)\n";
    cout << "\tMovie\t\t\tRegular\tGroup\tPremium\tGroup\n";
    for (i = 0; i < 4; i++) {
        cout << i + 1 << "\t" << Movie[i] << "\t" << R[x][y] << "\t" << R[x + 1][y] << "\t" << P[x][y] << "\t" << P[x + 1][y] << endl;
        y++;
    }
    do {
        cout << "\nEnter Movie: ";
        cin >> MovieNum;
        if (MovieNum > 0 && MovieNum < 5) {
            cout << "\nEnter Preferred cinema (Regular(R) or Premium(P)): ";
            cin >> Preference;
            if (Preference == 'P' || Preference == 'R') {
                cout << "\nEnter Number of Passengers: ";
                cin >> NumOPeople;
                if (NumOPeople > 0) {
                    if (Preference == 'R' && NumOPeople < 10) {
                        Regular(R, NumOPeople, MovieNum);
                        cout << endl << "The total price is:_" << Total_Price << "_Dollars for the movie " << Movie[MovieNum - 1] << " for " << NumOPeople << " People." << endl;
                    }
                    else if (Preference == 'P' && NumOPeople < 10) {
                        Premium(P, NumOPeople, MovieNum);
                        cout << endl << "The total price is:_" << Total_Price << "_Dollars for the movie " << Movie[MovieNum - 1] << " for " << NumOPeople << " People." << endl;
                    }
                    else if (Preference == 'R' && NumOPeople > 9) {
                        Regular_Group(R, NumOPeople, MovieNum);
                        cout << endl << "The total price is:_" << Total_Price << "_Dollars for the movie " << Movie[MovieNum - 1] << " for " << NumOPeople << " People." << endl;
                    }
                    else if (Preference == 'P' && NumOPeople > 9) {
                        Premium_Group(P, NumOPeople, MovieNum);
                        cout << endl << "The total price is:_" << Total_Price << "_Dollars for the movie " << Movie[MovieNum - 1] << " for " << NumOPeople << " People." << endl;
                    }
                    else if (NumOPeople == 'q' || NumOPeople == 'Q') {
                        return 0;
                    }
                    else {
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }
                }
                else if (NumOPeople == 'q' || NumOPeople == 'Q') {
                    return 0;
                }
                else {
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
            }
            else if (Preference == 'q' || Preference == 'Q') {
                return 0;
            }
        }
        else if (MovieNum == 'q' || MovieNum == 'Q') {
            return 0;
        }
        else {
            cin.clear();
            cin.ignore(10000, '\n');
        }
    } while (quit != true);
    return 0;
}