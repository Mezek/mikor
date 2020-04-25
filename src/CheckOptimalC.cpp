/**
 * @brief		Check next optimal values
 * @author		Erik Bartoš
 */

#include <iostream>

#include "Mikor2.cpp"

const std::string reset("\033[0m");
const std::string red("\033[0;31m");
const std::string green("\033[1;32m");
const std::string yellow("\033[1;33m");
const std::string blue("\033[1;34m");
const std::string magenta("\033[0;35m");
const std::string cyan("\033[0;36m");
const std::string white("\033[0;37m");

using namespace std;

template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}

char cSign (double n) {
	char s = '0';
	if (n > 0) { s = '+'; };
	if (n < 0) { s = '-'; };
	return s;
}

int main(int argc, char** argv)
{
	time_t rawtime;
	time ( &rawtime );
	cout << "\n> Program : " << argv[0] << endl;
	cout << "> Start   : " << ctime ( &rawtime ) << endl;

	vector<int> C {691, 907, 1259, 1543, 2129, 3001, 4001, 5003, 6007, 8191, 10007,
	13001, 20011, 30011, 40009, 50021, 75011,
	100003, 200003, 500009, 1000003, 2000003, 5000011};
	vector<int> P {23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,
	101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157,
	163, 167, 173, 179, 181, 191, 193, 197, 199,
	211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293,
	307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397,
	401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499};

	for (int i = 0; i < C.size(); i++) {
		cout << C[i] << ": " << endl;
		for (int j = 0; j < P.size(); j++) {
			if ((int)sqrt(C[i]) >= P[j-1]) {
				cout << P[j] << " : " << C[i]*P[j] << "\t";
			}
		}
		cout << endl;
	}

	vector<vector<int>> W {{3, 23, 5, 8, 3}};
	vector<vector<int>> Wx3 {{3, 23, 5, 8, 3},
		{3, 53, 17, 17, 25},
		{3, 101, 53, 40},
		{3, 151, 20, 20},
		{3, 307, 75, 75},
		{3, 523, 78, 78},
		{3, 829, 116, 116},
		{3, 1259, 433, 535},
		{3, 2129, 359, 937},
		{3, 3001, 276, 772},
		{3, 4001, 722, 722},
		{3, 5003, 1476,1476},
		{3, 6007, 592, 592},
		{3, 8191, 739, 739},
		{3, 10007, 544, 3072},
		{3, 13001, 2135, 4969},
		{3, 20011, 2759, 6880},
		{3, 30011, 2023, 10180},
		{3, 40009, 2979, 16592},
		{3, 50021, 3483, 12962},
		{3, 75011, 7623, 26279},
		{3, 100003, 6697, 13758},
		{3, 200003, 19477, 79253},
		{3, 500009, 55279, 33606},
		{3, 1000003, 90347, 342972},
		{3, 2000003, 191421, 920849},
		{3, 5000011, 613511, 889866}
	};

	double optV;

	Mikor2 bulli;
	bulli.setDimS(W[0][0]);
	cout << "Dimension: " << W[0][0] << endl;
	
	for (int i = 0; i < W.size(); i++) {
		bulli.setPprime(W[i][1]);
		double z = W[i][2];
		double a = bulli.hPolyChet(z);
		cout << "[" << setprecision(10);
		cout.width(9);
		cout << W[i][1] << "]\t";
		 cout << a << " "; //
		if (a > 2.1) { cout << red << "!" << reset; }
		int ws = W[i].size();
		for (int j = 2; j < ws; j++) {
			z = W[i][j];
			double b = bulli.hPolyChet(z);
			cout << "\t";
			cout.width(10);
			cout << setprecision(10) << z 
				<< " (" << blue << cSign(b - a) << reset
				<< " / " << setprecision(4) << (b - a)
				//<< " / " << b //
				<< ") ";
		}
		cout << endl;
	}
	
	time ( &rawtime );
	cout << "\n> End     : " << ctime ( &rawtime ) << endl;

	return EXIT_SUCCESS;
}
