
// CalculatorDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
#include "afxdialogex.h"
#include <string>
#include "Calculationer.h"
#include "Scanner.h"
#include "atlconv.h"
#include <stdlib.h>
#include <cstring>
#include <queue>

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


// CCalculatorDlg 对话框



CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
	, m_result(_T(""))
	, m_infile(_T(""))
	, m_outfile(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_result);
	DDX_Text(pDX, IDC_EDIT2, m_infile);
	DDX_Text(pDX, IDC_EDIT3, m_outfile);
	DDX_Control(pDX, IDC_EDIT2, infile);
	DDX_Control(pDX, IDC_EDIT3, outfile);
	
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CCalculatorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CCalculatorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CCalculatorDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &CCalculatorDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CCalculatorDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CCalculatorDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON9, &CCalculatorDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CCalculatorDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CCalculatorDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON13, &CCalculatorDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON14, &CCalculatorDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON4, &CCalculatorDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON8, &CCalculatorDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON12, &CCalculatorDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON16, &CCalculatorDlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON19, &CCalculatorDlg::OnBnClickedButton19)
	ON_BN_CLICKED(IDC_BUTTON20, &CCalculatorDlg::OnBnClickedButton20)
	ON_BN_CLICKED(IDC_BUTTON15, &CCalculatorDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON17, &CCalculatorDlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON18, &CCalculatorDlg::OnBnClickedButton18)
	ON_EN_CHANGE(IDC_EDIT2, &CCalculatorDlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, &CCalculatorDlg::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT1, &CCalculatorDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDOK, &CCalculatorDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON22, &CCalculatorDlg::OnBnClickedButton22)
	ON_BN_CLICKED(IDC_BUTTON21, &CCalculatorDlg::OnBnClickedButton21)
	ON_BN_CLICKED(IDC_BUTTON23, &CCalculatorDlg::OnBnClickedButton23)
END_MESSAGE_MAP()


// CCalculatorDlg 消息处理程序

BOOL CCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

void CCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCalculatorDlg::OnPaint()
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
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCalculatorDlg::OnBnClickedButton1()
{
	m_result += _T("1");
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButton2()
{
	m_result += _T("2");
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButton3()
{
	m_result += _T("3");
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButton5()
{
	m_result += _T("4");
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButton6()
{
	m_result += _T("5");
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButton7()
{
	m_result += _T("6");
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButton9()
{
	m_result += _T("7");
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButton10()
{
	m_result += _T("8");
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButton11()
{
	m_result += _T("9");
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButton13()
{
	m_result += _T("0");
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButton14()
{
	m_result += _T(".");
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButton4()
{
	m_result += _T("+");
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButton8()
{
	m_result += _T("-");
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButton12()
{
	m_result += _T("*");
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButton16()
{
	m_result += _T("/");
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButton19()
{
	m_result += _T("(");
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButton20()
{
	m_result += _T(")");
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButton15()
{
	Scanner sc;
	Calculationer ca;
	queue<string> res;
	string str;
	CT2A s(m_result);
	str = s;
	res = sc.ToStringQueue(str);
	str = ca.ToCalculate(res);
	m_result = str.c_str();
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButton17()
{
	
	m_result = _T("");
	UpdateData(FALSE);
}
// 处理ESC

void CCalculatorDlg::OnBnClickedButton18()
{
	int i = m_result.GetLength();
	m_result.Delete(i - 1, 1);
	UpdateData(FALSE);
}
//处理Backspace


void CCalculatorDlg::OnEnChangeEdit2()
{
	


	
}
//处理infile

void CCalculatorDlg::OnEnChangeEdit3()
{
}
//处理outfile

void CCalculatorDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CCalculatorDlg::OnBnClickedOk()
{
	CDialogEx::OnOK();
}



BOOL CCalculatorDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: Add your specialized code here and/or call the base class  
	if (pMsg->message == WM_KEYDOWN)
	{
		switch (pMsg->wParam)
		{  
		case '1':
		case VK_NUMPAD1: //小键盘  
			OnBnClickedButton1();
			break;
		case '2':
		case VK_NUMPAD2: //小键盘  
			OnBnClickedButton2();
			break;
		case '3':
		case VK_NUMPAD3: //小键盘  
			OnBnClickedButton3();
			break;
		case '4':
		case VK_NUMPAD4: //小键盘  
			OnBnClickedButton5();
			break;
		case '5':
		case VK_NUMPAD5: //小键盘  
			OnBnClickedButton6();
			break;
		case '6':
		case VK_NUMPAD6: //小键盘  
			OnBnClickedButton7();
			break;
		case '7':
		case VK_NUMPAD7: //小键盘  
			OnBnClickedButton9();
			break;
		case '8':
			if (GetKeyState(VK_SHIFT) < 0)
				OnBnClickedButton12();
			else  
				OnBnClickedButton10();
			break;
		case '9':
			if (GetKeyState(VK_SHIFT) < 0)
				OnBnClickedButton19();
			else
				OnBnClickedButton11();
			break;
		case '0':
			if (GetKeyState(VK_SHIFT) < 0)
				OnBnClickedButton20();
			else
				OnBnClickedButton13();
			break;
		case VK_ESCAPE:
			OnBnClickedButton17();
			break;
		case VK_BACK:
			OnBnClickedButton18();
			break;
		case VK_ADD:
			OnBnClickedButton4();
			break;
		case VK_OEM_PLUS:
			if (GetKeyState(VK_SHIFT) < 0)		
				OnBnClickedButton4();			
			else
				OnBnClickedButton15();
			break;
		case VK_OEM_MINUS:
		case VK_SUBTRACT:
			OnBnClickedButton8();
			break;
		case VK_MULTIPLY:
			OnBnClickedButton12();
			break;
		case VK_DIVIDE:
		case VK_OEM_2:
			OnBnClickedButton16();
			break;
		case VK_OEM_PERIOD:
		case VK_DECIMAL:
			OnBnClickedButton14();
			break;

		}
		return FALSE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}

void CCalculatorDlg::OnBnClickedButton22()
{
	string input, output;
	Scanner sc;
	Calculationer ca;
	queue<string> result, ans;

	string str1;
	infile.GetWindowText(m_infile);
	outfile.GetWindowText(m_outfile);
	CT2A s1(m_infile);
	str1 = s1;
	freopen(str1.c_str(), "r", stdin);

	while (cin >> input)
	{
		result = sc.ToStringQueue(input);
		output = ca.ToCalculate(result);
		ans.push(output);
	}

	string str2;
	CT2A s2(m_outfile);
	str2 = s2;
	freopen(str2.c_str(), "w", stdout);

	while (!ans.empty())
	{
		cout << ans.front() << endl;
		ans.pop();
	}
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButton21()
{
	{
		// TODO: Add your control notification handler code here   
		// 设置过滤器   
		TCHAR szFilter[] = _T("文本文件(*.txt)|*.txt|所有文件(*.*)|*.*||");
		// 构造打开文件对话框   
		CFileDialog fileDlg(TRUE, _T("txt"), NULL, 0, szFilter, this);
		CString strFilePath;

		// 显示打开文件对话框   
		if (IDOK == fileDlg.DoModal())
		{
			// 如果点击了文件对话框上的“打开”按钮，则将选择的文件路径显示到编辑框里   
			strFilePath = fileDlg.GetPathName();
			SetDlgItemText(IDC_EDIT2, strFilePath);
		}
	}
}


void CCalculatorDlg::OnBnClickedButton23()
{
	// TODO: 在此添加控件通知处理程序代码
	// TODO: Add your control notification handler code here   
	TCHAR szFilter[] = _T("文本文件(*.txt)|*.txt|Word文件(*.doc)|*.doc|所有文件(*.*)|*.*||");
	// 构造保存文件对话框   
	CFileDialog fileDlg(FALSE, _T("doc"), _T("my"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, this);
	CString strFilePath;

	// 显示保存文件对话框   
	if (IDOK == fileDlg.DoModal())
	{
		// 如果点击了文件对话框上的“保存”按钮，则将选择的文件路径显示到编辑框里   
		strFilePath = fileDlg.GetPathName();
		SetDlgItemText(IDC_EDIT3, strFilePath);
	}
}
