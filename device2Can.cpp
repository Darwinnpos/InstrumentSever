#include "device2Can.h"

CDevice2Can::CDevice2Can()
{
}

CDevice2Can::~CDevice2Can()
{
}

int CDevice2Can::Motor2Can(DeviceInfo deviceInfo, ActInfo actInfo)
{
	return 0;
}


int CDevice2Can::DeviceToCan(DeviceInfo deviceInfo, ActInfo actInfo)
{
	switch (deviceInfo.device_type)
	{
	case DeviceType::STEP_MOTOR:
		return Motor2Can(deviceInfo, actInfo);
		break;
	case DeviceType::IO:
		break;
	default:
		break;
	}
	return 0;
}
