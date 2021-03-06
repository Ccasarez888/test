/******************************************************************************
# Author:           Charlie Casarez
# Assignment:       A02 
# Date:             April 20, 2022
# Description:      This program will display a menu for the user and ask them 
		    to make a selection. The program will then calculate simple
		    interest or compound interest based off of their inputs.
# Input:	    INT userChoice, int selection, DOUBLE principal, interest, 
		    years, period.
# Output:           acrued interest, total interest
# Sources:	    zybooks, stackoverflow(Help with functions)
#******************************************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//Function Prototypes
double simpleInterest(double principal, double interest, double years);

double compoundInterest(double principal, double interest, double years,
double period);

void Welcome();
void DisplayMenu();
int readOption();
void executeOption(int userChoice);
void goodbye();

//main
int main(){
	int userChoice;

	Welcome();

	do {
	DisplayMenu();
	userChoice = readOption();
	executeOption(userChoice);
	goodbye();
}
	while (userChoice != 3);

	return 0;
}

//Welcome
void Welcome(){
	cout << "Welcome to my program!\n\n\n";
}

//DisplayMenu
void DisplayMenu(){
	cout << "Please pick one of the following: \n";
	cout << "1. Simple interest \n";
	cout << "2. Compound interest \n";
	cout << "3. Quit \n";

}

//validate user choice
int readOption(){
	int userChoice;
	while(userChoice < 1 || userChoice > 3){
	cout << "Please enter a value 1-3\n";
	cin >> userChoice;
}
	return userChoice;
}
//Calculate simple interest
double simpleInterest(double principal, double interest, double years){
	return principal * interest * years / 100;
}
//Calculate compound interest
double compoundInterest(double principal, double interest, double years, 
double period){
	return principal * (pow(1 + interest * 0.01 / period, years * period)) - principal;
}
//choice selection
void executeOption(int selection){
	double principal = 1;
	double interest = 1;
	double years = 1;
	double period = 1;

	double totalInterest = 0;
	double interestAmount = 0;

	if(selection == 1){
	cout << "Enter the principal amount: \n";
	cin >> principal;
	cout << "Enter the interest rate: \n";
	cin >> interest;
	cout << "Enter the time in years: \n";
	cin >> years;
}
	if(selection == 2){
	cout << "Enter the principal amount: \n";
	cin >> principal;
	cout << "Enter the interest rate: \n";
	cin >> interest;
	cout << "Enter the time in years: \n";
	cin >> years;
	cout << "Enter the number of compounding period: \n";
	cin >> period;
}
	if(selection == 3){
	return;
}
	if(selection == 1){
	interestAmount = simpleInterest(principal, interest, years);
}
	else if(selection == 2){
	interestAmount = compoundInterest(principal, interest, years, period);
}

//output
	totalInterest = principal + interestAmount;

	cout << setprecision(2) << fixed;
	cout << "Interest accreued: " << interestAmount << endl;
	cout << "Total accrued amount(interest + principal): " << totalInterest << endl;
}

//goodbye!
void  goodbye(){
	cout << "Thanks for using my program!\n";
	cout << "***\n";
	cout << "Goodbye!\n";
}







