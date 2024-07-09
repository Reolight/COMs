

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0628 */
/* at Tue Jan 19 06:14:07 2038
 */
/* Compiler settings for ATL1.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0628 
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __ATL1_i_h__
#define __ATL1_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef DECLSPEC_XFGVIRT
#if defined(_CONTROL_FLOW_GUARD_XFG)
#define DECLSPEC_XFGVIRT(base, func) __declspec(xfg_virtual(base, func))
#else
#define DECLSPEC_XFGVIRT(base, func)
#endif
#endif

/* Forward Declarations */ 

#ifndef __IVar8_FWD_DEFINED__
#define __IVar8_FWD_DEFINED__
typedef interface IVar8 IVar8;

#endif 	/* __IVar8_FWD_DEFINED__ */


#ifndef __CoVar8_FWD_DEFINED__
#define __CoVar8_FWD_DEFINED__

#ifdef __cplusplus
typedef class CoVar8 CoVar8;
#else
typedef struct CoVar8 CoVar8;
#endif /* __cplusplus */

#endif 	/* __CoVar8_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "shobjidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IVar8_INTERFACE_DEFINED__
#define __IVar8_INTERFACE_DEFINED__

/* interface IVar8 */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IVar8;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("23fa3c5b-bdda-41d9-9b29-bb8db9badb59")
    IVar8 : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Fun81( 
            /* [in] */ int a,
            /* [in] */ int b,
            /* [retval][out] */ float *ret) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Func82( 
            /* [in] */ int a,
            /* [in] */ int b,
            /* [in] */ int c,
            /* [retval][out] */ int *ret) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Func83( 
            /* [in] */ DOUBLE in,
            /* [out] */ DOUBLE *out) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IVar8Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVar8 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVar8 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVar8 * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IVar8 * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IVar8 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IVar8 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IVar8 * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        DECLSPEC_XFGVIRT(IVar8, Fun81)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Fun81 )( 
            IVar8 * This,
            /* [in] */ int a,
            /* [in] */ int b,
            /* [retval][out] */ float *ret);
        
        DECLSPEC_XFGVIRT(IVar8, Func82)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Func82 )( 
            IVar8 * This,
            /* [in] */ int a,
            /* [in] */ int b,
            /* [in] */ int c,
            /* [retval][out] */ int *ret);
        
        DECLSPEC_XFGVIRT(IVar8, Func83)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Func83 )( 
            IVar8 * This,
            /* [in] */ DOUBLE in,
            /* [out] */ DOUBLE *out);
        
        END_INTERFACE
    } IVar8Vtbl;

    interface IVar8
    {
        CONST_VTBL struct IVar8Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVar8_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IVar8_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IVar8_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IVar8_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IVar8_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IVar8_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IVar8_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IVar8_Fun81(This,a,b,ret)	\
    ( (This)->lpVtbl -> Fun81(This,a,b,ret) ) 

#define IVar8_Func82(This,a,b,c,ret)	\
    ( (This)->lpVtbl -> Func82(This,a,b,c,ret) ) 

#define IVar8_Func83(This,in,out)	\
    ( (This)->lpVtbl -> Func83(This,in,out) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVar8_INTERFACE_DEFINED__ */



#ifndef __ATL1Lib_LIBRARY_DEFINED__
#define __ATL1Lib_LIBRARY_DEFINED__

/* library ATL1Lib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_ATL1Lib;

EXTERN_C const CLSID CLSID_CoVar8;

#ifdef __cplusplus

class DECLSPEC_UUID("e6a1dcca-7608-460f-85a9-44e672da15d6")
CoVar8;
#endif
#endif /* __ATL1Lib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


