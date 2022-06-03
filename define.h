#pragma once

#include <iostream>
#include <vector>
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
	double VMax;
	double A1;
	double A2;
	double V_A1A2;
	double D1;
	double D2;
	double V_D1D2;
	double VStart;
	double VStop;
	double ACurrentOffset;//Acceleration current compensation coefficient, default is 1
	double DCurrentOffset;
}MotorSpdCfg;

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
typedef struct ActInfo
{
	string actMode;
	vector<string> actParam;  //�����豸���е�һ�Ѳ���
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
	bool nextActRunNow; //֧�ִ��кͲ���
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