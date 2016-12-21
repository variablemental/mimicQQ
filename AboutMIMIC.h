#if !defined(AFX_ABOUTMIMIC_H__B1E99BC6_20CA_4909_B31F_79EF8EF3984B__INCLUDED_)
#define AFX_ABOUTMIMIC_H__B1E99BC6_20CA_4909_B31F_79EF8EF3984B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AboutMIMIC.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// AboutMIMIC dialog

class AboutMIMIC : public CDialog
{
// Construction
public:
	AboutMIMIC(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(AboutMIMIC)
	enum { IDD = IDD_DIALOG6 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(AboutMIMIC)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(AboutMIMIC)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ABOUTMIMIC_H__B1E99BC6_20CA_4909_B31F_79EF8EF3984B__INCLUDED_)
