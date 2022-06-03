#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "define.h"

using namespace std;

class CMotorCfg
{
public:
	CMotorCfg();
	~CMotorCfg();
private:
	static CMotorCfg* ins;
	map<string, MotorCfg> motorCfgMap;
public:
	static CMotorCfg* GetInstance()
	{
		if (ins == nullptr)
		{
			ins = new CMotorCfg();
		}
		return ins;	
	}
	
	MotorSpdCfg GetMotorSpdCfgFromName(string name,uint8_t index);
	MotorBaseCfg GetMotorBaseCfgFromName(string name);
	int ClearAllMotorCfg();
	int LoadMotorCfg(map<string, MotorCfg> _motorCfgMap);
	int AddSingleMotorCfg(string name, MotorCfg _motorCfg);
	int DeleteSingleMotorCfg(string name);
};

