#include "Resistor.h"

items band_list[] = {
	{"black", BLACK},
	{"brown", BROWN},
	{"red", RED},
	{"orange", ORANGE},
	{"yellow", YELLOW},
	{"green", GREEN},
	{"blue", BLUE},
	{"violet", VIOLET},
	{"gray", GRAY},
	{"white", WHITE}
};

unsigned int multiplier[] = {1, 10, 100, 1000, 10000, 100000, 1000000,
10000000, 100000000, 1000000000};


void Resistor::setBands (const std::string& band1, const std::string& band2, const std::string& band3, const std::string& band4)
{
		this->__band_string[0] = band1;
		this->__band_string[1] = band2;
		this->__band_string[2] = band3;
		this->__band_string[3] = band4;
		this->__bands[0] = srchItems(band1);
		this->__bands[1] = srchItems(band2);
		this->__bands[2] = srchItems(band3);		
		this->__bands[3] = srchItems(band4);
		/*
		for (int i = 0; i < MINC; ++i)
		{
			std::cout << __band_string[i] << '\t' << __bands[i] << std::endl;
		}
		std::cout << std::endl;
		*/
}



int Resistor::srchItems (const std::string& ccode)
{
	//char lccode [MAXCC] = "";
	std::string String = ccode;
	std::transform(String.begin(), String.end(), String.begin(), tolower);

	const char *lccode = String.c_str();
	
	//std::cout << "nItems = " << nItems << std::endl; //Debug line
	for (int i = 0; i < (int)nItems; ++i) 
	{	
		if (*lccode == *(band_list[i].name))
		{
			//std::cout << "in the first if" << std::endl; //Debug line
			if (!this->scmp(band_list[i].name, lccode))
			{	
				//std::cout << "i = " << i <<std::endl; //Debug line
				return i;
			}
		}
	}
	return -1;
}

int Resistor::scmp (char const *a, char const *b)
{
    if (!a && !b) return 0;
    if ( a && !b) return 1;
    if (!a &&  b) return -1;

    for (; *a && *b && *a == *b; a++, b++) {}

    return *a - *b;
}

long Resistor::calculateValue ()
{
	long total = 0;
	if (this->validate())
	{
		if (__bands[MINC - 1] == -1)
		{
			for (int i = 0; i < MINC - 2; ++i)
			{
				//first band , second band values
				total = (total * 10) + this->__bands[i]; 
			}
			//third band is the multiplier
			this->__multi = this->__bands[2]; 
		}
		else
		{
			for (int i = 0; i < MINC - 1; ++i)
			{
				//first band , second band values
				total = (total * 10) + this->__bands[i]; 
			}
			//third band is the multiplier
			this->__multi = this->__bands[3]; 			
		}
		total *= multiplier[this->__multi]; // *
		return total;
	}
	else
	{
		return -1;
	}
}


bool Resistor::validate()
{
	int j = 0;
	if (__bands[MINC - 1] == -1)
	{
		for (int i = 0; i < MINC - 2; ++i)
		{
			if (this->__bands[i] == -1)
			{
				std::cout << __band_string[i] << std::endl;
				j++;
			}
		}
	}
	else
	{
		for (int i = 0; i < MINC; ++i)
		{
			if (this->__bands[i] == -1)
			{
				std::cout << __band_string[i] << std::endl;
				j++;
			}
		}
	}

	if (j == 1) 
	{
		std::cout << "Is an invalid input" << std::endl;
		return 0;
	}
	else if (j > 1) 
	{
		std::cout << "Are invalid inputs" << std::endl;
		return 0;
	}
	else 
		return 1;
}



