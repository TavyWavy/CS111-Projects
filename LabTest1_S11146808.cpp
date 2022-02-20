// S11146808
// Krishti Shivnay Prasad
// Lab Test MST.cpp
#include <iostream>

using namespace std;

int main() {
	// All the different types of data that is needed even if it may be once in this case to understand better for dummies :).
	// Variables are pretty easy to understand, no comments needed for most of them.
	string TypeOfCar[] = { "Compact Car", "Mid-Size Car", "Luxury Car" };
	int RentalPrice[] = { 40,55,70 };
	int I;				// Indexing Variable for getting array variables.
	int CarI=1;			//Car Index.
	int Days;			//Number of days the customer wants to use the car.
	int Sum = 0;		//Total cost of the end result.
	int Insurance = 15;	//One time variable, it is assigned for better understanding where it is used.
	int Bond = 100;		//One time variable, it is assigned for better understanding where it is used.

	//Options listing board.
	cout << "******************Type of Car **************** Rental Price ************\n";
	for (I = 0; I < 3; I++) {
		cout << "\t\t" << I + 1 << ". " << TypeOfCar[I] << "\t\t\t" << RentalPrice[I] << endl;
	}

	// Choice input prompts and inputs.
	cout << "Choose the type of car you would like for rental from above by number: ";
	cin >> CarI;
	CarI = CarI - 1;
	// If funtion for continuing with the selection if CarI input is correct.
	if (CarI == 0 || CarI == 1 || CarI == 2) {
		cout << "Choose how many days you would like to rent the vehicle: ";
		cin >> Days;
		// If funtion for continuing with the selection if Days input is correct.
		if (Days > 0) {
		for (I = 0; I < Days; I++) {
			Sum = Sum + RentalPrice[CarI];
			Sum = Sum + Insurance;
		}
		// Total Sum Calculations.
		Sum = Sum + Bond;
		cout << "Total cost of your rental is\t$" << Sum;
	}// If the second input is invalid.
		else {
			cout << "Invalid Input";
		}
	}// If the first input is invalid.
	else
	{
		cout << "Invalid Input";
	}
	return 0;
}

