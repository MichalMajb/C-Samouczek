#pragma once
#include "Plik.h"
class wyzazanie
	
{
	int l;
	double T, Tk, m, p, q, delta;
	double l1;
	double lbest;
	int z1, z2;
	int t1[10], t2[10];
public:
	wyzazanie();
	void dane();
	void algorytm(Plik & d, Plik & t, Plik & n);
	~wyzazanie();
};

