#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier

//#include <utility>
//#include <limits.h>
#define BIBLIOTEKA_EXPORTS
#include "biblioteka.h"

// DLL internal state variables:
//static unsigned long long previous_;  // Previous value, if any
//static unsigned long long current_;   // Current sequence value
//static unsigned index_;               // Current seq. position

extern "C" 
{
	BIBLIOTEKA_API void funkcja()
	{
		return;
	}
}

