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
	bX.resize(1);
}

Mikor2::Mikor2 ( std::size_t K ) : aX(K), bX(K)
{
	dimS = K;
	pPrime = 1;
	qPrime = 1;
}

void Mikor2::setDimS (int n)
{
	dimS = n;
	aX.resize(n);
	bX.resize(n);
}

void Mikor2::setPprime (int n)
{
	pPrime = n;
}

void Mikor2::setQprime (int n)
{
	qPrime = n;
}

void Mikor2::setNNodes ()
{
	nNodes = pPrime*qPrime;
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

int Mikor2::getNNodes ()
{
	return nNodes;
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
	for (int i = 0; i < sizeA; i++) {
		aX[i] = 1.;
	}
	double sum = 0.;
	long int zs = 1;
	for (int i = 0; i < sizeA; i++) {
		aX[i] = (double)zs / (double)pPrime;
		zs = (zs*z) % pPrime;
	}
	for (int i = 0; i < upperb; i++) {
		double kterm = 1.;
		for (int j = 0; j < sizeA; j++) {
			double ent = this->fraction((i + 1)*aX[j]);
			kterm = kterm*(1. - ent - ent);
		}
		sum = sum + kterm*kterm;
	}
	return sum;
}

double Mikor2::hPoly (int z)
{
	double poly = pow(3, dimS)/pPrime*this->hSum(pPrime, z);
	return poly;
}

double Mikor2::hPolyChet (int z)
{
	int p = (pPrime - 1)/2;
	double chet = pow(3, dimS)/pPrime*(1. + 2.*this->hSum(p, z));
	return chet;
}

int Mikor2::firstOptimalA ()
{
	int upRange = (pPrime - 1)/2;
	int optimalA = 0;
	double optimalVal = 1.e+18;
	double hSum = 0.;
	for (int i = 1; i < (upRange + 1); i++) {
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

double Mikor2::hTildeSum ( int upperb, int z, std::vector<int> aArg) {
	for (int i = 0; i < dimS; i++) {
		bX[i] = 1.;
	}
	double smk = 0.;
	long int zs = 1;
	for (int i = 0; i < dimS; i++) {
		bX[i] = (double)zs / (double)qPrime + (double)aArg[i] / (double)pPrime;
		zs = (zs*z) % qPrime;
	}
	for (int i = 0; i < upperb; i++) {
		double kterm = 1.;
		for (int j = 0; j < dimS; j++) {
			double ent = this->fraction((i + 1)*bX[j]);
			kterm = kterm*(1. - ent - ent);
		}
		smk = smk + kterm*kterm;
	}
	return smk;
}

double Mikor2::hTildePoly (int z, vector<int> aArg)
{
	double poly = pow(3, dimS)/nNodes*this->hTildeSum(nNodes, z, aArg);
	return poly;
}

int Mikor2::firstOptimalB (int optimalA)
{
	vector<int> calcA(dimS);
	calcA[0] = 1;
	calcA[1] = optimalA;
	for (int i = 2; i < dimS; i++) {
		calcA[i] = calcA[i - 1]*optimalA % pPrime;
	}
	/*for (int i = 0; i < dimS; i++) {
		cout << calcA[i] << " ";
	}
	cout << endl;*/
	int optimalB = 0;
	double optimalVal = 1.e+28;
	double hSum = 0.;
	for (int i = 1; i < qPrime; i++) {
		hSum = this->hTildePoly(i, calcA);
		if (hSum < optimalVal) {
			optimalB = i;
			optimalVal = hSum;
		}
	}
	cout << "optimal: b = " << optimalB 
		 << ",\tH(b)-1 = " << setprecision(10) << optimalVal - 1. << endl;

	return optimalB;
}