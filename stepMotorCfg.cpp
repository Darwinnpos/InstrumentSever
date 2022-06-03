
#include "stepMotorCfg.h"



CMotorCfg::CMotorCfg()
{
}

CMotorCfg::~CMotorCfg()
{
}

MotorSpdCfg CMotorCfg::GetMotorSpdCfgFromName(string name, uint8_t index)
{
	MotorSpdCfg motorSpdCfg;
	auto motorCfg = motorCfgMap[name];
	for (auto iter = motorCfg.motorAllSpdCfg.begin(); iter != motorCfg.motorAllSpdCfg.end(); iter++)
	{
		if (iter->Index == index)
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
//TODO
int CMotorCfg::AddSingleMotorCfg(string name, MotorCfg _motorCfg)
{
	return 0;
}
//TODO
int CMotorCfg::DeleteSingleMotorCfg(string name)
{
	return 0;
}
//TODO
int CMotorCfg::ClearAllMotorCfg()
{
	
	return 0;
}

