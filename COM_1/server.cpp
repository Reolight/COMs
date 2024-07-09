#include <Windows.h>
#include <initguid.h>
#include "CVar8.h"

long g_lObjs = 0;
long g_lLocks = 0;

static HMODULE g_hModule = NULL;   // DLL module handle
// Friendly name of component
const char g_szFriendlyName[] = "TCP_Lab1 Math Component 00333";
// Version-independent ProgID
const char g_szVerIndProgID[] = "Lab1.Var8.Component";
// ProgID
const char g_szProgID[] = "Lab1.Var8.Component.1";

__declspec(dllexport) STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, void** ppv) {
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

__declspec(dllexport) STDAPI DllCanUnloadNow(void) {
	if (g_lObjs || g_lLocks)
		return S_FALSE;
	else
		return S_OK;
}

BOOL APIENTRY DllMain(HANDLE hModule,
	DWORD dwReason,
	void* lpReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		g_hModule = (HMODULE)hModule;
	}
	return TRUE;
}
