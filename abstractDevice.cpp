// abstractDevice.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "abstractDevice.h"
#include <iostream>

using namespace std;

CAbstractDevice::CAbstractDevice()
{
}

CAbstractDevice::~CAbstractDevice()
{
}

int CAbstractDevice::LoadAbstractDevice(vector<DeviceInfo> _allDeviceInfo, vector<GroupDeviceInfo> _allGroupDeviceInfo)
{
	allDeviceInfo.swap(_allDeviceInfo);
	allGroupDeviceInfo.swap(_allGroupDeviceInfo);	
	return 0;
}

DeviceInfo CAbstractDevice::GetDevcieInfoFromName(string name)
{
	DeviceInfo deviceInfo;	
	for (vector <DeviceInfo>::iterator iter = allDeviceInfo.begin(); iter != allDeviceInfo.end(); iter++)
	{
		if (iter->name == name)
		{
			deviceInfo.name = iter->name;
			deviceInfo.device_type = iter->device_type;
			deviceInfo.channel = iter->channel;
			return deviceInfo;
		}
	}	
	deviceInfo.name = "\0";
	return deviceInfo;
}

GroupDeviceInfo CAbstractDevice::GetGroupDevcieInfoFromName(string name)
{
	
	GroupDeviceInfo groupDeviceInfo;
	for (vector <GroupDeviceInfo>::iterator iter = allGroupDeviceInfo.begin(); iter != allGroupDeviceInfo.end(); iter++)
	{
		if (iter->name == name)
		{
			groupDeviceInfo.name = iter->name;
			groupDeviceInfo.single_name.swap(iter->single_name);
			return groupDeviceInfo;
		}
	}
	groupDeviceInfo.name = "\0";
	return groupDeviceInfo;
}