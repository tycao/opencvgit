
// my_mfc2.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Cmy_mfc2App: 
// �йش����ʵ�֣������ my_mfc2.cpp
//

class Cmy_mfc2App : public CWinApp
{
public:
	Cmy_mfc2App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Cmy_mfc2App theApp;