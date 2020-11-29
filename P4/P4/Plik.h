#pragma once
class Plik
{
	int n;
	int d[9][9];
	int l = 0;
	int t[10];
	friend class P4;
	friend class wyzazanie;
public:
	FILE *plik;
	Plik();
	int N();
	int *D();
	int *T();
	//int L();
		
	~Plik();
};










