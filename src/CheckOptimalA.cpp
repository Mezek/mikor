/**
 * @brief		Check first optimal values
 * @author		Erik Bartoš
 */

#include <iostream>

#include "Mikor2.cpp"

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
	cout << "\n> Start of program: " << ctime ( &rawtime ) << endl;

	vector<vector<int>> W3 {{3, 23, 5, 8},
		{3, 53, 17, 17},
		{3, 101, 53, 40},
		{3, 151, 20, 20},
		{3, 307, 75, 75},
		{3, 523, 78, 78},
		{3, 829, 116, 116},
		{3, 1259, 433, 433},
		{3, 2129, 359, 937},
		{3, 3001, 276, 276},
		{3, 4001, 722, 722},
		{3, 5003, 1476,1476},
		{3, 6007, 592, 592},
		{3, 8191, 739, 739},
		{3, 10007, 544, 544},
		{3, 13001, 2135, 4969},
		{3, 20011, 2759, 4104},
		{3, 30011, 2023, 2326},
		{3, 40009, 2979, 16592},
		{3, 50021, 3483, 12962},
		{3, 75011, 7623, 14018},
		{3, 100003, 6697, 13758},
		{3, 200003, 19477, 95498},
		{3, 500009, 55279, 33606},
		{3, 1000003, 90347, 441796},
		{3, 2000003, 191421, 482047},
		{3, 5000011, 613511, 2206047}
	};
	double optV;

	Mikor2 bulli;
	bulli.setDimS(W3[0][0]);
	cout << "Dimension: " << W3[0][0] << endl;
	
	for (int i = 0; i < W3.size(); i++) {
		bulli.setPprime(W3[i][1]);
		double z = W3[i][2];
		double a = bulli.hPolyChet(z);
		cout << "[" << setprecision(10);
		cout.width(9);
		cout << W3[i][1] << "]\t";
		cout << a << " ";
		int ws = W3[i].size();
		for (int j = 2; j < ws; j++) {
			z = W3[i][j];
			double b = bulli.hPolyChet(z);
			cout << "\t";
			cout.width(10);
			cout << setprecision(9) << z 
				<< " (" << cSign(b - a) 
				//<< " / " << (b - a) 
				<< ") ";
		}
		cout << endl;
	}
	
	time ( &rawtime );
	cout << "\n\n> End of program:   " << ctime ( &rawtime ) << endl;

	return EXIT_SUCCESS;
}
