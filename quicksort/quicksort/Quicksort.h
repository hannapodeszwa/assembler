#ifndef Quicksort_H  
#define Quicksort_H
#pragma once
#include <string>
#include <sstream>

using namespace std;

class Quicksort
{
private:
	double czas;
	int tab[100];
	int liczba_watkow;
public:
	void quicksort();
	/*string get_czas()
	{
		stringstream ss;
		ss << czas;
		string str = ss.str();
		return str; }*/
	double get_czas() { return czas; }
	//void set_tab(int,int,int);
	void set_liczba_watkow(int w) { liczba_watkow = w; }

	bool wczytaj_z_pliku();
};

//public class Test {
//	public static void main(String[] args) {
//		//generate random array of size 1000000
//
//		long start = System.currentTimeMillis();
//
//		Quicksort.quicksort(arr, 0, arr.length - 1);
//
//		System.out.println("Single array sorted in " + (System.currentTimeMillis() - start) + " ms");
//
//		start = System.currentTimeMillis();
//
//		Quicksort.parallelQuicksort(arr2, 0, arr.length - 1);
//
//		System.out.println("Threaded array sorted in " + (System.currentTimeMillis() - start) + " ms");
//	}
//}

#endif