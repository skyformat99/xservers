#ifndef LINKSERVERARG_H_
#define LINKSERVERARG_H_


namespace x{
	struct LinkServerArgs{

		char appName[32];
		uint32_t appNo;

		//net
		char ip[32];
		uint16_t port;

		//other
		uint32_t threadNum; //�����߳���
		uint32_t init_connNum;//���ӳ�
		uint32_t max_connNum;//������ӳ�

		uint32_t init_RecvBuffSize;//���ջ����С
		uint32_t init_SendBuffSize;//���ͻ����С
		uint32_t init_SendQueueSize;//���ͳش�С

		bool enable_accept_thread; //�������ӵ��̶߳���
		bool enable_quick_ack; //TCP����ȷ��
	};

	struct LinkClientArgs{

		char appName[32];
		uint32_t appNo;

		//net
		//char ip[32];
		//uint16_t port;

		//other
		uint32_t threadNum; //�����߳���
		uint32_t init_connNum;//���ӳ�
		uint32_t max_connNum;//������ӳ�

		uint32_t init_RecvBuffSize;//���ջ����С
		uint32_t init_SendBuffSize;//���ͻ����С
		uint32_t init_SendQueueSize;//���ͳش�С

	};
}

#endif//LINKSERVERARG_H_