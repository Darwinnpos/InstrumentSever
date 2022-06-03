#pragma once

#include <iostream>
#include <vector>
#include <map>

using namespace std;

//abstract device
enum class DeviceType
{
	STEP_MOTOR = 0, 
	IO = 1
};


//���ڴ洢����������Ϣ
typedef struct DeviceInfo
{
	string name;
	DeviceType device_type;
	uint8_t board_num;
	uint8_t channel;
}DeviceInfo;

//���ڴ洢һ��������Ϣ
typedef struct GroupDeviceInfo
{
	string name;
	vector <string> single_name;
}GroupDeviceInfo;

//�������������ؽṹ��
//���ڴ洢һ�鲽�����������Ϣ
typedef struct AllSwitchInfo
{
	DeviceInfo reset;
	DeviceInfo limit;
}AllSwitchInfo;

//���ڴ洢һ�鲽�����������Ϣ
typedef struct MotorBaseCfg
{
	bool hardware_dir;
	bool logic_dir;
	AllSwitchInfo allSwitchInfo;
	double RateCurrent;
}MotorBaseCfg;

//���ڴ洢һ�鲽������ٶ���Ϣ
typedef struct MotorSpdCfg
{
	uint8_t Index;
	string spdName;
	map<string, float> paramList;
}MotorSpdCfg;

//Լ��Э���е�ö�ٵ�ֵ
enum class StrType
{
	ACT_MODE_CAN = 0,
	SPD_PARAM_CAN,
	ACT_PARAM,
	SUB_ACT_PARAM
};

enum class StringCode
{
	RUN = 0,
	RUN_BACK,
	ON,
	OFF,
	//spd param
	V_MAX,
	A1,
	A2,
	V_A1A2,
	D1,
	D2,
	V_D1D2,
	V_START,
	V_STOP,
	V_A_CURRENT_OFFSET,
	V_D_CURRENT_OFFSET,
	V_DEFAULT,
	//act param
	ABS_POSITION,
	REL_POSITION,
	ACT_NOW,
	DELAY_TIME,
	DEV_STATE,
	SPEED,
	//sub act param
	SPEED_NUM,
	SPEED_NAME
};

//���ڹ���ӳ��
typedef struct String2Int
{
	string _string;
	StringCode _int;
	StrType strType;
}String2Int;

//���ڴ洢���������Ϣ��һ�������Ϣ�������ٶ���Ϣ
typedef struct MotorCfg
{
	MotorBaseCfg motorBaseCfg;
	vector<MotorSpdCfg> motorAllSpdCfg;
}MotorCfg;

//IOCfg
typedef struct IOConfig
{
	bool direction;
	double responseTimeMs;
}IOConfig;

//Flow struct
//����˳��ṹ
typedef struct Param
{
	string paramName;
	union {
		float f_param;
		uint8_t u8_param;		
	};	
	string str_param;
}Param;

//
typedef struct ActInfo
{
	string actMode;
	vector<Param> actParam;  //�����豸���е�һ�Ѳ���
}ActInfo;

typedef struct DevActInfo
{
	string device_name;
	ActInfo actInfo;         //һ���豸�����������еĲ���
}DevActInfo;

//һ����ʱ������ ֧����һ�����������ִ�� �Ӷ������������Ĳ���
typedef struct subTiming
{
	string name;
	bool nextActRunNow; //֧�ִ��кͲ��� ��nextrun = trueʱ������ִ����һ���� ������������
	vector<DevActInfo> actInfoGroup; //һ���豸���ж���
}subTiming;

typedef struct Timing	
{
	string name;
	//��֧�ֲ���
	vector<subTiming> TimingVec;
}Timing;

typedef struct Flow
{
	string name;
	Timing timing;
}Flow;

typedef struct SpeedMap
{
	string speed_param_name;
	StringCode index;
}SpeedMap;
