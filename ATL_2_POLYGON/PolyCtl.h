// PolyCtl.h : Declaration of the CPolyCtl
#pragma once
#include <math.h>
#include "resource.h"       // main symbols
#include <atlctl.h>
#include "ATL2POLYGON_i.h"
#include "_IPolyCtlEvents_CP.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;



// CPolyCtl
class ATL_NO_VTABLE CPolyCtl :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CStockPropImpl<CPolyCtl, IPolyCtl>,
	public IOleControlImpl<CPolyCtl>,
	public IOleObjectImpl<CPolyCtl>,
	public IOleInPlaceActiveObjectImpl<CPolyCtl>,
	public IViewObjectExImpl<CPolyCtl>,
	public IOleInPlaceObjectWindowlessImpl<CPolyCtl>,
	public IConnectionPointContainerImpl<CPolyCtl>,
	public CProxy_IPolyCtlEvents<CPolyCtl>,
	public CComCoClass<CPolyCtl, &CLSID_PolyCtl>,
	public CComControl<CPolyCtl>,
	public IProvideClassInfo2Impl<&CLSID_PolyCtl, &DIID__IPolyCtlEvents, &LIBID_ATL2POLYGONLib>
{
public:


	CPolyCtl()
	{
		m_nSides = 3;
		m_clrFillColor = RGB(0, 0x11, 0xFF);
	}

DECLARE_OLEMISC_STATUS(OLEMISC_RECOMPOSEONRESIZE |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_INSIDEOUT |
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST
)

DECLARE_REGISTRY_RESOURCEID(IDR_POLYCTL)


BEGIN_COM_MAP(CPolyCtl)
	COM_INTERFACE_ENTRY(IPolyCtl)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IViewObjectEx)
	COM_INTERFACE_ENTRY(IViewObject2)
	COM_INTERFACE_ENTRY(IViewObject)
	COM_INTERFACE_ENTRY(IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceObject)
	COM_INTERFACE_ENTRY2(IOleWindow, IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceActiveObject)
	COM_INTERFACE_ENTRY(IOleControl)
	COM_INTERFACE_ENTRY(IOleObject)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
	COM_INTERFACE_ENTRY(IProvideClassInfo)
	COM_INTERFACE_ENTRY(IProvideClassInfo2)
END_COM_MAP()

BEGIN_PROP_MAP(CPolyCtl)
	PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
	PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
#ifndef _WIN32_WCE
	PROP_ENTRY_TYPE("FillColor", DISPID_FILLCOLOR, CLSID_StockColorPage, VT_UI4)
#endif
	// Example entries
	// PROP_ENTRY_TYPE("Property Name", dispid, clsid, vtType)
	// PROP_PAGE(CLSID_StockColorPage)
END_PROP_MAP()

BEGIN_CONNECTION_POINT_MAP(CPolyCtl)
	CONNECTION_POINT_ENTRY(__uuidof(_IPolyCtlEvents))
END_CONNECTION_POINT_MAP()

BEGIN_MSG_MAP(CPolyCtl)
	CHAIN_MSG_MAP(CComControl<CPolyCtl>)
	DEFAULT_REFLECTION_HANDLER()
	MESSAGE_HANDLER(WM_LBUTTONDOWN, OnLButtonnDown)
END_MSG_MAP()
// Handler prototypes:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);

// IViewObjectEx
	DECLARE_VIEW_STATUS(VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE)

// IPolyCtl
public:
	void CalcPoints(const RECT& rc);
	LRESULT OnLButtonnDown(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

	HRESULT OnDraw(ATL_DRAWINFO& di)
	{
		RECT& rc = *(RECT*)di.prcBounds;
		// Set Clip region to the rectangle specified by di.prcBounds
		HDC hdc = di.hdcDraw;

		COLORREF	colFore;
		HBRUSH		hOldBrush, hBrush;
		HPEN		hOldPen, hPen;

		OleTranslateColor(m_clrFillColor, NULL, &colFore);

		hPen = (HPEN)GetStockObject(BLACK_PEN);
		hOldPen = (HPEN)SelectObject(hdc, hPen);
		hBrush = (HBRUSH)GetStockObject(WHITE_BRUSH);
		hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);

		Ellipse(hdc, rc.left, rc.top, rc.right, rc.bottom);

		hBrush = CreateSolidBrush(colFore);
		SelectObject(hdc, hBrush);

		CalcPoints(rc);
		Polygon(hdc, &m_arrPoint[0], m_nSides);

		SelectObject(hdc, hOldPen);
		SelectObject(hdc, hOldBrush);
		DeleteObject(hBrush);

		return S_OK;
	}

	OLE_COLOR m_clrFillColor;

	short m_nSides;
	POINT m_arrPoint[9];

	STDMETHOD(get_Sides)(short* pval);
	STDMETHOD(put_Sides)(short newval);

	void OnFillColorChanged()
	{
		ATLTRACE(_T("OnFillColorChanged\n"));
	}

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}
};

OBJECT_ENTRY_AUTO(__uuidof(PolyCtl), CPolyCtl)
