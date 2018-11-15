// CDialogEXP3_1.cpp: 实现文件
//

#include "stdafx.h"
#include "MFC_EXP.h"
#include "CDialogEXP3_1.h"
#include "afxdialogex.h"


// CDialogEXP3_1 对话框

IMPLEMENT_DYNAMIC(CDialogEXP3_1, CDialogEx)

CDialogEXP3_1::CDialogEXP3_1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_EXP3_1, pParent)
	, isXYZ(1)
{

}

CDialogEXP3_1::~CDialogEXP3_1()
{
}

void CDialogEXP3_1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_XYZ, comboXYZ);
}


BEGIN_MESSAGE_MAP(CDialogEXP3_1, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO_XYZ, &CDialogEXP3_1::OnCbnSelchangeComboXyz)
	ON_BN_CLICKED(IDOK, &CDialogEXP3_1::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CDialogEXP3_1::OnBnClickedCancel)
END_MESSAGE_MAP()

void CDialogEXP3_1::OnCbnSelchangeComboXyz()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CDialogEXP3_1::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	isXYZ = comboXYZ.GetCurSel() + 1;
	UpdateData(FALSE);
	CDialogEx::OnOK();
}


void CDialogEXP3_1::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
