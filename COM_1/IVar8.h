#pragma once
#ifndef IVAR8_H
#define IVAR8_H
#include "objbase.h"

// {C21B6908-84D6-4C79-8B95-A661740D448C}
DEFINE_GUID(IID_IVAR8,
	0xc21b6908, 0x84d6, 0x4c79, 0x8b, 0x95, 0xa6, 0x61, 0x74, 0xd, 0x44, 0x8c);
// {73FEC557-C934-4324-A3C6-7524CB77CAE5}
DEFINE_GUID(CLSID_VAR8 ,
	0x73fec557, 0xc934, 0x4324, 0xa3, 0xc6, 0x75, 0x24, 0xcb, 0x77, 0xca, 0xe5);


class IVar8 : public IUnknown {
public:
	STDMETHOD(WINAPIFun71(int, int))			PURE;
	STDMETHOD(Fun72(int, int))					PURE;
	STDMETHOD(Fun73(double in, double* out))	PURE;
};

#endif // !IVAR8_H
