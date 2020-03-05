/**
 * @brief		Debug first optimal values
 * @author		Erik Bartoš
 */

#include <iostream>
#include <limits.h>

#include "MikorD.cpp"

using namespace std;

/*
Object class            : Mikor
dimension of integration: 3
dimension of result     : 1
p - prime               : 1000003
q - prime               : 1
number of nodes         : 1000003
sigma                   : 2
relative eps            : 1e-05  flag: False
strategy                : 3
      90347     / Fortran
H   = 1.0000000153634154
H_c = 1.000000015363267
      441796    / C++
H   = 1.000000035560087
H_c = 1.0000000355599925
      342972    / Python
H   = 1.0000000077374764
H_c = 1.0000000077373894
*/

int main(int argc, char** argv)
{
	time_t rawtime;
	time ( &rawtime );
	cout << "\n> Start of program: " << ctime ( &rawtime ) << endl;

	/*Mikor2 tut;
	tut.setDimS(3);
	int p = 23;
	tut.setPprime(p);
	for (int i = 0; i < p; i++) {
		double x = tut.fraction((double)(i + 1)/p);
		cout << i + 1 << " " << x << " " << 1.-2.*x << endl;
	}*/


	Mikor2 secret;
	secret.setDimS(3);
	secret.setPprime(1000003);
	vector<int> V = {90347, 441796, 342972};

	//vector<int> V = {90347};
	//vector<int> V = {441796};

	cout << setprecision(15);
	for (int i = 0; i < V.size(); i++) {
		cout << "      " << V[i] << endl;
		cout << "H   = " << secret.hPoly(V[i]) << endl;
		cout << "H_c = " << secret.hPolyChet(V[i]) << endl;
	}
	
	time ( &rawtime );
	cout << "\n\n> End of program:   " << ctime ( &rawtime ) << endl;

	return EXIT_SUCCESS;
}
