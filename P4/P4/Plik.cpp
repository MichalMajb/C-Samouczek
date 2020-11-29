#include "stdafx.h"
#include "Plik.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cstdlib>
#include <ctime>




Plik::Plik()
{
	plik = fopen("E:\\C++\\P4\\exp0.txt", "r");
}

int Plik::N()
{
	fscanf(plik, "%d", &n);
	return n;
}

int *Plik::D()
{
	for (int i = 0; i<9; i++)
	{
		for (int j = 0; j<9; j++)
		{
			fscanf(plik, "%d", &d[i][j]);//jakiœ wyj¹tek
		}
	}
	return *d;
}

int *Plik::T()
{
	for (int k = 0; k<10; k++)
	{
		fscanf(plik, "%d", &t[k]);
	}
	return t;
}

/*int Plik::L()
{
	for (int s = 0; s<n; s++)
	{
		l = l + d[t[s]][t[s + 1]];
	}
	//std::cout << std::endl << "L=" << l << std::endl;
	return l;
}*/






Plik::~Plik()
{
	fclose(plik);
}
