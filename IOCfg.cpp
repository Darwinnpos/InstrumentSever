
#include "IOCfg.h"





CIOcfg::CIOcfg()
{
}

CIOcfg::~CIOcfg()
{
}

int CIOcfg::LoadIOCfg(map<string, IOCfg> _IOCfgMap)
{
	IOCfgMap = _IOCfgMap;
	return 0;
}

int CIOcfg::CleanIOCfg()
{
	IOCfgMap.erase(IOCfgMap.begin(),IOCfgMap.end());
	return 0;
}
