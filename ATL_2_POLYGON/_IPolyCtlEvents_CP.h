#pragma once

using namespace ATL;

template <class T>
class CProxy_IPolyCtlEvents : public IConnectionPointImpl<T, &__uuidof(_IPolyCtlEvents), CComDynamicUnkArray>
{
	// WARNING: This class may be regenerated by the wizard
public:
	VOID Fire_ClickIn(LONG x, LONG y) {
		T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[2];
		int nConnections = m_vec.GetSize();

		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++) {
			pT->Lock();
			CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			pT->Unlock();
			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL) {
				pvars[1].vt = VT_I4;
				pvars[1].lVal = x;
				pvars[0].vt = VT_I4;
				pvars[0].lVal = y;
				DISPPARAMS disp = { pvars, NULL, 2 , 0 };
				pDispatch->Invoke(0x1, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}

		delete[] pvars;
	}

	VOID Fire_ClickOut(LONG x, LONG y)
	{
		T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[2];
		int nConnections = m_vec.GetSize();

		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			pT->Lock();
			CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			pT->Unlock();
			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[1].vt = VT_I4;
				pvars[1].lVal = x;
				pvars[0].vt = VT_I4;
				pvars[0].lVal = y;
				DISPPARAMS disp = { pvars, NULL, 2, 0 };
				pDispatch->Invoke(0x2, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}

		delete[] pvars;
	}
};
