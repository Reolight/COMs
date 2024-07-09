// dllmain.h : Declaration of module class.

class CATL2POLYGONModule : public ATL::CAtlDllModuleT< CATL2POLYGONModule >
{
public :
	DECLARE_LIBID(LIBID_ATL2POLYGONLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_ATL2POLYGON, "{a0d17eb0-96eb-4c4e-9de2-57ed328e2986}")
};

extern class CATL2POLYGONModule _AtlModule;
