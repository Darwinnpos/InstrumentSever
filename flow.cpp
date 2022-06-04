#include "flow.h"
#include "abstractDevice.h"
#include "instrument.h"
#include "protoCfg.h"
#include <thread>
#include <process.h>
#include <stdio.h>
#include <Windows.h>


CFlow::CFlow()
{
	//���ڹ���������ʽ���ַ�����int������
	//��Can��ʹ��int���ʹ��䶯�����ͣ����ٴ��俪��
	StringMapInit();
}

CFlow::~CFlow()
{
}


//������ִ�к��� ��֧�ִ��� ��СΪ1��������Ԫ
DWORD WINAPI ActThread(PVOID _runSubTiming)
{
	subTiming* runSubTiming = (subTiming*)_runSubTiming;
	vector<DevActInfo> runActInfoGroup = runSubTiming->actInfoGroup;
	for (auto iter2 = runActInfoGroup.begin(); iter2 != runActInfoGroup.end(); iter2++)
	{
		string runDeviceName = iter2->device_name;
		ActInfo runActInfo = iter2->actInfo;
		//���е�Ӳ����ӳ��ת��  
		DeviceInfo runDeviceInfo = CInstrument::GetInstance()->GetDevcieInfoFromName(runDeviceName);
		CInstrument::GetInstance()->DeviceToCan(&runDeviceInfo, &runActInfo);
	}
	return 0;
}

int CFlow::FlowExe(Flow flow)
{
	//��ʱ��ȡ������ʱ�����ݽṹ��
	vector<subTiming> runTiming = flow.timing.TimingVec;	
	HANDLE thread[255];//���֧��255�߳�
	uint8_t paralleActNumber = 0;
	subTiming runSubTiming;
	//������Ϊ��Ķ����� ֧�ִ���+�������
	for (auto iter = runTiming.begin(); iter != runTiming.end(); iter++)
	{
		//�ȴ���һ���߳� ִ�е�ǰ����
		runSubTiming = *iter;
		thread[paralleActNumber] = CreateThread(NULL, 0, ActThread, &runSubTiming, 0, NULL);

		//��������һ��Ϊ��������ʱ
		while (iter->nextActRunNow == true)
		{
			//��������ȡ�� �����ݸ��߳� �����߳�
			iter++;
			runSubTiming = *iter;
			thread[++paralleActNumber] = CreateThread(NULL, 0, ActThread, NULL, 0, NULL);
		}
		//�ж�ÿ���߳��Ƿ���� ������� ��ִ����һ��Ԫ
		for (int i = 0; i < paralleActNumber; i++)
		{
			static bool ret;
			PDWORD pdwExitCode = nullptr;
			ret = GetExitCodeThread(thread[i], pdwExitCode);
			if (ret != true)
				i = 0;
			Sleep(10);
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
