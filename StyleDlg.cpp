// StyleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Ex_Person.h"
#include "FontStyle.h"
#include "AboutMIMIC.h"
#include "MailDlg.h"
#include "StyleDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStyleDlg dialog


CStyleDlg::CStyleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStyleDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStyleDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CStyleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStyleDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CStyleDlg, CDialog)
	//{{AFX_MSG_MAP(CStyleDlg)
	ON_BN_CLICKED(IDC_BUTTON_FONT, OnButtonFont)
	ON_BN_CLICKED(IDC_BUTTON4, OnAbout)
	ON_BN_CLICKED(IDC_BUTTON_TIME, OnButtonTime)
	ON_BN_CLICKED(IDC_BUTTON_NETTEST, OnButtonNettest)
	ON_BN_CLICKED(IDC_BUTTON_SUGGESTION, OnButtonSuggestion)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStyleDlg message handlers

void CStyleDlg::OnButtonFont() 
{
	// TODO: Add your control notification handler code here
	CFontStyle dlg;
	if(IDOK!=dlg.DoModal())	return ;
	//if(m_fontSetting.GetLength()!=0)
		m_fontSetting+=dlg.m_strSetting;
	//AfxMessageBox(m_fontSetting);
}

BOOL CStyleDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CStyleDlg::OnAbout() 
{
	// TODO: Add your control notification handler code here
	AboutMIMIC dlg;
	if(IDOK!=dlg.DoModal())	return;
	
}

void CStyleDlg::OnButtonTime() 
{
	// TODO: Add your control notification handler code here
	ShellExecute(NULL,"open","eg0605.exe","","",SW_HIDE);
	
}

void CStyleDlg::OnButtonNettest() 
{
	// TODO: Add your control notification handler code here
	ShellExecute(NULL,"open","C://Windows//System32//cmd.exe","/c ping 192.168.177.1","",SW_HIDE);
	
}

void CStyleDlg::OnButtonSuggestion() 
{
	// TODO: Add your control notification handler code here
	CMailDlg dlg;
	if(IDOK!=dlg.DoModal())	return ;
	
}
