// OneDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Ex_Person.h"
#include "OneDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COneDlg dialog


COneDlg::COneDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COneDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(COneDlg)
	m_tBirth = 0;
	m_strAddress = _T("");
	m_strName = _T("");
	m_strNo = _T("");
	m_strPhone = _T("");
	//}}AFX_DATA_INIT
	m_bMale	= TRUE;
}


void COneDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COneDlg)
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER1, m_tBirth);
	DDX_Text(pDX, IDC_EDIT_ADDRESS, m_strAddress);
	DDV_MaxChars(pDX, m_strAddress, 150);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDV_MaxChars(pDX, m_strName, 20);
	DDX_Text(pDX, IDC_EDIT_NO, m_strNo);
	DDV_MaxChars(pDX, m_strNo, 20);
	DDX_Text(pDX, IDC_EDIT_PHONE, m_strPhone);
	DDV_MaxChars(pDX, m_strPhone, 25);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COneDlg, CDialog)
	//{{AFX_MSG_MAP(COneDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COneDlg message handlers

BOOL COneDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	// 设置单选按钮初始选中状态
	if (!m_bMale)
		CheckRadioButton(IDC_RADIO_MALE, IDC_RADIO_FEMALE, IDC_RADIO_FEMALE);
	else
		CheckRadioButton(IDC_RADIO_MALE, IDC_RADIO_FEMALE, IDC_RADIO_MALE);
	UpdateData( FALSE );
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void COneDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	m_strName.TrimLeft();
	m_strNo.TrimLeft();
	if (m_strName.IsEmpty())
		MessageBox("必须要有姓名！");
	else if (m_strNo.IsEmpty())
		MessageBox("必须要有学号！");
	else 
		CDialog::OnOK();
}
