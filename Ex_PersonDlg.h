// Ex_PersonDlg.h : header file
//

#if !defined(AFX_EX_PERSONDLG_H__98F6DE1A_C493_4145_A20D_B2FAC3DD32E5__INCLUDED_)
#define AFX_EX_PERSONDLG_H__98F6DE1A_C493_4145_A20D_B2FAC3DD32E5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CEx_PersonDlg dialog

class CEx_PersonDlg : public CDialog
{
// Construction
public:
	void OnAccept();
	CEx_PersonDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CEx_PersonDlg)
	enum { IDD = IDD_EX_PERSON_DIALOG };
	CListCtrl	m_dataList;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_PersonDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CEx_PersonDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonAdd();
	afx_msg void OnButtonChange();
	afx_msg void OnButtonDel();
	afx_msg void OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBtnCancel();
	afx_msg void OnButtonStart();
	afx_msg void OnButtonSend();
	afx_msg void OnBUTTONsend();
	afx_msg void OnButtonInsert();
	afx_msg void OnButtonStyle();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	int num;
 //	CListenSocket m_Server;
 //	BOOL m_bServer;
 //	int m_NetPort;
 // CMySocket *pNewClient;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_PERSONDLG_H__98F6DE1A_C493_4145_A20D_B2FAC3DD32E5__INCLUDED_)
