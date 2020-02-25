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

Mikor2::Mikor2 ( std::size_t K ) : vecX(K), vecAX(K), vecBX(K)
{
	numK = K;
	dd = K;
	pp = 1;
	qq = 1;
}

void Mikor2::printParameters ()
{
	cout << mOut << "Parameters" << endl;
	cout << mOS << "K  = " << numK << endl;
	cout << mOS << "d  = " << dd << endl;
	cout << mOS << "p  = " << pp << endl;
	cout << mOS << "q  = " << qq << endl;
}


void Mikor2::firstOptimalA ()
{
	int upRange = (pp - 1)/2;
	int optimalA = 0;
	double optimalVal = 1e+18;

	cout << mOS << upRange << endl;

	cout << mOS << "optimal a    = " << optimalA << endl;
	cout << mOS << "optimal H(a) = " << optimalVal << endl;
	/*  up_ran = int((self.p_prime - 1)/2)
        optimal_a = 0
        optimal_val = 1e+18

        for i in range(1, up_ran + 1):
            h_sum = self.h_poly_chet(i)
            if h_sum < optimal_val:
                optimal_a = i
                optimal_val = h_sum
            if prt != 0 and i % 1000 == 0:
                print(f'{i}. iteration')
        self.a_opt = optimal_a
        self.a_opt_value = optimal_val
        return optimal_a, optimal_val*/
}

/**
 * @todo Find optimal numbers.
 */
