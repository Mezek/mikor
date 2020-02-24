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

static const char* mError = "\n> MIKOR: Error: ";
static const char* mWarning = "\n> MIKOR: Warning: ";
static const char* mOut = "\n> MIKOR: ";
static const char* mOS = "> ";
static const char* mDebug = "\n>> Debug: ";
static const int dimI = 20;

class Mikor2
{
  private:
	int numK;
	std::vector<double> vecX, vecAX, vecBX;

  protected:

  public:

	Mikor2 ( std::size_t );
	~Mikor2 () {};

};

#endif // _MIKOR2_H_

