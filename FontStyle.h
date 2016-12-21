#if !defined(AFX_FONTSTYLE_H__432C802B_2E79_4EFB_B32E_3FBEF2E0C4A0__INCLUDED_)
#define AFX_FONTSTYLE_H__432C802B_2E79_4EFB_B32E_3FBEF2E0C4A0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FontStyle.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFontStyle dialog

class CFontStyle : public CDialog
{
// Construction
public:
	void FillListBox(void);
	CFontStyle(CWnd* pParent = NULL);   // standard constructor
	static int CALLBACK EnumFontProc(ENUMLOGFONTEX *lpelfe, 
									NEWTEXTMETRICEX *lpntme,
									DWORD nFontType,    
									LPARAM lParam );
	CString m_strSetting;

// Dialog Data
	//{{AFX_DATA(CFontStyle)
	enum { IDD = IDD_DIALOG5 };
	CListBox	m_listFont;
	CString	m_strSample;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFontStyle)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFontStyle)
	afx_msg void OnSelchangeList1();
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FONTSTYLE_H__432C802B_2E79_4EFB_B32E_3FBEF2E0C4A0__INCLUDED_)
