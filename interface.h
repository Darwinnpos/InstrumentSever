#pragma once

#include "define.h"

using namespace std;

class CInterface
{
public:
	virtual int LoadAbstractDevice(vector<DeviceInfo> _allDeviceInfo, vector<GroupDeviceInfo> _allGroupDeviceInfo) = 0;
	virtual DeviceInfo GetDevcieInfoFromName(string name) = 0;
	virtual GroupDeviceInfo GetGroupDevcieInfoFromName(string name) = 0;
};

