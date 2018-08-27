/**
 * $Date: 2014/09/29 09:04:07 $
 * $Revision: db831d4cfaf0 $
 * $Author: mezekus $
 * $Id: Mikor.cpp,v db831d4cfaf0 2014/09/29 09:04:07 mezekus $
 *
 * @file
 * @brief	Class file for numerical integration by the Korobov's method.
 */

#include <cassert>
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <cmath>

#include "ExternalFCN.h"
#include "Mikor.h"

/// Default constructor
/// Set the number of variables of the integration K, maximum is 20.
/// Set the number of integrals in the group N.
/// Set default parameter values.

Mikor::Mikor ( std::size_t K, std::size_t N ) : vecX(K), vecAX(K), vecBX(K),
	vecF(N), vecR(N), vecErr(N), vecEps(N)
{
	numK = K;
	numN = N;
	KP.kdim = 1;
	KP.kdab = 1;
	TM.timem = 0.;

	numT1 = -1.;
	numT2 = 1000000.;
	numL = 1;
	numH = 1.0;

	pRint = true;

	std::cout << mOut << "K: " << numK << "\tN: " << numN << std::endl;
}

/// Set the minimal number of points of the multidimension net of the integration.
/// Negative values &mdash; the program chooses the number of points itself.

void Mikor::setT1 ( double t1 )
{
	numT1 = t1;
}

/// Set the maximal number of points of the multidimension net of the integration.
/// Negative values &mdash; the program chooses the number of points itself.

void Mikor::setT2 ( double t2 )
{
	numT2 = t2;
}

/// Set the order of the periodisation (l = 1,2,3 recommended)
/// Negative values &mdash; the program chooses the order itself.

void Mikor::setL ( int l )
{
	numL = l;
}

/// Set the value of the boundary interval (h = 0.1,...,10. recommended)
/// Negative values &mdash; the program chooses the values itself.

void Mikor::setH ( double h )
{
	numH = h;
}

/// Set down and upper limits for all integrals.

void Mikor::setLimits ( double down, double up )
{
	for ( int i = 0; i < numK; ++i ) {
		vecAX[i] = down;
		vecBX[i] = up;
	}
	std::cout << mOut << "Limits of integration" << std::endl;
	std::cout << mOS << "Down = " << down << std::endl;
	std::cout << mOS << "Up   = " << up << std::endl;
}
/// Set all parameters at once.

void Mikor::setParameters ( double t1, double t2, int l, double h )
{
	this->setT1(t1);
	this->setT2(t2);
	this->setL(l);
	this->setH(h);
}

/// Print parameters.

void Mikor::printParameters ()
{
	std::cout << mOut << "Parameters" << std::endl;
	std::cout << mOS << "K    = " << numK << std::endl;
	std::cout << mOS << "N    = " << numN << std::endl;
	std::cout << mOS << "L    = " << numL << std::endl;
	std::cout << mOS << "H    = " << numH << std::endl;
	std::cout << mOS << "T1   = " << numT1 << std::endl;
	std::cout << mOS << "T2   = " << numT2 << std::endl;
	std::cout << mOS << "EPS  = " << vecEps[0] << std::endl;
}

/// Set EPS.

void Mikor::setEps ( double eps ) {
	for ( unsigned int i = 0; i < vecEps.size(); ++i ) {
		vecEps[i] = eps;
	}
}

/// Datkor method.

void Mikor::Datkor ( int kr, bool pRint )
{
	static int kaMax = 400000;
	static int lkp = 27;
	static int lkp1 = 26;
	static int kp[27] = { 23, 53, 101, 151, 307, 523, 829, 1259, 2129, 3001,
		4001, 5003, 6007, 8191, 10007, 13001, 20011, 30011, 40009, 50021, 75011,
		100003, 200003, 500009, 1000003, 2000003, 5000011 };
	static int kp1[26] = { 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987,
		1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393,
		196418, 317811, 514229 };
	static int ka[260] = { 5, 17, 53, 20, 75, 78, 116, 433, 359, 276,
		722, 1476, 592, 739, 544, 2135, 2759, 2023, 2979, 3483, 7623, 6697,
		19477, 55279, 90347, 191421, 613511, 5, 31, 15, 22, 42, 178,
		45, 483, 766, 174, 113, 792, 1351, 2488, 1206, 778, 2891,
		2243, 2775, 3353, 7601, 10101, 19293, 55251, 122713, 191447,
		492615, 21, 13, 127, 64, 146, 302, 618, 408, 1534, 840, 509,
		1386, 198, 830, 2803, 2311, 2945, 3581, 7639, 10019, 19777,
		61357, 122713, 191447, 492615, 109, 195, 118, 109, 200, 41,
		233, 1751, 2037, 312, 1632, 2240, 1940, 3169, 2347, 2875,
		3431, 7647, 10049, 19277, 33363, 66681, 191401, 613509, 27,
		90, 227, 596, 170, 115, 229, 721, 2107, 2304, 2116, 1773,
		2253, 2965, 3401, 7555, 6703, 24561, 33339, 66671, 191443,
		613509, 32, 392, 86, 993, 1850, 2362, 1253, 3787, 436, 1415,
		3295, 3267, 3093, 3455, 7809, 10029, 19827, 61365, 90343,
		191437, 492261, 636, 108, 1579, 526, 1597, 2139, 470, 1437,
		2533, 2077, 3119, 3469, 7813, 10099, 19461, 61365, 90343,
		191415, 613507, 431, 1262, 1751, 564, 1415, 1715, 2065, 2901,
		3413, 7677, 6699, 19153, 33341, 107369, 191435, 613515, 349,
		586, 1409, 2205, 3237, 4325, 5419, 8063, 10151, 24573, 55269,
		107393, 191389, 613515, 2191, 3319, 4319, 3407, 8099, 10151,
		24573, 61365, 107377, 191389, 613507, 5407, 8061, 10761,
		24573, 61371, 107375, 191433, 478471, 5407, 8099, 10143,
		19363, 61371, 106245, 191433, 478471, 5417, 8061, 10171,
		20015, 61371, 106265, 191405, 478471, 61373, 106257, 191405,
		492613, 61353, 106245, 191421, 492613, 61353, 106257, 191421,
		478471, 61353, 106245, 191421, 478471, 61353, 106233, 191421,
		478471 };

	//std::vector<int> kaVector (ka, ka + sizeof(ka)/sizeof(ka[0]) );

	for (int i = 0; i < 30; ++i) { // why 30??
		XT.pt[i] = 0;
		XT.at[i] = 0;
	}

	if (kr > numKMax) {
		std::cout << "\n" << mError << "DATKOR: The value of K ( = " << kr
			<< ") must be less then: " << numKMax+1 << "!" << std::endl;
		exit(EXIT_FAILURE);
	}

	int j;
	if (kr < 3) {
		XT.lt = lkp1 - 1;
		for ( int i = 0; i < XT.lt; ++i ) {
			j = i + 1;
			XT.pt[i] = kp1[j];
			XT.at[i] = kp1[i];
		}
	} else {
		int i = 0;
		int l = 2;

		while (l < kr) {
			XT.lt = 0;
			i = i + 1;
			XT.lt = XT.lt + 1;
			while ( ka[i-1] < kaMax ) {
                i = i + 1;
				XT.lt = XT.lt + 1;
			}
			l = l + 1;
		};

		i = i - XT.lt;
		j = lkp - XT.lt;

		for ( int ij = 0; ij < XT.lt; ++ij ) {
			++i;
			++j;
			XT.pt[ij] = kp[j-1];
			XT.at[ij] = ka[i-1];
		}
	}

	if ( pRint == true ) {
		std::cout << mOut << "DATKOR: The parameters of the Korobov's net for K = " << numK << std::endl;
		int ltp = XT.lt;
		int kpr = 0;
		int lp = 0;
		for ( int ipr = 1; ipr <= 100; ipr = ipr + 10 ) {
			lp = std::min (ltp,10);
			kpr = ipr + lp - 1;

            std::cout.precision(10);

			std::cout << mOS << "P = ";
			for (int k = ipr; k <= kpr; ++k) {
				std::cout << "\t" << XT.pt[k-1];
			}
			std::cout << std::endl;
			std::cout << mOS << "A = ";
			for (int k = ipr; k <= kpr; ++k) {
				std::cout << "\t" << XT.at[k-1];
			}
			std::cout << std::endl;
			ltp = ltp - 10;
			if ( ltp <= 0 ) { break; }
		}
	}
}

/// Datkor method with fix K

void Mikor::Datkor ( bool pRint )
{
	int kr = numK;
	this->Datkor(kr,pRint);
}

/// Inkor method.
/// @return numFlag

int Mikor::Inkor ()
{
	static int lMax = 10;
	static double rFlag = 1000000.;
	static double cp3 = 10.0;
	static double cMax = 20.0;

	static double a, a1, ad1, ad2;
	static double cntp;
	static int kr, lp;
	static int m, n1, n2, n3;
	static double p3, pMax, ptlt;
	static double timeInkor, timeMax;
	static bool itm, lFlag, kFlag;
	static double alpha, alpha1, alpha2, beta, beta1;
	static double l1, ak, al, a2l, b2l, cl, c2l, eps1, r1;
	static double csig[11], ctau[11], sig, tau;
	static double s[20], s1[20];
	static int in, jn, j2;
	static double fact, f1;
	static double q, y, y1, y2, w, z;

	ExternalFCN integrand(numN,vecX);

	const clock_t beginTime = std::clock();
	clock_t calcTime;
	//std::cout << "Time: " << float(std::clock() - beginTime) <<  std::endl;

	itm = false;
	kr = numK;
	lp = numL;
	n1 = numN;
	n2 = numN + numN;
	n3 = n2 + numN;
	vecR.resize(n3); // @todo Properly check the size and capacity of vecR

	p3 = pow(3.0,kr);
	pMax = numT2;
	if ( pMax < 0.) {
		pMax = cMax*p3;
	} else if ( pMax == 0. ) {
		pMax = XT.pt[XT.lt - 1];
	}

	timeInkor = TM.timem;
	if ( timeInkor <= 0. ) { timeInkor = 1.e6; }

	cntp = 0.;
	q = numT1;

	if ( q < 0. ) {
		if ( kr <= 10 ) { q = p3; }
	}
	p3 = cp3*p3;

	ptlt = XT.pt[XT.lt - 1];
	if ( q > ptlt ) { q = ptlt; }
	if ( lp > lMax ) { lp = lMax; }

	for ( int kt = 0; kt < XT.lt; ++kt ) {
		numFlag = 0.;
		KP.p = XT.pt[kt];
		a = XT.at[kt];
		if ( q <= KP.p ) {
			z = 2.0*KP.p;
			if ( itm == true ) {
				calcTime = float (std::clock() - beginTime);
				timeMax = calcTime*(cntp+KP.p)/cntp;
				if ( timeMax > timeInkor ) {
					std::cout << mError << "Time limit at Mikor: "
						<< calcTime << " sec." << std::endl;
					goto label900;
				}
			}
			itm = true;
			cntp = cntp + KP.p;
			lFlag = false;
			if ( lp < 0 ) {
				lp = 0;
				if ( q >= p3 ) { lp = 1; }
				if ( kr <= 6 ) { lp = lp + 1; }
			}
			if ( lp > 0 ) {
				lFlag = true;
				alpha = this->Period(kr,lp);
				alpha1 = 1./alpha;
				alpha2 = 0.5*alpha;
				beta = 1. - alpha;
				beta1 = 1./beta;
				l1 = lp + 1;
				ak = 0.;
				al = l1;
				a2l = lp + l1;
				b2l = a2l*al/(al-1.);
				cl = 1.;
				c2l = 1.;
				for ( int i = 0; i < l1; ++i ) {
					ctau[i] = cl/a2l;
					csig[i] = ctau[i]/(a2l+1.);
					ak = ak + 1.;
					al = al - 1.;
					a2l = a2l - 1.;
					cl = cl*al/ak;
					c2l = c2l*a2l/ak;
				}
				b2l = b2l*c2l*beta1;
				for ( int i = 0; i < l1; ++i ) {
					ctau[i] = b2l*ctau[i];
					csig[i] = b2l*alpha*csig[i];
				}
			}
			a1 = 1.;
			for ( int jk = 0; jk < kr; ++jk ) {
				if ( fmod(a1,2.) <= 0. ) { a1 = KP.p - a1; }
				s1[jk] = a1;
				s[jk] = s1[jk]*2.;
				a1 = fmod(a1*a,KP.p);
			}
			for ( int ij = 0; ij < n2; ++ij ) {
				vecR[ij] = 0.;
			}
			jn = 0.;
			m = KP.p;
			for ( int i = 1; i <= 2; ++i ) {
				switch ( KP.kdab ) {
				    case 1:
				        break;
					case 2:
					    for ( int ij = n2; ij < n3; ++ij ) {
                            vecR[ij] = 0.;
                        }
                        break;
				}
				for ( int j = 1; j <= m; ++j ) {
					fact = 1.;
					f1 = 1.;
					for ( int jk = 0; jk < kr; ++jk ) {
						y1 = s1[jk]/z;
						s1[jk] = s1[jk] + s[jk] - z;
						if ( s1[jk] < 0. ) { s1[jk] = s1[jk] + z; }
						if ( lFlag ) { // test for truth
							w = y1;
							y = w*alpha1;
							if ( w < alpha ) { } else {
								if ( w > beta ) {
									y = alpha1 - y;
								} else {
									y1 = (w - alpha2)*beta1;
									tau = beta1;
									fact = fact*tau;
									goto label61;
								}
							}
							y1 = -y;
							y2 = y;
							sig = csig[0];
							tau = ctau[0];
							for ( int il = 1; il < l1; ++il ) {
								y2 = y2*y;
								sig = sig*y1 + csig[il];
								tau = tau*y1 + ctau[il];
							}
							y1 = sig*y2*y;
							if ( y1 < 0. ) { y1 = 0.; }
							tau = tau*y2;
							if ( w >= alpha ) { y1 = 1. - y1; }
							fact = fact*tau;
						}
					  label61:
						y = vecBX[jk] - vecAX[jk];
						vecX[jk] = y*y1 + vecAX[jk];
						switch ( KP.kdab ) {
							case 1: fact = fact*y;
							case 2: f1 = f1*y;
						}
					}

					vecF = integrand(vecX);

					for ( int ij = 0; ij < n1; ++ij ) {
						in = ij + jn;
						j2 = ij + n2;
						switch ( KP.kdab ) {
							case 1:
							    vecR[in] = vecR[in] + fact*vecF[ij];
							    break;
							case 2: // ad[], d equivalence
								f1 = f1*fact*vecF[ij];
								ad1 = vecR[in];
								ad2 = vecR[j2];
								vecR[in] = ad1 + f1;
								vecR[j2] = ad2;
								break;
						}
					}
                }
				for ( int jk = 0; jk < kr; ++jk ) {
					s1[jk] = s[jk];
				}
				for ( int ij = 0; ij < n1; ++ij ) {
					in = ij + jn;
					j2 = ij + n2;
					switch ( KP.kdab ) { // ad[], d equivalence
						case 1:
						    vecR[in] = vecR[in]/KP.p;
						    break;
						case 2:
						    vecR[in] = vecR[in]/KP.p;
						    break;
					}
				}
				jn = jn + n1;
			}
			kFlag = true;
			eps1 = vecEps[0];
			for ( int i = 0; i < n1; ++i ) {
				in = i + n1;
				switch ( KP.kdim ) {
					case 1:
					    break;
					case 2:
					    eps1 = vecEps[i];
					    break;
				}
				if ( eps1 != 0. ) {
					vecR[i] = 0.5*(vecR[i] + vecR[in]);
					r1 = fabs(vecR[i] - vecR[in]);
					vecR[in] = r1;
					if ( eps1 < 0. ) {
						vecR[in] = rFlag;
						if ( vecR[i] != 0. ) { vecR[in] = fabs (r1/vecR[i]); }
					}
					if ( vecR[in] >= fabs(eps1) ) { kFlag = false; }
				}
			}
			numFlag = KP.p;
			if ( kFlag ) { // test for truth
				goto label777;
			}
			if ( KP.p >= pMax ) { goto label900; }

			vecF = integrand(vecX);

			if ( numFlag < 0. ) { goto label777; }
		}
	}
  label900:
	numFlag = 0.;
  label777:
	return numFlag;
}

/// Period method.

double Mikor::Period ( double kr, double lp )
{
	//assert ( 1 == 1 );
	static const double aMax = 0.3;
	static const double h1 = 1.0;

	static double a, ak;
	double alpha, d1;

	a = numH;
	if ( a <= 0. ) { a = h1; }

	ak = kr;

	d1 = 1.0/ak;
	alpha = a*lp/pow(KP.p,d1);

	if (alpha > aMax) { alpha = aMax; }

	return alpha;
}

/// Print precision results after calculation.
/**
 * flag < 0 ... user defined
 * flag = 0 ... number of net points exceed the limit or time limit has expired
 * flag > 0 ... achieved precision for all N integrals
 */

void Mikor::makeFlag ()
{
	double flag = numFlag;
	int p = KP.p;

	if ( flag == 0. ) {
		if ( KP.kdim != 1 ) {
			std::cout << mWarning << "The required precision EPS(N) is not arrived:" << std::endl;
			std::cout << mOut;
			for ( unsigned int i = 0; i < vecEps.size(); ++i ) {
				std::cout << "EPS(" << i << ") = " << vecEps[i] << "  ";
			}
		} else {
			std::cout << mWarning << "The required precision EPS = " << vecEps[0]
				<< " is not arrived!" << std::endl;
		}
		std::cout << mWarning << "It is necessary to assign T1 greater then = " << p << std::endl;
		std::cout << mWarning << "or the value of L to change!" << std::endl;
		std::cout << mOut << "The actual values of the errors are printed below:\n" << std::endl;
		int n1 = numN;
		int n2 = numN + numN;
		for ( int i = n1; i < n2; ++i ) {
            std::cout << "ERR[" << i-n1 << "] = " << vecR[i] << std::endl;
        }
		std::cout << std::endl;
	}
}

/// Print actual values of the vector R

void Mikor::Result()
{
	std::cout << mOut << "The actual values of the vector R: " << std::endl;
	for ( int i = 0; i < numN; ++i ) {
		std::cout << "R[" << i << "] = " << vecR[i] << std::endl;
	}
	//std::cout << mDebug << "Check the values of the errors." << std::endl;
}

double Mikor::FCNvalue ( int i ) {
	return vecR[i];
}

/// Make all together.
/// @return numFlag

int Mikor::Calculate ()
{
	this->Datkor(true);
	this->Inkor();
	this->makeFlag();
	this->Result();
	return numFlag;
}

/**
 * @todo Enable to set different limits for AX and BX.
 */
