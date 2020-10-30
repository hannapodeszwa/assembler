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
#include "framework.h"

using namespace std;
//typedef int(_stdcall* swap_a)(int*, int, int);
typedef int(_stdcall* ten_for)(int*, int, int,int);

class Quicksort
{
private:
	double czas;
	int liczba_watkow;
	int* tab;
	string plik_n;
	bool czy_asm;

	HINSTANCE dllHandle = LoadLibrary(L"dll_a.dll");


	int rozmiar_tab;

	int thread_count;
public:
	void quicksort();
	double get_czas() { return czas; }
	void set_plik(string s) { plik_n = s; }
	void set_czy_asm(bool b) { czy_asm = b; }
	void set_liczba_watkow(int w) { liczba_watkow = w; }

	bool wczytaj_z_pliku();

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void sort();
	void _swap(int * tab,int first, int second);
	void _sort(int* tab, int p, int r);
	int _partition(int * tab, int p, int r);
	};




#endif