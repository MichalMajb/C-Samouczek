// P3.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"
#include "Test.h"
#include "Friends.h"
#include <iostream>

class K {
	int M;
public:
	void Set(int n);
	int Get();
};
void K::Set(int n) {
	M = n;
}

int K::Get() {
	return M;
}



int main()
{
	K k;
	k.Set(5);
	std::cout << k.Get();
	{
		Friends k;
		Test t;
		t.m(k);
		f(k);

	}
	std::cout << "lol" << std::endl;
	{
		Test t1;
		Test t2 = t1;
	}
}

