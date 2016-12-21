#if !defined(AFX_ONEDLG_H__560E0F9C_1CCC_4C8D_8710_1DDAA9B7644C__INCLUDED_)
#define AFX_ONEDLG_H__560E0F9C_1CCC_4C8D_8710_1DDAA9B7644C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OneDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COneDlg dialog

class COneDlg : public CDialog
{
// Construction
public:
	BOOL m_bMale;
	COneDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(COneDlg)
	enum { IDD = IDD_DIALOG1 };
	CTime	m_tBirth;
	CString	m_strAddress;
	CString	m_strName;
	CString	m_strNo;
	CString	m_strPhone;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COneDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(COneDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ONEDLG_H__560E0F9C_1CCC_4C8D_8710_1DDAA9B7644C__INCLUDED_)
