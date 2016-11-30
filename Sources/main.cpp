#include <iostream>
#include "Resistor.h"

using namespace std;



int main(int argc, char const *argv[])
{

	Resistor resistor;

	cout << "argc #\t" << argc << endl;

	//printf("%s:\t%d\n", "argc #",argc);
	resistor.setBands(argv[1], argv[2], argv[3]);
	for (int i = 1; i < argc; ++i)
	{
		cout << argv[i] << endl;
	}
	cout << resistor.band1Value() << endl;
	cout << resistor.band2Value() << endl;
	cout << resistor.band3Value() << endl;
	return 0;
}

