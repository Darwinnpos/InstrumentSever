
#include "flow.h"
#include "abstractDevice.h"

CFlow::CFlow()
{
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
			for (auto iter2 = runActInfoGroup.begin(); iter2 != runActInfoGroup.end(); iter2++)
			{
				string runDeviceName = iter2->device_name;
				ActInfo runActInfo =  iter2->actInfo;
				//youwenti 
				//DeviceInfo deviceInfo = CAbstractDevice::GetInstance()->GetDevcieInfoFromName(runDeviceName);


			}
			
		}

	}
	
	return 0;
}
