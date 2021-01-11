// WHITE.cpp : implementation file
//

#include "stdafx.h"
#include "smtp.h"
#include "WHITE.h"
#include "shlwapi.h"
#include "SMTPDlg.h"
#pragma comment(lib, "shlwapi.lib")
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWHITE dialog


CWHITE::CWHITE(CWnd* pParent /*=NULL*/)
	: CDialog(CWHITE::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWHITE)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CWHITE::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWHITE)
	DDX_Control(pDX, IDC_LIST_WHITE, m_list);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWHITE, CDialog)
	//{{AFX_MSG_MAP(CWHITE)
	ON_BN_CLICKED(IDC_BUTTON_ADD, OnButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_DELETE2, OnButtonDelete2)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWHITE message handlers

BOOL CWHITE::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
		if(USER=="")
	{
		AfxMessageBox("请登录");
		return FALSE;
	}
	CStdioFile file;
	CString filepath,filename,str;
	filepath=_T("D:\\LIST"); //文件位置
	if(!PathFileExists(filepath))
	{
		if(!CreateDirectory(filepath,NULL))
		{
			AfxMessageBox("未能创建相关目录:"+filepath);
			return FALSE;
		}
	}
	filepath=filepath+"\\"+USER;
	if(!PathFileExists(filepath))
	{
		if(!CreateDirectory(filepath,NULL))
		{
			AfxMessageBox("未能创建相关目录:"+filepath);
			return FALSE;
		}
	}
	filename="whitelist.txt";  //文件名
	filename=filepath+"\\"+filename;  //文件路径

	if(!file.Open(filename,CFile::modeCreate|CFile::modeReadWrite|CFile::modeNoTruncate))//建立文件
	{
		AfxMessageBox("未找到相关文件!");
		return FALSE;
	}
	//ULONGLONG len = file.GetLength();
	int cnt=0;
	while(file.ReadString(str))
		m_list.InsertString(cnt++,str);
	file.Close();  //关闭文件
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CWHITE::OnButtonAdd() 
{
	// TODO: Add your control notification handler code here
	CString str,tmp;
	GetDlgItemText(IDC_EDIT1,str);
	if(str!="")
	{
		int L=m_list.GetCount();
		for(int i=0;i<L;++i)
		{
			m_list.GetText(i,tmp);
			if(tmp==str) {
				SetDlgItemText(IDC_EDIT1,"");
				return;
			}
		}
		m_list.InsertString(m_list.GetCount(),str);
	}
	SetDlgItemText(IDC_EDIT1,"");
}

void CWHITE::OnButtonDelete2() 
{
	// TODO: Add your control notification handler code here
	int ch=m_list.GetCurSel();
	if(ch!=CB_ERR)
	{
		m_list.DeleteString(ch);
	}
}

void CWHITE::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	CStdioFile file;
	CString filepath,filename,str;
	filepath=_T("D:\\LIST"); //文件位置
	if(!PathFileExists(filepath))
	{
		if(!CreateDirectory(filepath,NULL))
		{
			AfxMessageBox("未能创建相关目录:"+filepath);
			return;
		}
	}
	filepath=filepath+"\\"+USER;
	if(!PathFileExists(filepath))
	{
		if(!CreateDirectory(filepath,NULL))
		{
			AfxMessageBox("未能创建相关目录:"+filepath);
			return;
		}
	}
	filename="whitelist.txt";  //文件名
	filename=filepath+"\\"+filename;  //文件路径

	if(!file.Open(filename,CFile::modeCreate|CFile::modeReadWrite))//建立文件
	{
		AfxMessageBox("未找到相关文件!");
		return;
	}
	//ULONGLONG len = file.GetLength();
	int n=m_list.GetCount();
	white_list.RemoveAll();
	white_list.SetSize(n);
	for(int i=0;i<n;++i)
	{
		m_list.GetText(i,str);
		file.WriteString(str);
		white_list.SetAt(i,str);
	}
	file.Close();  //关闭文件
	CDialog::OnClose();
}
