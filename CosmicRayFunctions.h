
// Functions to simulate CRs
// Ed Callaghan
// November 2014

// log10(RAND_MAX) = 9

#ifndef COSMICRAYFUNCTIONS_H
#define COSMICRAYFUNCTIONS_H

#include "MathFunctions.h"

#include <stdlib.h>
#include <time.h>
using namespace std ;

// super elementary --- probability that a bit will flip (1 -> 0 or 0 -> 1) ~ 0.025% chance (Ed made this up)
double ProbOfFlip()
{
	return 0.00025 ;
}

bool didFlip()
{
//	// "successful" flip 0.025% of the time
//	// need to code this in without the magic numbers, eh?
//	// also going to need a better name here than "decider"

	int decider = randInt(0, pow(10, 5)) ;

	if (decider < 25)
		return true ;
	else
		return false ;
}

#endif
