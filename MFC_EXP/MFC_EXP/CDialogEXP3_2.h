#pragma once


// CDialogEXP3_2 对话框

class CDialogEXP3_2 : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogEXP3_2)

public:
	CDialogEXP3_2(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDialogEXP3_2();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_EXP3_2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	double mX;
	double mY;
	double mZ;
};
