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

	Mikor2 hoch(5);
	/* 5:   [[101, 21], [151, 58], [307, 29], [523, 64], [829, 146], [1259, 321],
             [2129, 618], [3001, 890], [4001, 1534], [5003, 840], [6007, 509],
             [8191, 2228], [10007, 1870], [13001, 1864], [20011, 9432], [30011, 13604],
             [40009, 13130], [50021, 7255], [75011, 16449], [100003, 48778]],*/
	
	hoch.setPprime(8191);
	hoch.printParameters();
	hoch.firstOptimalA();

	//cout << "\nValue with constant: " << myInt.FCNvalue(0)*4.*powf(52.768,3) << endl;

	time ( &rawtime );
	cout << "\n\n> End of program:   " << ctime ( &rawtime ) << endl;

	return EXIT_SUCCESS;
}
