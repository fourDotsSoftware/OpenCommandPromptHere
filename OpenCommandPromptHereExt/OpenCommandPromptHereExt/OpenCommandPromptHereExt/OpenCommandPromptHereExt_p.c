

/* this ALWAYS GENERATED file contains the proxy stub code */


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

#if defined(_M_AMD64)


#pragma warning( disable: 4049 )  /* more than 64k source lines */
#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extern to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma warning( disable: 4024 )  /* array to pointer mapping*/
#pragma warning( disable: 4152 )  /* function/data pointer conversion in expression */

#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 475
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif /* __RPCPROXY_H_VERSION__ */


#include "OpenCommandPromptHereExt_i.h"

#define TYPE_FORMAT_STRING_SIZE   3                                 
#define PROC_FORMAT_STRING_SIZE   1                                 
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   0            

typedef struct _OpenCommandPromptHereExt_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } OpenCommandPromptHereExt_MIDL_TYPE_FORMAT_STRING;

typedef struct _OpenCommandPromptHereExt_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } OpenCommandPromptHereExt_MIDL_PROC_FORMAT_STRING;

typedef struct _OpenCommandPromptHereExt_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } OpenCommandPromptHereExt_MIDL_EXPR_FORMAT_STRING;


static const RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const OpenCommandPromptHereExt_MIDL_TYPE_FORMAT_STRING OpenCommandPromptHereExt__MIDL_TypeFormatString;
extern const OpenCommandPromptHereExt_MIDL_PROC_FORMAT_STRING OpenCommandPromptHereExt__MIDL_ProcFormatString;
extern const OpenCommandPromptHereExt_MIDL_EXPR_FORMAT_STRING OpenCommandPromptHereExt__MIDL_ExprFormatString;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IOpenCommandPromptHereShellExt_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IOpenCommandPromptHereShellExt_ProxyInfo;



#if !defined(__RPC_WIN64__)
#error  Invalid build platform for this stub.
#endif

static const OpenCommandPromptHereExt_MIDL_PROC_FORMAT_STRING OpenCommandPromptHereExt__MIDL_ProcFormatString =
    {
        0,
        {

			0x0
        }
    };

static const OpenCommandPromptHereExt_MIDL_TYPE_FORMAT_STRING OpenCommandPromptHereExt__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */

			0x0
        }
    };


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IOpenCommandPromptHereShellExt, ver. 0.0,
   GUID={0x7F062A2E,0xDA80,0x4c1d,{0x90,0xD0,0x4E,0x62,0x5E,0xCB,0xF5,0x0A}} */

#pragma code_seg(".orpc")
static const unsigned short IOpenCommandPromptHereShellExt_FormatStringOffsetTable[] =
    {
    0
    };

static const MIDL_STUBLESS_PROXY_INFO IOpenCommandPromptHereShellExt_ProxyInfo =
    {
    &Object_StubDesc,
    OpenCommandPromptHereExt__MIDL_ProcFormatString.Format,
    &IOpenCommandPromptHereShellExt_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IOpenCommandPromptHereShellExt_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    OpenCommandPromptHereExt__MIDL_ProcFormatString.Format,
    &IOpenCommandPromptHereShellExt_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(3) _IOpenCommandPromptHereShellExtProxyVtbl = 
{
    0,
    &IID_IOpenCommandPromptHereShellExt,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy
};

const CInterfaceStubVtbl _IOpenCommandPromptHereShellExtStubVtbl =
{
    &IID_IOpenCommandPromptHereShellExt,
    &IOpenCommandPromptHereShellExt_ServerInfo,
    3,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    OpenCommandPromptHereExt__MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x50002, /* Ndr library version */
    0,
    0x8000253, /* MIDL Version 8.0.595 */
    0,
    0,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0
    };

const CInterfaceProxyVtbl * const _OpenCommandPromptHereExt_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IOpenCommandPromptHereShellExtProxyVtbl,
    0
};

const CInterfaceStubVtbl * const _OpenCommandPromptHereExt_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IOpenCommandPromptHereShellExtStubVtbl,
    0
};

PCInterfaceName const _OpenCommandPromptHereExt_InterfaceNamesList[] = 
{
    "IOpenCommandPromptHereShellExt",
    0
};


#define _OpenCommandPromptHereExt_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _OpenCommandPromptHereExt, pIID, n)

int __stdcall _OpenCommandPromptHereExt_IID_Lookup( const IID * pIID, int * pIndex )
{
    
    if(!_OpenCommandPromptHereExt_CHECK_IID(0))
        {
        *pIndex = 0;
        return 1;
        }

    return 0;
}

const ExtendedProxyFileInfo OpenCommandPromptHereExt_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _OpenCommandPromptHereExt_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _OpenCommandPromptHereExt_StubVtblList,
    (const PCInterfaceName * ) & _OpenCommandPromptHereExt_InterfaceNamesList,
    0, /* no delegation */
    & _OpenCommandPromptHereExt_IID_Lookup, 
    1,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* defined(_M_AMD64)*/

