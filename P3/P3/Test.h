#pragma once
#include "Friends.h"
class Test
{
public:
	void m(Friends &k) {
		k.t = 0;
	}

	Test();
	Test(const Test &);
	~Test();
};

