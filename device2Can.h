
#pragma once
#include "abstractDevice.h"
#include "flow.h"






class CDevice2Can
{
public:
	CDevice2Can();
	~CDevice2Can();

private:
	int Motor2Can(DeviceInfo deviceInfo, ActInfo actInfo);


public:
	int DeviceToCan(DeviceInfo deviceInfo,ActInfo actInfo);

};

