#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include "biblioteka2.h"



//void swap_c(int* tab, int first, int second)
//{
//	int temp = tab[first];
//	tab[first] = tab[second];
//	tab[second] = temp;
//}


void ten_for_c(int * tab, int p,int r,int pivot, int&i)
{

	for (int j = p; j <= (r - 1); j++)
	{
		if (tab[j] < pivot)
		{
			i++;
			int temp = tab[i];
			tab[i] = tab[j];
			tab[j] = temp;
		}
	}
}