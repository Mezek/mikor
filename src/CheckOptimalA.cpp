/**
 * @brief		Check first optimal values
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

	vector<int> w1 {3, 23, 5, 5};
	vector<int> w2 {3, 53, 17, 5};
	vector<int> w3 {3, 101, 53, 5};
	vector<vector<int>> W3 {w1, w2, w3};

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			cout << W3[i][j] << endl;
		}
	}
/*
	/// Output
	ofstream os;
	os.open("checkAopt.dat");
	os.precision(8);
	os << "% Output of finding optimal value" << endl;	

	Mikor2 hoch;

	hoch.setDimS(3);
	vector<int> bR {23, 53, 101, 151, 307, 523, 829, 1259, 2129, 3001,
	4001, 5003, 6007, 8191, 10007, 13001, 20011, 30011, 40009, 50021,
	75011, 100003, 200003, 500009, 1000003, 2000003, 5000011};

	int optA;
	int bRs = bR.size();
	os << "d = " << hoch.getDimS() << endl;
	for (int i = 0; i < 5; i++) {
		if (hoch.isPrime(bR[i])) {
			hoch.setPprime(bR[i]);
			cout << "d = " << hoch.getDimS() << "\tp = " << hoch.getPprime() << endl;
			optA = hoch.firstOptimalA();
			os << "[" << hoch.getPprime() << ", " << optA << "], " << endl;
		} else {
			cout << mError << bR[i] << " is not prime!" << endl;
			exit(EXIT_FAILURE);
		}
	}
	os.close();*/
	
	time ( &rawtime );
	cout << "\n\n> End of program:   " << ctime ( &rawtime ) << endl;

	return EXIT_SUCCESS;
}
