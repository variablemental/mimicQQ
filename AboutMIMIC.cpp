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
	CString content="�㾹Ȼ�Ѿ�̽���������ˣ�����˵�����MIMICQQ���Ȱ�!\nMIMICQQ����ȡTencentQQ��������������ͻ��ˣ�������\nʹ��Visual C++��MFC����Ͻ���һ����������������һ��\n�ڸ������绷���¶����ٿ������ͨѶ�ļ�ʱͨѶ�����\nͬʱ������BBS���ӹ������罻ý�幦�ܣ����ǵ���ּ�Ǽ�������������ʱ����ΰ��\n\n\n\n�����ߣ��ܽ���15751872610���Ž�  ";
	this->SetDlgItemText(IDC_STATIC_STICK,content);
	
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
