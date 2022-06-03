#include "flow.h"
#include "abstractDevice.h"
#include "instrument.h"
#include "protoCfg.h"


CFlow::CFlow()
{
	//���ڹ���������ʽ���ַ�����int������
	//��Can��ʹ��int���ʹ��䶯�����ͣ����ٴ��俪��
	modeStringMapInit();
	paramStringMapInit();
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
			//ʹ�õ�����������������
			for (auto iter2 = runActInfoGroup.begin(); iter2 != runActInfoGroup.end(); iter2++)
			{
				string runDeviceName = iter2->device_name;
				ActInfo runActInfo =  iter2->actInfo;
				//���е�Ӳ����ӳ��ת��  //����instrument���еĶ���
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

int CFlow::GetActModeMap(string actMode)
{
	return actModeMap[actMode];
}

int CFlow::GetActParamMap(string actParam)
{
	return actParamMap[actParam];
}

void CFlow::modeStringMapInit()
{
	//�����һЩ�������ַ���ӳ��
	for (auto i = 0; i < sizeof(actModeString2Int)/sizeof(actModeString2Int[0]); i++)
	{
		actModeMap.insert(make_pair(actModeString2Int[i]._string, actModeString2Int[i]._int));
	}
	//��Ҫ�������һЩ  �����ٶȲ��� ���ַ���ӳ��
	for (auto i = 0; i < sizeof(spdParamString2Int) / sizeof(spdParamString2Int[0]); i++)
	{
		actModeMap.insert(make_pair(spdParamString2Int[i]._string, spdParamString2Int[i]._int));
	}
}

void CFlow::paramStringMapInit()
{
	for (auto i = 0; i < sizeof(actParamString2Int) / sizeof(actParamString2Int[0]); i++)
	{
		actParamMap.insert(make_pair(actParamString2Int[i]._string, actParamString2Int[i]._int));
	}
}