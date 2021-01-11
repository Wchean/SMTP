// BLACK.cpp : implementation file
//

#include "stdafx.h"
#include "smtp.h"
#include "BLACK.h"
#include "SMTPDlg.h"
#include "shlwapi.h"
#pragma comment(lib, "shlwapi.lib")
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBLACK dialog


CBLACK::CBLACK(CWnd* pParent /*=NULL*/)
	: CDialog(CBLACK::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBLACK)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CBLACK::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBLACK)
	DDX_Control(pDX, IDC_LIST_BLACK, m_list);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBLACK, CDialog)
	//{{AFX_MSG_MAP(CBLACK)
	ON_BN_CLICKED(IDC_BUTTON_ADD, OnButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBLACK message handlers

BOOL CBLACK::OnInitDialog() 
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
	filename="blacklist.txt";  //文件名
	filename=filepath+"\\"+filename;  //文件路径

	if(!file.Open(filename,CFile::modeCreate|CFile::modeReadWrite|CFile::modeNoTruncate))//建立文件
	{
		AfxMessageBox("未找到相关文件!");
		return FALSE;
	}
	//ULONGLONG len = file.GetLength();
	int cnt=0;
	while(file.ReadString(str))
	{
		m_list.InsertString(cnt++,str);
		
	}
	file.Close();  //关闭文件
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CBLACK::OnButtonAdd() 
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

void CBLACK::OnButtonDelete() 
{
	// TODO: Add your control notification handler code here
	int ch=m_list.GetCurSel();
	if(ch!=CB_ERR)
	{
		m_list.DeleteString(ch);
	}
}

void CBLACK::OnClose() 
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
	filename="blacklist.txt";  //文件名
	filename=filepath+"\\"+filename;  //文件路径

	if(!file.Open(filename,CFile::modeCreate|CFile::modeReadWrite))//建立文件
	{
		AfxMessageBox("未找到相关文件!");
		return;
	}
	//ULONGLONG len = file.GetLength();
	int n=m_list.GetCount();
	black_list.RemoveAll();
	black_list.SetSize(n);
	for(int i=0;i<n;++i)
	{
		m_list.GetText(i,str);
		file.WriteString(str);
		black_list.SetAt(i,str);
	}
	file.Close();  //关闭文件
	
	CDialog::OnClose();
}
