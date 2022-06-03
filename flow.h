#pragma once

#include <iostream>
#include <vector>
#include <map>
#include "define.h"
#include "protoCfg.h"
using namespace std;

class CFlow
{
public:
	CFlow();
	~CFlow();

private:
	map<string, Flow> flowMap;
	map<string, StringCode> stringMap;
	vector<SpeedMap> speedParamList;
public:
	int FlowExe(Flow flow);				//临时运行一个flow
	int FlowExe(string name);			//通过名称找到已加载的flow进行运行
	int AddFlow(string name, Flow flow);
	int DeleteFlow(string name);
	int ClearAllFlow();

public:
	StringCode GetStringMap(string _string);
	vector<SpeedMap> GetSpeedParamList();
	void StringMapInit();
};

