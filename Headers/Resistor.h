#ifndef RESISTOR_H
#define RESISTOR_H 

#include <string>
#include <iostream>

#define nItems (sizeof band_list/sizeof *band_list)

enum {MINC = 3, MAXCC = 10};
enum resistor_band_items {BLACK, BROWN, RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET, GRAY, WHITE, UNKNOWN};



typedef struct 
{
 	char const *name;
 	enum resistor_band_items id;
}items;



class Resistor
{
private: 
	int __bands[MINC];
	int __multi;
public:
	//Resistor();
	//~Resistor();
	void setBands (const std::string& band1, const std::string& band2, const std::string& band3);
	
	int band1Value () {return this->__bands[0];}
	int band2Value () {return this->__bands[1];}
	int band3Value () {return this->__bands[2];}
	
	int srchItems (const std::string& ccode); //Look for the resistor band
	int scmp (char const *a, char const *b);

	long calculateValue ();
};


#endif
