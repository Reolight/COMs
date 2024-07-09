// dllmain.h : Declaration of module class.

class CATL1Module : public ATL::CAtlDllModuleT< CATL1Module >
{
public :
	DECLARE_LIBID(LIBID_ATL1Lib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_ATL1, "{270c0e99-81e7-4cc3-8973-96e7f754c49c}")
};

extern class CATL1Module _AtlModule;
