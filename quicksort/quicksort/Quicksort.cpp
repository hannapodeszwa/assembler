#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <time.h>
#include <forward_list>
#include <thread>
#include <vector>
#include <utility>
#include "framework.h"

//#include "biblioteka.h"
#include "biblioteka2.h"
#include "Quicksort.h"

using namespace std;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

typedef int(_stdcall* MyProc1)(int, int);
//HINSTANCE hInst;

void Quicksort::quicksort()
{
	if (wczytaj_z_pliku())
	{
		clock_t start = clock();

		sort();

		clock_t stop = clock();

		ofstream plik("zapisane.txt");

		if (plik)
		{
			for (int i=0;i<rozmiar_tab;i++)
			{
				plik << tab[i];
				plik << endl;
			}
		}
		plik.close();
		MessageBox::Show(Convert::ToString(tab[0]));

		czas = stop - start;
	}
}

bool Quicksort::wczytaj_z_pliku()
{
	rozmiar_tab = 0;
	//ifstream plik("liczby2.txt");
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
		int q = _partition(tab,p, r);
		if (thread_count >= liczba_watkow)
		{
			_sort(tab, p, q - 1);
			_sort(tab, q + 1, r);
		}
		else
		{
			/*std::thread lower((&Quicksort::_sort),this,tab, p, q - 1);
			std::thread upper(&Quicksort::_sort, this,tab, q + 1, r);
			
			lower.join();
			upper.join();*/
			std::thread lower((&Quicksort::_sort), this, tab, p, q - 1);
			_sort(tab, q + 1, r);
			lower.join();
		}
		thread_count--;
	}
}

int Quicksort::_partition(int * tab, int p, int r)
{
	HINSTANCE dllHandle = LoadLibrary(L"JAAsm.dll");// NULL;
  dllHandle = LoadLibrary(L"JAAsm.dll");

  MyProc1 procedura = (MyProc1)GetProcAddress(dllHandle, "MyProc1");

  int x = 9, y = 3;
  int retVal = procedura(x, y);



	auto first = tab[p];
	auto last = tab[r];
	int pivot = 0;
	// Median of three
	int middle = tab[(p + r) / 2];
	//if (first > middle)
	//{
	//	//funkcja(middle,last,pivot);

	//	if (middle > last)
	//	{
	//		pivot = middle;
	//	}
	//	else
	//	{
	//		pivot = std::min(first, last);
	//	}
	//}
	//else {
	//	if (middle > last)
	//	{
	//		pivot = std::max(first, last);
	//	}
	//	else
	//	{
	//		pivot = middle;
	//	}
	//}
	pivot = tab[r]; //
	auto i = p - 1;
	//for (int j = p; j < r; ++j)//j<r
	//{
	//	if (tab[j] <= pivot)
	//	{
	//		_swap(tab,++i, j);
	//	}
	//}
	//_swap(tab, i + 1, r);
	//return i + 1;
	for (int j = p; j <= (r-1); j++)//j<r
	{
		if (tab[j] < pivot)
		{
			i++;
			if (czy_asm)
			{
			}//swap_asm(tab, i, j);
			else
				swap_c(tab, i, j);
			//_swap(tab, i, j);
		}
	}
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

void Quicksort::_swap(int * tab,int first, int second)
{
	int temp = tab[first];
	tab[first] = tab[second];
	tab[second] = temp;
}


