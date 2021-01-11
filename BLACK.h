#if !defined(AFX_BLACK_H__3BDE7082_D933_472F_8A25_16CB0C66E90F__INCLUDED_)
#define AFX_BLACK_H__3BDE7082_D933_472F_8A25_16CB0C66E90F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BLACK.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBLACK dialog

class CBLACK : public CDialog
{
// Construction
public:
	CBLACK(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CBLACK)
	enum { IDD = IDD_DIALOG_BLACK };
	CListBox	m_list;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBLACK)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBLACK)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonAdd();
	afx_msg void OnButtonDelete();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BLACK_H__3BDE7082_D933_472F_8A25_16CB0C66E90F__INCLUDED_)
