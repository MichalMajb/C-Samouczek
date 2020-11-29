#include "stdafx.h"
#include "wyzazanie.h"
#include <iostream>
#include <cstdlib>
#include "Plik.h"
#include <ctime>


wyzazanie::wyzazanie()
{
}
void wyzazanie::dane() {
	std::cout << "podaj temperature poczatkowa" << std::endl;
	std::cin >> T;
	std::cout << "podaj spadek temperatury temperature" << std::endl;
	std::cin >> Tk;
	std::cout << "podaj wspolczynnik" << std::endl;
	std::cin >> m;
}
void wyzazanie::algorytm(Plik & a, Plik & b, Plik & c)
{
	srand(time(NULL));
	l = 0;
	l1 = 0;
	lbest=99999999;
	p = 0;
	q = 0;
	delta=0;
	while (T >= Tk)
	{
		for (int s = 0; s < c.n; s++)
		{
			l = l + a.d[b.t[s]][b.t[s + 1]];
		}
		z1 = rand() % 8 + 1;
		z2 = rand() % 8 + 1; //w razie czego wpisaæ flor

		if (z1 < z2) {
			for (int i = 0; i < z1; i++)
			{
				t1[i] = b.t[i];
			}
			for (int i = z1; i < z2; i++)
			{
				t1[i] = b.t[i + 1];
			}
			t1[z2] = b.t[z1];
			for (int i = z2 + 1; i < 10; i++)
			{
				t1[i] = b.t[i];
			}
		}
		else {
			for (int i = 0; i < z2; i++)
			{
				t1[i] = b.t[i];
			}
			for (int i = z2; i < z1; i++)
			{
				t1[i] = b.t[i + 1];
			}
			t1[z1] = b.t[z2];
			for (int i = z1 + 1; i < 10; i++)
			{
				t1[i] = b.t[i];
			}
		}
		for (int s = 0; s<c.n; s++)
		{
			l1 = l1 + a.d[t1[s]][t1[s + 1]];
		}

		if (l1 < lbest)
		{
			lbest = l1;
			for (int j = 0; j < 10; j++)
			{
				t2[j] = t1[j];
			}
		}

		delta = l1 - l;
		if (delta <= 0) {
			for (int j = 0; j < 10; j++)
			{
				b.t[j] = t1[j];
			}
		}
		else {
			p = exp(-delta / T);
			q = rand() % 1;
			if (q < p) {
				for (int y = 0; y < 10; y++)
				{
					b.t[y] = t1[y];
				}
			}

		}
		T = m*T;
		l1 = 0;


	}
	std::cout << lbest <<std::endl;
}


wyzazanie::~wyzazanie()
{
}
