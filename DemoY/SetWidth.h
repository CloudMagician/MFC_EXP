#if !defined(AFX_SETWIDTH_H__AC501965_22B8_4268_B2BB_7C91E074EB0D__INCLUDED_)
#define AFX_SETWIDTH_H__AC501965_22B8_4268_B2BB_7C91E074EB0D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SetWidth.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// SetWidth dialog

class SetWidth : public CDialog
{
// Construction
public:
	SetWidth(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(SetWidth)
	enum { IDD = IDD_DIALOG1 };
	int		m_width;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(SetWidth)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(SetWidth)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETWIDTH_H__AC501965_22B8_4268_B2BB_7C91E074EB0D__INCLUDED_)
