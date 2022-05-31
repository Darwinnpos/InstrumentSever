#pragma once
#include <iostream>
#include <vector>
#include <map>
using namespace std;

//定义数据类型
typedef struct MotorCfg
{
	double VMax;
	double A1;
	double A2;
	double V_A1A2;
	double D1;
	double D2;
	double V_D1D2;
	double VStart;
	double VStop;
}MotorCfg;

class CMotorCfg
{
public:
	CMotorCfg();
	~CMotorCfg();
private:
	static CMotorCfg* ins;

public:
	static CMotorCfg* GetInstance()
	{
		if (ins == nullptr)
		{
			ins = new CMotorCfg();
		}
		return ins;	
	}
	map<string , MotorCfg> motorCfgMap;
	MotorCfg GetMotorCfgFromName(string name);
	int AddMotorCfg(string name, MotorCfg motorCfg);
	int DeleteMotorCfg(string name);
	int CleanMotorCfg(string name);
};

