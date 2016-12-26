#include <iostream>
#include "Resistor.h"

using namespace std;

static void showUsage(std::string name)
{
    std::cerr << "Usage: " << name << " <option(s)> color bands\n"
              << "Options:\n"
              << "\t-h, --help\t\t\t\tShow this help message\n"
              << "\t-b, --bands BAND1 BAND2 BAND3 / BAND4\tSpecify the resistor color bands\n"
              << "\t-t, --tolerance TOLERANCE\t\tSpecify the resistor tolerance"
              << std::endl;
}


int main(int argc, char const *argv[])
{
	Resistor resistor; // make an instance of object Resistor
	long totalResistance; // variable to store the total resistance
	string toleranceBand; //

	//pass comand line arguments accordingly 
	for (int i = 1; i < argc; ++i)
	{
		if (string(argv[i]) == "-h" || string(argv[i]) == "--help")
		{
			showUsage(argv[0]);
			return 0;
		}
		if (string(argv[i]) == "-t" || string(argv[i]) == "--tolerance")
		{
			if (i + 1 < argc)
			{
				//cout << "-t found @: "<< i << " there are other arguments" << endl;
				if (string(argv[i+1]) == "-b" || string(argv[i+1]) == "--bands")
				{
					cout << "-t [--tolerance] option requires one argument" << endl;
				}
				else
				{
					toleranceBand = argv[i+1];
					cout << "tolerance band is set to: " << toleranceBand << endl;
				}
			}
		}
		else if (string(argv[i]) == "-b" || string(argv[i]) == "--bands")
		{
			int bandNum = argc - i;
			if (bandNum >= 5)
				resistor.setBands(argv[i+1], argv[i+2], argv[i+3], argv[i+4]);	
			else if (bandNum == 4)
				resistor.setBands(argv[i+1], argv[i+2], argv[i+3]);
			else
				cout << "-b [--bands] option requires 3 or 4 arguments" << endl;
		}
	}

	totalResistance = resistor.calculateValue(); //calculate the total resistance
	//Resistor::calculateValue() returns -1 if any of the arguments are invalid 
	//Prints an error 
	if (totalResistance != -1)
	{
		cout << totalResistance << endl; // print the total calculated value
	}
	return 0;
}

