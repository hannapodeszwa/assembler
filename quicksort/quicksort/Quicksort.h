#ifndef Quicksort_H  
#define Quicksort_H
#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
//#include <future>
#include <thread>
#include <mutex>
#include <chrono>
#include <math.h>
#include <stdlib.h>

using namespace std;


class Quicksort
{
private:
	double czas;
	int liczba_watkow;
	int* tab;
	vector<int> wektor;//1

	int rozmiar_tab;
	//const int pivot;

	vector<int> mniejsze; //1
	vector<int> wieksze;//1

	//int p;
	//int r;
	int thread_count;
public:
	//Quicksort() {}
	void quicksort();
	double get_czas() { return czas; }

	void set_liczba_watkow(int w) { liczba_watkow = w; }

	bool wczytaj_z_pliku();
	bool wczytaj_z_pliku_wektor();

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void sort();
	/*{
		thread_count = 0;
		int p = 0;
		int r = rozmiar_tab - 1;
		_sort(tab,p, r);
	}*/

	void _swap(int first, int second);
	/*{
		int temp = tab[first];
		tab[first] = tab[second];
		tab[second] = temp;
	}*/

	void _sort(int* tab, int p, int r);
	//{
	//	thread_count++;
	//	if (p < r)
	//	{
	//		int q = _partition(p,r);
	//		if (thread_count >= liczba_watkow)
	//		{
	//			_sort(tab,p, q - 1);
	//			_sort(tab,q + 1, r);
	//		}
	//		else
	//		{
	//			std::thread lower(&_sort, this,  p, q - 1);
	//			std::thread upper(&_sort, this,  q + 1, r);
	//			std::thread cos(&quicksort);
	//			lower.join();
	//			upper.join();
	//		}
	//		thread_count--;
	//	}
	//}

	int _partition(int * tab, int p, int r);
		//{
		//	auto first = tab[p];
		//	auto last = tab[r];
		//	int pivot = 0;
		//	// Median of three
		//	int middle = tab[(p + 2) / 2];
		//	if (first > middle)
		//	{
		//		if (middle > last)
		//		{
		//			pivot = middle;
		//		}
		//		else
		//		{
		//			pivot = last;
		//		}
		//	}
		//	else {
		//		if (middle > last)
		//		{
		//			pivot = std::max(first, last);
		//		}
		//		else
		//		{
		//			pivot = middle;
		//		}
		//	}
		//	auto i = p - 1;
		//	for (int j = p; j < r; ++j)
		//	{
		//		if (tab[j] <= pivot)
		//		{
		//			_swap(++i, j);
		//		}
		//	}
		//	_swap(i + 1, r);
		//	return i + 1;
		//}

		//void filtr_mniejsze_niz(const int pivot)
		//{
		//	for (int& el : wektor)
		//	{
		//		if (el < pivot)
		//			mniejsze.push_back(el);
		//	}
		///*	for (int i = 0;i < rozmiar_tab;i++)
		//	{
		//		if (tab[i] < pivot)
		//			mniejsze.push_back(tab[i]);
		//	}*/
		//}
		//void quicksort_parallel()
		//{
		//	int rozmiar = rozmiar_tab;
		//	if (rozmiar <= 1)
		//	{
		//		return;
		//	}
		//	/*int poczatek = tab[0];
		//	int koniec = tab[rozmiar_tab - 1];*/
		//	auto poczatek = wektor.begin();
		//	auto koniec = wektor.end();

		//	const int pivot = *poczatek;

		//	auto fut1 = std::async(std::launch::async, wektor)
		//		{
		//			filtr_mniejsze_niz(std::ref(tab), std::ref(mniejsze), pivot);
		//			quicksort_parallel(str::ref(mniejsze))
		//		})

		//		kopiuj(poczatek + 1, koniec, std::back_inserter(wieksze), [tab]
		//			{
		//				return el >= pivot;
		//			}
		//			);

		//			quicksort_parallel(wieksze);
		//			fut1.wait();

		//			std::copy(mniejsze.begin(), mniejsze.end(), tab[0]);
		//			tab[mniejsze.size()] = pivot;
		//			std::copy(wieksze.begin(), wieksze.end(), tab[0] + mniejsze.size() + 1);
		//}

	};




#endif