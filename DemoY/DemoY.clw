; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDemoYView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "DemoY.h"
LastPage=0

ClassCount=7
Class1=CDemoYApp
Class2=CDemoYDoc
Class3=CDemoYView
Class4=CMainFrame

ResourceCount=4
Resource1=IDR_MAINFRAME
Class5=CAboutDlg
Resource2=IDD_ABOUTBOX
Class6=SetWidth
Resource3=IDD_DIALOG1
Class7=SetColor
Resource4=IDD_SETCOLOR

[CLS:CDemoYApp]
Type=0
HeaderFile=DemoY.h
ImplementationFile=DemoY.cpp
Filter=N

[CLS:CDemoYDoc]
Type=0
HeaderFile=DemoYDoc.h
ImplementationFile=DemoYDoc.cpp
Filter=N

[CLS:CDemoYView]
Type=0
HeaderFile=DemoYView.h
ImplementationFile=DemoYView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=ID_IN


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=CMainFrame




[CLS:CAboutDlg]
Type=0
HeaderFile=DemoY.cpp
ImplementationFile=DemoY.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_SETWIDTH
Command15=ID_VIEW_TOOLBAR
Command16=ID_VIEW_STATUS_BAR
Command17=ID_APP_ABOUT
CommandCount=17

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
Command9=ID_LINE
Command10=ID_POLYGON
Command11=ID_IN
CommandCount=11

[DLG:IDD_DIALOG1]
Type=1
Class=SetWidth
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT1,edit,1350631552

[CLS:SetWidth]
Type=0
HeaderFile=SetWidth.h
ImplementationFile=SetWidth.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=ID_APP_ABOUT

[DLG:IDD_SETCOLOR]
Type=1
Class=SetColor
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_R,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_G,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_B,edit,1350631552

[CLS:SetColor]
Type=0
HeaderFile=SetColor.h
ImplementationFile=SetColor.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=ID_APP_ABOUT

