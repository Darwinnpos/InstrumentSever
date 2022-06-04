#include "flow.h"
#include "abstractDevice.h"
#include "instrument.h"
#include "protoCfg.h"
#include <thread>


CFlow::CFlow()
{
	//用于构建各种形式的字符串到int的索引
	//在Can上使用int类型传输动作类型，减少传输开销
	StringMapInit();
}

CFlow::~CFlow()
{
}

int CFlow::FlowExe(Flow flow)
{
	cout << flow.name << "is running" << endl;
	vector<subTiming> runTiming = flow.timing.TimingVec;	
	for (auto iter = runTiming.begin(); iter != runTiming.end(); iter++)
	{
		if (iter->nextActRunNow == false)
		{
			cout << iter->name << "sub time is running" << endl;
			subTiming runSubTiming = *iter;
			vector<DevActInfo> runActInfoGroup = runSubTiming.actInfoGroup;
			//使用迭代器遍历整个流程
			for (auto iter2 = runActInfoGroup.begin(); iter2 != runActInfoGroup.end(); iter2++)
			{
				string runDeviceName = iter2->device_name;
				ActInfo runActInfo =  iter2->actInfo;
				bool parallelOrNot = iter->nextActRunNow;
				while (parallelOrNot == true)
				{
					//开启一个线程执行动作1
				
					//
					iter2++;
					//开启一个线程执行线程2

				}
				//进行到硬件的映射转换  
				DeviceInfo runDeviceInfo = CInstrument::GetInstance()->GetDevcieInfoFromName(runDeviceName);
				CInstrument::GetInstance()->DeviceToCan(&runDeviceInfo, &runActInfo);
			}
		}
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
