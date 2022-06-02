#pragma once
#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef struct SwitchChl
{
	uint8_t reset;
	uint8_t limit;
}SwitchChl;


typedef struct MotorBaseCfg
{
	bool hardware_dir;
	bool logic_dir;
	SwitchChl switchChannel;
	double RateCurrent;
}MotorBaseCfg;

typedef struct MotorSpdCfg
{
	uint8_t Index;
	double VMax;
	double A1;
	double A2;
	double V_A1A2;
	double D1;
	double D2;
	double V_D1D2;
	double VStart;
	double VStop;
	double ACurrentOffset;//Acceleration current compensation coefficient, default is 1
	double DCurrentOffset;
}MotorSpdCfg;

typedef struct MotorCfg
{	
	MotorBaseCfg motorBaseCfg;
	vector<MotorSpdCfg> motorAllSpdCfg;
}MotorCfg;

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
	int LoadMotorCfg(map<string, MotorCfg> _motorCfgMap);
	int CleanMotorCfg(string name);
};

