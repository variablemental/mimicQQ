// TwoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Ex_Person.h"
#include "TwoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// TwoDlg dialog


TwoDlg::TwoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(TwoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(TwoDlg)
	m_strMessage = _T("");
	m_strMotto = _T("");
	m_strIP = _T("");
	m_strNickName = _T("");
	m_strQQ = _T("");
	m_strZone = _T("");
	//}}AFX_DATA_INIT
}


void TwoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(TwoDlg)
	DDX_Text(pDX, IDC_EDIT_MESSGAE, m_strMessage);
	DDX_Text(pDX, IDC_EDIT_MOTTO, m_strMotto);
	DDX_Text(pDX, IDC_EDIT_IP, m_strIP);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strNickName);
	DDX_Text(pDX, IDC_EDIT_NO, m_strQQ);
	DDX_Text(pDX, IDC_EDIT_ZONE, m_strZone);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(TwoDlg, CDialog)
	//{{AFX_MSG_MAP(TwoDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// TwoDlg message handlers

BOOL TwoDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void TwoDlg::OnOK() 
{	
	UpdateData();
	m_strNickName.TrimLeft();
	m_strQQ.TrimLeft();
	if(m_strNickName.IsEmpty())
		MessageBox("±ÿ–ÎÃÓ–¥Í«≥∆£°");
	else if(m_strQQ.IsEmpty())
		MessageBox("±ÿ–ÎÃÓ–¥QQ£°");
	else
		CDialog::OnOK();
}
