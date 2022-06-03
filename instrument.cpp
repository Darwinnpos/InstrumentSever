#include "instrument.h"

CInstrument* CInstrument::instance = NULL;

CInstrument::CInstrument()
{
	//初始化对象
	abstractDevice = new CAbstractDevice();
	motorCfg = new CMotorCfg();
	IOCfg = new CIOCfg();
	flow = new CFlow();
	device2Can = new CDevice2Can();
	//初始化变量信息
}

CInstrument::~CInstrument()
{
	delete(abstractDevice);
	delete(motorCfg);
	delete(IOCfg);
	delete(flow);
	delete(device2Can);
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

MotorSpdCfg CInstrument::GetMotorSpdCfgFromName(string name, uint8_t spdIndex)
{
	return motorCfg->GetMotorSpdCfgFromName(name, spdIndex);
}

MotorSpdCfg CInstrument::GetMotorSpdCfgFromName(string name, string spdName)
{
	return motorCfg->GetMotorSpdCfgFromName(name, spdName);
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
	return motorCfg->LoadMotorCfg(_motorCfgMap);
}

int CInstrument::AddSingleMotorCfg(string name, MotorCfg _motorCfg)
{
	return motorCfg->AddSingleMotorCfg(name, _motorCfg);
}

int CInstrument::DeleteSingleMotorCfg(string name)
{
	return motorCfg->DeleteSingleMotorCfg(name);
}

IOConfig CInstrument::GetIOCfgFromName(string name)
{
	return IOCfg->GetIOCfgFromName(name);
}

int CInstrument::ClearIOCfg()
{
	return IOCfg->ClearIOCfg();
}

int CInstrument::LoadIOCfg(map<string, IOConfig> _IOCfgMap)
{
	return IOCfg->LoadIOCfg(_IOCfgMap);
}

int CInstrument::AddSingleIOCfg(string name, IOConfig _IOCfg)
{
	return IOCfg->AddSingleIOCfg(name, _IOCfg);
}

int CInstrument::DeleteSingleIOCfg(string name)
{
	return IOCfg->DeleteSingleIOCfg(name);
}

int CInstrument::FlowExe(Flow _flow)
{
	return flow->FlowExe(_flow);
}

int CInstrument::FlowExe(string name)
{
	return flow->FlowExe(name);
}

int CInstrument::AddFlow(string name, Flow _flow)
{
	return flow->AddFlow(name, _flow);
}

int CInstrument::DeleteFlow(string name)
{
	return flow->DeleteFlow(name);
}

int CInstrument::ClearAllFlow()
{
	return flow->ClearAllFlow();
}

int CInstrument::DeviceToCan(DeviceInfo* deviceInfo, ActInfo* actInfo)
{
	return device2Can->DeviceToCan(deviceInfo, actInfo);
}

int CInstrument::GetActModeMap(string actMode)
{
	return flow->GetActModeMap(actMode);
}

int CInstrument::GetActParamMap(string actParam)
{
	return flow->GetActParamMap(actParam);
}

