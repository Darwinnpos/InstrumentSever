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

//用于存储单个器件信息
typedef struct DeviceInfo
{
	string name;
	DeviceType device_type;
	uint8_t board_num;
	uint8_t channel;
}DeviceInfo;

//用于存储一组器件信息
typedef struct GroupDeviceInfo
{
	string name;
	vector <string> single_name;
}GroupDeviceInfo;

//步进电机配置相关结构体
//用于存储一组步进电机开关信息
typedef struct AllSwitchInfo
{
	DeviceInfo reset;
	DeviceInfo limit;
}AllSwitchInfo;

//用于存储一组步进电机基础信息
typedef struct MotorBaseCfg
{
	bool hardware_dir;
	bool logic_dir;
	AllSwitchInfo allSwitchInfo;
	double RateCurrent;
}MotorBaseCfg;

//用于存储一组步进电机速度信息
typedef struct MotorSpdCfg
{
	uint8_t Index;
	string spdName;
	map<string, float> paramList;
}MotorSpdCfg;

//用于构建映射
typedef struct String2Int
{
	string _string;
	uint8_t _int;
}String2Int;

//用于存储步进电机信息，一组基础信息，多组速度信息
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
typedef struct Param
{
	string paramName;
	union {
		float f_param;
		uint8_t u8_param;
		//string str_param;
	};	
}Param;

//
typedef struct ActInfo
{
	string actMode;
	vector<Param> actParam;  //描述设备运行的一堆参数
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
	bool nextActRunNow; //支持串行和并行 当nextrun = true时，立即执行下一步骤 看起来就像并行
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
