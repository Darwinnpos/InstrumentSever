#include "instrument.h"

CInstrument* CInstrument::instance = NULL;

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

CInstrument* CInstrument::GetInstance()
{
	if (instance == NULL) {
		instance = new CInstrument();
	}
	return instance;
}

int CInstrument::LoadAbstractDevice(vector<DeviceInfo> _allDeviceInfo, vector<GroupDeviceInfo> _allGroupDeviceInfo)
{
	return abstractDevice->LoadAbstractDevice(_allDeviceInfo, _allGroupDeviceInfo);
}

DeviceInfo CInstrument::GetDevcieInfoFromName(string name)
{
	return abstractDevice->GetDevcieInfoFromName(name);
}

GroupDeviceInfo CInstrument::GetGroupDevcieInfoFromName(string name)
{
	return abstractDevice->GetGroupDevcieInfoFromName(name);
}

MotorSpdCfg CInstrument::GetMotorSpdCfgFromName(string name, uint8_t index)
{
	return motorCfg->GetMotorSpdCfgFromName(name, index);
}

MotorBaseCfg CInstrument::GetMotorBaseCfgFromName(string name)
{
	return motorCfg->GetMotorBaseCfgFromName(name);
}

int CInstrument::ClearAllMotorCfg()
{
	return motorCfg->ClearAllMotorCfg();
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
