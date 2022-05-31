
#include "stepMotorCfg.h"




CMotorCfg::CMotorCfg()
{
}

CMotorCfg::~CMotorCfg()
{
}

MotorCfg CMotorCfg::GetMotorCfgFromName(string name)
{
	return motorCfgMap[name];
}

int CMotorCfg::AddMotorCfg(string name, MotorCfg motorCfg)
{
	auto pair = make_pair(name, motorCfg);
	motorCfgMap.insert(pair);
	return 0;
}

int CMotorCfg::DeleteMotorCfg(string name)
{
	motorCfgMap.erase(name);
	return 0;
}

int CMotorCfg::CleanMotorCfg(string name)
{
	motorCfgMap.erase(motorCfgMap.begin(), motorCfgMap.end());
	return 0;
}
