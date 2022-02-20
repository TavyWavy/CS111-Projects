//Planned, written and compiled by Emelina Talosaga and Krishti Shivnay Prasad
//Student ID's: S11206886, S11146808
//Assignment 2 CS111 2021, Semester 2.

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

//Global variables that help the program run correctly under the given specifications.
string outputSD, ID[300], Last_Name[300], First_Name[300], hourlyrate[300], hoursworked[300];
double Hourly_Rate[300], Hours_Worked[300], Tax[300], Net_Pay[300];
int i, i2, i3, max_record;

// First function responsible for reading the content of the txt file into arrays.
void data_import() {
	cout << fixed;
	cout << setprecision(2);

	ifstream SDInput;
	SDInput.open("StaffDetails.txt");

	for (i = 0; i < 300; i++) {
		SDInput >> outputSD;
		if (i < 5) {/*	This if statement is here to prevent the headers of the txt files to be unneccesarily stored in the array.
						This leads to the program only storing the staff details.*/
		}
		else {
			i2 = 0;
			i3 = 0;

			// While loop for reading all the data from the text file and storing them into arrays.
			while (SDInput >> outputSD) {
				if (i2 == 0) {
					ID[i3] = outputSD;
					i2++;
				}
				else if (i2 == 1) {
					Last_Name[i3] = outputSD;
					i2++;
				}
				else if (i2 == 2) {
					First_Name[i3] = outputSD;
					i2++;
				}
				else if (i2 == 3) {
					hourlyrate[i3] = outputSD;
					i2++;
				}
				else if (i2 == 4) {
					hoursworked[i3] = outputSD;
					i3++;
					i2 = 0;
				}max_record = i3;
			}
		}
	}
	for (i = 0; i < max_record; i++) {
		Hourly_Rate[i] = stod(hourlyrate[i]);
		Hours_Worked[i] = stod(hoursworked[i]);
	}
}

// Function below is responsible for executing option 1 from the user menu.
void print_employee_data() {
	data_import();
	int i;
	cout << "ID\tLast_Name\tFirst_Name\tHourly_Rate\tHours_Worked\n";
	for (i = 0; i < 300; i++) {
			cout << ID[i] << "\t " << Last_Name[i] << "\t\t" << First_Name[i] << "\t\t" << hourlyrate[i] << "\t\t" << hoursworked[i] << endl;
			if (ID[i]=="") {
				i = 300;
			}
	}
}

// Function below is responsible for executing option 2 from the user menu.
void common_surname_funtion() {
	data_import();
	int i;

	cout << fixed;
	cout << setprecision(2);

	string common_surname;
	int max_common_surname = 0;
	cout << "Enter surname: ";
	cin >> common_surname;

	for (i = 0; i < max_record; i++) {
		if (common_surname == Last_Name[i]) {
			max_common_surname++;
			if (max_common_surname == 1) {
				cout << "ID\tLast_Name\tFirst_Name\tHourly_Rate\tHours_Worked\n";
			}
			cout << ID[i] << "\t " << Last_Name[i] << "\t\t" << First_Name[i] << "\t\t" << Hourly_Rate[i] << "\t\t" << Hours_Worked[i] << endl;
		}
	}
	if (max_common_surname == 0) {
		cout << "No surname matches your input.\n";
	}
	max_common_surname = 0;
}

// Function below is responsible for executing option 3 from the user menu.
void wages_calculator() {
	data_import();
	int i;
	double total_pay[300];

	cout << fixed;
	cout << setprecision(2);

	for (i = 0; i < max_record; i++) {
		total_pay[i] = Hourly_Rate[i] * Hours_Worked[i];
		Net_Pay[i] = total_pay[i] * (92.5 / 100);
		Tax[i] = total_pay[i] * (7.5 / 100);
	}
}

// Function below is responsible for executing option 5 from the user menu.
void export_result() {

	ofstream output;
	output.open("PayrollRun.txt");
	if (output.fail()) {
		cout << "Could not create PayrollRun.txt!\n";
	}
	else {
		output << fixed;
		output << setprecision(2);
		output << "ID            First Name      Last Name        Net Pay      \t\tTax\n";
		output << "------------------------------------------------------------------------------\n";
		for (i = 0; i < max_record; i++) {
			output << ID[i] << "\t\t" << First_Name[i] << "\t\t" << Last_Name[i] << "\t\t" << Net_Pay[i] << "\t\t\t" << Tax[i] << endl;
		}
	}
}

int main(){
	ifstream SDInput;
	SDInput.open("StaffDetails.txt");

	//list of variables that will be used in the main fuction.
	string optionsmenu;
	int i;
	bool calculations = false;
	



	if (SDInput.fail()) {
		cout << "FAILED TO LOAD FILE.\n";
		return 0;
	}
	else {

				//'for loop' for converting the decimal numbers from string to double variables.
				
		
				//while loop for the user interface.
				while (optionsmenu != "6" || optionsmenu != "q" || optionsmenu != "Q") {
					cout << "1) Print all employee data.\n";
					cout << "2) Print all data about of employees which match a given last name that is entered by a user.\n";
					cout << "3) Calculate the net wages for all employees and store it in an array.\n";
					cout << "4) Display payroll results.\n";
					cout << "5) Write results to file.\n";
					cout << "6) Exit program.\n";
					cin >> optionsmenu;

					

					if (optionsmenu == "1") {
						print_employee_data();
					}
					else if (optionsmenu == "2") {
						common_surname_funtion();
					}
					else if (optionsmenu == "3") {
						calculations = true;
						wages_calculator();
						//for (i = 0; i < max_record; i++) {
							//total_pay[i] = Hourly_Rate[i] * Hours_Worked[i];
							//Net_Pay[i] = total_pay[i] * (92.5 / 100);
							//Tax[i] = total_pay[i] * (7.5 / 100);
						//}
					}
					else if (optionsmenu == "4") {
						if (calculations == true) {
							cout << "ID\t  First Name\t\tLast Name\t\tNet Pay\t\tTax\n";
							for (i = 0; i < max_record; i++) {
								cout << ID[i] << "\t   " << First_Name[i] << "\t\t" << Last_Name[i] << "\t\t\t" << Net_Pay[i] << "\t\t" << Tax[i] << endl;
							}
						}
						else {
							cout << "Option 3 has not been chosen, thus could not use the calculations\n";
						}
					}
					else if (optionsmenu == "5") {
						if (calculations == true) {
							export_result();
						}
						else {
							cout << "Option 3 has not been chosen, thus could not use the calculations\n";
						}
					}
					else if (optionsmenu == "6" || optionsmenu == "q" || optionsmenu == "Q") {
						cout << "Exiting Program...\n";
						return 0;
					}
					else {
						cin.clear();
						cin.ignore(10000, '\n');
						cout << "Invalid Input.\n";
					}
				}
			
		
	}
}
