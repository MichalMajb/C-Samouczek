#include "stdafx.h"
#include "Test.h"
#include "Friends.h"
#include <iostream>


Test::Test()
{
	std::cout << "konstruktor" << std::endl;
	
}


Test::Test(const Test &)
{
	std::cout << "konstruktor kopiujacy" << std::endl;
}

Test::~Test()
{
	std::cout << "destruktor" << std::endl;
}
