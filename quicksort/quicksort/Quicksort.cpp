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
//#include "windows.h"
//#include "libloaderapi.h"

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
	if (wczytaj_z_pliku() /*&& wczytaj_z_pliku_wektor(*/)
	{
		clock_t start = clock();

		//quicksort_parallel;
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

//void Quicksort::set_tab(int, int, int)
//{
//
//}

bool Quicksort::wczytaj_z_pliku()
{
	rozmiar_tab = 0;
	ifstream plik("liczby.txt");
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

bool Quicksort::wczytaj_z_pliku_wektor()
{
	ifstream plik("liczby.txt");
	int n_wartosc;
	if (plik)
	{
		while (!plik.eof())
		{
			plik >> n_wartosc;
			wektor.push_back(n_wartosc);
		}
		plik.close();
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
			//thread lower(_sort);
			std::thread lower((&Quicksort::_sort),this,tab, p, q - 1);
			std::thread upper(&Quicksort::_sort, this,tab, q + 1, r);
			//std::thread cos(&quicksort);
			lower.join();
			upper.join();
		}
		thread_count--;
	}
}
//typedef HRESULT(CALLBACK* LPFNDLLFUNC1)(DWORD, UINT*);
//
//HRESULT LoadAndCallSomeFunction(DWORD dwParam1, UINT* puParam2)
//{
//	HINSTANCE hDLL;               // Handle to DLL
//	LPFNDLLFUNC1 lpfnDllFunc1;    // Function pointer
//	HRESULT hrReturnVal;
//
//	hDLL = LoadLibrary("Dll_cpp");
//	if (NULL != hDLL)
//	{
//		lpfnDllFunc1 = (LPFNDLLFUNC1)GetProcAddress(hDLL, "DLLFunc1");
//		if (NULL != lpfnDllFunc1)
//		{
//			// call the function
//			hrReturnVal = lpfnDllFunc1(dwParam1, puParam2);
//		}
//		else
//		{
//			// report the error
//			hrReturnVal = ERROR_DELAY_LOAD_FAILED;
//		}
//		FreeLibrary(hDLL);
//	}
//	else
//	{
//		hrReturnVal = ERROR_DELAY_LOAD_FAILED;
//	}
//	return hrReturnVal;
//}
int Quicksort::_partition(int * tab, int p, int r)
{
	//HINSTANCE hDLL;               // Handle to DLL
	//LPFNDLLFUNC1 lpfnDllFunc1;    // Function pointer
	//HRESULT hrReturnVal;

	auto first = tab[p];
	auto last = tab[r];
	int pivot = 0;
	// Median of three
	int middle = tab[(p + 2) / 2];
	if (first > middle)
	{
		///////////////////////////////////////////////////////////////////////////////////////////////
		//hDll =LoadLibraryEx ("Dll_cpp");
		//GetProcAddress;

		//FreeLibrary;

		if (middle > last)
		{
			pivot = middle;
		}
		else
		{
			pivot = last;
		}
	}
	else {
		if (middle > last)
		{
			pivot = std::max(first, last);
		}
		else
		{
			pivot = middle;
		}
	}
	auto i = p - 1;
	for (int j = p; j < r; ++j)
	{
		if (tab[j] <= pivot)
		{
			_swap(++i, j);
		}
	}
	_swap(i + 1, r);
	return i + 1;
}

void Quicksort::sort()
{
	thread_count = 0;
	int p = 0;
	int r = rozmiar_tab - 1;
	_sort(tab, p, r);
}

void Quicksort::_swap(int first, int second)
{
	int temp = tab[first];
	tab[first] = tab[second];
	tab[second] = temp;
}


//template <typename T>
//void filter_less_than(const vector<T>& amp; v, vector<T>& amp; lesser, const int pivot) {
//	for (const auto el : v) {
//		if (el < pivot) lesser.push_back(el);
//	}
//}
//
//template <typename T>
//void quick_sort_parallel1(vector<T>& amp; v) {
//	if (v.size() <= 1) return;
//	auto start_it = v.begin();
//	auto end_it = v.end();
//
//	const T pivot = *start_it;
//	vector<T> lesser;
//	auto fut1 = std::async(
//		std::launch::async,
//		[&amp;]() {
//		filter_less_than<T>(std::ref(v), std::ref(lesser), pivot);
//		quick_sort_parallel1<T>(std::ref(lesser));
//	});
//
//	vector<T> greater;
//	copy_if(start_it + 1, end_it, std::back_inserter(greater),
//		[&amp;](const T& amp; el) { return el >= pivot; });
//
//	quick_sort_parallel1(greater);
//
//	fut1.wait();
//
//	std::copy(lesser.begin(), lesser.end(), v.begin());
//	v[lesser.size()] = pivot;
//	std::copy(greater.begin(), greater.end(),
//		v.begin() + lesser.size() + 1);
//}