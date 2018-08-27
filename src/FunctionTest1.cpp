/**
 * $Date: 2014/09/29 09:04:07 $
 * $Revision: db831d4cfaf0 $
 * $Author: mezekus $
 * $Id: FunctionTest1.cpp,v db831d4cfaf0 2014/09/29 09:04:07 mezekus $
 *
 * @file
 * @brief	Class file for external function.
 */

#include <cassert>
#include <cmath>

#include "ExternalFCN.h"

/**
 * Test: easy 8 dimensional integral
 */

std::vector<double> ExternalFCN::operator() ( const std::vector<double>& x ) const
{
	assert( x.size() < 21 );
	double x1, x2, x3, t, y1, y2, z, xi;
	double x1m1, x2m1, x3m1, tm1, y1m1, y2m1, zm1, xim1;

	double eps1, eta, smu2, alpha2, al2, delta2, d2, a, b, rho;
	double a1, a2, b1, b2, b3;
	double dcom, dgam, f1;

	std::vector<double> res;
	
	x1 = x[0];
	x2 = x[1];
	x3 = x[2];
	t  = x[3];
	y1 = x[4];
	y2 = x[5];
	z  = x[6];
	xi = x[7];

	x1m1 = 1. - x1;
	x2m1 = 1. - x2;
	x3m1 = 1. - x3;
	tm1  = 1. - t;
	y1m1 = 1. - y1;
	y2m1 = 1. - y2;
	zm1  = 1. - z;
	xim1 = 1. - xi;

	eps1 = 52.768;
	eta = 1.622;
	eta = 26.6597;

	smu2 = x1*t*eps1+tm1*eta;
	alpha2 = y1*y2*(1-y1*y2);
	al2 = y2*y1m1/(1.-y1*y2);

	delta2 = (pow((y2*y1m1),2.)+eps1*(y1*y2*x3+x2*y2m1))/alpha2;
	d2 = pow((xi*(zm1+z*al2)),2.) + xi*z*delta2+smu2*xim1;

	a = y2*y1m1;
	b = y1*y2;
	rho = xi*(zm1+al2*z);

	a1 = (-3.-9.*rho)/8.;
	a2 = -3./4.*pow(rho,3.);
	b1 = a*b*.25;
	b2 = pow(a,2.)*.5*(-1.-rho)+a*b*rho*(-.5+.25*rho);
	b3 = 0.;

	dcom =- 2.*a1/pow(d2,3.) + 3.*a2/pow(d2,4.) +
            3.*z*xi/alpha2*(-b1/pow(d2,3.) + b2/pow(d2,4.) - 2.*b3/pow(d2,5.));

	dgam = t*y1*y2m1*z*pow((y2*xi*xim1/alpha2),2.);

	f1 = dgam*dcom;

	res.push_back(f1);

	return res;
}
