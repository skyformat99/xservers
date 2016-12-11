///���ݿ���������ӿڶ���(���ݿ������ӿڹ淶)
/*******************************************************
  Դ��������:DefDriver.h
  �������Ȩ:���ݺ������ӹɷ����޹�˾
  ϵͳ����:  ���ݿ�ͳһ����-���ݿ����� 
  ģ������:  ���ݿ���������ӿڶ���
  ����˵��:  �����������ݿ������������ʵ�ֵĽӿں��� 
  ����ĵ�:  ��Ҫ��ƽӿڲ���
  ��    ��:  ������
  ��������:  20040509
  ��    ע:  
    �޸���Ա��dongpf
	�޸�ʱ�䣺2009-09-21
	�޸�˵��������Oracle rac�л�ģʽ����
    20140915 huxb ֧������
    20141215 huxb ���ӽ���������浽������ؽӿ�
	20150203 huxb ���ӷ��������ͻ�ȡ���ִ�е�sql�Ľӿ�
*********************************************************/     
#ifndef DefDriver_H
#define DefDriver_H


#ifdef PLATFORM_UNIX
	#define DLL_EXPORT
#else
	#define DLL_EXPORT  __declspec(dllexport)
#endif

///�������ش�����
typedef void (*fpHasError)(void * errOwner,int HSErrint,int err ,const char * errinfo);
///����������Ϣ����
typedef void (*fpHasMessage)(void * msgOwner,int HSMsgno,int msgno,const char * msgtext);

//--------��������-------------
#define  HSDB_NO                 1         ///��,û��
#define  HSDB_YES                0         ///�϶�,��,���� 
#define  HSDB_SUCESS             0         //����ɹ�
#define  HSDB_FAILURE            1         //����ʧ��
#define  HSDB_TRUE               1         //true
#define  HSDB_FALSE              0         //false
#define  HSDB_WASNULL            1000      ///��¼����NULL����
#define  HSDB_SELECT             1001      ///��ʾ��ִ��select
#define  HSDB_PROCESS            1002      ///��ʾִ�е��Ǵ洢����
#define  HSDB_PARAM_INPUT         1003      /// ����Ϊ�������
#define  HSDB_PARAM_OUTPUT       1004      ///����Ϊ�������   
#define  HSDB_TEMPDATASOURCE     1005      ///��ʱ����Դ
#define  HSDB_NOTTEMPDATASOURCE  1006      ///����ʱ����Դ
#define  HSDB_CONNECT_DISCONN    1007      //�����������ӶϿ�
#define  HSDB_CONNECT_OK         1009      //����������������
#define  HSDB_NO_MORE_ROWS       1008      //�Ѿ�û�м�¼��
#define  HSDB_END_PARAM          -1        //���̲���������־
#define  HSDB_DRIVER_DATATYPE_STRING    'S'         //��������Ϊstring C��׼���ַ��� 
#define  HSDB_DRIVER_DATATYPE_CHAR      'C'         //��������Ϊchar
#define  HSDB_DRIVER_DATATYPE_LONG      'I'        //��������Ϊlong
#define  HSDB_DRIVER_DATATYPE_DOUBLE    'D'         //��������Ϊdouble
#define  HSQL_DRIVER_DATATYPE_BINARY    'R'         //�������������
#define  HSDB_APPLICATION_NAME   "FINBASE_AS"//Ӧ����
#define  HSDB_ERRINFO_LENGTH     200         //������Ϣ����

//2009-09-21 dongpf ����Oracle rac�л�ģʽ����
#define  HSDB_SERVERTYPE_NONE     0         //��rac�л�ģʽ
#define  HSDB_SERVERTYPE_SELECT   1         //selectģʽ
#define  HSDB_SERVERTYPE_SESSION  2         //sessionģʽ
//-------------------------------

///���ݿ����Ӿ������(����������Ӧ���ж���HSQLHANDLE���)
#ifndef HSQLHANDLE
	#define HSQLHANDLE void *
#endif

///���ݿ����������(����������Ӧ���ж���HSQLHANDLE���)
#ifndef STMT_HANDLE
	#define STMT_HANDLE void *
#endif

/**@name ������ӿں���ָ�붨��*/
//@{
    typedef void (* fpHSQLSetUpErrorHandle)(fpHasError  errhandle);
    typedef  void (* fpHSQLSetUpMsgHandle)(fpHasMessage  msghandle);
	typedef void (*fpHSQLFreeMemory)(void * param);
	typedef int (*fpHSQLGetInfo)(char ** dbType);
	typedef int (*fpHSQLInit)(void ** context);

	typedef HSQLHANDLE (*fpHSQLInitHandle)(void * context,void * owner);
	typedef void (*fpHSQLFreeHandle)(HSQLHANDLE hp);
	typedef int (*fpHSQLConnect)( HSQLHANDLE hp,char * username,char *password,char * server,char * database);
	typedef int (*fpHSQLDisconnect)( HSQLHANDLE hp);
    typedef STMT_HANDLE (*fpHSQLAllocStmt)(HSQLHANDLE hp);
    typedef void (*fpHSQLFreeStmt)(HSQLHANDLE hp,STMT_HANDLE pStmt);
    typedef int (* fpHSQLPrepare)(STMT_HANDLE pStmt,const char * StatementText, int TextLen);
    typedef int (* fpHSQLExecute)(STMT_HANDLE pStmt);
    typedef int (* fpHSQLOpen)(STMT_HANDLE pStmt);
    typedef int (* fpHSQLResult)(STMT_HANDLE pStmt,int SelecOrProce);

    typedef int (* fpHSQLNumResultCols)(STMT_HANDLE pStmt,int SelecOrProce,int * ColumnCountPtr);
    typedef int (* fpHSQLColName)(STMT_HANDLE pStmt,int SelecOrProce,int indexCol,char  namebuffer[]);
    typedef char (* fpHSQLColType)(STMT_HANDLE pStmt,int SelecOrProce,int indexCol);
    typedef int (* fpHSQLColLen)(STMT_HANDLE pStmt,int SelecOrProce,int indexCol);
    typedef int ( * fpHSQLColPrecision)(STMT_HANDLE pStmt,int SelecOrProce,int indexCol);
    typedef int ( * fpHSQLColScale)(STMT_HANDLE pStmt,int SelecOrProce,int indexCol);
    typedef int (* fpHSQLColIsNull)(STMT_HANDLE pStmt,int SelecOrProce,int indexCol);
    typedef int (* fpHSQLDefineCol)(STMT_HANDLE pStmt,int SelecOrProce,int indexCol,void * buff,int len);
    typedef int (* fpHSQLNext)(STMT_HANDLE pStmt,int SelecOrProce);
	typedef int (*fpHSQLRpcPrepare)(STMT_HANDLE pStmt ,int YorNForResult, char * sql);
	typedef int (*fpHSQLExecuteStoreProcess)(STMT_HANDLE hp ,int YorNForResult,int iRetExits, char * p_storeName, int *type,int * inOroutType,void  ** p_ProParamUnion);
	typedef int (*fpHSQLDbretdata)(STMT_HANDLE pStmt,int iRetExist, int *type,int * inOroutType,void  ** p_ProParamUnion);

    typedef int ( * fpHSQLCancels)(STMT_HANDLE hp);
    typedef int (* fpHSQLCount)(STMT_HANDLE pStmt);

	typedef int (* fpHSQLGetServerType)(const char * ServerName);

	typedef void * (* fpHSQLGetSQLContext)(HSQLHANDLE hp);

	typedef int (* fpHSQLBindByPos)(STMT_HANDLE pStmt,int iIndex,void * pData,int iDataLen,char cDataType);

    //huxb 20140915 ����֧��
    typedef int (* fpHSQLSetAutoCommit)(HSQLHANDLE hp, bool bAutoCommit);
    typedef int (* fpHSQLCommit)(HSQLHANDLE hp);
    typedef int (* fpHSQLRollback)(HSQLHANDLE hp);
    //huxb 20141215 ��������������
    typedef int (* fpHSQLOpenAll)(STMT_HANDLE pStmt, int * lpCount);
    typedef int (* fpHSQLExecuteStoreProcess2)(STMT_HANDLE hp ,int YorNForResult,int iRetExits, char * p_storeName, int *type,int * inOroutType,void  ** p_ProParamUnion, int * lpCount);
	//huxb 20140203 ��������
	typedef int (* fpHSQLHeartbeat)(STMT_HANDLE hp);
	//��ȡ���ִ�е�SQL
	typedef const char * (* fpHSQLGetLastSQL)(STMT_HANDLE hp);
//@}


#ifdef __cplusplus
extern "C" { 
#endif

///20150203 huxb
///��ȡ���ִ�е�SQL
/**
*@param HSQLHANDLE hp  ���ݿ����Ӿ��
*@return int 0�ɹ�����0ʧ��
*/ 
DLL_EXPORT const char * HSQLGetLastSQL(HSQLHANDLE hp); 

///��������
/**
*@param HSQLHANDLE hp  ���ݿ����Ӿ��
*@return int 0�ɹ�����0ʧ��
*/ 
DLL_EXPORT int HSQLHeartbeat(HSQLHANDLE hp); 

///20140915 huxb
///�����Զ��ݽ���Ĭ���Զ��ݽ���
/**
*@param HSQLHANDLE hp  ���ݿ����Ӿ��
*@param bool bAutoCommit  �Ƿ��Զ��ݽ�
*@return int �ɹ����0�ɹ�����0ʧ��
*/ 
DLL_EXPORT int HSQLSetAutoCommit( HSQLHANDLE hp, bool bAutoCommit = true); 

///�ύ����
/**
*@param HSQLHANDLE hp  ���ݿ����Ӿ��
*@return int �ɹ����0�ɹ�����0ʧ��
*/ 
DLL_EXPORT int HSQLCommit( HSQLHANDLE hp);

///����ع�
/**
*@param HSQLHANDLE hp  ���ݿ����Ӿ��
*@return int �ɹ����0�ɹ�����0ʧ��
*/ 
DLL_EXPORT int HSQLRollback( HSQLHANDLE hp);

///20141215 huxb
///ִ��select��䣬�����ؽ��������
/**
*@param HSQLHANDLE hp  ���ݿ����Ӿ��
*@param int * lpCount ���ؽ��������
*@return int �ɹ����0�ɹ�����0ʧ��
*/ 
DLL_EXPORT int HSQLOpenAll( STMT_HANDLE pStmt, int * lpCount);

/**ִ�д洢����(����н���������ȫ�����浽���أ������ؽ��������)
 *@param   STMT_HANDLE pStmt �����
 *@param   int YorNForResult  ��ʾ�����޽����:HSQL_NO,HSQL_YES
 *@param char * p_storeName �洢������ 
 *@param int * type     �������� ���������ַ
 *@param int * inOroutType ���������������ʶ
 *@param void ** p_ProParamUnion ���������������ַ
 *@param int * lpCount ���ؽ��������
 *@return int   HSQLSUCCEED �ɹ�  HSQLFAILʧ��������
 */
DLL_EXPORT int HSQLExecuteStoreProcess2(STMT_HANDLE pStmt ,int YorNForResult,int iRetExist, char * p_storeName,int *type,int * inOroutType,void ** p_ProParamUnion, int * lpCount);

///���ô�����ص�����
DLL_EXPORT void HSQLSetUpErrorHandle(fpHasError errhandle);
///������Ϣ����ص�����
DLL_EXPORT void HSQLSetUpMsgHandle(fpHasMessage  msghandle);

///�ͷ���������������ڴ�ռ�
/**���������Ϊ�ַ�����ʱ���ַ����Ŀռ���������������ģ��������⸺���ͷ�
 *@param void * p ����������������ڴ�ָ��
 */
DLL_EXPORT void  HSQLFreeMemory(void * p);

/**ȡ���ݿ������ӿڿ���Ϣ
 * @param  char ** dbType  ��ǰ�ӿڿ��Ӧ�����ݿ����ʹ�������������һ��ָ�룬�˺������޸�ָ��ָ��
 * @return int             ���ؽӿڿ�汾��
 */
DLL_EXPORT int  HSQLGetInfo(char ** dbType);

///���ݿ�ӿڿ��ʼ��,�ӿڿ���غ�Ӧ���ȵ��ô˺���.
/**@param void ** context:������������ָ���ַ(sybase�õ�)
 *@return int   HSQLSUCCEED �ɹ�  HSQLFAILʧ��
 */
DLL_EXPORT int HSQLInit(void ** context);

///�������ݿ����Ӿ����Ϊ��������Ӧ�Ĵ洢�ռ�
/**
 *@param context ������������ָ��
 *@param void * owner  ����ʹ����ָ�룬���ﴦ��ص�������Ҫ��ָ����Ϊ�ص�����(��������Ӧ����)
 *@return  HSQLHANDLE  ���ݿ����Ӿ��,����NULL��ʾ����ʧ��
 */
DLL_EXPORT HSQLHANDLE HSQLInitHandle(void * lpContext,void * owner);

///�ͷ����ݿ����Ӿ��
/**
 *@param HSQLHANDLE p_db_handle  ���Ӿ��
 */
DLL_EXPORT void HSQLFreeHandle(HSQLHANDLE p_db_handle);

///�������ݿ�	
/**ʹ�ø����������������ݿ������
 *@param HSQLHANDLE hp  ���ݿ����Ӿ��
 *@param  char * username  ���ݿ��û���
 *@param  char * password  ����
 *@param  char * server    ���ݿ�ͻ������õ����ݿ����
 *@param  char * database  ��ǰ����ȱʡ���ݿ���(��sql server,sybaseʱ������)
 *@return int   HSQLSUCCEED ����  HSQLFAILʧ��
 */
DLL_EXPORT int HSQLConnect( HSQLHANDLE hp,char * username,char *password,char * server,char * database); 

///�Ͽ����ݿ�����
/**
 *@param HSQLHANDLE hp  ���ݿ����Ӿ��
 *@return int   HSQLSUCCEED ����  HSQLFAILʧ��
 */ 
DLL_EXPORT int HSQLDisconnect( HSQLHANDLE hp); 

/**��������� ����oracle��sql server�������ָ������ݽṹ��������Ӿ����
 *@param    HSQLHANDLE hp  ���ݿ����Ӿ��
 *@return   STMT_HANDLE �����
 */
DLL_EXPORT STMT_HANDLE HSQLAllocStmt (HSQLHANDLE hp);

/**�ͷ������
 *@param   HSQLHANDLE hp  ���ݿ����Ӿ��
 *@param   STMT_HANDLE ���ͷ������
 */
DLL_EXPORT void HSQLFreeStmt(HSQLHANDLE hp,STMT_HANDLE pStmt);

/**׼��SQL���
 *@param   STMT_HANDLE �����
 *@param   char * StatementText ����ַ�����ַ
 *@param   int TextLen  ��䳤��
 *@return int   HSQLSUCCEED �ɹ�  HSQLFAILʧ��
 */
DLL_EXPORT int HSQLPrepare(STMT_HANDLE pStmt,char * StatementText, int TextLen);

/**ִ��׼���õ�sql���(�޽�������ص�sql���,����select ���)
 *@param   STMT_HANDLE �����
 *@return int   HSQLSUCCEED �ɹ�  HSQLFAILʧ��
 */
DLL_EXPORT int HSQLExecute (STMT_HANDLE pStmt);

/**ִ��׼���õ�select ���
 *@param   STMT_HANDLE �����
 *@return int   HSQLSUCCEED �ɹ�  HSQLFAILʧ��
 */
DLL_EXPORT int HSQLOpen (STMT_HANDLE pStmt);

/** @name ������������� */
//@{

/**�򿪽������ȡ����һ����¼
 *@param   STMT_HANDLE pStmt �����
 *@param   int SelecOrProce  ��ʾ��ȡselect�Ľ�������Ǵ洢���̷��صĽ����:HSDB_SELECT,HSDB_PROCESS
 *@return int   HSQLSUCCEED �ɹ�  HSQLFAILʧ��������
 */
DLL_EXPORT int HSQLResult(STMT_HANDLE pStmt,int SelecOrProce);

/**ȡ������ֶ���
 *@param   STMT_HANDLE pStmt �����
 *@param   int SelecOrProce  ��ʾ��ȡselect�Ľ�������Ǵ洢���̷��صĽ����:HSDB_SELECT,HSDB_PROCESS
 *@param   int * ColumnCountPtr �����ֶ���
 *@return int   HSQLSUCCEED �ɹ�  HSQLFAILʧ��
 */
DLL_EXPORT int HSQLNumResultCols(STMT_HANDLE pStmt,int SelecOrProce,int * ColumnCountPtr);

/**ȡ������ֶ���
 *@param   STMT_HANDLE pStmt �����
 *@param   int SelecOrProce  ��ʾ��ȡselect�Ľ�������Ǵ洢���̷��صĽ����:HSDB_SELECT,HSDB_PROCESS
 *@param   int  indexCol    �ֶ����(��1Ϊ����)
  *@param   char * namebuffer �ֶ���buffer  �ռ������洴��
 *@return  char * �ֶ���
 */
DLL_EXPORT int HSQLColName(STMT_HANDLE pStmt,int SelecOrProce,int indexCol,char  namebuffer[]);

/**ȡ������ֶ���������
 *@param   STMT_HANDLE pStmt �����
 *@param   int SelecOrProce  ��ʾ��ȡselect�Ľ�������Ǵ洢���̷��صĽ����:HSDB_SELECT,HSDB_PROCESS
 *@param   int  indexCol    �ֶ����(��1Ϊ����)
 *@return  char  �������� 
 */
DLL_EXPORT char HSQLColType(STMT_HANDLE pStmt,int SelecOrProce,int indexCol);

/**ȡ������ֶγ���
 *@param   STMT_HANDLE pStmt �����
 *@param   int SelecOrProce  ��ʾ��ȡselect�Ľ�������Ǵ洢���̷��صĽ����:HSDB_SELECT,HSDB_PROCESS
 *@param   int  indexCol    �ֶ����(��1Ϊ����)
 *@return  int  �����ֶ���󳤶�,������-1(�±�Խ��);
 */
DLL_EXPORT int HSQLColLen(STMT_HANDLE pStmt,int SelecOrProce,int indexCol);
	
/**ȡ�ֶξ���
 *@param   STMT_HANDLE pStmt �����
 *@param   int SelecOrProce  ��ʾ��ȡselect�Ľ�������Ǵ洢���̷��صĽ����:HSDB_SELECT,HSDB_PROCESS
 *@param   int  indexCol    �ֶ����(��1Ϊ����)
 *@return  int  �±�Խ�����ʧ�ܷ��� -1;
 */
DLL_EXPORT  int HSQLColPrecision(STMT_HANDLE pStmt,int SelecOrProce,int indexCol);

/**ȡ�ֶ�С��λ��
 *@param   STMT_HANDLE pStmt �����
  *@param   int SelecOrProce  ��ʾ��ȡselect�Ľ�������Ǵ洢���̷��صĽ����:HSDB_SELECT,HSDB_PROCESS
 *@param   int  indexCol    �ֶ����(��1Ϊ����)
 *@return  int  �±�Խ�����ʧ�ܷ��� -1;
 */
DLL_EXPORT int HSQLColScale(STMT_HANDLE pStmt,int SelecOrProce,int indexCol);

/**ȡ�ֶ�ȡֵ�Ƿ����ΪNULL
 *@param   STMT_HANDLE pStmt �����
  *@param   int SelecOrProce  ��ʾ��ȡselect�Ľ�������Ǵ洢���̷��صĽ����:HSDB_SELECT,HSDB_PROCESS
 *@param   int  indexCol    �ֶ����(��1Ϊ����)
 *@return  int  0 ������ ,1 ����,�±�Խ�����ʧ�ܷ��� -1;
 */
DLL_EXPORT int HSQLColIsNull(STMT_HANDLE pStmt,int SelecOrProce,int indexCol);


/**���ֶΣ�Ϊ��������������ַ�����ʽ��
 *@param   STMT_HANDLE pStmt �����
 *@param   int SelecOrProce  ��ʾ��ȡselect�Ľ�������Ǵ洢���̷��صĽ����:HSDB_SELECT,HSDB_PROCESS
 *@param   int  indexCol    �ֶ����(��1Ϊ����)
 *@param   void * buff      ����ַ���������
 *@param   int len          ����ַ�����󳤶�
 *@return int   HSQLSUCCEED �ɹ�  HSQLFAILʧ��
 */
DLL_EXPORT int HSQLDefineCol(STMT_HANDLE pStmt,int SelecOrProce,int indexCol,void * buff,int len);

/**ȡһ����¼���ֶ�ֵ��������󶨵Ļ�����
 *@param   STMT_HANDLE pStmt �����
 *@param   int SelecOrProce  ��ʾ��ȡselect�Ľ�������Ǵ洢���̷��صĽ����:HSDB_SELECT,HSDB_PROCESS
 *@return int   HSQLSUCCEED �ɹ�  HSQLFAILʧ��������
 */
DLL_EXPORT int HSQLNext(STMT_HANDLE pStmt,int SelecOrProce);

//@}

/**���ô洢���̵�׼��
 *@param   STMT_HANDLE pStmt �����
 *@param   int YorNForResult  ��ʾ�����޽����: :HSQL_NO,HSQL_YES
 *@param   char * sql   ���ô洢�������:�Ը�ʽҪ������:
 *
 *��return��
 *
 *"? = call StoreProName(?,?,?,?)"  
 *
 *
 *˵��: ��һ���ʺŴ���returnֵ��ռλ��
 *
 *						      ��С�����е��ʺŴ���������������ռλ��.����Ҫ��
 *
 *							  ������ʵ�����������.
 *
 *���û�з���ֵ�򲻹��ķ���ֵ ,�����sql���ӦΪ:
 *
 *						 " call StoreProName(?,?,?,?)"
 *
 *@return int   HSQLSUCCEED �ɹ�  HSQLFAILʧ��������
 */
DLL_EXPORT int HSQLRpcPrepare(STMT_HANDLE pStmt,int YorNForResult,char * sql);

/**ִ�д洢����
 *@param   STMT_HANDLE pStmt �����
 *@param   int YorNForResult  ��ʾ�����޽����:HSQL_NO,HSQL_YES
 *@param char * p_storeName �洢������ 
 *@param int * type     �������� ���������ַ
 *@param int * inOroutType ���������������ʶ
 *@param void ** p_ProParamUnion ���������������ַ
 *@return int   HSQLSUCCEED �ɹ�  HSQLFAILʧ��������
 */
DLL_EXPORT int HSQLExecuteStoreProcess(STMT_HANDLE pStmt ,int YorNForResult,int iRetExist, char * p_storeName,int *type,int * inOroutType,void ** p_ProParamUnion);

/**���н����������»�ô洢����return ֵ ���������
 *@param   STMT_HANDLE pStmt �����
 *@param  int iRetExist ָ���Ƿ����returnֵ
 *@param int * type     �������� ���������ַ
 *@param int * inOroutType ���������������ʶ
 *@param void ** p_ProParamUnion ���������������ַ
 *@return int   HSQLSUCCEED �ɹ�  HSQLFAILʧ��������
 */
DLL_EXPORT int HSQLDbretdata(STMT_HANDLE  s_handle,int iRetExist,int *type,int * inputtype,void ** p_ProParamUnion);

/**Cancels the current command batch and flushes any pending results.
 *@param   STMT_HANDLE pStmt �����
 *@return  int   HSQLSUCCEED �ɹ�  HSQLFAILʧ��
 */
DLL_EXPORT int HSQLCancels(STMT_HANDLE pStmt);
/**ȡ��ǰ���Ӱ��ļ�¼����
 *@param   STMT_HANDLE pStmt �����
 *@return  ��ǰ���Ӱ��ļ�¼����
 */
DLL_EXPORT int HSQLCount(STMT_HANDLE pStmt);

/**���ݷ�����ȡ��������
 *@param   const char * ServerName ������
 *@return  �������ͣ��Ҳ�������-1
 */
DLL_EXPORT int HSQLGetServerType(const char * ServerName);

/**@name ����Ϊzly�����ýӿ� */
//@{
	///��λ�ð󶨣��ɵ�����׼���ռ�
	DLL_EXPORT int HSQLBindByPos(STMT_HANDLE pStmt,int iIndex,void * pData,int iDataLen,char cDataType);	
	///ִ�д洢����
	DLL_EXPORT int HSQLExecRPC(STMT_HANDLE pStmt);

	///��ȡǶ��SQL��������������
	/**
	 *@param HSQLHANDLE p_db_handle  ���Ӿ��
	 */
	DLL_EXPORT void *  HSQLGetSQLContext(HSQLHANDLE p_db_handle);
	
//@}
	
 

#ifdef __cplusplus
  }
#endif

#endif
