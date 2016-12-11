#ifndef XDB_SERVICE_INTF_H_
#define XDB_SERVICE_INTF_H_

#include <xbase/os_common.h>
#include <include/xservice_intf.h>
#include <include/xmessage_intf.h>

namespace x {

#define PLUGIN_DB		"xdb"
#define SID_DB			"x.db"

	

	const int XDB_CONNECTION_STATUS_DISCONN                    = 0;//����Ϊ�Ͽ�״̬
	const int XDB_CONNECTION_STATUS_FREE                       = 1;//����Ϊ����״̬
	const int XDB_CONNECTION_STATUS_BUSY                       = 2;//����Ϊæ״̬
	const int XDB_CONNECTION_STATUS_BUSY_AND_DISCONN           = 3;//����Ϊæ���ҶϿ�״̬��

	

	

	struct IDBStatement{
	    ///׼��Ҫ���õ�sql����洢�������
		/**@param  char *sql  ��׼SQL����洢�������(�μ���չ��ICallableStatement�ӿ�)
		*@return 0�ɹ���1ʧ��
		*/
		virtual int   prepare(char * sql) = 0;
	
		///ִ��һ��update,insert,delete,truncate��sql���
		/**@param  sql: һ��update,insert,delete,truncate��sql���
		*@return 0�ɹ���1ʧ��
		*/
		virtual int  exec(void) = 0;

		///ִ��һ��select���
		/**@param   sql: һ����������ص�sql���
		*@return  :�����ָ��
		*/
		virtual IPack * open(void) = 0;
	};
	//Target
	struct IDBConnection{
		virtual int  getConnStatus(void) = 0; 
		virtual IDBStatement * createStatement(void)=0;
		virtual void *  toFree() = 0;
	};
	//���ݿ�ͳһ���ʷ���
	struct IDBService : public IService{
		//virtual IDBConnection* getConnection(int func_id)=0;
		virtual IDBConnection*  getConnection(const char* datasource_name) = 0;
	};
}//namespace

#endif //XDB_SERVICE_INTF_H_
