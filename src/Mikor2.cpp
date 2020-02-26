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

/*
def is_prime(n):
    """
    Check if n is prime number
    :param n: number
    :return: True/False
    """
    # if n in (2, 3, 5, 7, 11):  # special case small primes
    #    return True
    if n % 2 == 0 or n == 1:  # special case even numbers and 1
        return False
    for i in range(3, int(math.sqrt(n)) + 1, 2):
        if n % i == 0:
            return False
    return True


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

/*
 *     def h_sum(self, upperb, z):
        """
        Summation in H(z) function without coefficient
        :param upperb: upper bound of summation
        :param z: polynomial parameter
        :return: sum in H(z) function
        """
        s = self.dim_s
        p = self.p_prime
        a = np.ones(s)
        sm_k = 0
        zs = 1
        for j in range(s):
            a[j] = zs / p
            zs = (zs*z) % p
        for k in range(1, upperb + 1):
            k_term = 1.
            for l in range(s):
                ent = fraction(k*a[l])
                k_term = k_term*(1. - ent - ent)
            sm_k = sm_k + k_term*k_term
        return sm_k

    def h_poly(self, z):
        return pow(3, self.dim_s)/self.p_prime*self.h_sum(self.p_prime, z)

    def h_poly_chet(self, z):
        p = int((self.p_prime - 1)/2)
        chet = pow(3, self.dim_s)/self.p_prime*(1. + 2.*self.h_sum(p, z))
        return chet
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
