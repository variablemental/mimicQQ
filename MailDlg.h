#if !defined(AFX_MAILDLG_H__2C6BAF28_E464_492A_9134_9F28987E0B6A__INCLUDED_)
#define AFX_MAILDLG_H__2C6BAF28_E464_492A_9134_9F28987E0B6A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MailDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMailDlg dialog

class CMailDlg : public CDialog
{
// Construction
public:
	CMailDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMailDlg)
	enum { IDD = IDD_DIALOG7 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMailDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMailDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnBUTTONMail();
	afx_msg void OnBUTTONGitHub();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAILDLG_H__2C6BAF28_E464_492A_9134_9F28987E0B6A__INCLUDED_)
