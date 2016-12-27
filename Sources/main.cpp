#include <iostream>
#include "Resistor.h"

using namespace std;

static void showUsage(std::string name)
{
    std::cout << "Usage: " << name << " color bands <option(s)>\n"
    		  << "Calculates resistor value [resistance] from it's color bands.\n\n"
              << "Options:\n"
              << "\t-h, --help\t\t\t\t\tShow this help message\n"
              << "\t-b, --bands <BAND1><BAND2><BAND3>/<BAND4>\tSpecify the resistor color bands\n"
              << "\t-t, --tolerance <TOLERANCE>\t\t\tSpecify the resistor tolerance\n"
              << std::endl;
}


int main(int argc, char const *argv[])
{
	//cout << "argc = " << argc << endl; //Debug
	Resistor resistor; // make an instance of object Resistor
	long totalResistance; // variable to store the total resistance
	string toleranceBand; //
	bool t = true; //if an argument is passed with the optioin
	
	for (int i = 1; i < argc; ++i)
	{
		// -h , --help  
		if (string(argv[i]) == "-h" || string(argv[i]) == "--help")
		{
			//cout << "-h found @ index: " << i << endl; //Debug
			showUsage(argv[0]);
			return 0;
		}
		// -t , --tolerance
		else if (string(argv[i]) == "-t" || string(argv[i]) == "--tolerance")
		{
			//cout << "-t found @ index: " << i << endl; //Debug
			if (i+1 == argc) //somehow doesn't work
			{
				//cout << "******" << endl; // Debug
				t = false;
			}
			if ( ((string(argv[i+1]).find("-") != string::npos) || (string(argv[i+1]).find("--") != string::npos)))
			{
				t = false;	
			}
			else
			{
				if (i+1 < argc)
				{
					cout << "Tolerance band = " << argv[i+1] << endl;
					toleranceBand = string(argv[i+1]);
				}
			}
			if (t == false)
			{
				cout << "-t, --tolerance <argument>" << endl;
				//return 0;
			}	
		}
		// -b , --bands
		else if (string(argv[i]) == "-b" || string(argv[i]) == "--bands")
		{
			//cout << "-b found @ index: " << i << endl; //Debug
			//int bandNum = argc - i; // Debug
			//cout << "bandNum = " << bandNum << '\t' << "i = " << i << endl; //Debug
			int k = 0; // counter for occurrence of other options passed by user
			int b = 0; // counter for number of bands passed by user
			for (int j = i+1; j < argc; ++j)
			{
				//cout << "#" << j << '\t' << argv[j] << endl; //Debug
				if (k == 0)
				{
					if ( !((string(argv[j]).find("-") != string::npos) || (string(argv[j]).find("--") != string::npos)))
					{
						//cout << "band name:\t" << argv[j] << endl; //Debug
						b++;
					}
					else
					{
						k++;
					}
				}
			}
			//cout << "b = " << b << '\t' << "k = " << k << endl; //Debug
			if (k >= 0 && b < 3)
			{
				cout << "-b, --bands <BAND COLOR> <BAND COLOR> <BAND COLOR> / <BAND COLOR>" << endl;
				return 0;
			}
			else if (b == 3)
			{
				cout << "3 band resistor" << endl; //Debug
				resistor.setBands(argv[i+1], argv[i+2], argv[i+3]);	
			}
			else if (b == 4)
			{
				cout << "4 band resistor" << endl; //Debug
				resistor.setBands(argv[i+1], argv[i+2], argv[i+3], argv[i+4]);	
			}
		}	
	}

	totalResistance = resistor.calculateValue(); //calculate the total resistance
	//Resistor::calculateValue() returns -1 if any of the arguments are invalid 
	//Prints an error 
	if (totalResistance != -1)
	{
		cout << "Total Resistance = " << totalResistance << " ohm"<< endl; // print the total calculated value
	}
	resistor.tolerance(totalResistance, toleranceBand);
	return 0;
}

