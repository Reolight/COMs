#include "IVar8.h"

extern long g_lObjs;
extern long g_lLocks;

class CVar8 : public IVar8 {
protected:
	long m_lRef;
public:
	CVar8();
	~CVar8();

public:

	STDMETHOD(QueryInterface(REFIID, void**));
	STDMETHOD_(ULONG, AddRef());
	STDMETHOD_(ULONG, Release());

	STDMETHOD(WINAPIFun71(int, int));
	STDMETHOD(Fun72(int, int));
	STDMETHOD(Fun73(double in, double* out));
};

class ivar8Factory : public IClassFactory{
protected:
	long m_lRef;
public:
	ivar8Factory();
	~ivar8Factory();

	STDMETHOD(QueryInterface(REFIID, void**));
	STDMETHOD_(ULONG, AddRef());
	STDMETHOD_(ULONG, Release());

	STDMETHOD(CreateInstance(LPUNKNOWN, REFIID, void**));
	STDMETHOD(LockServer(BOOL));
};