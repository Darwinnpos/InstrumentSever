#pragma once

#include <iostream>
#include <vector>
using namespace std;

enum class DeviceType
{
	STEP_MTOROR = 0,
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


class CAbstractDevice
{

public:
	CAbstractDevice();
	~CAbstractDevice();

private:
	static CAbstractDevice* ins;	
	vector<DeviceInfo> allDeviceInfo;
	vector<GroupDeviceInfo> allGroupDeviceInfo;

public:
	static CAbstractDevice* GetInstance()
	{
		if(ins == nullptr)
		{
			ins = new CAbstractDevice();
		}
		return ins;
	}
	int LoadAbstractDevice(vector<DeviceInfo> _allDeviceInfo, vector<GroupDeviceInfo> _allGroupDeviceInfo);
	DeviceInfo  GetDevcieInfoFromName(string name);
	GroupDeviceInfo GetGroupDevcieInfoFromName(string name);
};

//使用方法
//单例对象
//
