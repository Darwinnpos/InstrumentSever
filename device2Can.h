#pragma once
#include "abstractDevice.h"
#include "flow.h"

class CDevice2Can
{
public:
	CDevice2Can();
	~CDevice2Can();

private:
	int Motor2Can(DeviceInfo* deviceInfo, ActInfo* actInfo);
	int Msg2Can(uint8_t boardNum, char msg[8]);
public:
	int DeviceToCan(DeviceInfo* deviceInfo,ActInfo* actInfo);

};

