#ifndef RESISTOR_H
#define RESISTOR_H 

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

#define nItems (sizeof band_list/sizeof *band_list)

enum {MINC = 4, MAXCC = 10};
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
	std::string __band_string[MINC];
	int __multi;
	bool validate();

public:
	//Resistor();
	//~Resistor();
	void setBands (const std::string& band1, const std::string& band2, const std::string& band3, const std::string& band4 = "-2");
	
	int srchItems (const std::string& ccode); //Look for the resistor band
	int scmp (char const *a, char const *b);
	
	long calculateValue ();
};


#endif
