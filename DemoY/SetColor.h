#if !defined(AFX_SETCOLOR_H__E6EAA207_1574_4EAE_A286_2A37C39F08CE__INCLUDED_)
#define AFX_SETCOLOR_H__E6EAA207_1574_4EAE_A286_2A37C39F08CE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SetColor.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// SetColor dialog

class SetColor : public CDialog
{
// Construction
public:
	SetColor(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(SetColor)
	enum { IDD = IDD_SETCOLOR };
	int		m_g;
	int		m_b;
	int		m_r;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(SetColor)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(SetColor)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETCOLOR_H__E6EAA207_1574_4EAE_A286_2A37C39F08CE__INCLUDED_)
