// Var8.h : Declaration of the CVar8

#pragma once
#include "resource.h"       // main symbols



#include "ATL1_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CVar8

class ATL_NO_VTABLE CVar8 :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CVar8, &CLSID_CoVar8>,
	public IDispatchImpl<IVar8, &IID_IVar8, &LIBID_ATL1Lib, /*wMajor =*/ 1, /*wMinor =*/ 1>
{
public:
	CVar8()
	{
	}

DECLARE_REGISTRY_RESOURCEID(106)


BEGIN_COM_MAP(CVar8)
	COM_INTERFACE_ENTRY(IVar8)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:
	STDMETHOD(Fun81)(int a, int b, float* ret);
	STDMETHOD(Func82)(int a, int b, int c, int* ret);
	STDMETHOD(Func83)(DOUBLE in, DOUBLE* out);
};

OBJECT_ENTRY_AUTO(__uuidof(CoVar8), CVar8)
