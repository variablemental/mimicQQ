// AboutMIMIC.cpp : implementation file
//

#include "stdafx.h"
#include "Ex_Person.h"
#include "AboutMIMIC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// AboutMIMIC dialog


AboutMIMIC::AboutMIMIC(CWnd* pParent /*=NULL*/)
	: CDialog(AboutMIMIC::IDD, pParent)
{
	//{{AFX_DATA_INIT(AboutMIMIC)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void AboutMIMIC::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(AboutMIMIC)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(AboutMIMIC, CDialog)
	//{{AFX_MSG_MAP(AboutMIMIC)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// AboutMIMIC message handlers

BOOL AboutMIMIC::OnInitDialog() 
{
	CDialog::OnInitDialog();
	CString content="你竟然已经探索到这里了！足以说明你对MIMICQQ的热爱!\nMIMICQQ是吸取TencentQQ精华的轻型聊天客户端，致力于\n使用Visual C++的MFC框架上建立一个聊天社区，打造一款\n在各种网络环境下都至少可以完成通讯的即时通讯软件。\n同时还设有BBS电子公告板等社交媒体功能，我们的宗旨是简朴中体现网络时代的伟大。\n\n\n\n开发者：周健航15751872610，张健  ";
	this->SetDlgItemText(IDC_STATIC_STICK,content);
	
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
