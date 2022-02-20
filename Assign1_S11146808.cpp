// S11146808
// Krishti Shivnay Prasad

#include <iostream>
#include <iomanip>

using namespace std;

int main() {

	string HolDest[] = { "Japan", "South Korea", "China", "Germany", "United Kingdom" };
	int VI = 0;								// VI = Vote Index.
	string vi;								// vi = vote index as a string for a possible user input error correction.
	double SVC = 0;							// SVC = Successful Vote Count.
	int FVC = 0;							// FVC = Failed Vote Count.
	int DVC[] = { 0, 0, 0, 0, 0 };			// DVC = Destination Vote Count.
	double dvc[] = { 0, 0, 0, 0, 0 };		// dvc => Double varible because integer division doesn't give an accurate decimal variable.
	double VR[] = { 0, 0, 0, 0, 0 };		// VR = Vote Ratio.
	int MVDC = 0;							// MVD = Most Voted Destination Count.
	string YorN;							// YorN = Yes or No!

	do {			// Main loop funtion for all the user inputs.
		cout << "\nAre You A New Voter? (y/n) \nIf no then you will be sent to the results: ";
		cin >> YorN;
		if (YorN == "y") {
			do {
				cout << "\n*********** FAVORITE HOLIDAY DESTINATION OPINION POLL ***********\n";
				for (int VI = 0; VI < 5; VI++) {			//Compacted Listing of Holiday Destinations, this is better way to list if there was a lot of destinations.
					cout << "\t" << VI + 1 << ". " << HolDest[VI] << endl;
				}
				cout << "\t6. Quit voting\n";
				cout << "Please choose your favorite holiday destination from the list above by number.\n\n";

				cout << "Your Choice: ";
				cin >> vi;
				VI = 0;
				if (vi == "1") {			//reassigning of input from a string to int, this is done to remove certain possible input errors/ incorrect end results.
					VI = 1;
				}
				else if (vi == "2") {
					VI = 2;
				}
				else if (vi == "3") {
					VI = 3;
				}
				else if (vi == "4") {
					VI = 4;
				}
				else if (vi == "5") {
					VI = 5;
				}
				else if (vi == "6") {
					VI = 6;
				}

				if (VI == 1 || VI == 2 || VI == 3 || VI == 4 || VI == 5) {			//show which option was chosen or if input was wrong or if the user wants to quit without voting.
					VI = VI - 1;
					switch (VI) {
					case 0: cout << "You voted for " << HolDest[VI] << endl;
						DVC[0]++, dvc[0]++;
						break;
					case 1: cout << "You voted for " << HolDest[VI] << endl;
						DVC[1]++, dvc[1]++;
						break;
					case 2: cout << "You voted for " << HolDest[VI] << endl;
						DVC[2]++, dvc[2]++;
						break;
					case 3: cout << "You voted for " << HolDest[VI] << endl;
						DVC[3]++, dvc[3]++;
						break;
					case 4: cout << "You voted for " << HolDest[VI] << endl;
						DVC[4]++, dvc[4]++;
						break;
					} SVC++;
					VI = 6;
				}
				else if (VI != 6) {
					cin.clear();
					cin.ignore(10000, '\n');
					VI = 6;
					FVC++;
					cout << "\nInvalid Input.\nNo second chances provided you.\nLet the next voter a turn.\n\n";
				}
				else if (VI == 6) {
					YorN = "n";
				}
			} while (VI != 6);
		}
		else if (YorN != "n") {
			cout << "\nInvalid Yes or No Input!\n\n";
		}
	} while (YorN != "n");

	if (SVC >= 1) {				//Function for getting the percentage of the votes and also for the most voted destination(s).
		for (int VI = 0; VI < 5; VI++) {
			VR[VI] = (100 * dvc[VI]) / SVC;
		}
		for (VI = 0; VI < 5; VI++) {
			if (DVC[VI] > MVDC) {
				MVDC = DVC[VI];
			}
		}
	}

	cout << "\n*********** FAVORITE HOLIDAY DESTINATION POLL RESULTS ***********\n";		//this is not incorporated into a loop because the spacing between the variables in the table doesn't align if done in a loop.
	cout << "\t DESTINATION \t\t VOTES \t\t PERCENTAGE\n";
	cout << setprecision(1) << fixed;
	cout << "\t " << HolDest[0] << " \t\t\t " << DVC[0] << " \t\t " << VR[0] << endl;
	cout << "\t " << HolDest[1] << " \t\t " << DVC[1] << " \t\t " << VR[1] << endl;
	cout << "\t " << HolDest[2] << " \t\t\t " << DVC[2] << " \t\t " << VR[2] << endl;
	cout << "\t " << HolDest[3] << " \t\t " << DVC[3] << " \t\t " << VR[3] << endl;
	cout << "\t " << HolDest[4] << " \t " << DVC[4] << " \t\t " << VR[4] << endl << endl;
	if (SVC >= 1) {
		cout << "According to this poll, the holiday destination with majority of votes is/are: ";
		// Multiple else if funtions to determine most common voted destinations if there are any.
		if (DVC[0] == MVDC) {
			cout << HolDest[0];
		}
		if (DVC[1] == MVDC && DVC[0] == MVDC) {
			cout << ", " << HolDest[1];
		}
		else if (DVC[1] == MVDC) {
			cout << HolDest[1];
		}
		if (DVC[2] == MVDC && DVC[0] == MVDC) {
			cout << ", " << HolDest[2];
		}
		else if (DVC[2] == MVDC && DVC[1] == MVDC) {
			cout << ", " << HolDest[2];
		}
		else if (DVC[2] == MVDC) {
			cout << HolDest[2];
		}
		if (DVC[3] == MVDC && DVC[0] == MVDC) {
			cout << ", " << HolDest[3];
		}
		else if (DVC[3] == MVDC && DVC[1] == MVDC) {
			cout << ", " << HolDest[3];
		}
		else if (DVC[3] == MVDC && DVC[2] == MVDC) {
			cout << ", " << HolDest[3];
		}
		else if (DVC[3] == MVDC) {
			cout << HolDest[3];
		}
		if (DVC[4] == MVDC && DVC[0] == MVDC) {
			cout << ", " << HolDest[4];
		}
		else if (DVC[4] == MVDC && DVC[1] == MVDC) {
			cout << ", " << HolDest[4];
		}
		else if (DVC[4] == MVDC && DVC[2] == MVDC) {
			cout << ", " << HolDest[4];
		}
		else if (DVC[4] == MVDC && DVC[3] == MVDC) {
			cout << ", " << HolDest[4];
		}
		else if (DVC[4] == MVDC) {
			cout << HolDest[4];
		}
		cout << ".\n";
	}
	else if (FVC >= 1) {
		cout << "Unable to calculate above due to total invalid vote input(s).\n";
	}
	else {
		cout << "Why didnt anyone vote? :(\n";
	}

	cout << setprecision(0);
	cout << "\nTotal Valid Votes: " << SVC << endl;
	cout << "Total Invalid Votes: " << FVC << "\t\t\t Total votes received: " << FVC + SVC << endl;

	return 0;
}
