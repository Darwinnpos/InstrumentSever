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
	map<string, IOCfg> IOCfgMap;
public:
	//≤È—Ø
	IOCfg GetIOCfgFromName(string name);
	int ClearIOCfg();
	int LoadIOCfg(map<string, IOCfg> _IOCfgMap);	
	int AddSingleIOCfg(string name, IOCfg _IOCfg);
	int DeleteSingleIOCfg(string name);
};


