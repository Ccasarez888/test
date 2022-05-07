/******************************************************************************
# Author:           Charlie Casarez
# Assignment:       A03 
# Date:             April 3, 2022
# Description:    
# Input:           
# Output:          
# Sources:         
#*****************************************************************************/



#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;


//Function Declaration
void Welcome();
void Menu(char& selection);
char readOption();
void userInput(char& clubType, int& months, int& pt);
void calcCost(char clubType, int months, int pt);

//Constants
const double yearDiscount = .10;
const double ptDiscount = .20;
const double sports = 20.0;
const double ultraSports = 30.0;
const double pt_cost = 10.0;

//Main
int main(){
	char selection = ' ';
	char clubType = ' ';
	int months = 0;
	int pt = 0;

	Welcome();

	do{
		Menu(selection);
		if(selection == 'c' || selection == 'C'){

			userInput(clubType, months, pt);

		} 
		else if(selection == 'q' || selection == 'Q'){
			cout << "Goodbye!";
			exit(0);
		}
		else{
			"invalid";
		}
	}
	while (selection == 'C' or selection == 'c' or selection == 'Q' or selection == 'q');

	return 0;
}





//Function definitions 

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

//DisplayMenu
void Menu(char& selection){
	cout << "Please pick one of the following options\n";
	cout << "(C/c) Calculate the membership costs\n";
	cout << "(Q/Q) quit this program\n";
	cout << selection;
	selection = readOption();
}


//readOption
char  readOption(){
	char selection = ' ';
	cin >> selection;

	return selection;
}


//userInput
void userInput(char &clubType, int &months, int &pt){
	bool cont= false;
	while (cont==true){//while userput is valid
		cout << "Would you prefer (S)ports or (U)ltra sports club?\n";
		clubType = readOption();
		if (clubType == 'S' || clubType == 's' || clubType == 'u' || clubType == 'U'){
			cont=false;//good input
		}
		else{
			cout<<"invalid input, redo input plz\n";
			cont= true;
		}

		cout << "How many months of membership would you like?\n";
		months = readOption();
		if (months>0 && months < 12){
			cont = false;//good input
		}
		else{
			cout<<"invalid input, redo input plz\n";
			cont = true;

		}

		cout << "How many personal training sessions would you like?\n";
		pt = readOption();
		if(pt<0){
			cout << "Invalid input, please try again\n";
			cont = true;
		}
		else{
			cont = false;
		}
	}

	calcCost(clubType, months, pt);

}	


//calCost
void calcCost(char clubType, int months,int  pt) {
	cout<<clubType << endl;
	cout<<months << endl;
	cout<<pt<< endl;


	double memberTotal = 0.0;
	double trainingTotal = 0.0;

	if (clubType == 'S' || clubType == 's'){
		memberTotal = sports * months;
	}
	else{ 
		memberTotal = ultraSports * months;
	}

	if (memberTotal >= 12){
		memberTotal -= (memberTotal * yearDiscount);
		cout << "Your memebership total after the discount is: $" << memberTotal << endl;
	}
	else {
		cout << "your membership total is: $" << memberTotal << endl;
	}


	trainingTotal += (pt * pt_cost);
	if (pt > 5){
		trainingTotal -= (trainingTotal * ptDiscount);

	}
	cout << "Your personal training cost for " << pt << " sessions is $" 
		<< trainingTotal << endl;

	cout << "Your membership total is $" << trainingTotal + memberTotal 
		<< endl;


}

