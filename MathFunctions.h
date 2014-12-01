
// Mathematical functions
// Ed Callaghan
// November 2014

#ifndef MATHFUNCTIONS_H
#define MATHFUNCTIONS_H

#include <cmath>
#include <string> // is this even necessary?
#include <stdlib.h>
#include <time.h>
using namespace std ;

double randScale()
{
	return rand()/RAND_MAX ;
}

int randInt(int lower, int upper)
{
	return lower + rand() % upper ;
}

void to_string() {} ; // used to force compilation of sciForm()

// DOES NOT WORK
template <class T>
string sciForm(T input, int precision)
{
	double digitCount ;
	string inString = to_string(input) ;

	string outString = inString[0] + '.' ;

	int index = 1 ;
	while (digitCount < precision)
	{
		char currentDigit = inString[index] ;
		if (currentDigit != '.')
		{
			outString += currentDigit ;

			if (currentDigit != '-')
				digitCount++ ;
		}

		index++ ;
	}

	string ordOfMag = to_string(floor(log10(input))) ;

	outString += 'E' + ordOfMag ;

	return outString ;
}

#endif
