// Ex_PersonDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Ex_Person.h"
#include "Ex_PersonDlg.h"
#include "OneDlg.h"
#include "TwoDlg.h"
#include "ChatDlg.h"
#include "FontStyle.h"
#include "StyleDlg.h"
#include "Server.h"
#include "Client.h"
#include <Afxsock.h>  
#include <afxwin.h>
#include <string>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// Global Variables
CWinThread *pThread=NULL;
bool m_bexit=false;
CString strFont;

//线程工作函数
unsigned int StartServer(LPVOID lParam)
{
	if(!AfxSocketInit())
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return 1;
	}
	m_bexit=false;
	CEx_PersonDlg *Dlg=(CEx_PersonDlg *)lParam;
	CString portStr;
	Dlg->GetDlgItemText(IDC_EDIT_PORT,portStr);
	UINT nPort=atoi(portStr);
	CSocket socket,serverSocket;
	if(!socket.Socket())
	{
		char ErrorMsg[256];
		sprintf(ErrorMsg,"Error Code:%d",GetLastError());
		AfxMessageBox(ErrorMsg);
		return 1;
	}
	BOOL bOptVal=TRUE;
	int bOptLen=sizeof(BOOL);
	socket.SetSockOpt(SO_REUSEADDR,(void *)&bOptVal,bOptLen,SOL_SOCKET);
	if(!socket.Bind(nPort))																		//开始绑定端口
	{
		char Error[256];
		sprintf(Error,"Bind Error Code:%d",GetLastError());
		AfxMessageBox(Error);
		return 1;
	}
	if(!socket.Listen(10))																		//开始监听端口
	{
		char Error[256];
		sprintf(Error,"Listen Error Code:%d %d",GetLastError(),nPort);
		AfxMessageBox(Error);
		return 1;
	}
	CString strText;
	strText+="登录成功!";
	Dlg->SetDlgItemText(IDC_STATIC_NETWORK,strText);
	while(!m_bexit)
	{
		if(!socket.Accept(serverSocket))
			continue;
		else
		{
			char Receive[256]={0};
			char printMsg[256]={0};
			//CString printMsg;
			
			static CFont font;
			font.Detach();
			font.DeleteObject();
			font.CreatePointFont(-100,strFont);
			CWnd *pWnd=Dlg->GetDlgItem(IDC_STATIC_NETWORK);
			pWnd->SetFont(&font);

			serverSocket.Receive(Receive,256);
			//Receive[sizeof(Receive)/sizeof(Receive[0])+1]='\0';
			sprintf(printMsg,"hacker:%s \r\n",Receive);
			Dlg->GetDlgItemText(IDC_STATIC_NETWORK,strText);
			strText+=printMsg;
			Dlg->SetDlgItemText(IDC_STATIC_NETWORK,strText);
			serverSocket.Close();
		}
	}
	socket.Close();
	serverSocket.Close();
	Dlg->GetDlgItemText(IDC_STATIC_NETWORK,strText);
	strText+="终止了聊天";
	Dlg->SetDlgItemText(IDC_STATIC_NETWORK,strText);
	return 0;
}

void StopServer()
{
	m_bexit=true;
}



/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_PersonDlg dialog

CEx_PersonDlg::CEx_PersonDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEx_PersonDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEx_PersonDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEx_PersonDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEx_PersonDlg)
	DDX_Control(pDX, IDC_LIST1, m_dataList);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CEx_PersonDlg, CDialog)
	//{{AFX_MSG_MAP(CEx_PersonDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_ADD, OnButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_CHANGE, OnButtonChange)
	ON_BN_CLICKED(IDC_BUTTON_DEL, OnButtonDel)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, OnItemchangedList1)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, OnBtnCancel)
	ON_BN_CLICKED(IDC_BUTTON_START, OnButtonStart)
	ON_BN_CLICKED(IDC_BUTTON_send, OnBUTTONsend)
	ON_BN_CLICKED(IDC_BUTTON_INSERT, OnButtonInsert)
	ON_BN_CLICKED(IDC_BUTTON_STYLE, OnButtonStyle)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_PersonDlg message handlers

BOOL CEx_PersonDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}



	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
//	m_iNetPort=3127;
//	m_Server.Initialize(this);
//	m_bServer=FALSE;

	
	// TODO: Add extra initialization here
	// 创建列表控件的标题头
	CString strHeader[]={ "QQ号", "昵称", "个性签名", "ta的QQ空间",
		"IP地址", "网络状况"};
	int nHeaderWidth[]={ 110,105, 40, 100, 100, 200 };
	for (int nCol=0; nCol<6; nCol++)
		m_dataList.InsertColumn(nCol,strHeader[nCol],
						LVCFMT_LEFT,nHeaderWidth[nCol]);
	GetDlgItem( IDC_BUTTON_CHANGE )->EnableWindow(FALSE);
	GetDlgItem( IDC_BUTTON_DEL )->EnableWindow(FALSE);
	int nIndex=m_dataList.InsertItem(m_dataList.GetItemCount(),"346122313");
	m_dataList.SetItemText(nIndex,1,"隔壁老王");
	nIndex=m_dataList.InsertItem(m_dataList.GetItemCount(),"8884545546");
	m_dataList.SetItemText(nIndex,1,"对门老张");
	nIndex=m_dataList.InsertItem(m_dataList.GetItemCount(),"512241546");
	m_dataList.SetItemText(nIndex,1,"办公室小汪");
	nIndex=m_dataList.InsertItem(m_dataList.GetItemCount(),"346145732");
	m_dataList.SetItemText(nIndex,1,"酱油店小周");


	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CEx_PersonDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CEx_PersonDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CEx_PersonDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CEx_PersonDlg::OnButtonAdd() 
{
	// TODO: Add your control notification handler code here

	CString myIP;
	CString peerIP;
	CString myPort;
	CString peerPort;
	CChatDlg dlg;
	POSITION pos;
	pos=m_dataList.GetFirstSelectedItemPosition();
	int nItem=m_dataList.GetNextSelectedItem(pos);
	dlg.SetTag(m_dataList.GetItemText(nItem,1));									//获得好友姓名
	peerIP=m_dataList.GetItemText(nItem,4);
	this->GetDlgItem(IDC_EDIT_PORT)->GetWindowText(myPort);
	this->GetDlgItem(IDC_EDIT_PEERPORT)->GetWindowText(peerPort);
	int pPort=atoi(peerPort);
	int mPort=atoi(myPort);

	CSocket clientSocket;
	AfxSocketInit();
	if(!clientSocket.Create())
	{
		char Error[256];
		sprintf(Error,"Create Error Code:%d",GetLastError());
		AfxMessageBox(Error);
		return ;
	}
	if(!clientSocket.Connect(peerIP,pPort))
	{	
		char Error[256];
		sprintf(Error,"Connect Error Code:%d",GetLastError());
		AfxMessageBox(Error);
		return ;
	}
	else
	{
		CString content="隔壁老王向你发起了聊天！他的端口号是:";
		content+=myPort+"\n";
		clientSocket.Send(content,content.GetLength());
	}

//	COneDlg dlg;
	if (IDOK != dlg.DoModal()) return;
}

void CEx_PersonDlg::OnButtonChange() 
{
	// TODO: Add your control notification handler code here
	// 获取被选择的列表项索引号
	POSITION pos;
	pos = m_dataList.GetFirstSelectedItemPosition();
	if (pos == NULL){
		MessageBox("还没有选中列表项！");
		return;
	}
	int nItem = m_dataList.GetNextSelectedItem( pos );

	TwoDlg dlg;

	if (IDOK != dlg.DoModal()) return;

	m_dataList.SetItemText( nItem, 0, dlg.m_strQQ);
	m_dataList.SetItemText( nItem, 1, dlg.m_strNickName);
	m_dataList.SetItemText( nItem, 2, dlg.m_strMotto);
	m_dataList.SetItemText( nItem, 3, dlg.m_strZone);
	m_dataList.SetItemText( nItem, 4, dlg.m_strIP );
	m_dataList.SetItemText( nItem, 5, "未连接");		
}

void CEx_PersonDlg::OnButtonDel() 
{
	POSITION pos;
	pos = m_dataList.GetFirstSelectedItemPosition();
	if (pos == NULL){
		MessageBox("还没有选中列表项！");
		return;
	}
	int nItem = m_dataList.GetNextSelectedItem( pos );
	if ( IDYES == MessageBox( "确实要删除吗？", "警告", 
		MB_ICONWARNING | MB_YESNO ) )
	{
		m_dataList.DeleteItem( nItem );
	}	
}

void CEx_PersonDlg::OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	POSITION pos;
	pos = m_dataList.GetFirstSelectedItemPosition();
	if (pos == NULL){
		GetDlgItem( IDC_BUTTON_CHANGE )->EnableWindow(FALSE);	
		GetDlgItem( IDC_BUTTON_DEL )->EnableWindow(FALSE);	
	} else
	{
		GetDlgItem( IDC_BUTTON_CHANGE )->EnableWindow(TRUE);	
		GetDlgItem( IDC_BUTTON_DEL )->EnableWindow(TRUE);	
	}
	*pResult = 0;
}

void CEx_PersonDlg::OnBtnCancel() 
{
	// TODO: Add your control notification handler code here
	StopServer();
	pThread->SuspendThread();
	delete pThread;
	pThread=NULL;
	GetDlgItem(IDC_BUTTON_START)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_CANCEL)->EnableWindow(FALSE);
}

void CEx_PersonDlg::OnButtonStart() 
{
	// TODO: Add your control notification handler code here
	pThread=new CWinThread(StartServer,(LPVOID)this);
	pThread->CreateThread(CREATE_SUSPENDED);
	pThread->ResumeThread();
	GetDlgItem(IDC_BUTTON_START)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_CANCEL)->EnableWindow(TRUE);
}


void CEx_PersonDlg::OnBUTTONsend() 
{
	// TODO: Add your control notification handler code here
	CString IP;
	CString Port;
	CString strText;
	AfxSocketInit();
	CSocket clientSocket;
	this->GetDlgItem(IDC_EDIT_IP)->GetWindowText(IP);
	this->GetDlgItem(IDC_EDIT_PEERPORT)->GetWindowText(Port);
	this->GetDlgItem(IDC_EDIT_CHAT)->GetWindowText(strText);
	int nPort=atoi(Port);
	if(!clientSocket.Create())
	{
		char Error[256];
		sprintf(Error,"Create Error Code:%d",GetLastError());
		AfxMessageBox(Error);
		return ;
	}
	if(clientSocket.Connect(IP,nPort))
	{
		char Receive[1024]={0};
		clientSocket.Send(strText,strText.GetLength());

		//clientSocket.Receive((void *)Receive,1024);
		//GetDlgItem(IDC_STATIC_NETWORK)->SetWindowText(Receive);
	}
	else
	{
		char Error[256];
		sprintf(Error,"Connect Error Code:%d",GetLastError());
		AfxMessageBox(Error);
	}
	clientSocket.Close();
}

void CEx_PersonDlg::OnButtonInsert() 
{
	// TODO: Add your control notification handler code here
	TwoDlg dlg;
	if(IDOK!=dlg.DoModal())	return ;
	LVFINDINFO info;
	info.flags=LVFI_PARTIAL|LVFI_STRING;
	info.psz=dlg.m_strQQ;
	if(m_dataList.FindItem(&info)!=-1)
	{
		MessageBox("ta已经是你的好友啦！");
		return ;
	}
	int nIndex=m_dataList.InsertItem(m_dataList.GetItemCount(),dlg.m_strQQ);
	m_dataList.SetItemText(nIndex,1,dlg.m_strNickName);
	m_dataList.SetItemText(nIndex,2,dlg.m_strMotto);
	m_dataList.SetItemText(nIndex,3,dlg.m_strZone);
	m_dataList.SetItemText(nIndex,4,dlg.m_strIP);
	m_dataList.SetItemText(nIndex,5,"未连接");	
}

void CEx_PersonDlg::OnButtonStyle() 
{
	// TODO: Add your control notification handler code here
	CStyleDlg dlg;
	if(IDOK!=dlg.DoModal())	return ;
	//if(!dlg.m_fontSetting.IsEmpty())
		strFont+=dlg.m_fontSetting;
	
}
