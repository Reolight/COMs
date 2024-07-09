#include <Windows.h>
#include <tchar.h>
#include <cstdio>

#include <initguid.h>
#include "..\COM_1\IVar8.h"
 
int _main() {
	printf("Initializing COM\n");
	system("pause");

	if (FAILED(CoInitialize(NULL))) {
		printf("unable to initialize COM \n");
		return -1;
	}

	const char* szProgID = R"(Lab1.Var8.Component.1)";
	WCHAR szWideProgID[128];
	CLSID clsid;
	long lLen = MultiByteToWideChar(CP_ACP, 0, szProgID,
		strlen(szProgID), szWideProgID, sizeof(szWideProgID));
	szWideProgID[lLen] = '\0';
	HRESULT hr = ::CLSIDFromProgID(szWideProgID, &clsid);
	if (FAILED(hr)) {
		printf("Unable to get CLSID from ProgID. HR = %X\n", hr);
		return -1;
	}

	IClassFactory* pCF;
	hr = CoGetClassObject(clsid, CLSCTX_INPROC, NULL, IID_IClassFactory, (void**)&pCF);
	if (FAILED(hr)) {
		printf("Failed to GetClassObject server instance. HR = %X\n", hr);
		return -1;
	}

	IUnknown* pUnk;
	hr = pCF->CreateInstance(NULL, IID_IUnknown, (void**) & pUnk);
	pCF->Release();
	if (FAILED(hr)) {
		printf("Unable to get IUnknown. HR = %X\n", hr);
		return -1;
	}

	IVar8* pvar8;
	hr = pUnk->QueryInterface(IID_IVAR8, (LPVOID*)&pvar8);
	pUnk->Release();
	if (FAILED(hr)) {
		printf("failed to get IVar8 interface. HR = %X\n", hr);
		return -1;
	}

	printf("\nfun72 for 2 and 5: %d", pvar8->Fun72(2, 5));
	double* pd = 0;
	pvar8->Fun73(2.5, pd);
	printf("\nfun73 for 2.5: %f", *pd);

	pvar8->Release();
	printf("\nShutting down COM\n");
	CoUninitialize();

	printf("Finished\n");
	return 0;
}

int main(int argc, char* argv[]) {
	int pidw = (int)GetCurrentProcessId();
	printf("PID %d", pidw);

	auto res = _main();
	system("pause");
	return res;
}