#include "pch.h"
#include <iostream>


struct Lista
{
	Lista * ogon;
	int liczba;
};

struct WspolrzedneListy
{
	Lista* poczatek;
	Lista* koniec;
};

// Wypisz wszystkie elementy listy
void wypisz(Lista * lista)
{
	// Przechodzenie po liście *rekurencyjnie*
	if (lista)
	{
		std::cout << lista->liczba << ", ";
		wypisz(lista->ogon);
	}
}


// Zwróć: wskaźnik na ostatni element listy
Lista * ostatni(Lista * lista)
{
	// Przechodzenie po liście *iteracyjnie*
	if (lista)
		while (lista->ogon)
			lista = lista->ogon;

	return lista;
}


// Dodaj element na koniec listy
void dodajKoniec(Lista *& lista,Lista*& koniec, int liczba)
{
	// Tworzymy nowy element listy
	Lista * nowy = new Lista;
	nowy->liczba = liczba;
	nowy->ogon = nullptr;

	// Dopisujemy na koniec
	if (lista)
		ostatni(lista)->ogon = nowy;
	else
		lista = nowy;
	koniec = nowy;
}
void dodajPoczatek(Lista *& lista, int liczba)
{
	
	Lista * nowy = new Lista;
	nowy->liczba = liczba;
	nowy->ogon = lista;

		lista = nowy;
}


// Usuwa listę
void zniszcz(Lista *& lista)
{
	while (lista)
	{
		Lista * tmp = lista;
		lista = lista->ogon;
		delete tmp;
	}

	lista = nullptr;
}


int main()
{
	int liczba;
	WspolrzedneListy lista = { nullptr, nullptr };
	std::cout << "Podaj liczby, 0 lub blad konczy:\n";

	while (std::cin >> liczba && liczba)
		dodajKoniec(lista.poczatek, lista.koniec, liczba);

	std::cout << "Koniec, oto liczby:\n";
	wypisz(lista.poczatek);
	zniszcz(lista.poczatek);
}