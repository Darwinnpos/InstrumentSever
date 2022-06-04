#pragma once

#include <iostream>
#include <vector>
#include "define.h"
#include "abstractDevice.h"
using namespace std;

class CAbstractDevice
{
public:
	CAbstractDevice();
	~CAbstractDevice();

private:	
	vector<DeviceInfo> allDeviceInfo;
	vector<GroupDeviceInfo> allGroupDeviceInfo;

public:	
	int LoadAbstractDevice(vector<DeviceInfo> _allDeviceInfo, vector<GroupDeviceInfo> _allGroupDeviceInfo);
	DeviceInfo GetDevcieInfoFromName(string name);
	GroupDeviceInfo GetGroupDevcieInfoFromName(string name);
};


