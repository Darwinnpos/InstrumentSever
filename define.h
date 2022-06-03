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