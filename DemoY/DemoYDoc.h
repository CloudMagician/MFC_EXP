// DemoYDoc.h : interface of the CDemoYDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DEMOYDOC_H__7651D047_9FD0_4A9B_8F57_00272C6DB9CC__INCLUDED_)
#define AFX_DEMOYDOC_H__7651D047_9FD0_4A9B_8F57_00272C6DB9CC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDemoYDoc : public CDocument
{
protected: // create from serialization only
	CDemoYDoc();
	DECLARE_DYNCREATE(CDemoYDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDemoYDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDemoYDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDemoYDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEMOYDOC_H__7651D047_9FD0_4A9B_8F57_00272C6DB9CC__INCLUDED_)
