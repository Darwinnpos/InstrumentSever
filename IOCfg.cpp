#include "IOCfg.h"

CIOCfg::CIOCfg()
{
}

CIOCfg::~CIOCfg()
{
}

int CIOCfg::LoadIOCfg(map<string, IOConfig> _IOCfgMap)
{
	IOCfgMap = _IOCfgMap;
	return 0;
}

int CIOCfg::AddSingleIOCfg(string name, IOConfig _IOCfg)
{
	IOCfgMap.insert(make_pair(name, _IOCfg));
	return 0;
}

int CIOCfg::DeleteSingleIOCfg(string name)
{
	IOCfgMap.erase(name);
	return 0;
}

IOConfig CIOCfg::GetIOCfgFromName(string name)
{
	return IOCfgMap[name];
}

int CIOCfg::ClearIOCfg()
{
	IOCfgMap.erase(IOCfgMap.begin(),IOCfgMap.end());
	return 0;
}
