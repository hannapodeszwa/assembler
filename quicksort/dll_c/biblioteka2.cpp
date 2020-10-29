#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include <utility>
#include <limits.h>
#include "biblioteka2.h"



void swap_c(int* tab, int first, int second)
{
	int temp = tab[first];
	tab[first] = tab[second];
	tab[second] = temp;
}
