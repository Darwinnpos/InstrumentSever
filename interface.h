#pragma once
#include <map>
#include "define.h"

using namespace std;


//ͳһ����ӿ�
class CInterface
{
public:
	//���������豸
	virtual int LoadAbstractDevice(vector<DeviceInfo> _allDeviceInfo, vector<GroupDeviceInfo> _allGroupDeviceInfo) = 0;
	virtual DeviceInfo GetDevcieInfoFromName(string name) = 0;
	virtual GroupDeviceInfo GetGroupDevcieInfoFromName(string name) = 0;
	//�����������
	virtual MotorSpdCfg GetMotorSpdCfgFromName(string name, uint8_t index) = 0;
	virtual MotorBaseCfg GetMotorBaseCfgFromName(string name) = 0;
	virtual int ClearAllMotorCfg() = 0;
	virtual int LoadMotorCfg(map<string, MotorCfg> _motorCfgMap) = 0;
	virtual int AddSingleMotorCfg(string name, MotorCfg _motorCfg) = 0;
	virtual int DeleteSingleMotorCfg(string name) = 0;
	//��������IO

	//ϵͳ�������̽ӿ�
};

