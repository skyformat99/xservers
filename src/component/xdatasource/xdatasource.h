// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� XDATASOURCE_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// XDATASOURCE_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef XDATASOURCE_EXPORTS
#define XDATASOURCE_API __declspec(dllexport)
#else
#define XDATASOURCE_API __declspec(dllimport)
#endif

// �����Ǵ� xdatasource.dll ������
class XDATASOURCE_API Cxdatasource {
public:
	Cxdatasource(void);
	// TODO: �ڴ�������ķ�����
};

extern XDATASOURCE_API int nxdatasource;

XDATASOURCE_API int fnxdatasource(void);
