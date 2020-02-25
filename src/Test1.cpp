/**
 * $Date: 2014/09/29 09:04:07 $
 * $Revision: db831d4cfaf0 $
 * $Author: mezekus $
 * $Id: Test1.cpp,v db831d4cfaf0 2014/09/29 09:04:07 mezekus $
 *
 * @file
 * @brief	Test of numerical integration by the Korobov's method.
 */

#include <iostream>

#include "FunctionTest1.cpp"
#include "Mikor.cpp"

//using namespace std;

/**
 * Test: easy integral
 */

int main(int argc, char** argv)
{

	std::cout << "\n==============================================" << std::endl;
	std::cout << "  Program: " << argv[0] << std::endl;
	std::cout << "  Version 1.0.0, (c) 2014 Erik Bartos" << std::endl;
	std::cout << "==============================================" << std::endl;

	time_t rawtime;
	time ( &rawtime );
	std::cout << "\n> Start of program: " << ctime ( &rawtime ) << std::endl;

	Mikor myInt(8,1);
	myInt.printParameters();
	myInt.setParameters(1.e7,-1.,3,-0.1); // T1, T2, L, H
	myInt.setEps(-0.01);
	myInt.printParameters();
	myInt.setLimits(0.0001,0.9999);

	myInt.Calculate();
	myInt.Datkor(true);
	//myInt.makeFlag();

	std::cout << "\nValue with constant: " << myInt.FCNvalue(0)*4.*powf(52.768,3) << std::endl;

	time ( &rawtime );
	std::cout << "\n\n> End of program:   " << ctime ( &rawtime ) << std::endl;

	return EXIT_SUCCESS;
}
