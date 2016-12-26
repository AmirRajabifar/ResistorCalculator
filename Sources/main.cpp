#include <iostream>
#include "Resistor.h"

using namespace std;



int main(int argc, char const *argv[])
{

	Resistor resistor; // make an instance of object Resistor
	long totalResistance; // variable to store the total resistance
	//pass comand line arguments accordingly 
	if (argc == 5)
		resistor.setBands(argv[1], argv[2], argv[3], argv[4]);	
	else
		resistor.setBands(argv[1], argv[2], argv[3]);
	totalResistance = resistor.calculateValue(); //calculate the total resistance
	//Resistor::calculateValue() returns -1 if any of the arguments are invalid 
	//Prints an error 
	if (totalResistance != -1)
	{
		cout << totalResistance << endl; // print the total calculated value
	}
	return 0;
}

