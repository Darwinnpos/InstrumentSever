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


typedef struct DeviceInfo
{
	string name;
	DeviceType device_type;
	uint8_t channel;
}DeviceInfo;


typedef struct GroupDeviceInfo
{
	string name;
	vector <string> single_name;
}GroupDeviceInfo;


typedef struct SwitchChl
{
	uint8_t reset;
	uint8_t limit;
}SwitchChl;

//step motor
typedef struct MotorBaseCfg
{
	bool hardware_dir;
	bool logic_dir;
	SwitchChl switchChannel;
	double RateCurrent;
}MotorBaseCfg;

typedef struct MotorSpdCfg
{
	uint8_t Index;
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
//这是顺序结构
typedef struct ActInfo
{
	string actMode;
	vector<string> actParam;  //描述设备运行的一堆参数
}ActInfo;

typedef struct DevActInfo
{
	string device_name;
	ActInfo actInfo;         //一个设备的完整的运行的参数
}DevActInfo;

//一个子时序描述 支持下一个步骤的立即执行 从而完成数个步骤的并行
typedef struct subTiming
{
	string name;
	bool nextActRunNow; //支持串行和并行
	vector<DevActInfo> actInfoGroup; //一组设备运行动作
}subTiming;

typedef struct Timing
{
	string name;
	//不支持并行
	vector<subTiming> TimingVec;
}Timing;


typedef struct Flow
{
	string name;
	Timing timing;
}Flow;