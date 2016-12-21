// Ex_DLGDlg.h : header file
//

#if !defined(AFX_EX_DLGDLG_H__88213580_4028_4094_B469_1CAD79856604__INCLUDED_)
#define AFX_EX_DLGDLG_H__88213580_4028_4094_B469_1CAD79856604__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CEx_DLGDlg dialog

class CEx_DLGDlg : public CDialog
{
// Construction
public:
	CEx_DLGDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CEx_DLGDlg)
	enum { IDD = IDD_EX_DLG_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_DLGDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CEx_DLGDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CString temp;
	CString myInfo;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_DLGDLG_H__88213580_4028_4094_B469_1CAD79856604__INCLUDED_)
