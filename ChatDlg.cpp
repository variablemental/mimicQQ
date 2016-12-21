// ChatDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Ex_Person.h"
#include "ChatDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChatDlg dialog


CChatDlg::CChatDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CChatDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CChatDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CChatDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChatDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CChatDlg, CDialog)
	//{{AFX_MSG_MAP(CChatDlg)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChatDlg message handlers

void CChatDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	myInfo="you:";
	SYSTEMTIME sysTime;
	COleDateTime odtData;
//	odtData.GetAsSystemTime(sysTime);								//¼ÓÊ±¼ä´Á
//	CString time=CTime(sysTime).GetCurrentTime+"";
//	myInfo+=time;
	myInfo+="\n";
	CString strEdit;
	GetDlgItem(IDC_EDIT1)->GetWindowText( strEdit );
	strEdit.TrimLeft();
	if ( strEdit.GetLength() > 0 )
	{
			strEdit.Format("%s",strEdit); 
			GetDlgItem(IDC_STATIC_RES)->SetWindowText(temp+myInfo+strEdit+"\n"+Tag+":\nºÇºÇ\n");
	} else
		MessageBox( "ÇëÊäÈëÄÚÈİ£¡", "×¢Òâ", 0 );
	GetDlgItem(IDC_EDIT1)->SetWindowText("");
	temp+=myInfo+strEdit+"\r\n"+Tag+":\nºÇºÇ\n";
}

void CChatDlg::SetTag(CString tag)
{
	this->Tag=tag;
}
