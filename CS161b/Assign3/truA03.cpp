/*****************************
 * Author: Charlie Casarez
 * Assignment: 
 * Date: 04/3/2022
 * Descritpion: 
 * Input:
 * Output:
 * Sources:
 *****************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

//Declarations
void Welcome();
void Menu(char selection);
char readOption();
void userInput(char& clubType, int& numMonths, int& sessions);
void calcCost(char clubType, int numMonths, int sessions);

//constants
const double yearDiscount = .10;
const double sessionDiscount = .20;
const double sports = 20.0;
const double ultraSports = 30.;

//main 
int main(){
	char clubType = ' ';
	char selection = ' ';
	int numMonths = 0;
	int sessions = 0;


	Welcome();

	userInput(clubType, numMonths, sessions);
cout << clubType << numMonths;
return 0;	
}



//Definitions

//Welcome
void Welcome(){
        cout << "Welcome to my fitnessClub  program!\n";
        cout << "******************************************************************************\n";
        cout << "The cost to become a member of the fitClub center is as follows: \n\n";
        cout << "The membership fee per month for Sports Club is $20.00\n";
        cout << "*\n";
        cout << "The membership fee per month for Ultra Sports Club is $30.00\n";
        cout << "*\n";
        cout << "If the membership is bought and paid for 12 or more months, the discount is 10% off membership cost\n";
        cout << "*\n";
        cout << "Personal training sessions are $10.00 per session\n";
        cout << "*\n";
        cout << "If more than 5 personal training sessions are bought and paid for, the discount on each session is 20%\n\n\n";
}


void Menu(char& selection){
	cout << "Please pick one of the following: \n\n";
	cout << "(C/c) Calculate membership costs\n";
	cout << "(Q/q) quit this program\n";
	selection = readOption();
}
char readOption(){
	char selection = ' ';
	cin >> selection;

	return selection;
}
void userInput(char& clubType, int& numMonths, int& sessions){
	cout << "Would you prefer (S)ports or (U)ltra sports club?\n";
	cin >> clubType;
	while(clubType != 's' || clubType != 'u'){
		cout << "invalid membership type! try again\n";
		cin >> clubType;
	//	clubType = readOption();

	}
	clubType = readOption();
	cout << "How many months of membership would you like?\n";
	cin >> numMonths;
	numMonths = readOption();
	while(numMonths > 12 || numMonths < 0){
		cout << "Invalid number please try again\n";
		cin >> numMonths;
		numMonths = readOption();
	}

	cout << "How many person traning sesions would you like?\n";
       	cin >> sessions;
	while(sessions < 0){
		cout << "Invalid input, please try again\n";
		cin >> sessions;
		sessions = readOption();
	}	

}
//void calcCost(char clubType, int numMonths, int sessions){}
