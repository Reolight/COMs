#include <Windows.h>
#include <initguid.h>
#include "CVar8.h"

long g_lObjs = 0;
long g_lLocks = 0;

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, void** ppv) {
	HRESULT hr;
	ivar8Factory *pCF;

	pCF = 0;

	if (rclsid != CLSID_VAR8)
		return E_FAIL;

	pCF = new ivar8Factory;

	if (!pCF)
		return E_OUTOFMEMORY;

	hr = pCF->QueryInterface(riid, ppv);

	if (FAILED(hr))
	{
		delete pCF;
		pCF = 0;
	}

	return 0;
}

STDAPI DllCanUnloadNow(void) {
	if (g_lObjs || g_lLocks)
		return S_FALSE;
	else
		return S_OK;
}