#pragma once

class Friends
{
	int t;
	friend class Test;
	friend void f(Friends & );
public:
	Friends();
	~Friends();
};

