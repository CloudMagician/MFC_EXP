#pragma once


// CDialogEXP5 对话框

class CDialogEXP5 : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogEXP5)

public:
	CDialogEXP5(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDialogEXP5();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_EXP4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int x0;		int y0;		int z0;
	int x1;		int y1;		int z1;
	int x2;		int y2;		int z2;
	int x3;		int y3;		int z3;
	int x4;		int y4;		int z4;
	int x5;		int y5;		int z5;
	int x6;		int y6;		int z6;
	int x7;		int y7;		int z7;
	int x8;		int y8;		int z8;
	int x9;		int y9;		int z9;
	int x10;	int y10;	int z10;
	int x11;	int y11;	int z11;
	int x12;	int y12;	int z12;
	int x13;	int y13;	int z13;
	int x14;	int y14;	int z14;
	int x15;	int y15;	int z15;
};
