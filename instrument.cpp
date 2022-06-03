#include "instrument.h"



CInstrument::CInstrument()
{
	abstractDevice = new CAbstractDevice();
	motorCfg = new CMotorCfg();
	IOCfg = new CIOCfg();
}

CInstrument::~CInstrument()
{
	delete(abstractDevice);
	delete(motorCfg);
	delete(IOCfg);
}

int CInstrument::LoadAbstractDevice(vector<DeviceInfo> _allDeviceInfo, vector<GroupDeviceInfo> _allGroupDeviceInfo)
{
	return 0;
}

DeviceInfo CInstrument::GetDevcieInfoFromName(string name)
{
	return DeviceInfo();
}

GroupDeviceInfo CInstrument::GetGroupDevcieInfoFromName(string name)
{
	return GroupDeviceInfo();
}

MotorSpdCfg CInstrument::GetMotorSpdCfgFromName(string name, uint8_t index)
{
	return MotorSpdCfg();
}

MotorBaseCfg CInstrument::GetMotorBaseCfgFromName(string name)
{
	return MotorBaseCfg();
}

int CInstrument::ClearAllMotorCfg()
{
	return 0;
}

int CInstrument::LoadMotorCfg(map<string, MotorCfg> _motorCfgMap)
{
	return 0;
}

int CInstrument::AddSingleMotorCfg(string name, MotorCfg _motorCfg)
{
	return 0;
}

int CInstrument::DeleteSingleMotorCfg(string name)
{
	return 0;
}

IOConfig CInstrument::GetIOCfgFromName(string name)
{
	return IOConfig();
}

int CInstrument::ClearIOCfg()
{
	return 0;
}

int CInstrument::LoadIOCfg(map<string, IOConfig> _IOCfgMap)
{
	return 0;
}

int CInstrument::AddSingleIOCfg(string name, IOConfig _IOCfg)
{
	return 0;
}

int CInstrument::DeleteSingleIOCfg(string name)
{
	return 0;
}
