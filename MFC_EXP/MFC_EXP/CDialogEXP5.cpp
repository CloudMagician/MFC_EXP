// CDialogEXP5.cpp: 实现文件
//

#include "stdafx.h"
#include "MFC_EXP.h"
#include "CDialogEXP5.h"
#include "afxdialogex.h"


// CDialogEXP5 对话框

IMPLEMENT_DYNAMIC(CDialogEXP5, CDialogEx)

CDialogEXP5::CDialogEXP5(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_EXP4, pParent)
	,	x0(-180),	y0(-180),	z0(0)
	,   x1(-180),	y1(-60),	z1(20)
	,   x2(-180),	y2(60),		z2(20)
	,   x3(-180),	y3(180),	z3(0)
	,   x4(-60),	y4(-180),	z4(40)
	,   x5(-60),	y5(-60),	z5(60)
	,   x6(-60),	y6(60),		z6(60)
	,   x7(-60),	y7(180),	z7(40)
	,   x8(60),		y8(-180),	z8(40)
	,   x9(60),		y9(-60),	z9(60)
	,   x10(60),	y10(60),	z10(60)
	,   x11(60),	y11(180),	z11(40)
	,   x12(180),	y12(-180),	z12(0)
	,   x13(180),	y13(-60),	z13(20)
	,   x14(180),	y14(60),	z14(20)
	,   x15(180),	y15(180),	z15(0)
	
{

}

CDialogEXP5::~CDialogEXP5()
{
}

void CDialogEXP5::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDITX0, x0); DDX_Text(pDX, IDC_EDITY0, y0); DDX_Text(pDX, IDC_EDITZ0, z0);
	DDX_Text(pDX, IDC_EDITX1, x1); DDX_Text(pDX, IDC_EDITY1, y1); DDX_Text(pDX, IDC_EDITZ1, z1);
	DDX_Text(pDX, IDC_EDITX2, x2); DDX_Text(pDX, IDC_EDITY2, y2); DDX_Text(pDX, IDC_EDITZ2, z2);
	DDX_Text(pDX, IDC_EDITX3, x3); DDX_Text(pDX, IDC_EDITY3, y3); DDX_Text(pDX, IDC_EDITZ3, z3);
	DDX_Text(pDX, IDC_EDITX4, x4); DDX_Text(pDX, IDC_EDITY4, y4); DDX_Text(pDX, IDC_EDITZ4, z4);
	DDX_Text(pDX, IDC_EDITX5, x5); DDX_Text(pDX, IDC_EDITY5, y5); DDX_Text(pDX, IDC_EDITZ5, z5);
	DDX_Text(pDX, IDC_EDITX6, x6); DDX_Text(pDX, IDC_EDITY6, y6); DDX_Text(pDX, IDC_EDITZ6, z6);
	DDX_Text(pDX, IDC_EDITX7, x7); DDX_Text(pDX, IDC_EDITY7, y7); DDX_Text(pDX, IDC_EDITZ7, z7);
	DDX_Text(pDX, IDC_EDITX8, x8); DDX_Text(pDX, IDC_EDITY8, y8); DDX_Text(pDX, IDC_EDITZ8, z8);
	DDX_Text(pDX, IDC_EDITX9, x9); DDX_Text(pDX, IDC_EDITY9, y9); DDX_Text(pDX, IDC_EDITZ9, z9);
	DDX_Text(pDX, IDC_EDITX10, x10); DDX_Text(pDX, IDC_EDITY10, y10); DDX_Text(pDX, IDC_EDITZ10, z10);
	DDX_Text(pDX, IDC_EDITX11, x11); DDX_Text(pDX, IDC_EDITY11, y11); DDX_Text(pDX, IDC_EDITZ11, z11);
	DDX_Text(pDX, IDC_EDITX12, x12); DDX_Text(pDX, IDC_EDITY12, y12); DDX_Text(pDX, IDC_EDITZ12, z12);
	DDX_Text(pDX, IDC_EDITX13, x13); DDX_Text(pDX, IDC_EDITY13, y13); DDX_Text(pDX, IDC_EDITZ13, z13);
	DDX_Text(pDX, IDC_EDITX14, x14); DDX_Text(pDX, IDC_EDITY14, y14); DDX_Text(pDX, IDC_EDITZ14, z14);
	DDX_Text(pDX, IDC_EDITX15, x15); DDX_Text(pDX, IDC_EDITY15, y15); DDX_Text(pDX, IDC_EDITZ15, z15);
}


BEGIN_MESSAGE_MAP(CDialogEXP5, CDialogEx)
END_MESSAGE_MAP()


// CDialogEXP5 消息处理程序
