
// lab4c.2.h : ������� ���� ��������� ��� ���������� lab4c.2
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"       // �������� �������


// Clab4c2App:
// � ���������� ������� ������ ��. lab4c.2.cpp
//

class Clab4c2App : public CWinApp
{
public:
	Clab4c2App();


// ���������������
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ����������
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Clab4c2App theApp;
