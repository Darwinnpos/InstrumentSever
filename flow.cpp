#include "flow.h"
#include "abstractDevice.h"
#include "instrument.h"
#include "protoCfg.h"
#include <thread>
#include <stdio.h>



CFlow::CFlow()
{
	//用于构建各种形式的字符串到int的索引
	//在Can上使用int类型传输动作类型，减少传输开销
	StringMapInit();
}

CFlow::~CFlow()
{
}

void cc()
{
}


//动作包执行函数 仅支持串行 最小为1个动作单元
void ActThread(subTiming _runSubTiming)
{
	subTiming runSubTiming = _runSubTiming;	
	vector<DevActInfo> runActInfoGroup = runSubTiming.actInfoGroup;
	for (auto iter2 = runActInfoGroup.begin(); iter2 != runActInfoGroup.end(); iter2++)
	{
		string runDeviceName = iter2->device_name;
		ActInfo runActInfo = iter2->actInfo;
		//进行到硬件的映射转换  
		DeviceInfo runDeviceInfo = CInstrument::GetInstance()->GetDevcieInfoFromName(runDeviceName);
		CInstrument::GetInstance()->DeviceToCan(&runDeviceInfo, &runActInfo);
	}
}

int CFlow::FlowExe(Flow flow)
{
	//将时序内容取出到临时的数据结构中
	vector<subTiming> runTiming = flow.timing.TimingVec;	
	vector<thread*> threads;
	subTiming runSubTiming;
	//遍历较为大的动作组 支持串行 + 并行设计
	for (auto iter = runTiming.begin(); iter != runTiming.end(); iter++)
	{
		//先创建一个线程 执行当前任务
		runSubTiming = *iter;
		auto ptr_thread = new thread(ActThread, runSubTiming);
		threads.push_back(ptr_thread);
		//当发现下一包为并行流程时
		while (iter->nextActRunNow == true)
		{
			//将包内容取出 并传递给线程 开启线程
			iter++;
			runSubTiming = *iter;			
			ptr_thread = new thread(ActThread, runSubTiming);
			threads.push_back(ptr_thread);
		}
		//判断每个线程是否结束 如果结束 则执行下一单元
		for (auto iter = threads.begin(); iter < threads.end(); iter++)
		{
			thread* x = *iter;
			x->join();
		}
		threads.clear();
	}
	return 0;
}

int CFlow::FlowExe(string name)
{
	return 0;
}

int CFlow::AddFlow(string name, Flow flow)
{
	return 0;
}

int CFlow::DeleteFlow(string name)
{
	return 0;
}

int CFlow::ClearAllFlow()
{
	return 0;
}

StringCode CFlow::GetStringMap(string _string)
{
	return stringMap[_string];
}

vector<SpeedMap> CFlow::GetSpeedParamList()
{
	return speedParamList;
}

void CFlow::StringMapInit()
{
	//添加了一些动作的字符串映射 方便使用map进行索引
	for (auto i = 0; i < sizeof(string2Int)/sizeof(string2Int[0]); i++)
	{
		stringMap.insert(make_pair(string2Int[i]._string, string2Int[i]._int));
		//当类型为speed中的单独添加一次索引 
		if (string2Int[i].strType == StrType::SPD_PARAM_CAN)
		{
			SpeedMap speedMap;
			speedMap.speed_param_name = string2Int[i]._string;
			speedMap.index = string2Int[i]._int;
			speedParamList.push_back(speedMap);
		}
	}
}
