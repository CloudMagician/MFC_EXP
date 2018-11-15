// CDialogEXP3_2.cpp: 实现文件
//

#include "stdafx.h"
#include "MFC_EXP.h"
#include "CDialogEXP3_2.h"
#include "afxdialogex.h"


// CDialogEXP3_2 对话框

IMPLEMENT_DYNAMIC(CDialogEXP3_2, CDialogEx)

CDialogEXP3_2::CDialogEXP3_2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_EXP3_2, pParent)
	, mX(0)
	, mY(0)
	, mZ(0)
{

}

CDialogEXP3_2::~CDialogEXP3_2()
{
}

void CDialogEXP3_2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDITX, mX);
	DDX_Text(pDX, IDC_EDITY, mY);
	DDX_Text(pDX, IDC_EDITZ, mZ);
}


BEGIN_MESSAGE_MAP(CDialogEXP3_2, CDialogEx)
END_MESSAGE_MAP()


// CDialogEXP3_2 消息处理程序
