// OpenCommandPromptHereShellExt.h : Declaration of the COpenCommandPromptHereShellExt

#pragma once
#include "resource.h"       // main symbols
#include <sstream>
#include <vector>
#include "OpenCommandPromptHereExt_i.h"
/*
//start
#include <shlobj.h>
#include <comdef.h>
//end
*/

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// COpenCommandPromptHereShellExt

class ATL_NO_VTABLE COpenCommandPromptHereShellExt :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<COpenCommandPromptHereShellExt, &CLSID_OpenCommandPromptHereShellExt>,
	public IShellExtInit,
	public IContextMenu
	
	//public IOpenCommandPromptHereShellExt
{
public:
	COpenCommandPromptHereShellExt();
	

DECLARE_REGISTRY_RESOURCEID(IDR_HANDYRESIZERSHELLEXT)

DECLARE_NOT_AGGREGATABLE(COpenCommandPromptHereShellExt)

BEGIN_COM_MAP(COpenCommandPromptHereShellExt)
	//COM_INTERFACE_ENTRY(IOpenCommandPromptHereShellExt)
	COM_INTERFACE_ENTRY(IShellExtInit)
	COM_INTERFACE_ENTRY(IContextMenu)
END_COM_MAP()

	 int iOpenCommandPromptHere;
	 int iOpenCommandPromptHereEncoding;
	 

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

	protected:
  //TCHAR m_szFile[MAX_PATH];
  LPCWSTR m_szFile;
  string_list m_lsFiles;
  std::vector<LPCWSTR> m_lsFiles2;
  
public:
  // IShellExtInit

  STDMETHODIMP Initialize(LPCITEMIDLIST, LPDATAOBJECT, HKEY);
public:

	public:
  // IContextMenu

  STDMETHODIMP GetCommandString(UINT_PTR, UINT, UINT*, LPSTR, UINT);
  //STDMETHODIMP GetCommandString(UINT, UINT, UINT*, LPSTR, UINT);
  STDMETHODIMP InvokeCommand(LPCMINVOKECOMMANDINFO);
  STDMETHODIMP QueryContextMenu(HMENU, UINT, UINT, UINT, UINT);

  
  protected:
  HBITMAP     m_hUnlockBmp;
  
};


OBJECT_ENTRY_AUTO(__uuidof(OpenCommandPromptHereShellExt), COpenCommandPromptHereShellExt)
