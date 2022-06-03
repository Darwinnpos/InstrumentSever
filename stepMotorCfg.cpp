
#include "stepMotorCfg.h"



CMotorCfg::CMotorCfg()
{
}

CMotorCfg::~CMotorCfg()
{
}

MotorSpdCfg CMotorCfg::GetMotorSpdCfgFromName(string name, uint8_t spdIndex)
{
	MotorSpdCfg motorSpdCfg;
	auto motorCfg = motorCfgMap[name];
	for (auto iter = motorCfg.motorAllSpdCfg.begin(); iter != motorCfg.motorAllSpdCfg.end(); iter++)
	{
		if (iter->Index == spdIndex)
		{
			motorSpdCfg = *iter;
			return motorSpdCfg;
		}
	}	
	motorSpdCfg.Index = 0;
	return motorSpdCfg;
}

MotorSpdCfg CMotorCfg::GetMotorSpdCfgFromName(string name, string spdName)
{
	MotorSpdCfg motorSpdCfg;
	auto motorCfg = motorCfgMap[name];
	for (auto iter = motorCfg.motorAllSpdCfg.begin(); iter != motorCfg.motorAllSpdCfg.end(); iter++)
	{
		if (iter->spdName == spdName)
		{
			motorSpdCfg = *iter;
			return motorSpdCfg;
		}
	}
	motorSpdCfg.Index = 0;
	return motorSpdCfg;
}

MotorBaseCfg CMotorCfg::GetMotorBaseCfgFromName(string name)
{
	return motorCfgMap[name].motorBaseCfg;
}

int CMotorCfg::LoadMotorCfg(map<string, MotorCfg> _motorCfgMap)
{
	motorCfgMap = _motorCfgMap;
	return 0;
}

int CMotorCfg::AddSingleMotorCfg(string name, MotorCfg _motorCfg)
{
	motorCfgMap.insert(make_pair(name, _motorCfg));
	return 0;
}

int CMotorCfg::DeleteSingleMotorCfg(string name)
{
	motorCfgMap.erase(name);
	return 0;
}

int CMotorCfg::ClearAllMotorCfg()
{
	motorCfgMap.clear();
	return 0;
}

