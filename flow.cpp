#include "flow.h"
#include "abstractDevice.h"
#include "instrument.h"
#include "protoCfg.h"
#include <thread>


CFlow::CFlow()
{
	//���ڹ���������ʽ���ַ�����int������
	//��Can��ʹ��int���ʹ��䶯�����ͣ����ٴ��俪��
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
			//ʹ�õ�����������������
			for (auto iter2 = runActInfoGroup.begin(); iter2 != runActInfoGroup.end(); iter2++)
			{
				string runDeviceName = iter2->device_name;
				ActInfo runActInfo =  iter2->actInfo;
				bool parallelOrNot = iter->nextActRunNow;
				while (parallelOrNot == true)
				{
					//����һ���߳�ִ�ж���1
				
					//
					iter2++;
					//����һ���߳�ִ���߳�2

				}
				//���е�Ӳ����ӳ��ת��  
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
