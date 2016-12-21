#if !defined(AFX_TWODLG_H__1E74BC6B_9F4C_4FBA_ADD1_9CB743A53C44__INCLUDED_)
#define AFX_TWODLG_H__1E74BC6B_9F4C_4FBA_ADD1_9CB743A53C44__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TwoDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// TwoDlg dialog

class TwoDlg : public CDialog
{
// Construction
public:
	TwoDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(TwoDlg)
	enum { IDD = IDD_DIALOG3 };
	CString	m_strMessage;
	CString	m_strMotto;
	CString	m_strIP;
	CString	m_strNickName;
	CString	m_strQQ;
	CString	m_strZone;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(TwoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(TwoDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TWODLG_H__1E74BC6B_9F4C_4FBA_ADD1_9CB743A53C44__INCLUDED_)
