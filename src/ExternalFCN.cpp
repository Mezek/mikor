/**
 * $Date: 2014/09/29 09:04:07 $
 * $Revision: db831d4cfaf0 $
 * $Author: mezekus $
 * $Id: ExternalFCN.cpp,v db831d4cfaf0 2014/09/29 09:04:07 mezekus $
 *
 * @file
 * @brief	Class file for external function.
 */

#include <cassert>
#include <cmath>

#include "ExternalFCN.h"

/**
 * User external function which represents the integrand of numerical integration.
 * @param   x vector contains the variables of the integration.
 * @return  f vector of the function values
 */

std::vector<double> ExternalFCN::operator() ( const std::vector<double>& x ) const
{
	//assert( x.size() > 20 );

	std::vector<double> F;
	double a, b, res;

	a = 44.*pow(x[0],3.)*pow(x[1],10.);
	b = 1./sqrt(x[0] + log(x[1] + x[2])*log(x[1] + x[2]));

	res = a;

	F.push_back(res);

	res = b;

	F.push_back(res);

	return F;
}
