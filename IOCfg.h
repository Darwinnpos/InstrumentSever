#pragma once

#include <iostream>
#include <vector>
#include <map>
using namespace std;


typedef struct IOCfg
{
	bool direction;
	double responseTimeMs;
}IOCfg;


class CIOcfg
{
public:
	CIOcfg();
	~CIOcfg();

private:
	map<string, IOCfg> IOCfgMap;
	static CIOcfg* ins;
public:
	static CIOcfg* GetInstance()
	{
		if (ins == nullptr)
		{
			ins = new CIOcfg();
		}
		return ins;
	}
	int LoadIOCfg(map<string, IOCfg> _IOCfgMap);
	int CleanIOCfg();
};


