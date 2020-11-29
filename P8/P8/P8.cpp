#include "pch.h"
#include <iostream>
#include <stdexcept>


void funkcja()
{
	//throw 5;
	//throw "cos innego";
	//throw std::logic_error("Cos poszlo nie tak :(");
	throw std::runtime_error("Cos poszlo nie tak :(");
}

void test()
{
	try
	{
		std::cout << "Proba pierwsza\n";
		funkcja();
		std::cout << "Proba druga\n";
		funkcja();
	}
	catch (std::runtime_error & e)
	{
		std::cout << "Runtime error: " << e.what() << "  (ale nic nie szkodzi)\n";
	}
	catch (std::exception & e)
	{
		std::cout << "Inny standardowy wyjatek: " << e.what() << '\n';
		// Rzuć złapany wyjątek ponownie
		throw;
		// Nie:
		//throw e;
		// Patrz: czerwona ramka
	}
	catch (int)
	{
		std::cout << "Mowilem, zebys nie rzucal int >:/\n";
		// Rzuć nowy, inny wyjątek
		throw std::logic_error("Nieoczekiwany int");
	}
	catch (...)
	{
		std::cout << "Nieoczekiwany, nieznany wyjatek!\n";
		throw std::logic_error("Zlapano nieznany wyjatek");
	}
}

int main()
{
	try
	{
		test();
	}
	catch (std::runtime_error & e)
	{
		std::cout << "Blad wykonania programu: " << e.what() << '\n';
	}
	catch (std::logic_error & e)
	{
		std::cout << "Blad logiczny programu: " << e.what() << '\n';
	}
}