#pragma once

#include <iostream>
#include <vector>
#include "interface.h"
#include "abstractDevice.h"
#include "stepMotorCfg.h"
#include "IOCfg.h"

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
public:
	//��ȡ�Ǳ���
	static CInstrument* GetInstance();
	//���������豸
	int LoadAbstractDevice(vector<DeviceInfo> _allDeviceInfo, vector<GroupDeviceInfo> _allGroupDeviceInfo);
	DeviceInfo GetDevcieInfoFromName(string name);
	GroupDeviceInfo GetGroupDevcieInfoFromName(string name);
	//�����������
	MotorSpdCfg GetMotorSpdCfgFromName(string name, uint8_t index);
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

};




