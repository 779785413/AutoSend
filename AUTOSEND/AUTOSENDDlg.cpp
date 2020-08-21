
// AUTOSENDDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "AUTOSEND.h"
#include "AUTOSENDDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CAUTOSENDDlg 对话框



CAUTOSENDDlg::CAUTOSENDDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_AUTOSEND_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAUTOSENDDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAUTOSENDDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_MFCEDITBROWSE1, &CAUTOSENDDlg::OnEnChangeMfceditbrowse1)
	ON_BN_CLICKED(IDC_BUTTON3, &CAUTOSENDDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CAUTOSENDDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON1, &CAUTOSENDDlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT1, &CAUTOSENDDlg::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CAUTOSENDDlg 消息处理程序

BOOL CAUTOSENDDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);
	my_icon.SubclassDlgItem(IDC_PICTURE,this);
	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CAUTOSENDDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CAUTOSENDDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CAUTOSENDDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CAUTOSENDDlg::OnEnChangeMfceditbrowse1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CAUTOSENDDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog open_img(TRUE,
		NULL,
		NULL,
		OFN_OVERWRITEPROMPT,
		NULL,
		NULL);
	CEdit* MyEdit = (CEdit*)GetDlgItem(IDC_EDIT1);
	
	if (open_img.DoModal() == IDOK)
	{
		
		MyEdit->SetSel(0, -1);
		MyEdit->ReplaceSel(_T(""));
		FileSelect = open_img.GetPathName();
		CEdit* FileNameEdit = (CEdit*)GetDlgItem(IDC_EDIT2);
		FileNameEdit->SetWindowTextW(FileSelect);
		CStdioFile file;
		if (!file.Open(FileSelect, CFile::modeReadWrite)) {
			FileSelect = "";
			
			return;
		}
		CString Content;
		while (file.ReadString(Content)) {
			MyEdit->SetSel(MyEdit->GetWindowTextLengthW(), MyEdit->GetWindowTextLengthW());
			MyEdit->ReplaceSel(Content + L"\r\n");
		}
		file.Close();
	}
	else {
		FileSelect = "";
	}
}


void CAUTOSENDDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	CEdit* p = (CEdit*)GetDlgItem(IDC_EDIT1);
	int LineCount = p->GetLineCount();
	LPTSTR ls = new TCHAR[1000];
	CStdioFile file;
	if (FileSelect == "")
	{
		CFileDialog Folder(FALSE, NULL, NULL, OFN_OVERWRITEPROMPT| OFN_CREATEPROMPT| OFN_READONLY, _T("*.txt|*.txt||"), NULL);
		if (Folder.DoModal() != IDOK) {
			return;
		}
		FileSelect = Folder.GetPathName();
		CEdit* FileNameEdit = (CEdit*)GetDlgItem(IDC_EDIT2);
		FileNameEdit->SetWindowTextW(FileSelect);
		if (file.Open(FileSelect, CFile::modeCreate) == FALSE)
		{
			return;
		}
		file.Close();
	}
	if (file.Open(FileSelect, CFile::modeReadWrite) == FALSE)
	{
		return;
	}
	CString Content;
	p->GetWindowText(Content);
	Content.Remove('\r');
	file.WriteString(Content);
	file.Close();
}

void CAUTOSENDDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CEdit* p = (CEdit*)GetDlgItem(IDC_EDIT1);
	int cpxy;
	POINT cp = GetCaretPos();
	cpxy = p->CharFromPos(cp);
	int row = HIWORD(cpxy);
	int n = p->LineLength(-1);
	LPTSTR ls = new TCHAR[n];

	p->GetLine(row, ls, n);
	if (CatchHWnd == NULL || (!IsWindow(CatchHWnd)))
	{
		return;
	}
	for (int i = 0; i < n; i++)
	{
		::SendMessage(CatchHWnd, WM_CHAR, ls[i], 0);
		//Sleep(0.2);
	}
	Sleep(0.5);
	::SendMessage(CatchHWnd, WM_IME_KEYDOWN, VK_RETURN, 0);
	::SendMessage(CatchHWnd, WM_IME_KEYDOWN, VK_RETURN, 0);
	int TextLength = 0;
	for (int i = 0; i <= row; i++)
	{
		TextLength += p->LineLength(p->LineIndex(i)) + 2;
	}
	TextLength += p->LineLength(p->LineIndex(row + 1));
	p->SetFocus();
	p->SetSel(TextLength, TextLength);
}
void CAUTOSENDDlg::OnOK()
{
	if (GetDlgItem(IDOK) == GetFocus())
	{
		CDialog::OnOK();
	}
	//handle enter key
}

void CAUTOSENDDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
