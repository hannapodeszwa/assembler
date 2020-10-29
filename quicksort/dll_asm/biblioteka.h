#pragma once
//
//#ifdef BIBLIOTEKA2_EXPORTS
#define  BIBLIOTEKA_API __declspec(dllexport)
//#else
//#define  BIBLIOTEKA2_API __declspec(dllimport)
//#endif


extern "C"  BIBLIOTEKA_API void swap_asm(int* tab, int first, int second);
//extern "C"  BIBLIOTEKA_API void MyProc1(int,int);