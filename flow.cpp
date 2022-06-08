#include "flow.h"
#include "abstractDevice.h"
#include "instrument.h"
#include "protoCfg.h"
#include <thread>
#include <stdio.h>



CFlow::CFlow()
{
	//���ڹ���������ʽ���ַ�����int������
	//��Can��ʹ��int���ʹ��䶯�����ͣ����ٴ��俪��
	StringMapInit();
}

CFlow::~CFlow()
{
}

void cc()
{
}


//������ִ�к��� ��֧�ִ��� ��СΪ1��������Ԫ
void ActThread(subTiming _runSubTiming)
{
	subTiming runSubTiming = _runSubTiming;	
	vector<DevActInfo> runActInfoGroup = runSubTiming.actInfoGroup;
	for (auto iter2 = runActInfoGroup.begin(); iter2 != runActInfoGroup.end(); iter2++)
	{
		string runDeviceName = iter2->device_name;
		ActInfo runActInfo = iter2->actInfo;
		//���е�Ӳ����ӳ��ת��  
		DeviceInfo runDeviceInfo = CInstrument::GetInstance()->GetDevcieInfoFromName(runDeviceName);
		CInstrument::GetInstance()->DeviceToCan(&runDeviceInfo, &runActInfo);
	}
}

int CFlow::FlowExe(Flow flow)
{
	//��ʱ������ȡ������ʱ�����ݽṹ��
	vector<subTiming> runTiming = flow.timing.TimingVec;	
	vector<thread*> threads;
	subTiming runSubTiming;
	//������Ϊ��Ķ����� ֧�ִ��� + �������
	for (auto iter = runTiming.begin(); iter != runTiming.end(); iter++)
	{
		//�ȴ���һ���߳� ִ�е�ǰ����
		runSubTiming = *iter;
		auto ptr_thread = new thread(ActThread, runSubTiming);
		threads.push_back(ptr_thread);
		//��������һ��Ϊ��������ʱ
		while (iter->nextActRunNow == true)
		{
			//��������ȡ�� �����ݸ��߳� �����߳�
			iter++;
			runSubTiming = *iter;			
			ptr_thread = new thread(ActThread, runSubTiming);
			threads.push_back(ptr_thread);
		}
		//�ж�ÿ���߳��Ƿ���� ������� ��ִ����һ��Ԫ
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
	//�����һЩ�������ַ���ӳ�� ����ʹ��map��������
	for (auto i = 0; i < sizeof(string2Int)/sizeof(string2Int[0]); i++)
	{
		stringMap.insert(make_pair(string2Int[i]._string, string2Int[i]._int));
		//������Ϊspeed�еĵ������һ������ 
		if (string2Int[i].strType == StrType::SPD_PARAM_CAN)
		{
			SpeedMap speedMap;
			speedMap.speed_param_name = string2Int[i]._string;
			speedMap.index = string2Int[i]._int;
			speedParamList.push_back(speedMap);
		}
	}
}
