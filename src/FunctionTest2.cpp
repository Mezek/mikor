/**
 * $Date: 2014/09/29 09:04:07 $
 * $Revision: db831d4cfaf0 $
 * $Author: mezekus $
 * $Id: FunctionTest2.cpp,v db831d4cfaf0 2014/09/29 09:04:07 mezekus $
 *
 * @file
 * @brief	Class file for external function.
 */

#include <cassert>
#include <cmath>

#include "ExternalFCN.h"

/**
 * Test: polynoms and goniometric functions
 */

std::vector<double> ExternalFCN::operator() ( const std::vector<double>& x ) const
{
	//assert( x.size() > 20 );

	std::vector<double> F;
	double a,b,c,res;

	a = 60480.*pow(x[0],3.)*pow(x[1],4.)*pow(x[2],5.)*pow(x[3],6.)*pow(x[4],7.)*pow(x[5],8.);
	b = 44.*pow(x[0],3.)*pow(x[1],10.);
	c = sin(x[0])*cos(x[0]);

	res = a;

	F.push_back(res);

	res = b;

	F.push_back(res);

	res = c;

	F.push_back(res);

	res = 13.*pow(x[0],12);

	F.push_back(res);

	return F;
}
