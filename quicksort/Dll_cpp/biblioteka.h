#pragma once
#ifndef BIBLIOTEKA_H
#define BIBLIOTEKA_H

#if defined BIBLIOTEKA_EXPORTS
#define BIBLIOTEKA_API __declspec(dllexport)
#else
#define BIBLIOTEKA_API __declspec(dllimport)
#endif

extern "C" BIBLIOTEKA_API void funkcja();

#endif