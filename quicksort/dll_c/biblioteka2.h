#pragma once
//
//#ifdef BIBLIOTEKA2_EXPORTS
#define  BIBLIOTEKA2_API __declspec(dllexport)
//#else
//#define  BIBLIOTEKA2_API __declspec(dllimport)
//#endif


//extern "C"  BIBLIOTEKA2_API void swap_c(int* tab, int first, int second);
extern "C"  BIBLIOTEKA2_API void ten_for_c(int* tab, int p, int r, int pivot, int& i);



