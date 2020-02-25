/**
 * @brief		Find first optimal value z = a
 * @author		Erik Bartoš
 */

#include <iostream>

#include "Mikor2.cpp"

using namespace std;

int main(int argc, char** argv)
{
	time_t rawtime;
	time ( &rawtime );
	cout << "\n> Start of program: " << ctime ( &rawtime ) << endl;

	Mikor2 optimal(10);
	optimal.printParameters();

	//cout << "\nValue with constant: " << myInt.FCNvalue(0)*4.*powf(52.768,3) << endl;

	time ( &rawtime );
	cout << "\n\n> End of program:   " << ctime ( &rawtime ) << endl;

	return EXIT_SUCCESS;
}
