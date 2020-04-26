/**
 * @brief		Find next optimal value z = b
 * @author		Erik Bartoš
 */

#include <iostream>

#include "Mikor2.cpp"

using namespace std;

int main(int argc, char** argv)
{
	time_t rawtime;
	time ( &rawtime );
	cout << "\n> Program : " << argv[0] << endl;
	cout << "> Start   : " << ctime ( &rawtime ) << endl;

	/// Output
	ofstream os;
	os.open("dim3Copt.dat");
	os.precision(8);
	os << "% Output of finding optimal value" << endl;	

	vector<vector<int>> Z {{3},
	{691, 29, 176}, {907, 31, 402}, {1259, 31, 535}, {1543, 37, 355}, {2129, 47, 937},
	{3001, 53, 276}, {4001, 53, 722}, {5003, 61, 1476}, {6007, 79, 592},
	{8191, 89, 739}, {10007, 101, 544}, {13001, 113, 4969}, {20011, 139, 6880},
	{30011, 173, 10180}, {40009, 199, 16592}, {50021, 223, 12962},
	{75011, 271, 26279}, {100003, 313, 13758}, {200003, 443, 79253}, {300007, 547, 39593},
	{400009, 631, 181370}, {500009, 701, 33606}, {700001, 829, 202879},
	{1000003, 997, 342972}
	};

	// 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,
	// 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157,
	// 163, 167, 173, 179, 181, 191, 193, 197, 199,
	// 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293,
	// 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397,
	// 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499,

	vector<vector<int>> Zx10 {{10},
	{1299827, 1637}, {3001, 53}, {4001, 53}, {5003, 61}, {6007, 79}
	};

	Mikor2 mroch;
	int ds = Z[0][0];
	mroch.setDimS(ds);
	int Zs = Z.size();
	os << "d = " << mroch.getDimS() << endl;
	int optA, optB;
	for (int i = 1; i < Zs; i++) {
		for (int j = 0; j < 2; j++) {
			if (mroch.isPrime(Z[i][j])) {
				//
			} else {
				cout << mError << Z[i][j] << " is not the prime!" << endl;
				exit(EXIT_FAILURE);
			}
		}
		mroch.setPprime(Z[i][0]);
		mroch.setQprime(Z[i][1]);
		mroch.setNNodes();
		long int nN = mroch.getNNodes();
		if ((nN >= pow(2,31)) || (nN < 0)) {
			cout << mError << "Check nodes value: " << nN << endl;
			return EXIT_FAILURE;
		}

		optA = Z[i][2];
		// optA = mroch.firstOptimalA();
		optB = mroch.firstOptimalB(optA);
		os << "[" 
			<< mroch.getPprime() << ", " 
			<< mroch.getQprime() << ", "
			<< optA << ", " << optB
			<< "], " << endl;
	}
	os.close();

	time ( &rawtime );
	cout << "\n> End     : " << ctime ( &rawtime ) << endl;

	return EXIT_SUCCESS;
}
