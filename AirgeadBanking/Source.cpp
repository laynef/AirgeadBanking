/**
*
* Name: Layne Faler
* Course: CS210
* Date: 06/5/21
* 
* Project: Airgead Banking
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	// declare variables
	float initInv, monDep, AnuInt, months, years, totalAm, intAmt, yearTotInt;
	// Display Data Inputs
	cout << "************\n";
	cout << "**** Data Input ****\n";
	cout << "Initial Investment Amount: \n";
	cout << "Monthly Deposit: \n";
	cout << "Annual Intrest: \n";
	cout << "Number of years: \n";
	system("PAUSE");

	// Get inputs for user
	cout << "***********\n";
	cout << "**** Data Input ****\n";
	cout << "Initial Investment Amount: $";
	cin >> initInv;
	cout << "Monthly Deposit: $";
	cin >> monDep;
	cout << "Annual Interest: %";
	cin >> AnuInt;
	cout << "Number of years: ";
	cin >> years;

	months = years * 12; // convert years into months
	system("PAUSE");

	totalAm = initInv; // set total amount with init investment

	// display table header
	cout << "\nBalance and Interest Without Additional Monthly Deposits\n";
	cout << "==============================================================\n";
	cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
	cout << "--------------------------------------------------------------\n";

	// calculate balance and interest in each year
	for (int i = 0; i < years; i++) {
		intAmt = (totalAm) * (AnuInt / 100); // calculate interest amount
		totalAm +=  intAmt; // add interest amount to total ammount
		cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << totalAm << "\t\t\t$" << intAmt << "\n";
	}

	totalAm = initInv; // reset total amount with init investment

	// display table header
	cout << "\n\nBalance and Interest With Additional Monthly Deposits\n";
	cout << "==============================================================\n";
	cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
	cout << "--------------------------------------------------------------\n";

	// loop through all the years
	for (int i = 0; i < years; i++) {
		yearTotInt = 0;

		// calculate balance and interest for each month in the year
		for (int j = 0; j < 12; j++) {
			intAmt = (totalAm + monDep) * ((AnuInt / 100) / 12); // Calculate initial amount
			yearTotInt += intAmt; // add interest amount to yearly total interest
			totalAm += monDep + intAmt; // add monthly desposit and interest ammount to total amount
		}

		// display table body
		cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << totalAm << "\t\t\t$" << yearTotInt << "\n";
	}

	return 0;
}
