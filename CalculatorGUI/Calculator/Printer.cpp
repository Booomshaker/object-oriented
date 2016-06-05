// Printer.cpp : 实现文件
//

#include "stdafx.h"
#include "Calculator.h"
#include "Printer.h"
#include "afxdialogex.h"


// Printer 对话框

IMPLEMENT_DYNAMIC(Printer, CDialogEx)

Printer::Printer(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
{

}

Printer::~Printer()
{
}

void Printer::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Printer, CDialogEx)
END_MESSAGE_MAP()


// Printer 消息处理程序
