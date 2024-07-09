// PolyCtl.cpp : Implementation of CPolyCtl
#include "pch.h"
#include "PolyCtl.h"


// CPolyCtl

void CPolyCtl::CalcPoints(const RECT& rc)
{
	const double pi = 3.14159265358979;
	POINT ptCenter;
	double dblRadiusX = (rc.right - rc.left) / 2;
	double dblRadiusY = (rc.bottom - rc.top) / 2;
	double dblAngle = 3 * pi / 2;
	double dblDiff = 2 * pi / m_nSides;
	ptCenter.x = (rc.left + rc.right) / 2;
	ptCenter.y = (rc.top + rc.bottom) / 2;

	for (int i = 0; i < m_nSides; i++) {
		m_arrPoint[i].x = (long)(dblRadiusX * cos(dblAngle) + ptCenter.x + .5);
		m_arrPoint[i].y = (long)(dblRadiusY * sin(dblAngle) + ptCenter.y + .5);
		dblAngle += dblDiff;
	}
}

LRESULT CPolyCtl::OnLButtonnDown(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	HRGN hRgn;
	WORD xPos = LOWORD(lParam);
	WORD yPos = HIWORD(lParam);

	CalcPoints(m_rcPos);
	hRgn = CreatePolygonRgn(&m_arrPoint[0], m_nSides, WINDING);

	short tempSides = m_nSides;
	if (PtInRegion(hRgn, xPos, yPos))
	{
		put_Sides(++tempSides);
		Fire_ClickIn(xPos, yPos);
	}
	else
	{
		put_Sides(--tempSides);
		Fire_ClickOut(xPos, yPos);
	}

	DeleteObject(hRgn);
	bHandled = false;
	return 0;
}

STDMETHODIMP CPolyCtl::get_Sides(short* pval)
{
	*pval = m_nSides;
	return S_OK;
}

STDMETHODIMP CPolyCtl::put_Sides(short newVal) {
	if (2 < newVal && newVal < 10) {
		m_nSides = newVal;
		FireViewChange();
		return S_OK;
	}

	return Error(_T("Shape must have between 3 and 9 sides"));
}
