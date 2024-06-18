#include <Windows.h>
#include "CVar8.h"

CVar8::CVar8() {
	m_lRef = 0;
	InterlockedIncrement(&g_lObjs);
}

CVar8::~CVar8() {
	InterlockedDecrement(&g_lObjs);
}

STDMETHODIMP CVar8::QueryInterface(REFIID riid, void** ppv) {
	*ppv = 0;
	if (riid == IID_IUnknown || riid == IID_IVAR8)
		*ppv = this;

	if (*ppv)
	{
		AddRef();
		return (S_OK);
	}

	return (E_NOINTERFACE);
}

STDMETHODIMP_(ULONG) CVar8::AddRef() {
	return InterlockedIncrement(&m_lRef);
}

STDMETHODIMP_(ULONG) CVar8::Release() {
	if (!InterlockedDecrement(&m_lRef)) {
		delete this;
		return 0;
	}

	return m_lRef;
}

ivar8Factory::ivar8Factory() {
	m_lRef = 0;
}

ivar8Factory::~ivar8Factory() {}

STDMETHODIMP ivar8Factory::QueryInterface(REFIID riid, void** ppv) {
	*ppv = 0;

	if (riid == IID_IUnknown || riid == IID_IClassFactory)
		*ppv = this;

	if (*ppv) {
		AddRef();
		return S_OK;
	}

	return E_NOINTERFACE;
}

STDMETHODIMP_(ULONG) ivar8Factory::AddRef() {
	return InterlockedIncrement(&m_lRef);
}

STDMETHODIMP_(ULONG) ivar8Factory::Release() {
	if (!InterlockedDecrement(&m_lRef)) {
		delete this;
		return 0;
	}
	
	return m_lRef;
}

STDMETHODIMP ivar8Factory::CreateInstance(LPUNKNOWN pUnkOuter, REFIID riid, void** ppvObj) {
	CVar8* pVar8;
	HRESULT hr;

	*ppvObj = 0;

	pVar8 = new CVar8;

	if (!pVar8) 
		return E_OUTOFMEMORY;

	hr = pVar8->QueryInterface(riid, ppvObj);
	if (FAILED(hr))
		delete pVar8;

	return hr;
}

STDMETHODIMP ivar8Factory::LockServer(BOOL fLock) {
	if (fLock)
		InterlockedIncrement(&g_lLocks);
	else
		InterlockedDecrement(&g_lLocks);

	return S_OK;
}

STDMETHODIMP CVar8::Fun72(int a, int b) {
	return a + b + 72;
}

STDMETHODIMP CVar8::Fun73(double in, double* out) {
	double* val = new double(in);
	if (!val) return E_OUTOFMEMORY;
	return *val;
}

STDMETHODIMP CVar8::WINAPIFun71(int a, int b) {
	return a + b;
}