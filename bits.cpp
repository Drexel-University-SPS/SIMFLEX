
// Starting point for CRIBFLEX simulation
// Ed Callaghan
// November 2014

// char is 1 byte = 8 bits - max of 255
// int is 4 bytes = 32 bits

// 1 Gbit is 1e9 bits is 1.25e8 bytes = 1.25e8 chars

// with P(flip|ray) = 0.025%, expect to see ~10^5 flips with this

#include "BitFunctions.h"
#include "MathFunctions.h"
#include "CosmicRayFunctions.h"
// #include "Drive.h" // do not include until finished writing
// #include "Drive.c" //

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std ;

int main()
{
//	// setting everything up...
	const int nBytes = static_cast<int>(1.25e3) ;
//	const int nBytes = 5 ;
	unsigned char bytes[nBytes] ;
	const int typeSize = sizeof(bytes[0]) ;
	const int nBits = 8*typeSize ;

	cout << "Using chars is " << typeSize << " bytes\n\n" ;

// 	// all of the below should be packaged into a class c_Drive
//	// initializes all bits to 1, to be monitored for flipping
	for (int iByte = 0 ; iByte < nBytes ; iByte++)
	{
		unsigned char newByte = 0 ;
		for (int iBit = 0 ; iBit < nBits ; iBit++)
		{
			setBit(newByte, iBit) ; // see BitFunctions.h
		}

		bytes[iByte] = newByte ;
	}

//	// checks that bits have been set
	bool flag = false ;
	for (int iByte = 0 ; iByte < nBytes ; iByte++)
	{
		for (int iBit = 0 ; iBit < nBits ; iBit++)
		{
			if (bitSet(bytes[iByte], iBit) == false)
				flag = true ;
		}
	}

	if (flag == true)
		cout << "bits not set\n" ;
	else
		cout << nBytes << " bytes = " << 8*nBytes << " bits set\n\n" ;

//	// initializes RNG
	srand(time(0)) ;

	cout << "RNG initialized\n\n" ;

//	// begins run
	int nLoops = 1e5 ;
	int loopCount = 0 ;

	int flipCount = 0 ;
	while (loopCount < nLoops)
	{
//		// flip? (loop over bits)
		if (didFlip() == true)
			flipCount++ ;

//		// monitoring (loop over bits)

		loopCount++ ;
	}

	cout << flipCount << " flips occurred\n" ;
}
