// OpenCommandPromptHereShellExt.cpp : Implementation of COpenCommandPromptHereShellExt

#include "stdafx.h"
#include "OpenCommandPromptHereShellExt.h"
#include <atlconv.h>  // for ATL string conversion macros
#include "Resource.h"
#include <atlcom.h>
#include <atlstr.h>
#include <stdio.h>
#include <tchar.h>
#define BUFSIZE 65536
#include <cwchar> 

//#include "ShobjIdl.h"
//#include "Shellapi.h"

// COpenCommandPromptHereShellExt
COpenCommandPromptHereShellExt::COpenCommandPromptHereShellExt()
{
	m_hUnlockBmp = LoadBitmap( _AtlBaseModule.GetModuleInstance()  ,
                           MAKEINTRESOURCE(IDB_BITMAP1) );
}


STDMETHODIMP COpenCommandPromptHereShellExt::Initialize ( 
  LPCITEMIDLIST pidlFolder,
  LPDATAOBJECT pDataObj,
  HKEY hProgID )
{
FORMATETC fmt = { CF_HDROP, NULL, DVASPECT_CONTENT, -1, TYMED_HGLOBAL };
STGMEDIUM stg = { TYMED_HGLOBAL };
HDROP     hDrop;

    // Look for CF_HDROP data in the data object.
    if ( FAILED( pDataObj->GetData ( &fmt, &stg ) ))
        {
        // Nope! Return an "invalid argument" error back to Explorer.
        return E_INVALIDARG;
        }

    // Get a pointer to the actual data.
    hDrop = (HDROP) GlobalLock ( stg.hGlobal );

    // Make sure it worked.
    if ( NULL == hDrop )
        return E_INVALIDARG;

    // Sanity check - make sure there is at least one filename.
UINT uNumFiles = DragQueryFile ( hDrop, 0xFFFFFFFF, NULL, 0 );
HRESULT hr = S_OK;

    if ( 0 == uNumFiles )
        {
        GlobalUnlock ( stg.hGlobal );
        ReleaseStgMedium ( &stg );
        return E_INVALIDARG;
        }

	bool isok=false;

	std::vector<LPCWSTR>::iterator it;
	it = m_lsFiles2.begin();		

	for (int k=0;k<uNumFiles;k++)
	{
		LPWSTR m_szFile3=new WCHAR[MAX_PATH];

		if ( 0 != DragQueryFile ( hDrop, k, (LPWSTR) m_szFile3, MAX_PATH ) )
		{
			isok=true;
			it=m_lsFiles2.insert ( it , m_szFile3 );
			//m_lsFiles2.a.push_back(m_szFile);
			
		}
	}
    // Get the name of the first file and store it in our member variable m_szFile.
    //if ( 0 == DragQueryFile ( hDrop, 0, m_szFile, MAX_PATH ) )
    //hr = E_INVALIDARG;

	if (!isok)
	{
		hr = E_INVALIDARG;
	}

    GlobalUnlock ( stg.hGlobal );
    ReleaseStgMedium ( &stg );

    return hr;


}

HRESULT COpenCommandPromptHereShellExt::QueryContextMenu (
  HMENU hmenu, UINT uMenuIndex, UINT uidFirstCmd,
  UINT uidLastCmd, UINT uFlags )
{
  // If the flags include CMF_DEFAULTONLY then we shouldn't do anything.

  if ( uFlags & CMF_DEFAULTONLY )
    return MAKE_HRESULT ( SEVERITY_SUCCESS, FACILITY_NULL, 0 );

	UINT uID = uidFirstCmd;
	UINT upos=uMenuIndex;
	
// Insert the submenu into the ctx menu provided by Explorer.      	
	
	InsertMenu ( hmenu, iOpenCommandPromptHere=upos++, MF_BYPOSITION, uID++, _T("Open Command Prompt here"));				

	if ( NULL != m_hUnlockBmp) 
	SetMenuItemBitmaps ( hmenu, upos-1, MF_BYPOSITION, m_hUnlockBmp, m_hUnlockBmp );
	
    return MAKE_HRESULT ( SEVERITY_SUCCESS, FACILITY_NULL, uID - uidFirstCmd );		
}


HRESULT COpenCommandPromptHereShellExt::GetCommandString (
  UINT_PTR idCmd, UINT uFlags, UINT* pwReserved,
//  UINT idCmd, UINT uFlags, UINT* pwReserved,
  LPSTR pszName, UINT cchMax )

{
USES_CONVERSION;		

return E_INVALIDARG;
  // Check idCmd, it must be 0 since we have only one menu item.

 // if ( 0 != idCmd )
  //  return E_INVALIDARG;
//	return E_FAIL;
 
  // If Explorer is asking for a help string, copy our string into the

  // supplied buffer.
  
  if (uFlags==GCS_VALIDATE)
  {
	return NOERROR;
  }
  else if ( uFlags == GCS_HELPTEXT || uFlags==GCS_HELPTEXTW)
    {
    LPCTSTR szText = _T("Copy File Contents");	

	//HINSTANCE hInst = AfxGetInstanceHandle();
    if ( uFlags & GCS_UNICODE )
      {
      // We need to cast pszName to a Unicode string, and then use the

      // Unicode string copy API.

      lstrcpynW ( (LPWSTR) pszName, T2CW(szText), cchMax );
      }
    else
      {
      // Use the ANSI string copy API to return the help string.

      lstrcpynA ( pszName, T2CA(szText), cchMax );
      }
 
    return S_OK;
	//return NOERROR;
    }
	else if ( uFlags == GCS_VERB || uFlags==GCS_VERBW)
    {
	//	MessageBox ( NULL , _T("gcs_verb"), _T("SimpleShlExt"),MB_ICONINFORMATION );
    LPCTSTR szText = _T("OpenCommandPromptHere");
 
    if ( uFlags & GCS_UNICODE )
      {
      // We need to cast pszName to a Unicode string, and then use the

      // Unicode string copy API.

      lstrcpynW ( (LPWSTR) pszName, T2CW(szText), cchMax );
      }
    else
      {
      // Use the ANSI string copy API to return the help string.

      lstrcpynA ( pszName, T2CA(szText), cchMax );
      }
 
    return S_OK;
	//return NOERROR;
    }
 
   
  //return E_INVALIDARG;
  return S_OK;
}

HRESULT COpenCommandPromptHereShellExt::InvokeCommand(
  LPCMINVOKECOMMANDINFO pCmdInfo)
{  
  if ( 0 != HIWORD( pCmdInfo->lpVerb) )
    return E_INVALIDARG;
 
  //MessageBox ( NULL ,_T("Invokecmd"), _T("SimpleShlExt"),MB_ICONINFORMATION );

  // Get the command index - the only valid one is 0.  		

  int iVerb=LOWORD(pCmdInfo->lpVerb);

   WCHAR sParam[40000];

	lstrcpyW(sParam,_T("\""));
	
	if (m_lsFiles2.size()>=1)
   {
		lstrcatW(sParam,(WCHAR*)m_lsFiles2[0]);
		
   }
   else
   {
	  return E_UNEXPECTED;
   }

   lstrcatW(sParam,_T("\""));

  WCHAR cmd[100];

		WCHAR szMsg[MAX_PATH + 32];
	    CRegKey reg;
        LONG    lRet;

        lRet = reg.Open ( HKEY_LOCAL_MACHINE,
                          _T("Software\\4dots Software\\OpenCommandPromptHere"),KEY_QUERY_VALUE);

		//MessageBox ( NULL , _T("test"), _T("SimpleShlExt"),
        //         MB_ICONINFORMATION );	    

		if (lRet!=ERROR_SUCCESS)
		{
			return E_UNEXPECTED;
		}

		TCHAR szFp[MAX_PATH];		
		DWORD dwSizeFp = sizeof(szFp) / sizeof(TCHAR); // # of characters in the buffer 
		
		lRet=reg.QueryStringValue(_T("InstallationDirectory"),szFp,&dwSizeFp);
 
		if (lRet!=ERROR_SUCCESS)
		{
			return E_UNEXPECTED;
		}

		//MessageBox ( NULL , _T("test2"), _T("SimpleShlExt"),
         //        MB_ICONINFORMATION );	    

		
		//MessageBox ( pCmdInfo->hwnd, m_szFile, _T("SimpleShlExt"),
          //         MB_ICONINFORMATION );


		//ShellExecute(NULL, _T("open"), _T("test.txt"), NULL, _T("."),SW_SHOWNORMAL);
		TCHAR szFp2[MAX_PATH];
		//szFp=lstrcat(szFp,_T("ImgTransformer.exe"));

		
		wcscat_s(szFp,_T("\\OpenCommandPromptHere.exe") );

		//MessageBox ( pCmdInfo->hwnd, szFp, _T("SimpleShlExt"),
          //         MB_ICONINFORMATION );				

		
		lstrcpyW(szFp2,_T("\""));
		lstrcatW(szFp2,szFp);
		lstrcatW(szFp2,_T("\""));

        ShellExecute(NULL, _T("open"), szFp2, sParam, _T("."), SW_SHOWNORMAL);		
 
      return S_OK;
   }


  


