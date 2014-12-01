
// Functions to call on individual chars
// Ed Callaghan
// November 2014

#ifndef BITFUNCTIONS_H
#define BITFUNCTIONS_H

#include <iostream>
using namespace std ;

// should implement in all below some kind of warning or error for if bit-index exceeds size of T

// setBit: byte += 2^bit
template <class T>
void setBit(T &byte, int bit)
{
	byte = byte | (1 << bit) ;
}

template <class T>
bool bitSet(T &byte, int bit)
{
	T mask = (1 << bit) ;

	return byte & mask ;
}

template <class T>
void printInt(T byte)
{
	cout << static_cast<int>(byte) ;
}

/* read/write methods for binary files

binary fstreams use one feed for writing and one feed for reading: g(et) and p(ut)
the tellg() and seekg(int) methods respectively print and set the positions of the g-feed
analagous methods exist for the p-feed

call fstream::write(char* memblock, int size) ; memblock points to data to write at tellp()
call fstream::read(char *memblock, int size) ; memblock points to location to write to at position tellg()

in both of the above methods size is either nBits or nChars - but which???

*/

#endif
