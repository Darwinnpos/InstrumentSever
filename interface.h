#pragma once
#include <map>
#include "define.h"

using namespace std;

//统一的虚接口
class CInterface
{
public:
	//操作虚拟设备
	virtual int LoadAbstractDevice(vector<DeviceInfo> _allDeviceInfo, vector<GroupDeviceInfo> _allGroupDeviceInfo) = 0;
	virtual DeviceInfo GetDevcieInfoFromName(string name) = 0;
	virtual GroupDeviceInfo GetGroupDevcieInfoFromName(string name) = 0;
	//操作步进电机
	virtual MotorSpdCfg GetMotorSpdCfgFromName(string name, uint8_t index) = 0;
	virtual MotorBaseCfg GetMotorBaseCfgFromName(string name) = 0;
	virtual int ClearAllMotorCfg() = 0;
	virtual int LoadMotorCfg(map<string, MotorCfg> _motorCfgMap) = 0;
	virtual int AddSingleMotorCfg(string name, MotorCfg _motorCfg) = 0;
	virtual int DeleteSingleMotorCfg(string name) = 0;
	//操作数字IO
	virtual IOConfig GetIOCfgFromName(string name) = 0;
	virtual int ClearIOCfg() = 0;
	virtual int LoadIOCfg(map<string, IOConfig> _IOCfgMap) = 0;
	virtual int AddSingleIOCfg(string name, IOConfig _IOCfg) = 0;
	virtual int DeleteSingleIOCfg(string name) = 0;
	//系统运行流程接口

};

