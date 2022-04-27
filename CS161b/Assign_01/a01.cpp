/******************************************************************************
# Author:           (Charlie Casarez)
# Assignment:       (Assignment 1)
# Date:             (04/14/22)
# Description:      This program asks the user to enter their data plan, how
 much they used last month, and calculates how much they spent. If suitable,
suggest upgrading to save money
# Input:            CHAR planSize
		    DOUBLE n

# Output:	    INT plan charge
                    DOUBLE total
		    DOUBLE overage (total - 75)
# Sources:          Lab 1 specifications
#                   mycplusplus.com
#                   
#******************************************************************************/


#include <iomanip>
#include <cmath>
#include <iostream>
#include<string>
using namespace std;

//Menu function
void DisplayMenu(){
cout << "***** Welcome to Mint Mobile! *****" << endl;
cout << "Lets Calculate youre monthly bill!" << endl;
cout << "S: 2GB $35/mo*" << endl
     << "M: 4GB $50/mo*" << endl
     << "L: 8GB $70/mo*" << endl
     << "U: Unlimited $75/mo" << endl
     << "*Overage charges $15 per GB" << endl;

}

//Main
int main(){

	char planSize;
	double total = 0.0;
	double n = 0.0;
	const double  planS = 35.00;
	const double planM = 50.00;
	const double planL = 70.00;
	const double planU = 75.00;

//Display Menu
DisplayMenu();

//User input and validity

cout << " \n Which plan are you on? (S/M/L/U): " << endl;
cin >> planSize;

while(true){
	if(planSize !='S' && planSize != 's' 
 	&& planSize != 'M' && planSize != 'm'
        && planSize != 'L' && planSize != 'l'
	&& planSize != 'U' && planSize != 'u')
{
	cout << "Invalid Choice!" << endl;
	cout << "Which plan are you on? (S/M/L/U)" << endl;
	cin >> planSize;
}

else
	break;
}

//gb used
cout << "How many GB did you use last month?" << endl;
cin >> n;
n = ceil(n);

//Plan Switch
switch(planSize){
	case 's':
	case 'S':
	   total = planS;
	   cout << "Plan charges: $" << fixed << setprecision(2) << 35 << endl;
	   if(n > 2){
	   total += (n-2) * 15;
	   cout << "Overage charges: $" << fixed << setprecision(2) << (n-2)*15;
}
break;
	case 'm':
	case 'M':
	   total = planM;
	   cout << "Plan charges: $" << fixed << setprecision(2) << 50 << endl;
	   if(n > 4){
	   total += (n-4) * 15;
	   cout << "Overage charges: $" << fixed << setprecision(2) << (n-4)*15 <<
	   endl;
}
break;
	case 'l':
	case 'L':
	   total = planL;
	   cout << "Plan charges: $" << fixed << setprecision(2) << 70 << endl;
	   if (n > 8){
	   total += (n-8)*15;
	   cout << "Overage charges: $" << fixed << setprecision(2)
	    << (n-8)*15 << endl;
}
break;
	case 'u':
	case 'U':
	   total = planU;
	   cout << "Plan charges: $" << fixed << setprecision(2) << 75 << endl;
break;
}

//totals
cout << "Total cost: $" << total << endl;
if(total > 75){
          cout << "Upgrade to Unlimited and save $" << fixed << setprecision(2)	
          << (total - 75) << endl;
}


//Goodbye
cout << "Thank you for using mint mobile, \n goodbye!" << endl;

return 0;
}
