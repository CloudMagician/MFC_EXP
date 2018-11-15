#pragma once


// CDialogEXP3_1 对话框

class CDialogEXP3_1 : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogEXP3_1)

public:
	CDialogEXP3_1(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDialogEXP3_1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_EXP3_1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// 旋转轴
	int isXYZ;
	CComboBox comboXYZ;
	afx_msg void OnCbnSelchangeComboXyz();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
