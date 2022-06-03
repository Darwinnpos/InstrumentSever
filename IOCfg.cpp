#include "IOCfg.h"

CIOCfg::CIOCfg()
{
}

CIOCfg::~CIOCfg()
{
}

int CIOCfg::LoadIOCfg(map<string, IOCfg> _IOCfgMap)
{
	IOCfgMap = _IOCfgMap;
	return 0;
}
//TODO
int CIOCfg::AddSingleIOCfg(string name, IOCfg _IOCfg)
{
	return 0;
}
//TODO
int CIOCfg::DeleteSingleIOCfg(string name)
{
	return 0;
}

IOCfg CIOCfg::GetIOCfgFromName(string name)
{
	IOCfg IOCfg;
	return IOCfgMap[name];
}

int CIOCfg::ClearIOCfg()
{
	IOCfgMap.erase(IOCfgMap.begin(),IOCfgMap.end());
	return 0;
}
