/**
 * $Date: 2014/09/29 09:04:07 $
 * $Revision: db831d4cfaf0 $
 * $Author: mezekus $
 * $Id: FunctionTest3.cpp,v db831d4cfaf0 2014/09/29 09:04:07 mezekus $
 *
 * @file
 * @brief	Class file for external function.
 */

#include <cassert>
#include <cmath>

#include "ExternalFCN.h"

/**
 * Test: two integrals
 */

std::vector<double> ExternalFCN::operator() ( const std::vector<double>& x ) const
{
	assert( x.size() < 21 );
	double u, w, y, z;
	double d, g, h;
	std::vector<double> res;

	u = x[0];
	w = x[1];
	y = x[2];
	z = x[3];

	d = 1.-u*u*w*w*y*y*z*z;
	g = d*cos(u*w*y*z) - d*u*w*y*z*sin(u*w*y*z);

	res.push_back(g);

	h = exp(-u*u*u)/(u*u+1.);

	res.push_back(h);
	
	return res;
}
