#ifndef _XLINK_COMMON_H_
#define _XLINK_COMMON_H_
namespace x {
	enum{
		CONN_STATUS_NOT_CONNECT = 0,
		CONN_STATUS_CONNECTING,
		CONN_STATUS_CONNECTED,
		CONN_STATUS_REGISTED
	};

	//�����Ϻ���Ҫ����һ��ע����Ϣ
	struct FuncReqRegisterBody{
		uint32_t type;			//0:�м�� 1:�ͻ���
		uint32_t sysNo;
		uint32_t subSysNo;
		char appName[32];
		uint32_t appNo;
	};

	struct FuncAnsRegisterBody{
		uint32_t sysNo;
		uint32_t subSysNo;
		char appName[32];
		uint32_t appNo;
		uint32_t connectionID;
	};

}
#endif//_XLINK_COMMON_H_