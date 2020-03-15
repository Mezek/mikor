/**
 * @brief		Header file for numerical integration by the Korobov's method.
 * @author		Erik Bartoš 
 */

#ifndef _MIKOR2_H_
#define _MIKOR2_H_

/**
 * The Mikor2 library is a new C++ version of Mikor. It provides basically all
 * the functionality present in the older version. Furthermore, it contains new
 * functionality, like the possibility to find optimal numbers.
 */

static const char* mError = "\n> MIKOR2: Error: ";
static const char* mWarning = "\n> MIKOR2: Warning: ";
static const char* mOut = "\n> MIKOR2: ";
static const char* mOS = "> ";
static const char* mDebug = "\n>> Debug: ";
static const int dimI = 20;

class Mikor2
{
  private:
	int dimS, pPrime, qPrime;
	std::vector<double> aX;

  protected:

  public:

	Mikor2 ();
	Mikor2 ( std::size_t );
	void setDimS ( int );
	void setPprime ( int );
	void setQprime ( int );
	int getDimS ();
	int getPprime ();
	int getQprime ();
	void printParameters();
	double fraction ( double );
	bool isPrime ( int );
	int nextPrime ( int );
	double hSum ( int, int );
	double hPoly ( int );
	double hPolyChet ( int );
	int firstOptimalA();
	~Mikor2 () {};

};

#endif // _MIKOR2_H_

