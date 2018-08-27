/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * main.cc
 * Copyright (C) 2014 Erik Barto¨ <erik.bartos@gmail.com>
 *
 * Mikor is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Mikor is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * $Date: 2014/09/29 09:04:07 $
 * $Revision: db831d4cfaf0 $
 * $Author: mezekus $
 * $Id: main.cpp,v db831d4cfaf0 2014/09/29 09:04:07 mezekus $
 *
 * @file
 * @brief	Main programe for numerical integration by the Korobov's method.
 */

#include <iostream>
#include <ctime>

#include "ExternalFCN.cpp"
#include "Mikor.cpp"

//using namespace std;

int main(int argc, char** argv)
{

	std::cout << "\n==============================================" << std::endl;
	std::cout << "   Program: " << argv[0] << std::endl;
	std::cout << "   Version 1.0.0, (c) 2014 Erik Bartos" << std::endl;
	std::cout << "==============================================" << std::endl;

	time_t rawtime;
	time ( &rawtime );
	std::cout << "\n> Start of program: " << ctime ( &rawtime ) << std::endl;

	Mikor myIntegral(3,2);
	std::cout << "> Simple polynomial like functions: " << std::endl;
	std::cout << "> Function 1: 44.*x[0]^3.*x[1]^10." << std::endl;
	std::cout << "> Function 2: 1./sqrt(x[0] + log(x[1] + x[2])*log(x[1] + x[2]))" << std::endl;

	myIntegral.printParameters();
	std::cout << "> Default parameters." << std::endl;
	
	myIntegral.setParameters(1.,-1.,3,-0.1); // T1, T2, L, H
	myIntegral.setEps(-0.001);
	myIntegral.printParameters();
	std::cout << "> User parameters." << std::endl;

	myIntegral.setLimits(0.,1.);

	myIntegral.Calculate();

	time ( &rawtime );
	std::cout << "\n> End of program:   " << ctime ( &rawtime ) << std::endl;

	return EXIT_SUCCESS;
}
