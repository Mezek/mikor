/**
 * @brief		Class file for numerical integration by the Korobov's method.
 * @author		Erik Bartoš
 */

#include <cassert>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <cmath>
#include <vector>


#include "Mikor2.h"

using namespace std;

/// Default constructor
/// Set the number of variables of the integration K, maximum is 20.
/// Set default parameter values.

Mikor2::Mikor2 ( std::size_t K ) : aX(K)
{
	dd = K;
	pPrime = 1;
	qPrime = 1;
}


void Mikor2::setPprime (int n)
{
	pPrime = n;
}

void Mikor2::printParameters ()
{
	cout << mOut << "Parameters" << endl;
	cout << mOS << "d  = " << dd << endl;
	cout << mOS << "p  = " << pPrime << endl;
	cout << mOS << "q  = " << qPrime << endl;
}

double Mikor2::fraction (double x)
{
	double f, p;
	f = modf(x, &p);
	return f;
}

bool Mikor2::isPrime (int n)
{
	if (n < 2) return false; 
	if (n = 2) return true; 
	if (n % 2 == 0) return false;
	for (int i=3; (i*i)<=n; i+=2) {
		if(n % i == 0 ) return false;
    }
	return true;
}
/*
def n_prime(n):
    """
    Find prime p >= n
    :param n: Number of nodes
    :return: prime p >= n
    """
    next_prime = n
    while not is_prime(next_prime):
        next_prime = next(filter(is_prime, count(next_prime)))
    return next_prime
*/

double Mikor2::hSum (int upperb, int z)
{
	int sizeA = aX.size();
	for (int i = 0; i < sizeA; ++i) {
		aX[i] = 1.;
	}
	double sum = 0.;
	int zs = 1;
	for (int i = 0; i < sizeA; ++i) {
		aX[i] = (double)zs/pPrime;
		zs = (zs*z) % pPrime;
	}
	for (int i = 0; i < upperb; ++i) {
		double kterm = 1.;
		for (int j = 0; j < sizeA; ++j) {
			double ent = this->fraction(i*aX[j]);
			kterm = kterm*(1. - ent - ent);
		}
		sum = sum + kterm*kterm;
	}
	return sum;
}

double Mikor2::hPoly (int z)
{
	double poly = pow(3, dd)/pPrime*this->hSum(pPrime, z);
	return poly;
}

double Mikor2::hPolyChet (int z)
{
	int p = (pPrime - 1)/2;
	double chet = pow(3, dd)/pPrime*(1. + 2.*this->hSum(p, z));
	return chet;
}

void Mikor2::firstOptimalA ()
{
	int upRange = (pPrime - 1)/2;
	int optimalA = 0;
	double optimalVal = 1e+18;
	double hSum = 0.;
	for (int i = 1; i < (upRange + 1); ++i) {
		hSum = this->hPolyChet(i);
		if (hSum < optimalVal) {
			optimalA = i;
			optimalVal = hSum;
		}
		if ((i % 1000) == 0) {
			cout << i << ". iteration" << endl;
		}
	}
	cout << mOS << "optimal a    = " << optimalA << endl;
	cout << mOS << "optimal H(a) = " << optimalVal << endl;
}

/**
 * @todo Find optimal numbers.
 */
