#pragma once
#include "connection.h"
#include <include/xdb_intf.h>
#include "connmysqlppadapter.h"
#include "mysql++.h"
using namespace mysqlpp;
namespace x {
class StatementMysqlAdapter:public IDBStatement
{
public:
	StatementMysqlAdapter(Connection* adptee);
	~StatementMysqlAdapter();

	//IDBStatement
	virtual int   prepare(char * sql);

	//ִ������ɾ���ĵȲ�����
	virtual int  exec(void);
	//ִ�в�ѯ���ؽ�����Ȳ���
	virtual IPack * open(void);

	//adaptee

	mysqlpp::Connection* statementadptee;
	mysqlpp::Query adaptee_;
	
};
}

