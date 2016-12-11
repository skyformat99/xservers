#ifndef _XLINK_CONNECTOR_H_
#define _XLINK_CONNECTOR_H_
#include <xbase/os_common.h>
#include "link_common.h"
#include "connection.h"
#include "channel.h"
#include "include/xlink_intf.h"

namespace x {
//һ���е����İ�װ��,����·����Ϣ��
class Connector:public ILinkClient,Connection::Callback{
public:
	class ConnectorCallback {
	public:
		virtual void OnRecv(Connector* conn, IMessage* msg){}
		virtual void OnClose(Connector* conn){}
		virtual void OnConnected(Connector* conn){}
	};
public:
	Connector();
	~Connector(void);
public:
	bool Connect(const char* ip, uint16_t port);
	int Send(IMessage* msg);
protected:
	virtual void OnAccept(Connection* conn,Socket* socket) ;
	virtual void OnConfirm(Connection* conn);
	virtual void OnRecv(Connection* conn, IMessage* msg);
	virtual void OnClose(Connection* conn);
public:
	char			name[128];				//[name]#[id]@[sysNo]#[subSysNo]
	int8_t			direction;				//0:����� 1:���ն�				
	uint32_t		sysNo;
	uint32_t		subSysNo;
	char			appName[32];
	uint32_t		appNo;	
	int32_t			connectionID;
	char			IP[32];		
	uint16_t		port;
	int8_t			status;					//0:����δ���� 1:���ӽ����� 2:�����ѽ��� 3:������ע��
	Connection* connChannel;//Channel Connection* 	conn;
	uint64_t		connectTime;

	ConnectorCallback* callback_;
};
}
#endif//_XLINK_CONNECTOR_H_