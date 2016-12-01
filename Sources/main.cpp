#include <iostream>
#include "Resistor.h"

using namespace std;



int main(int argc, char const *argv[])
{

	Resistor resistor;
	long totalResistance;
	//cout << "argc #\t" << argc << endl;
	resistor.setBands(argv[1], argv[2], argv[3]);
	//debug
	/*
	for (int i = 1; i < argc; ++i)
	{
		cout << argv[i] << "\t" << flush;
	}
	cout << resistor.band1Value() << endl;
	cout << resistor.band2Value() << endl;
	cout << resistor.band3Value() << endl;
	//end debug
	*/
	totalResistance = resistor.calculateValue();
	cout << totalResistance << endl;
	return 0;
}

