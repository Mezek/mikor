/**
 * $Date: 2014/09/29 09:04:07 $
 * $Revision: db831d4cfaf0 $
 * $Author: mezekus $
 * $Id: Mikor.h,v db831d4cfaf0 2014/09/29 09:04:07 mezekus $
 *
 * @file
 * @brief	Header file for numerical integration by the Korobov's method.
 */

#ifndef _MIKOR_H_
#define _MIKOR_H_

/**
 * This class is intended for the evaluation of a group of the multidimension
 * integrals with the constant limits of the integration
 * @param numK  the number of variables of the integration (the maximum is 20)
 * @param numN  the number of integrals in the group
 * @param vecX[numK]  the variables of the integration
 * @param vecF[numN]  the values of the integrable functions
 * @param vecR[2*numN]  the results and the actual errors
 * @param numT1  the minimum number of points of the multidimension
 *    net of the integration
 * @param numT2  the maximum number of points of the multidimension
 *    net of the integration
 * @param numL  the order of the periodisation (l = 1, 2, 3 are recommended)
 * @param numH  the values in the interval (0.1, 10.) are recommended
 * @param vecAX[numK], vecBX[numK]  the lower and the upper limits
 * @param vecEps[numN]  the maximum error of the integration
 * vecEps = 0. ... the integration with two fixed nets, the results are
 *    vecR[i] and vecR[j] (i = 0,...,numN-1; j = numN,...,2*numN-1)
 * vecEps > 0. ... the integration with the maximum absolute error Eps,
 *    the results are vecR[i] and the actual absolute errors are vecR[j]
 * vecEps < 0. ... the integration with the maximum relative error Abs(Eps)
 *    the results are vecR[i] and the actual relative errors are vecR[j]
 * @param numFlag return parameter which represents the output of
 *    the integration process
 * numFlag < 0 ... user defined
 * numFlag = 0 ... the number of net points exceed the limit
 *                 or time limit has expired
 * numFlag > 0 ... achieved precision for all N integrals
 * i. e., if vecEps is nonzero and numFlag = 0 it means that the maximum
 * number of points is arrived, but the required precision is not arrived
 * @param ExternalFCN  the external function which for the vector
 * of variables x(numK) at the entry returns the vector vecF(numN)
 * of function values
 */

static const char* mError = "\n> MIKOR: Error: ";
static const char* mWarning = "\n> MIKOR: Warning: ";
static const char* mOut = "\n> MIKOR: ";
static const char* mOS = "> ";
static const char* mDebug = "\n>> Debug: ";
static const int numKMax = 20;

/** Common Block Declarations */

struct mikink {
	int kdim, kdab;
	double p;
};

struct timemi {
	double timem;
};

struct indat {
	double pt[30], at[30];
	int lt;
};

class Mikor
{
  private:
	// input parameters
	int numK, numN;
	mikink KP;
	indat XT;
	timemi TM;

	std::vector<double> vecX, vecAX, vecBX;
	std::vector<double> vecF, vecR, vecErr, vecEps;
	double numT1, numT2;
	int numL;
	double numH;
	double numFlag;
	bool pRint;

  protected:

  public:

	Mikor ( std::size_t , std::size_t );
	void setT1 ( double );
	void setT2 ( double );
	void setL ( int );
	void setH ( double );
	void setEps ( double );
	void setPrecision ( int );
	void setLimits ( double, double );
	void setParameters ( double, double, int, double ); // T1, T2, L, H
	void printParameters ();
	void Datkor ( int, bool );
	void Datkor ( bool );
	int Inkor ( void );
	double Period ( double, double );
	void makeFlag ();
	int Calculate ();
	void Result ();
	double FCNvalue ( int );
	~Mikor () {};

};

#endif // _MIKOR_H_

