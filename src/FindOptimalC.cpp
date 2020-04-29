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

	vector<vector<int>> Zx3 {{3},
	{691, 29, 176}, {907, 31, 402}, {1259, 31, 535}, {1543, 37, 355}, {2129, 47, 937},
	{3001, 53, 276}, {4001, 53, 722}, {5003, 61, 1476}, {6007, 79, 592},
	{8191, 89, 739}, {10007, 101, 544}, {13001, 113, 4969}, {20011, 139, 6880},
	{30011, 173, 10180}, {40009, 199, 16592}, {50021, 223, 12962},
	{75011, 271, 26279}, {100003, 313, 13758}, {200003, 443, 79253}, 
	{300007, 547, 39593}, {400009, 631, 181370}, {500009, 701, 33606},
	{700001, 829, 202879}, {1000003, 997, 342972}
	};

	vector<vector<int>> Zx4 {{4},
	{691, 29, 132}, {907, 31, 376}, {1259, 31, 483}, {1543, 37, 663}, {2129, 47, 766},
	{3001, 53, 1466}, {4001, 53, 956}, {5003, 61, 2053}, {6007, 79, 1351},
	{8191, 89, 3842}, {10007, 101, 1206}, {13001, 113, 778}, {20011, 139, 6016},
	{30011, 173, 12084}, {40009, 199, 9023}, {50021, 223, 23277},
	{75011, 271, 13715}, {100003, 313, 12475}, {200003, 443, 17914},
	{300007, 547, 95149}, {400009, 631, 125457}, {500009, 701, 127616},
	{700001, 829, 231525}, {1000003, 997, 33889}
	};

	vector<vector<int>> Zx5 {{5},
	{907, 31, 53}, {1259, 31, 302}, {1543, 37, 58}, {2129, 47, 618},
	{3001, 53, 408}, {4001, 53, 1534}, {5003, 61, 840}, {6007, 79, 509},
	{8191, 89, 1386}, {10007, 101, 198}, {13001, 113, 1864}, {20011, 139, 9432},
	{30011, 173, 13604}, {40009, 199, 12216}, {50021, 223, 7255},
	{75011, 271, 16449}, {100003, 313, 11729}, {200003, 443, 62638},
	{300007, 547, 90248}, {400009, 631, 181176}, {500009, 701, 32497},
	{700001, 829, 94882}, {1000003, 997, 335440}
	};

	vector<vector<int>> Zx6 {{6},
	{1259, 31, 200}, {1543, 37, 342}, {2129, 47, 727},
	{3001, 53, 322}, {4001, 53, 1780}, {5003, 61, 2208}, {6007, 79, 312},
	{8191, 89, 3699}, {10007, 101, 2399}, {13001, 113, 1940}, {20011, 139, 6387},
	{30011, 173, 6645}, {40009, 199, 4902}, {50021, 223, 15683},
	{75011, 271, 2127}, {100003, 313, 6798}, {200003, 443, 99038},
	{300007, 547, 81023}, {400009, 631, 101030}, {500009, 701, 174069},
	{700001, 829, 167391}, {1000003, 997, 127632}
	};

	vector<vector<int>> Zx7 {{7},
	{1543, 37, 207}, {2129, 47, 718}, {3001, 53, 170}, {4001, 53, 115},
	{5003, 61, 1573}, {6007, 79, 1508}, {8191, 89, 2107},
	{10007, 101, 2304}, {13001, 113, 4797}, {20011, 139, 3851},
	{30011, 173, 8784}, {40009, 199, 14905}, {50021, 223, 23981},
	{75011, 271, 12914}, {100003, 313, 18083}, {200003, 443, 72045},
	{300007, 547, 75343}, {400009, 631, 131240}, {500009, 701, 75479},
	{700001, 829, 99121}, {1000003, 997, 119956}
	};

	vector<vector<int>> Zx8 {{8},
	{2129, 47, 86}, {3001, 53, 955}, {4001, 53, 1728},
	{5003, 61, 2362}, {6007, 79, 1253}, {8191, 89, 2602},
	{10007, 101, 1905}, {13001, 113, 1352}, {20011, 139, 7191},
	{30011, 173, 7011}, {40009, 199, 9946}, {50021, 223, 10899},
	{75011, 271, 17605}, {100003, 313, 15120}, {200003, 443, 39993},
	{300007, 547, 116617}, {400009, 631, 117552}, {500009, 701, 42535},
	{700001, 829, 77235}, {1000003, 997, 230727}
	};

	vector<vector<int>> Zx9 {{9},
	{2129, 47, 636}, {3001, 53, 108}, {4001, 53, 1234},
	{5003, 61, 526}, {6007, 79, 2633}, {8191, 89, 3052},
	{10007, 101, 4748}, {13001, 113, 3391}, {20011, 139, 6181},
	{30011, 173, 2348}, {40009, 199, 10979}, {50021, 223, 5358},
	{75011, 271, 10460}, {100003, 313, 48635}, {200003, 443, 2611},
	{300007, 547, 115693}, {400009, 631, 72439}, {500009, 701, 10374},
	{700001, 829, 189792}, {1000003, 997, 26697}
	};

	vector<vector<int>> Zx10 {{10},
	{3001, 53, 855}, {4001, 53, 1828},
	{5003, 61, 592}, {6007, 79, 1262}, {8191, 89, 1751},
	{10007, 101, 1554}, {13001, 113, 3466}, {20011, 139, 6951},
	{30011, 173, 8883}, {40009, 199, 15619}, {50021, 223, 9224},
	{75011, 271, 31958}, {100003, 313, 833}, {200003, 443, 43298},
	{300007, 547, 17881}, {400009, 631, 6006}, {500009, 701, 131579},
	{700001, 829, 120073}, {1000003, 997, 291906}
	};

	vector<vector<int>> Zx11 {{11},
	{4001, 53, 1887}, {5003, 61, 1485}, {6007, 79, 1298}, {8191, 89, 349},
	{10007, 101, 480}, {13001, 113, 5116}, {20011, 139, 8978},
	{30011, 173, 12217}, {40009, 199, 9873}, {50021, 223, 5346},
	{75011, 271, 11723}, {100003, 313, 45273}, {200003, 443, 17662},
	{300007, 547, 54772}, {400009, 631, 62707}, {500009, 701, 131},
	{700001, 829, 216705}, {1000003, 997, 162844}
	};

	vector<vector<int>> Zx12 {{12},
	{5003, 61, 1494}, {6007, 79, 2991}, {8191, 89, 3147},
	{10007, 101, 2123}, {13001, 113, 6426}, {20011, 139, 9832},
	{30011, 173, 10777}, {40009, 199, 15380}, {50021, 223, 5963},
	{75011, 271, 14706}, {100003, 313, 35982}, {200003, 443, 80442},
	{300007, 547, 121927}, {400009, 631, 23997}, {500009, 701, 70666},
	{700001, 829, 99859}, {1000003, 997, 337644}
	};

	vector<vector<int>> Zx13 {{13},
	{6007, 79, 1330}, {8191, 89, 2},
	{10007, 101, 684}, {13001, 113, 463}, {20011, 139, 9721},
	{30011, 173, 13148}, {40009, 199, 5491}, {50021, 223, 22854},
	{75011, 271, 28319}, {100003, 313, 37813}, {200003, 443, 98505},
	{300007, 547, 31398}, {400009, 631, 139667}, {500009, 701, 146033},
	{700001, 829, 238553}, {1000003, 997, 7110}
	};

	vector<vector<int>> Zx14 {{14},
	{8191, 89, 2}, {10007, 101, 684}, {13001, 113, 1862}, {20011, 139, 235},
	{30011, 173, 602}, {40009, 199, 19668}, {50021, 223, 2711},
	{75011, 271, 34855}, {100003, 313, 4329}, {200003, 443, 64600},
	{300007, 547, 46069}, {400009, 631, 176722}, {500009, 701, 173675},
	{700001, 829, 66514}, {1000003, 997, 343964}
	};

	vector<vector<int>> Zx15 {{15},
	{10007, 101, 1447}, {13001, 113, 155}, {20011, 139, 3043},
	{30011, 173, 584}, {40009, 199, 3054}, {50021, 223, 14360},
	{75011, 271, 6348}, {100003, 313, 11971}, {200003, 443, 8712},
	{300007, 547, 43496}, {400009, 631, 43350}, {500009, 701, 193732},
	{700001, 829, 280706}, {1000003, 997, 38756}
	};
	
	vector<vector<int>> Zx16 {{16},
	{13001, 113, 6500}, {20011, 139, 2964}, {30011, 173, 5738},
	{40009, 199, 2648}, {50021, 223, 1616}, {75011, 271, 15486},
	{100003, 313, 24883}, {200003, 443, 25445}, {300007, 547, 36857},
	{400009, 631, 15065}, {500009, 701, 10055}, {700001, 829, 212990},
	{1000003, 997, 144679}
	};

	vector<vector<int>> Zx17 {{17},
	{20011, 139, 1249}, {30011, 173, 722},	{40009, 199, 2648},
	{50021, 223, 251}, {75011, 271, 15424}, {100003, 313, 14382},
	{200003, 443, 37201}, {300007, 547, 91248},	{400009, 631, 140640},
	{500009, 701, 40738}, {700001, 829, 218816}, {1000003, 997, 143952}
	};
	
	vector<vector<int>> Zx18 {{18},
	{30011, 173, 653},	{40009, 199, 2648}, {50021, 223, 8080},
	{75011, 271, 4651}, {100003, 313, 23065},
	{200003, 443, 60437}, {300007, 547, 108846}, {400009, 631, 25009},
	{500009, 701, 174372}, {700001, 829, 139751}, {1000003, 997, 58280}
	};

	vector<vector<int>> Zx19 {{19},
	{40009, 199, 2}, {50021, 223, 251},	{75011, 271, 2}, {100003, 313, 35304},
	{200003, 443, 60437}, {300007, 547, 122082}, {400009, 631, 103187},
	{500009, 701, 223350}, {700001, 829, 309551}, {1000003, 997, 452812}
	};

	vector<vector<int>> Zx20 {{20},
	{50021, 223, 2}, {75011, 271, 2}, {100003, 313, 11276},
	{200003, 443, 71129}, {300007, 547, 5281}, {400009, 631, 164406},
	{500009, 701, 180304}, {700001, 829, 159746}, {1000003, 997, 275605}
	};

	// 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,
	// 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157,
	// 163, 167, 173, 179, 181, 191, 193, 197, 199,
	// 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293,
	// 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397,
	// 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499,

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
