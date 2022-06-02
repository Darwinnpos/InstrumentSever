// abstractDevice.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "abstractDevice.h"
#include <iostream>
using namespace std;


CAbstractDevice* CAbstractDevice::ins = new CAbstractDevice();


CAbstractDevice::CAbstractDevice()
{
}

CAbstractDevice::~CAbstractDevice()
{

}

CAbstractDevice* CAbstractDevice::GetInstance()
{
	return CAbstractDevice::ins;
}

int CAbstractDevice::LoadAbstractDevice(vector<DeviceInfo> _allDeviceInfo, vector<GroupDeviceInfo> _allGroupDeviceInfo)
{
	allDeviceInfo.swap(_allDeviceInfo);
	allGroupDeviceInfo.swap(_allGroupDeviceInfo);	
	return 0;
}

DeviceInfo CAbstractDevice::GetDevcieInfoFromName(string name)
{
	DeviceInfo deviceInfo;	
	for (vector <DeviceInfo>::iterator iter = allDeviceInfo.begin(); iter != allDeviceInfo.end(); iter++)
	{
		if (iter->name == name)
		{
			deviceInfo.name = iter->name;
			deviceInfo.device_type = iter->device_type;
			deviceInfo.channel = iter->channel;
			return deviceInfo;
		}
	}	
	deviceInfo.name = "\0";
	return deviceInfo;
}

GroupDeviceInfo CAbstractDevice::GetGroupDevcieInfoFromName(string name)
{
	
	GroupDeviceInfo groupDeviceInfo;
	for (vector <GroupDeviceInfo>::iterator iter = allGroupDeviceInfo.begin(); iter != allGroupDeviceInfo.end(); iter++)
	{
		if (iter->name == name)
		{
			groupDeviceInfo.name = iter->name;
			groupDeviceInfo.single_name.swap(iter->single_name);
			return groupDeviceInfo;
		}
	}
	groupDeviceInfo.name = "\0";
	return groupDeviceInfo;
}




// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
