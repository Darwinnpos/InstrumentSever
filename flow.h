#pragma once

#include <iostream>
#include <vector>
#include <map>
using namespace std;

//这是顺序结构
typedef struct ActInfo
{
	string actMode;  
	vector<string> actParam;  //描述设备运行的一堆参数
}ActInfo;

typedef struct DevActInfo
{
	string device_name;
	ActInfo actInfo;         //一个设备的完整的运行的参数
}DevActInfo;

//一个子时序描述 支持下一个步骤的立即执行 从而完成数个步骤的并行
typedef struct subTiming
{
	string name;
	bool nextActRunNow; //支持串行和并行
	vector<DevActInfo> actInfoGroup; //一组设备运行动作
}subTiming;

typedef struct Timing
{
	string name;
	//不支持并行
	vector<subTiming> TimingVec;
}Timing;


typedef struct Flow
{
	string name;
	Timing timing;
}Flow;

class CFlow
{
public:
	CFlow();
	~CFlow();

private:

public:
	int FlowExe(Flow flow);
};

