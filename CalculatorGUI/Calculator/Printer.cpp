// Printer.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Calculator.h"
#include "Printer.h"
#include "afxdialogex.h"


// Printer �Ի���

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


// Printer ��Ϣ�������
