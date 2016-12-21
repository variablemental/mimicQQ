#if !defined(AFX_CHATDLG_H__3EDFD337_BFF7_433A_A2C6_DA11664E63D6__INCLUDED_)
#define AFX_CHATDLG_H__3EDFD337_BFF7_433A_A2C6_DA11664E63D6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ChatDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CChatDlg dialog

class CChatDlg : public CDialog
{
// Construction
public:
	CChatDlg(CWnd* pParent = NULL);   // standard constructor
	void SetTag(CString tag);

// Dialog Data
	//{{AFX_DATA(CChatDlg)
	enum { IDD = IDD_DIALOG2 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChatDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CChatDlg)
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
		CString temp;
		CString myInfo;
		CString Tag;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHATDLG_H__3EDFD337_BFF7_433A_A2C6_DA11664E63D6__INCLUDED_)
