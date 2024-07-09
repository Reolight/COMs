// Var8.cpp : Implementation of CVar8
#include "pch.h"
#include "Var8.h"


// CVar8

STDMETHODIMP CVar8::Fun81(int a, int b, float* ret) {
	if (b == 0)
		return S_FALSE;
	*ret = static_cast<float>(a) / b;
	return S_OK;
}

STDMETHODIMP CVar8::Func82(int a, int b, int c, int* ret) {
	*ret = a * b * c;
	return S_OK;
}

STDMETHODIMP CVar8::Func83(DOUBLE in, DOUBLE* out) {
	*out = in;
	return S_OK;
}