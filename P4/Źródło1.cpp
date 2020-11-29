// Ty te¿ jesteœ spokoMichal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include<cstdlib>
#include <ctime>



using namespace std;

void main()
{
	srand(time(NULL));

	int z1, z2;
	int n;
	int d[9][9];
	int L = 0, L1 = 0, Lbest = 1000000;
	int t[10];
	double T = 1000;
	double Tk = 0.1;
	double a = 0.995;
	double p, q;
	int t1[10], t2[10]; //t1 tymczasowe t2 najlepsze
	int delta;

	FILE* plik;
	plik = fopen("E:\\stopien2\\optymalizacja\\Ty te¿ jesteœ spokoMichal\\exp0.txt", "r");

	fscanf(plik, "%d", &n);

	for (int i = 0; i<9; i++)
	{
		for (int j = 0; j<9; j++)
		{
			fscanf(plik, "%d", &d[i][j]);
		}
	}

	for (int k = 0; k<11; k++)
	{
		fscanf(plik, "%d", &t[k]);
	}

	fclose(plik);


	while (T >= Tk)
	{
		for (int s = 0; s<n; s++)
		{
			L = L + d[t[s]][t[s + 1]];
		}
		z1 = rand() % 8 + 1;
		z2 = rand() % 8 + 1; //w razie czego wpisaæ flor

		if (z1 < z2) {
			for (int i = 0; i < z1; i++)
			{
				t1[i] = t[i];
			}
			for (int i = z1; i < z2; i++)
			{
				t1[i] = t[i + 1];
			}
			t1[z2] = t[z1];
			for (int i = z2 + 1; i < 10; i++)
			{
				t1[i] = t[i];
			}
		}
		else {
			for (int i = 0; i < z2; i++)
			{
				t1[i] = t[i];
			}
			for (int i = z2; i < z1; i++)
			{
				t1[i] = t[i + 1];
			}
			t1[z1] = t[z2];
			for (int i = z1 + 1; i < 10; i++)
			{
				t1[i] = t[i];
			}
		}

		for (int s = 0; s<n; s++)
		{
			L1 = L1 + d[t1[s]][t1[s + 1]];
		}

		if (L1 < Lbest)
		{
			Lbest = L1;
			for (int j = 0; j < 10; j++)
			{
				t2[j] = t1[j];
			}
		}

		delta = L1 - L;
		if (delta <= 0) {
			for (int j = 0; j < 10; j++)
			{
				t[j] = t1[j];
			}
		}
		else {
			p = exp(-delta / T);
			q = rand() % 1;
			if (q < p) {
				for (int y = 0; y < 10; y++)
				{
					t[y] = t1[y];
				}
			}

		}
		T = a*T;
		L1 = 0;


	}



	printf("L= %d\n", Lbest);

}




