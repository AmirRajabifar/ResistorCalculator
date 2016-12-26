#include <iostream>
#include "Resistor.h"

using namespace std;



int main(int argc, char const *argv[])
{

	Resistor resistor;
	long totalResistance;
	//cout << "argc #\t" << argc << endl;
	if (argc == 5)
	{
		resistor.setBands(argv[1], argv[2], argv[3], argv[4]);	
	}
	else
	{
		resistor.setBands(argv[1], argv[2], argv[3]);
	}

	totalResistance = resistor.calculateValue();
	if (totalResistance != -1)
	{
		cout << totalResistance << endl;
	}
	return 0;
}

