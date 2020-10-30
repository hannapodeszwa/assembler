#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <time.h>
#include <forward_list>
#include <thread>
#include "framework.h"

#include "biblioteka2.h"
#include "Quicksort.h"

using namespace std;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;




void Quicksort::quicksort()
{
	czas = 0;
	if (wczytaj_z_pliku())
	{
		sort();


		ofstream plik("zapisane.txt");

		if (plik)
		{
			for (int i = 0;i < rozmiar_tab;i++)
			{
				plik << tab[i];
				plik << endl;
			}
			plik.close();
		}
		else
			MessageBox::Show("Blad otwarcia pliku wyjsciowego.");
		MessageBox::Show("Gotowe.");
		
	}
}

bool Quicksort::wczytaj_z_pliku()
{
	rozmiar_tab = 0;
	ifstream plik(plik_n);
	int n_wartosc;

	if (plik)
	{
		forward_list <int> tmp;
		while (!plik.eof())
		{
			rozmiar_tab++;
			plik >> n_wartosc;
			tmp.push_front(n_wartosc);
		}
		plik.close();


		tab = (int*)malloc((rozmiar_tab * sizeof(int)));
		int i = 0;
		for (int& c : tmp)
		{
			tab[i] = c;
			i++;
		}
	}
	else
	{
		MessageBox::Show("Blad otwarcia pliku.");
		return false;
	}
	return true;
}


void Quicksort::_sort(int* tab, int p, int r)
{
	thread_count++;
	if (p < r)
	{
		clock_t start = clock();

		int q = _partition(tab, p, r);
		clock_t stop = clock();
		czas += stop - start;
		if (thread_count >= liczba_watkow)
		{
			_sort(tab, p, q - 1);
			_sort(tab, q + 1, r);
		}
		else
		{
			std::thread lower((&Quicksort::_sort), this, tab, p, q - 1);
			_sort(tab, q + 1, r);
			lower.join();
		}
		thread_count--;
	}
}

int Quicksort::_partition(int* tab, int p, int r)
{
	int first = tab[p];
	int last = tab[r];
	int pivot = 0;


	pivot = tab[r];
	auto i = p - 1;
	int max = r - 1;
	int j = p;

	if (czy_asm)
	{
		ten_for procedura2 = (ten_for)GetProcAddress(dllHandle, "ten_for");
		int x = procedura2(tab, p, r, pivot);
		i = x;
	}
	else
		ten_for_c(tab, p,r,pivot,i);


	//for (int j = p; j <= (r - 1); j++)
	//{
	//	if (tab[j] < pivot)
	//	{
	//		i++;
	//		_swap(tab, i, j);
	//	}
	//}
	_swap(tab, i + 1, r);
	return i + 1;
}

void Quicksort::sort()
{
	thread_count = 0;
	int p = 0;
	int r = rozmiar_tab - 1;
	_sort(tab, p, r);
}

void Quicksort::_swap(int* tab, int first, int second)
{
	int temp = tab[first];
	tab[first] = tab[second];
	tab[second] = temp;
}


