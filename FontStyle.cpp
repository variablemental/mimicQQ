// FontStyle.cpp : implementation file
//

#include "stdafx.h"
#include "Ex_Person.h"
#include "FontStyle.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFontStyle dialog


CFontStyle::CFontStyle(CWnd* pParent /*=NULL*/)
	: CDialog(CFontStyle::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFontStyle)
	m_strSample = _T("");
	//}}AFX_DATA_INIT
}


void CFontStyle::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFontStyle)
	DDX_Control(pDX, IDC_LIST1, m_listFont);
	DDX_Text(pDX, IDC_STATIC_SAMPLE, m_strSample);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFontStyle, CDialog)
	//{{AFX_MSG_MAP(CFontStyle)
	ON_LBN_SELCHANGE(IDC_LIST1, OnSelchangeList1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFontStyle message handlers

void CFontStyle::FillListBox()
{
	m_listFont.ResetContent();
	CClientDC dc( this );
	::EnumFontFamilies( (HDC)dc, NULL, (FONTENUMPROC)EnumFontProc, (LPARAM)this );
}

int CALLBACK CFontStyle::EnumFontProc(ENUMLOGFONTEX *lpelfe, 
									NEWTEXTMETRICEX *lpntme,
									DWORD nFontType,    
									LPARAM lParam )
{
	CFontStyle	*pWnd	= (CFontStyle	*)lParam;
	if (( TRUETYPE_FONTTYPE &  nFontType))
		pWnd->m_listFont.AddString( lpelfe->elfLogFont.lfFaceName );
	return 1;

}

void CFontStyle::OnSelchangeList1() 
{
	// TODO: Add your control notification handler code here
	int nIndex = m_listFont.GetCurSel();
	if ( nIndex != LB_ERR )
	{
		CWnd *pWnd = GetDlgItem( IDC_STATIC_SAMPLE );
		CString strFaceName;
		static CFont font;
		font.Detach();
		font.DeleteObject();
		m_listFont.GetText( nIndex, strFaceName );
		font.CreatePointFont( -200, strFaceName );
		pWnd->SetFont( &font );
		m_listFont.GetText(m_listFont.GetCurSel(),m_strSetting);
	}	
	
}

BOOL CFontStyle::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_strSample="ÄãºÃ,MIMICQQ!";
	UpdateData(FALSE);
	FillListBox();
	this->OnSelchangeList1();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CFontStyle::OnOK() 
{
	// TODO: Add extra validation here
	CDialog::OnOK();
}
