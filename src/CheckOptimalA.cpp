/**
 * @brief		Check first optimal values
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
	cout << "\n> Start of program: " << ctime ( &rawtime ) << endl;

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

	vector<vector<int>> Wx4 {{4, 23, 5, 5},
		{4, 53, 31, 12},
		{4, 101, 15, 27},
		{4, 151, 22, 48},
		{4, 307, 42, 95},
		{4, 523, 178, 238},
		{4, 829, 45, 350},
		{4, 1259, 483, 550},
		{4, 2129, 766, 970},
		{4, 3001, 174, 1466},
		{4, 4001, 113, 956},
		{4, 5003, 792, 2053},
		{4, 6007, 1351, 2610},
		{4, 8191, 2488, 3842},
		{4, 10007, 1206, 1784},
		{4, 13001, 778, 4796},
		{4, 20011, 2891, 6016},
		{4, 30011, 2243, 12084},
		{4, 40009, 2775, 9023},
		{4, 50021, 3353, 23277},
		{4, 75011, 7601, 13715},
		{4, 100003, 10101, 12475},
		{4, 200003, 19293, 17914},
		{4, 500009, 55251, 127616, 246131},
		{4, 1000003, 122713, 33889},
		{4, 2000003, 191447, 317039},
		{4, 5000011, 492615, 1305459}
	};

	vector<vector<int>> Wx5 {{5, 101, 21, 21},
		{5, 151, 13, 58},
		{5, 307, 127, 127},
		{5, 523, 64, 237},
		{5, 829, 146, 146},
		{5, 1259, 302, 302},
		{5, 2129, 618, 720},
		{5, 3001, 408, 408},
		{5, 4001, 1534, 1534},
		{5, 5003, 840, 840},
		{5, 6007, 509, 509},
		{5, 8191, 1386, 1386},
		{5, 10007, 198, 198},
		{5, 13001, 830, 1864},
		{5, 20011, 2803, 9432},
		{5, 30011, 2311, 13604},
		{5, 40009, 2945, 12216},
		{5, 50021, 3581, 7255},
		{5, 75011, 7639, 16449},
		{5, 100003, 10019, 11729},
		{5, 200003, 19777, 62638, 25268},
		{5, 500009, 61357, 32497},
		{5, 1000003, 122713, 335440},
		{5, 2000003, 191447, 701679},
		{5, 5000011, 492615, 1516505}
	};

	vector<vector<int>> Wx6 {{6, 151, 109, 18},
		{6, 307, 195, 74, 122},
		{6, 523, 118, 164},
		{6, 829, 109, 289},
		{6, 1259, 200, 200},
		{6, 2129, 41, 727},
		{6, 3001, 233, 322},
		{6, 4001, 1751, 1780},
		{6, 5003, 2037, 2208},
		{6, 6007, 312, 312},
		{6, 8191, 1632, 3699},
		{6, 10007, 2240, 2399},
		{6, 13001, 1940, 1940},
		{6, 20011, 3169, 6387},
		{6, 30011, 2347, 6645},
		{6, 40009, 2875, 4902},
		{6, 50021, 3431, 15683},
		{6, 75011, 7647, 2127},
		{6, 100003, 10049, 6798},
		{6, 200003, 19277, 99038, 18122},
		{6, 500009, 33363, 174069},
		{6, 1000003, 66681, 127632},
		{6, 2000003, 191401, 752526},
		{6, 5000011, 613509, 60100}
	};

	vector<vector<int>> Wx7 {{7, 523, 27, 155},
		{7, 829, 90, 175},
		{7, 1259, 227, 599},
		{7, 2129, 596, 718},
		{7, 3001, 170, 865},
		{7, 4001, 115, 115},
		{7, 5003, 229, 1573},
		{7, 6007, 721, 1508},
		{7, 8191, 2107, 2834},
		{7, 10007, 2304, 2304},
		{7, 13001, 2116, 4797},
		{7, 20011, 1773, 3851},
		{7, 30011, 2253, 8784},
		{7, 40009, 2965, 14905},
		{7, 50021, 3401, 23981},
		{7, 75011, 7555, 12914},
		{7, 100003, 6703, 18083},
		{7, 200003, 24561, 72045, 2368},
		{7, 500009, 33339, 75479},
		{7, 1000003, 66671, 119956},
		{7, 2000003, 191443, 259724},
		{7, 5000011, 613509, 0}
	};

	vector<vector<int>> Wx8 {{8, 829, 32, 32},
		{8, 1259, 392, 392},
		{8, 2129, 86, 86},
		{8, 3001, 993, 955},
		{8, 4001, 1850, 1728},
		{8, 5003, 2362, 2362},
		{8, 6007, 1253, 1253},
		{8, 8191, 3787, 2602},
		{8, 10007, 436, 1905},
		{8, 13001, 1415, 1352},
		{8, 20011, 3295, 7191},
		{8, 30011, 3267, 7011},
		{8, 40009, 3093, 9946},
		{8, 50021, 3455, 10899},
		{8, 75011, 7809, 17605},
		{8, 100003, 10029, 15120},
		{8, 200003, 19827, 39993},
		{8, 500009, 61365, 42535},
		{8, 1000003, 90343, 230727},
		{8, 2000003, 191437, 0},
		{8, 5000011, 492261, 0}
	};

	vector<vector<int>> Wx9 {{9, 2129, 636, 636},
		{9, 3001, 108, 108},
		{9, 4001, 1579, 1234},
		{9, 5003, 526, 526},
		{9, 6007, 1597, 2633},
		{9, 8191, 2139, 3052},
		{9, 10007, 470, 4748},
		{9, 13001, 1437, 3391},
		{9, 20011, 2533, 6181},
		{9, 30011, 2077, 2348},
		{9, 40009, 3119, 10979},
		{9, 50021, 3469, 5358},
		{9, 75011, 7813, 10460},
		{9, 100003, 10099, 48635},
		{9, 200003, 19461, 2611},
		{9, 500009, 61365, 10374},
		{9, 1000003, 90343, 26697},
		{9, 2000003, 191415, 312566},
		{9, 5000011, 613507, 1498606}
	};

	vector<vector<int>> Wx10 {{10, 5003, 431, 592},
		{10, 6007, 1262, 1262},
		{10, 8191, 1751, 1751},
		{10, 10007, 564, 1554},
		{10, 13001, 1415, 3466},
		{10, 20011, 1715, 6951},
		{10, 30011, 2065, 8883},
		{10, 40009, 2901, 15619},
		{10, 50021, 3413, 9224},
		{10, 75011, 7677, 31958},
		{10, 100003, 6699, 833},
		{10, 200003, 19153, 0},
		{10, 500009, 33341, 131579},
		{10, 1000003, 107369, 291906},
		{10, 2000003, 191435, 81876},
		{10, 5000011, 613515, 903657}
	};
	
	vector<vector<int>> Wx11 {{11, 10007, 586, 480},
		{11, 13001, 1409, 5116},
		{11, 20011, 2205, 8978},
		{11, 30011, 3237, 12217},
		{11, 40009, 4325, 9873},
		{11, 50021, 5419, 5346},
		{11, 75011, 8063, 11723},
		{11, 100003, 10151, 45273},
		{11, 200003, 24573, 17662},
		{11, 500009, 55269, 131},
		{11, 1000003, 107393, 162844},
		{11, 2000003, 191389, 506852},
		{11, 5000011, 613515, 46355}
	};

	vector<vector<int>> Wx12 {{12, 20011, 2191, 9832},
		{12, 30011, 3319, 10777},
		{12, 40009, 4319, 15380},
		{12, 50021, 3407, 5963},
		{12, 75011, 8099, 14706},
		{12, 100003, 10151, 35982},
		{12, 200003, 24573, 0},
		{12, 500009, 61365, 0},
		{12, 1000003, 107377, 0},
		{12, 2000003, 191389, 0},
		{12, 5000011, 613507, 0}
	};

	vector<vector<int>> Wx13 {{13, 50021, 5407, 22854},
		{13, 75011, 8061, 28319},
		{13, 100003, 10761, 37813},
		{13, 200003, 24573, 0},
		{13, 500009, 61371, 0},
		{13, 1000003, 107375, 0},
		{13, 2000003, 191433, 0},
		{13, 5000011, 478471, 0}
	};

	vector<vector<int>> Wx14 {{14, 50021, 5407, 2711},
		{14, 75011, 8099, 34855},
		{14, 100003, 10143, 4329},
		{14, 200003, 19363, 0},
		{14, 500009, 61371, 0},
		{14, 1000003, 106245, 0},
		{14, 2000003, 191433, 0},
		{14, 5000011, 478471, 0}
	};

	vector<vector<int>> Wx15 {{15, 50021, 5417, 14360},
		{15, 75011, 8061, 6348},
		{15, 100003, 10171, 11971},
		{15, 200003, 20015, 0},
		{15, 500009, 61371, 0},
		{15, 1000003, 106265, 0},
		{15, 2000003, 191405, 0},
		{15, 5000011, 478471, 0}
	};

	vector<vector<int>> Wx16 {{16, 500009, 61373, 0},
		{16, 1000003, 106257, 0},
		{16, 2000003, 191405, 0},
		{16, 5000011, 492613, 0}
	};

	vector<vector<int>> Wx17 {{17, 500009, 61353, 0},
		{17, 1000003, 106245, 0},
		{17, 2000003, 191421, 0},
		{17, 5000011, 492613, 0}
	};

	vector<vector<int>> Wx18 {{18, 500009, 61353, 0},
		{18, 1000003, 106257, 0},
		{18, 2000003, 191421, 0},
		{18, 5000011, 478471, 0}
	};

	vector<vector<int>> Wx19 {{19, 500009, 61353, 0},
		{19, 1000003, 106245, 0},
		{19, 2000003, 191421, 0},
		{19, 5000011, 478471, 0}
	};

	vector<vector<int>> Wx20 {{20, 500009, 61353, 0},
		{20, 1000003, 106233, 0},
		{20, 2000003, 191421, 0},
		{20, 5000011, 478471, 0}
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
	cout << "\n\n> End of program:   " << ctime ( &rawtime ) << endl;

	return EXIT_SUCCESS;
}
