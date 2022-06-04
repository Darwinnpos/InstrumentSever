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
	int FlowExe(Flow flow);				//��ʱ����һ��flow
	int FlowExe(string name);			//ͨ�������ҵ��Ѽ��ص�flow��������
	int AddFlow(string name, Flow flow);
	int DeleteFlow(string name);
	int ClearAllFlow();

public:
	StringCode GetStringMap(string _string);
	vector<SpeedMap> GetSpeedParamList();
	void StringMapInit();
};

