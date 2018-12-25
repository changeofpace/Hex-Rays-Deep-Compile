#pragma once

#ifdef __NT__
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

#include <stdio.h>
#include <tr1/unordered_set>

// ida 
//#define NO_OBSOLETE_FUNCS

#include <ida.hpp>
#include <idp.hpp>
#include <loader.hpp>
#include <funcs.hpp>
#include <hexrays.hpp>

