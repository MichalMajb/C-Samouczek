// Ty te¿ jesteœ spokoMichal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Plik.h"
#include "wyzazanie.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cstdlib>
#include <ctime>



void main()
{

	Plik P;
	wyzazanie A;
	P.N();
	P.D();
	P.T();
	A.dane();
	std::cout << "Najlepszy wynik to:" << std::endl;
	A.algorytm(P,P,P);

}




