#if !defined(AFX_STYLEDLG_H__F41B6721_CF71_4FDD_897D_8AB44AD604C0__INCLUDED_)
#define AFX_STYLEDLG_H__F41B6721_CF71_4FDD_897D_8AB44AD604C0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// StyleDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStyleDlg dialog

class CStyleDlg : public CDialog
{
// Construction
public:
	CStyleDlg(CWnd* pParent = NULL);   // standard constructor


	CString m_fontSetting;
// Dialog Data
	//{{AFX_DATA(CStyleDlg)
	enum { IDD = IDD_DIALOG4 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStyleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CStyleDlg)
	afx_msg void OnButtonFont();
	virtual BOOL OnInitDialog();
	afx_msg void OnAbout();
	afx_msg void OnButtonTime();
	afx_msg void OnButtonNettest();
	afx_msg void OnButtonSuggestion();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STYLEDLG_H__F41B6721_CF71_4FDD_897D_8AB44AD604C0__INCLUDED_)
