#ifndef XLINK_LINKFACTORY_H_
#define XLINK_LINKFACTORY_H_


#include "event_dispatch.h"
#include "eventthreadpool.h"
#include "include/xlink_intf.h"
#include "connector.h"
namespace x{

	class LinkFactory:public ILinkClientApi
	{
	public:
		LinkFactory(void);
		~LinkFactory(void);
	public:
		//LinkClientApi
		virtual IMessage* NewMessage() ;
		virtual IPack* NewPack() ;

		virtual int Init(LinkClientArgs& args) ;
		virtual int UnInit() ;

		virtual ILinkClient* NewLinkClient(LinkClientCallback* callback);

	protected:
		//ConnectorCallback

	private:
		EventThreadPool* threadpool_;
	    //���ӳأ��ݲ��������û��Լ�������
	};
}
#endif // !XLINK_LINKFACTORY_H_

