#pragma once

#include <iostream>
#include <vector>
#include "interface.h"
#include "abstractDevice.h"
#include "stepMotorCfg.h"
#include "IOCfg.h"

using namespace std;
//仪表类是抽象设备的具体实现
class CInstrument:public CInterface
{
public:
	CInstrument();
	~CInstrument();
private://仪表的单例指针
	static CInstrument* instance;
private://仪表设备所包含对象
	CAbstractDevice* abstractDevice;
	CMotorCfg* motorCfg;
	CIOCfg* IOCfg;
public:
	//获取仪表单例
	static CInstrument* GetInstance();
	//操作虚拟设备
	int LoadAbstractDevice(vector<DeviceInfo> _allDeviceInfo, vector<GroupDeviceInfo> _allGroupDeviceInfo);
	DeviceInfo GetDevcieInfoFromName(string name);
	GroupDeviceInfo GetGroupDevcieInfoFromName(string name);
	//操作步进电机
	MotorSpdCfg GetMotorSpdCfgFromName(string name, uint8_t index);
	MotorBaseCfg GetMotorBaseCfgFromName(string name);
	int ClearAllMotorCfg();
	int LoadMotorCfg(map<string, MotorCfg> _motorCfgMap);
	int AddSingleMotorCfg(string name, MotorCfg _motorCfg);
	int DeleteSingleMotorCfg(string name);
	//操作数字IO
	IOConfig GetIOCfgFromName(string name);
	int ClearIOCfg();
	int LoadIOCfg(map<string, IOConfig> _IOCfgMap);
	int AddSingleIOCfg(string name, IOConfig _IOCfg);
	int DeleteSingleIOCfg(string name);
	//系统运行流程接口

};




