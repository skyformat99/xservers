// xdatasource.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "xdatasource.h"


// ���ǵ���������һ��ʾ��
XDATASOURCE_API int nxdatasource=0;

// ���ǵ���������һ��ʾ����
XDATASOURCE_API int fnxdatasource(void)
{
	return 42;
}

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� xdatasource.h
Cxdatasource::Cxdatasource()
{
	return;
}
