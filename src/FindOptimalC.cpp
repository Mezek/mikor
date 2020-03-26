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

	/* [[691, 29, 176, 20], [907, 31, 402, 12], [1259, 31, 535, 26], [1543, 37, 355, 14],
    [2129, 47, 937, 45], [3001, 53, 772, 24], [4001, 53, 722, 35], [5003, 61, 1476, 55],
    [6007, 79, 592, 13], [8191, 89, 739, 76], [10007, 101, 544, 94]] */

	vector<vector<int>> Z {{3},
	{691, 29, 176}, {907, 31, 402}, {1259, 31, 535}, {1543, 37, 355}, {2129, 47, 937},
	{3001, 53, 772}, {4001, 53, 722}, {5003, 61, 1476}, {6007, 79, 592},
	{8191, 89, 739}, {10007, 101, 544}};

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
		cout << "d = " << mroch.getDimS() 
			<< "\tp = " << mroch.getPprime()
			<< "\tq = " << mroch.getQprime() << endl;

		optA = Z[i][2];
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
