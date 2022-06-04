#pragma once

#include <iostream>
#include <vector>
#include <map>
#include "define.h"

using namespace std;

class CIOCfg
{
public:
	CIOCfg();
	~CIOCfg();
private:
	map<string, IOConfig> IOCfgMap;
public:
	//≤È—Ø
	IOConfig GetIOCfgFromName(string name);
	int ClearIOCfg();
	int LoadIOCfg(map<string, IOConfig> _IOCfgMap);
	int AddSingleIOCfg(string name, IOConfig _IOCfg);
	int DeleteSingleIOCfg(string name);
};


