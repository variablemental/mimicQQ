; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMailDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Ex_Person.h"

ClassCount=10
Class1=CEx_PersonApp
Class2=CEx_PersonDlg
Class3=CAboutDlg

ResourceCount=10
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_EX_PERSON_DIALOG
Class4=COneDlg
Resource4=IDD_DIALOG5
Class5=CChatDlg
Resource5=IDD_DIALOG4
Class6=TwoDlg
Resource6=IDD_DIALOG6
Class7=CStyleDlg
Resource7=IDD_DIALOG3
Class8=CFontStyle
Resource8=IDD_DIALOG2
Class9=AboutMIMIC
Resource9=IDD_DIALOG1
Class10=CMailDlg
Resource10=IDD_DIALOG7

[CLS:CEx_PersonApp]
Type=0
HeaderFile=Ex_Person.h
ImplementationFile=Ex_Person.cpp
Filter=N

[CLS:CEx_PersonDlg]
Type=0
HeaderFile=Ex_PersonDlg.h
ImplementationFile=Ex_PersonDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_BUTTON_send

[CLS:CAboutDlg]
Type=0
HeaderFile=Ex_PersonDlg.h
ImplementationFile=Ex_PersonDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_EX_PERSON_DIALOG]
Type=1
Class=CEx_PersonDlg
ControlCount=18
Control1=IDC_LIST1,SysListView32,1350631425
Control2=IDC_BUTTON_ADD,button,1342242816
Control3=IDC_BUTTON_CHANGE,button,1342242816
Control4=IDC_BUTTON_DEL,button,1342242816
Control5=IDC_BUTTON_START,button,1342242816
Control6=IDC_BUTTON_CANCEL,button,1342242816
Control7=IDC_STATIC_NETWORK,static,1342308352
Control8=IDC_EDIT_PORT,edit,1350631552
Control9=IDC_STATIC,static,1342308352
Control10=IDC_EDIT_IP,edit,1350631552
Control11=IDC_STATIC_IP,static,1342308352
Control12=IDC_EDIT_CHAT,edit,1350631552
Control13=IDC_STATIC,static,1342308352
Control14=IDC_BUTTON_send,button,1342242816
Control15=IDC_STATIC,static,1342308352
Control16=IDC_EDIT_PEERPORT,edit,1350631552
Control17=IDC_BUTTON_INSERT,button,1342242816
Control18=IDC_BUTTON_STYLE,button,1342242816

[DLG:IDD_DIALOG1]
Type=1
Class=COneDlg
ControlCount=14
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT_NAME,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT_NO,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_EDIT_IP,edit,1350631552
Control11=IDC_STATIC,static,1342308352
Control12=IDC_EDIT_MESSGAE,edit,1350631556
Control13=IDC_EDIT_MOTTO,edit,1350631552
Control14=IDC_EDIT_ZONE,edit,1350631552

[CLS:COneDlg]
Type=0
HeaderFile=OneDlg.h
ImplementationFile=OneDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_EDIT_ZONE

[DLG:IDD_DIALOG2]
Type=1
Class=CChatDlg
ControlCount=4
Control1=IDC_EDIT1,edit,1350631552
Control2=IDC_BUTTON1,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC_RES,static,1342308352

[CLS:CChatDlg]
Type=0
HeaderFile=ChatDlg.h
ImplementationFile=ChatDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CChatDlg
VirtualFilter=dWC

[DLG:IDD_DIALOG3]
Type=1
Class=TwoDlg
ControlCount=14
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_EDIT_NAME,edit,1350631552
Control8=IDC_EDIT_NO,edit,1350631552
Control9=IDC_EDIT_MOTTO,edit,1350631552
Control10=IDC_EDIT_ZONE,edit,1350631552
Control11=IDC_EDIT_IP,edit,1350631552
Control12=IDC_EDIT_MESSGAE,edit,1350631556
Control13=IDOK,button,1342242817
Control14=IDCANCEL,button,1342242816

[CLS:TwoDlg]
Type=0
HeaderFile=TwoDlg.h
ImplementationFile=TwoDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_EDIT_IP

[DLG:IDD_DIALOG4]
Type=1
Class=CStyleDlg
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308352
Control3=IDC_BUTTON_FONT,button,1342242816
Control4=IDC_BUTTON_WINDOW,button,1342242816
Control5=IDC_BUTTON_NETTEST,button,1342242816
Control6=IDC_BUTTON4,button,1342242816
Control7=IDC_BUTTON_SUGGESTION,button,1342242816
Control8=IDC_BUTTON_TIME,button,1342242816

[CLS:CStyleDlg]
Type=0
HeaderFile=StyleDlg.h
ImplementationFile=StyleDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CStyleDlg
VirtualFilter=dWC

[DLG:IDD_DIALOG5]
Type=1
Class=CFontStyle
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDC_STATIC_SAMPLE,static,1342308865
Control3=IDC_LIST1,listbox,1352728835
Control4=IDC_EDIT1,edit,1350631552
Control5=IDC_STATIC,static,1342308864

[CLS:CFontStyle]
Type=0
HeaderFile=FontStyle.h
ImplementationFile=FontStyle.cpp
BaseClass=CDialog
Filter=D
LastObject=CFontStyle
VirtualFilter=dWC

[DLG:IDD_DIALOG6]
Type=1
Class=AboutMIMIC
ControlCount=1
Control1=IDC_STATIC_STICK,static,1342308352

[CLS:AboutMIMIC]
Type=0
HeaderFile=AboutMIMIC.h
ImplementationFile=AboutMIMIC.cpp
BaseClass=CDialog
Filter=D
LastObject=AboutMIMIC
VirtualFilter=dWC

[DLG:IDD_DIALOG7]
Type=1
Class=CMailDlg
ControlCount=3
Control1=IDC_STATIC_INTRODUCE,static,1342308352
Control2=IDC_BUTTON_Mail,button,1342242816
Control3=IDC_BUTTON_GitHub,button,1342242816

[CLS:CMailDlg]
Type=0
HeaderFile=MailDlg.h
ImplementationFile=MailDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CMailDlg
VirtualFilter=dWC

