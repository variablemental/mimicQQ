// Ex_Person.h : main header file for the EX_PERSON application
//

#if !defined(AFX_EX_PERSON_H__577F5B95_4586_4276_BAF1_CCC0EE13763A__INCLUDED_)
#define AFX_EX_PERSON_H__577F5B95_4586_4276_BAF1_CCC0EE13763A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CEx_PersonApp:
// See Ex_Person.cpp for the implementation of this class
//

class CEx_PersonApp : public CWinApp
{
public:
	CEx_PersonApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_PersonApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CEx_PersonApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_PERSON_H__577F5B95_4586_4276_BAF1_CCC0EE13763A__INCLUDED_)
