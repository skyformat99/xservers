
#include "datasource.h"

namespace x {
DataSource::DataSource(void)
	:conns_(NULL)
{
}


DataSource::~DataSource(void)
{
	if (conns_)
	{
		delete conns_;
	}
}

 void DataSource ::Init(DSArgs* args){
	 conns_ =new x::ConnPool();
	 conns_->InitConnection(args);
     //�����̼߳������
 }
 IDBConnection* DataSource ::GetConn(){

	 if (conns_ == NULL){
		 return NULL;
	 }
	 //����ѭ����ֱ��ȡ��Ϊֹ
	return conns_->getConn();
 }
}
