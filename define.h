#pragma once

#include <iostream>
#include <vector>
using namespace std;

enum class DeviceType
{
	STEP_MOTOR = 0,
	IO = 1
};


typedef struct DeviceInfo
{
	string name;
	DeviceType device_type;
	uint8_t channel;
}DeviceInfo;


typedef struct GroupDeviceInfo
{
	string name;
	vector <string> single_name;
}GroupDeviceInfo;