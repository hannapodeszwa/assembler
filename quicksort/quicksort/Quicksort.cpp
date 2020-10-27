#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <time.h>

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
	clock_t start = clock();
	wczytaj_z_pliku();
	clock_t stop = clock();
	//cout << "Dziala" << endl;
	MessageBox::Show(Convert::ToString(tab[0]));
	
	czas = stop - start;
}

//void Quicksort::set_tab(int, int, int)
//{
//
//}

bool Quicksort::wczytaj_z_pliku()
{
	ifstream plik("liczby.txt");
	int n_wartosc;
	if (plik)
	{

		for (int i = 0;i < 100;i++)
		{
			plik >> tab[i];
			
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