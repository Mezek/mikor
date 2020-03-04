/**
 * @brief		Class file for numerical integration by the Korobov's method.
 * @author		Erik Bartoš
 */

#include <cassert>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
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

Mikor2::Mikor2 ()
{
	dimS = 1;
	pPrime = 1;
	qPrime = 1;
	aX.resize(1);
}

Mikor2::Mikor2 ( std::size_t K ) : aX(K)
{
	dimS = K;
	pPrime = 1;
	qPrime = 1;
}

void Mikor2::setDimS (int n)
{
	dimS = n;
	aX.resize(n);
}

void Mikor2::setPprime (int n)
{
	pPrime = n;
}

void Mikor2::setQprime (int n)
{
	qPrime = n;
}

int Mikor2::getDimS ()
{
	return dimS;
}

int Mikor2::getPprime ()
{
	return pPrime;
}

int Mikor2::getQprime ()
{
	return qPrime;
}

void Mikor2::printParameters ()
{
	cout << mOut << "Parameters" << endl;
	cout << mOS << "d  = " << dimS << endl;
	cout << mOS << "p  = " << pPrime << endl;
	cout << mOS << "q  = " << qPrime << endl;
}

double Mikor2::fraction (double x)
{
	double f, p;
	f = modf(x, &p);
	//if ( f > 1. ) { cout << mError << f << endl; }
	return f;
}

bool Mikor2::isPrime (int n)
{
	if (n < 2) return false; 
	if (n == 2) return true; 
	if (n % 2 == 0) return false;
	for (int i = 3; (i*i) <= n; i += 2) {
		if(n % i == 0 ) return false;
    }
	return true;
}

int Mikor2::nextPrime (int n)
{
	int fol = n;
	while (!this->isPrime(fol)) {
		++fol;
	}
	return fol;
}

double Mikor2::hSum (int upperb, int z)
{
	int sizeA = dimS;
	for (int i = 0; i < sizeA; ++i) {
		aX[i] = 1.;
	}
	double sum = 0.;
	int zs = 1;
	for (int i = 0; i < sizeA; ++i) {
		aX[i] = (double)zs/(double)pPrime;
		zs = (zs*z) % pPrime;
		if ( aX[i] < 0. ) { cout << mError << i << " " << aX[i] << endl; }
	}
	for (int i = 0; i < upperb; ++i) {
		double kterm = 1.;
		for (int j = 0; j < sizeA; ++j) {
			double ent = this->fraction((i + 1)*aX[j]);
			double dva = 1. - ent - ent;
			//if ( aX[j] < 0. ) { cout << mError << i << " " << aX[j] << endl; }
			//if ( ent < 0. ) { cout << mError << ent << " " << dva << endl; }
			//if ( dva > 1. ) { cout << mError << ent << " " << dva << endl; }
			kterm = kterm*(1. - ent - ent);
		}
		sum = sum + kterm*kterm;
		//if ((sum > 19000.) && (sum < 20000.)) {cout << i << " " << sum << " " << kterm << endl;}
	}
	return sum;
}

double Mikor2::hPoly (int z)
{
	double poly = pow(3., dimS)/pPrime*this->hSum(pPrime, z);
	return poly;
}

double Mikor2::hPolyChet (int z)
{
	int p = (pPrime - 1)/2;
	double chet = pow(3., dimS)/pPrime*(1. + 2.*this->hSum(p, z));
	//cout << "\n" << mOS << pow(3., dimS)/pPrime << " " << this->hSum(p,z) << endl;
	return chet;
}

int Mikor2::firstOptimalA ()
{
	int upRange = (pPrime - 1)/2;
	int optimalA = 0;
	double optimalVal = 1.e+18;
	double hSum = 0.;
	for (int i = 1; i < (upRange + 1); ++i) {
		hSum = this->hPolyChet(i);
		if (hSum < optimalVal) {
			optimalA = i;
			optimalVal = hSum;
		}
		/*if ((i % 1000) == 0) {
			cout << i << ". iteration" << endl;
		}*/
	}
	cout << "optimal: a = " << optimalA 
		 << ",\tH(a) = " << setprecision(10) << optimalVal << endl;
	return optimalA;
}
