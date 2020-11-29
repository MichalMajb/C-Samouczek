#include "pch.h"
#include "stdlib.h"
#include <iostream>

void main() {
	int * tab = nullptr, size = 0;
	std::cout << "Podawaj liczby, 0 konczy wczytywanie.\n";
	int *newTab = new int[size];
	while (true) {
		int number;
		std::cin >> number;

		if (number == 0) {
			break;
		}
	/*	for (int i = 0; i < size; ++i) {
			newTab[i] = tab[i];
		} */
		newTab[size] = number;
		//delete[] tab;
		//tab = newTab;
		size++;
	}
	std::cout << "to samo ale odwrotnie \n";
	for (int i = size - 1; i >= 0; i--) {
		std::cout << newTab[i] << ' ';
	}
	delete [size] newTab;
}