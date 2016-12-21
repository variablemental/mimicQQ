// MailDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Ex_Person.h"
#include "MailDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMailDlg dialog


CMailDlg::CMailDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMailDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMailDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CMailDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMailDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMailDlg, CDialog)
	//{{AFX_MSG_MAP(CMailDlg)
	ON_BN_CLICKED(IDC_BUTTON_Mail, OnBUTTONMail)
	ON_BN_CLICKED(IDC_BUTTON_GitHub, OnBUTTONGitHub)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMailDlg message handlers

BOOL CMailDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CString content=" 你可以通过短信联系我们给我们留言\n也可以按下方的邮件按钮，给我们发送邮件。\n同样也可以上GayHub账号找到我们并与我们激情讨论\n";
	SetDlgItemText(IDC_STATIC_INTRODUCE,content);


	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CMailDlg::OnBUTTONMail() 
{
	// TODO: Add your control notification handler code here
	ShellExecute(NULL,"open","www.baidu.com",NULL,NULL,SW_SHOWNORMAL);	
}

void CMailDlg::OnBUTTONGitHub() 
{
	// TODO: Add your control notification handler code here
	ShellExecute(NULL,"open","https://github.com/variablemental/mimicQQ",NULL,NULL,SW_SHOWNORMAL);	
	
}
