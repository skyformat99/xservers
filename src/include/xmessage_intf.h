#ifndef X_PLUGIN_XMESSAGE_XMESSAGE_INTF_H_
#define X_PLUGIN_XMESSAGE_XMESSAGE_INTF_H_

#include <xbase/os_common.h>
#include <include/xservice_intf.h>

namespace x {
	
#define PLUGIN_MESSAGE		"xconnection"
#define SID_MESSAGE			"x.message"

//Pack�������Ͷ���
enum {
	PACK_COL_TYPE_UNKOWN = -1,
	PACK_COL_TYPE_UINT8,
	PACK_COL_TYPE_UINT16,
	PACK_COL_TYPE_UINT32,
	PACK_COL_TYPE_INT8,
	PACK_COL_TYPE_INT16,
	PACK_COL_TYPE_INT32,
	PACK_COL_TYPE_DOUBLE,
	PACK_COL_TYPE_STR,
	PACK_COL_TYPE_RAW
};

//Message�����Ͷ���
enum {
	MSG_TAG_ROUTE_SRC	= 0,	
	MSG_TAG_ROUTE_DEST,
	MSG_TAG_ROUTE_INTERNAL,
	MSG_TAG_FUNC_INFO,
	MSG_TAG_FUNC_BODY
};

//���ܺ����Ͷ���
enum {
	MSG_FUNC_TYPE_REQ = 0,
	MSG_FUNC_TYPE_ANS
};

//�����붨��
enum{
	MSG_RETURN_CODE_ERR_TRANSFORM = -2,
	MSG_RETURN_CODE_ERR_SYSTEM,
	MSG_RETURN_CODE_OK,
	MSG_RETURN_CODE_ERR
};

//ϵͳ���ܺŶ���(0~1000)
enum {
	FUNC_REGISTER_CONNECTION = 0
};

struct MsgRoute{
	uint32_t	sysNo;				//ϵͳ��
	uint32_t	subSysNo;			//��ϵͳ��
	char		appName[32];		//Ӧ����
	uint32_t    appNo;				//Ӧ�ñ��
	int32_t		connectionID;		//���ӱ��
	char		plugin[32];			//�����
};

struct MsgFuncInfo{
	uint32_t sysNo;
	uint32_t subSysNo;
	uint32_t funcID;
	uint32_t type;					//0 �����, 1 Ӧ���
	uint32_t sendID;
	int32_t	 returnNo;				//0 ����, -1 ϵͳ����, -2 ת������
};


struct IPack : public IRefCounted{
	virtual bool SetBuff(void* buff, uint32_t len) = 0;
	virtual bool GetBuff(void** buff, uint32_t* len) = 0;
	
	virtual void Clear() = 0;
	virtual void BeginPack() = 0;
	virtual void EndPack() = 0;

	virtual void AddCol(const char* name, int8_t type = PACK_COL_TYPE_STR) = 0;
	virtual uint32_t GetColCount() = 0;
	virtual const char* GetColName(uint32_t col) = 0;
	virtual int8_t GetColType(uint32_t col) = 0;

	virtual void AddRow() = 0;
	virtual uint32_t GetRowCount() = 0;
	
	virtual void AddValue(const char* name, uint8_t value) = 0;
	virtual void AddValue(const char* name, uint16_t value) = 0;
	virtual void AddValue(const char* name, uint32_t value) = 0;
	virtual void AddValue(const char* name, int8_t value) = 0;
	virtual void AddValue(const char* name, int16_t value) = 0;
	virtual void AddValue(const char* name, int32_t value) = 0;
	virtual void AddValue(const char* name, double value) = 0;
	virtual void AddValue(const char* name, char* value) = 0;
	virtual void AddValue(const char* name, void* value, uint32_t len) = 0;

	virtual uint8_t GetValueUint8(const char* name, uint32_t row = 0) = 0;
	virtual uint16_t GetValueUint16(const char* name, uint32_t row = 0) = 0;
	virtual uint32_t GetValueUint32(const char* name, uint32_t row = 0) = 0;
	virtual int8_t GetValueInt8(const char* name, uint32_t row = 0) = 0;
	virtual int16_t GetValueInt16(const char* name, uint32_t row = 0) = 0;
	virtual int32_t GetValueInt32(const char* name, uint32_t row = 0) = 0;
	virtual double GetValueDouble(const char* name, uint32_t row = 0) = 0;
	virtual char* GetValueStr(const char* name, uint32_t row = 0) = 0;
	virtual void* GetValueRaw(uint32_t* len, const char* name, uint32_t row = 0) = 0;
	
	virtual uint8_t GetValueUint8(uint32_t col, uint32_t row) = 0;
	virtual uint16_t GetValueUint16(uint32_t col, uint32_t row) = 0;
	virtual uint32_t GetValueUint32(uint32_t col, uint32_t row) = 0;
	virtual int8_t GetValueInt8(uint32_t col, uint32_t row) = 0;
	virtual int16_t GetValueInt16(uint32_t col, uint32_t row) = 0;
	virtual int32_t GetValueInt32(uint32_t col, uint32_t row) = 0;
	virtual double GetValueDouble(uint32_t col, uint32_t row) = 0;
	virtual char* GetValueStr(uint32_t col, uint32_t row) = 0;
	virtual void* GetValueRaw(uint32_t* len, uint32_t col, uint32_t row) = 0;
};

struct IMessage : public IRefCounted{
	virtual bool SetBuff(void* data, uint32_t len) = 0;
	virtual bool GetBuff(void** data, uint32_t* len) = 0;
	
	virtual bool SetData(uint32_t tagID, void* data, uint32_t len, int32_t type=-1) = 0;
	virtual bool AddData(uint32_t tagID, void* data, uint32_t len, int32_t type=-1) = 0;
	virtual uint32_t GetDataCount(uint32_t tagID) = 0;
	virtual bool GetData(uint32_t tagID, void** data, uint32_t* len, int32_t* type = NULL, uint32_t index = 0) = 0;
	virtual bool DataExist(uint32_t tagID) = 0;
	virtual void RemoveData(uint32_t tagID) = 0;
	virtual void Clear() = 0;

	virtual void ChangeReq2Ans() = 0;

	virtual void SetSysNo(uint32_t sysNo) = 0;
	virtual bool GetSysNo(uint32_t* sysNo) = 0;
	virtual void SetSubSysNo(uint32_t subSysNo) = 0;
	virtual bool GetSubSysNo(uint32_t* subSysNo) = 0;
	virtual void SetFuncID(uint32_t funcID) = 0;
	virtual bool GetFuncID(uint32_t* funcID) = 0;
	virtual void SetFuncType(uint32_t funcType) = 0;
	virtual bool GetFuncType(uint32_t* funcType) = 0;
	virtual void SetSendID(uint32_t sendID) = 0;
	virtual bool GetSendID(uint32_t* sendID) = 0;
	virtual void SetReturnID(int32_t returnID) = 0;
	virtual bool GetReturnID(int32_t* returnID) = 0;	
};

struct IMessageService : public IService {
	virtual IMessage* NewMessage() = 0;
	virtual IPack* NewPack() = 0;
};

}//namespace x


#endif //X_PLUGIN_XMESSAGE_XMESSAGE_INTF_H_