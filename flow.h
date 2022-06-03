#pragma once

#include <iostream>
#include <vector>
#include <map>
#include "define.h"
using namespace std;


class CFlow
{
public:
	CFlow();
	~CFlow();

private:
	map<string, Flow> flowMap;
	map<string, int> actModeMap;
	map<string, int> actParamMap;
public:
	int FlowExe(Flow flow);				//临时运行一个flow
	int FlowExe(string name);			//通过名称找到已加载的flow进行运行
	int AddFlow(string name, Flow flow);
	int DeleteFlow(string name);
	int ClearAllFlow();

public:
	int GetActModeMap(string actMode);
	int GetActParamMap(string actParam);
	void modeStringMapInit();
	void paramStringMapInit();
};

