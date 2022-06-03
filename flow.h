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
	int FlowExe(Flow flow);				//��ʱ����һ��flow
	int FlowExe(string name);			//ͨ�������ҵ��Ѽ��ص�flow��������
	int AddFlow(string name, Flow flow);
	int DeleteFlow(string name);
	int ClearAllFlow();

public:
	int GetActModeMap(string actMode);
	int GetActParamMap(string actParam);
	void modeStringMapInit();
	void paramStringMapInit();
};

