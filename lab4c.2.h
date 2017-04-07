
// lab4c.2.h : главный файл заголовка для приложения lab4c.2
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// Clab4c2App:
// О реализации данного класса см. lab4c.2.cpp
//

class Clab4c2App : public CWinApp
{
public:
	Clab4c2App();


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Clab4c2App theApp;
