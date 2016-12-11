#ifndef XSERVER_SERVICE_INTF_H_
#define XSERVER_SERVICE_INTF_H_

#include <xbase/os_common.h>
#include <xbase/ref_counted.h>
#include <xbase/xml.h>
namespace x {

#define MAX_APP_NAME 128

struct IMessage;
struct IContainer;

//����ӿ�
struct IService : public IRefCounted{

};

//��Ϣ����ӿ�
#define SID_MSG "x.msg"
struct IMsgService : public IService {
	virtual void RegisterPre(IMsgService* service) = 0;
	virtual void RegisterNext(IMsgService* service) = 0;
	virtual void PostMsg(IMessage* msg, IMsgService* from) = 0;
};

//����ע�����ӿ�
#define SID_IOC	"x.ioc"
struct IIocService : public IService {
	virtual void SetContainer(IContainer* container) = 0;
	virtual void SetConfig(XMLElement* config) = 0;
	virtual void SetArg(const char* name, const char* value) = 0;
};

//�������ӿ�
#define SID_MANAGER "x.manager"
#define MANAGER_EVENT_INIT 0
#define MANAGER_EVENT_START 1
#define MANAGER_EVENT_STOP 2
#define	MANAGER_EVENT_UNINIT 3
struct IMngService : public IService {
	virtual void OnEvent(int eventType) = 0;
};

//�������
struct IContainer {
	virtual IService* GetService(const char* plugin, const char* id) = 0;
	virtual IService* GetService(const char* id) = 0;
};

//������Ϣ
struct ServiceInfo {
	const char* id;
	const char* caption;
	const char* version;
};

//�����Ϣ
struct PluginInfo {
	const char* caption;
	const char* version;
};

#define ARGS_WORKSPACE  	"workspace"
#define ARGS_SYS_NO			"sys_no"
#define ARGS_SUB_SYS_NO		"sub_sys_no"
#define ARGS_APP_CFG		"app_config"
#define ARGS_APP_NAME		"app_name"
#define ARGS_APP_NO			"app_no"

//���������������
typedef void (FUNC_CALL * PFGetPluginInfo)(PluginInfo& info);
typedef bool (FUNC_CALL * PFGetServiceInfo)(int index, ServiceInfo& info);
typedef IService* (FUNC_CALL * PFGetService)(const char* id);

}//namespace x

#endif //XSERVER_SERVICE_INTF_H_
