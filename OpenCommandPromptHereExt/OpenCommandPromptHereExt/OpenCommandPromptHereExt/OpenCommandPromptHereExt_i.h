

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0595 */
/* at Mon Jun 17 15:25:34 2019
 */
/* Compiler settings for OpenCommandPromptHereExt.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.00.0595 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __OpenCommandPromptHereExt_i_h__
#define __OpenCommandPromptHereExt_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IOpenCommandPromptHereShellExt_FWD_DEFINED__
#define __IOpenCommandPromptHereShellExt_FWD_DEFINED__
typedef interface IOpenCommandPromptHereShellExt IOpenCommandPromptHereShellExt;

#endif 	/* __IOpenCommandPromptHereShellExt_FWD_DEFINED__ */


#ifndef __OpenCommandPromptHereShellExt_FWD_DEFINED__
#define __OpenCommandPromptHereShellExt_FWD_DEFINED__

#ifdef __cplusplus
typedef class OpenCommandPromptHereShellExt OpenCommandPromptHereShellExt;
#else
typedef struct OpenCommandPromptHereShellExt OpenCommandPromptHereShellExt;
#endif /* __cplusplus */

#endif 	/* __OpenCommandPromptHereShellExt_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IOpenCommandPromptHereShellExt_INTERFACE_DEFINED__
#define __IOpenCommandPromptHereShellExt_INTERFACE_DEFINED__

/* interface IOpenCommandPromptHereShellExt */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IOpenCommandPromptHereShellExt;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7F062A2E-DA80-4c1d-90D0-4E625ECBF50A")
    IOpenCommandPromptHereShellExt : public IUnknown
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct IOpenCommandPromptHereShellExtVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOpenCommandPromptHereShellExt * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOpenCommandPromptHereShellExt * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOpenCommandPromptHereShellExt * This);
        
        END_INTERFACE
    } IOpenCommandPromptHereShellExtVtbl;

    interface IOpenCommandPromptHereShellExt
    {
        CONST_VTBL struct IOpenCommandPromptHereShellExtVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOpenCommandPromptHereShellExt_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOpenCommandPromptHereShellExt_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOpenCommandPromptHereShellExt_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOpenCommandPromptHereShellExt_INTERFACE_DEFINED__ */



#ifndef __OpenCommandPromptHereExtLib_LIBRARY_DEFINED__
#define __OpenCommandPromptHereExtLib_LIBRARY_DEFINED__

/* library OpenCommandPromptHereExtLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_OpenCommandPromptHereExtLib;

EXTERN_C const CLSID CLSID_OpenCommandPromptHereShellExt;

#ifdef __cplusplus

class DECLSPEC_UUID("51E71264-75A5-4a8e-A7FC-F474603F7A01")
OpenCommandPromptHereShellExt;
#endif
#endif /* __OpenCommandPromptHereExtLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


