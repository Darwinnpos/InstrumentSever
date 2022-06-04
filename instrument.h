#pragma once

#include <iostream>
#include <vector>
#include "interface.h"
#include "abstractDevice.h"
#include "stepMotorCfg.h"
#include "IOCfg.h"
#include "Flow.h"
#include "device2Can.h"

using namespace std;
//�Ǳ����ǳ����豸�ľ���ʵ��
class CInstrument:public CInterface
{
public:
	CInstrument();
	~CInstrument();
private://�Ǳ�ĵ���ָ��
	static CInstrument* instance;
private://�Ǳ��豸����������
	CAbstractDevice* abstractDevice;
	CMotorCfg* motorCfg;
	CIOCfg* IOCfg;
	CFlow* flow;
	CDevice2Can* device2Can;
public:
	//��ȡ�Ǳ���
	static CInstrument* GetInstance();
	//���������豸
	int LoadAbstractDevice(vector<DeviceInfo> _allDeviceInfo, vector<GroupDeviceInfo> _allGroupDeviceInfo);
	DeviceInfo GetDevcieInfoFromName(string name);
	GroupDeviceInfo GetGroupDevcieInfoFromName(string name);
	//�����������
	MotorSpdCfg GetMotorSpdCfgFromName(string name, uint8_t spdIndex);
	MotorSpdCfg GetMotorSpdCfgFromName(string name, string spdName);
	MotorBaseCfg GetMotorBaseCfgFromName(string name);
	int ClearAllMotorCfg();
	int LoadMotorCfg(map<string, MotorCfg> _motorCfgMap);
	int AddSingleMotorCfg(string name, MotorCfg _motorCfg);
	int DeleteSingleMotorCfg(string name);
	//��������IO
	IOConfig GetIOCfgFromName(string name);
	int ClearIOCfg();
	int LoadIOCfg(map<string, IOConfig> _IOCfgMap);
	int AddSingleIOCfg(string name, IOConfig _IOCfg);
	int DeleteSingleIOCfg(string name);
	//ϵͳ�������̽ӿ�
	int FlowExe(Flow _flow);				//��ʱ����һ��flow
	int FlowExe(string name);			//ͨ�������ҵ��Ѽ��ص�flow��������
	int AddFlow(string name, Flow _flow);
	int DeleteFlow(string name);
	int ClearAllFlow();
	//�����豸��CAN
	int DeviceToCan(DeviceInfo* deviceInfo, ActInfo* actInfo);
public:	
	//���ⲿ�ӿ�ʹ��
	StringCode GetStringMap(string _string);
	vector<SpeedMap> GetSpeedParamList();
};




