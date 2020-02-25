/**
 * @brief		Class file for numerical integration by the Korobov's method.
 * @author		Erik Bartoš
 */

#include <cassert>
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <cmath>

#include "Mikor2.h"

using namespace std;

/// Default constructor
/// Set the number of variables of the integration K, maximum is 20.
/// Set default parameter values.

Mikor2::Mikor2 ( std::size_t K ) : vecX(K), vecAX(K), vecBX(K)
{
	numK = K;
	dd = K;
	pp = 1;
	qq = 1;

	cout << mOut << "K: " << numK << "\tN: " << numN << endl;
	cout << mOut << "d: " << dd << endl;
	cout << mOut << "p: " << pp << endl;
	cout << mOut << "q: " << qq << endl;
}

void Mikor2::printParameters ()
{
	cout << mOut << "Parameters" << endl;
	cout << mOS << "K    = " << numK << endl;
}


int Mikor2::Calculate ()
{
	this->printParameters();
}

/**
 * @todo Find optimal numbers.
 */
