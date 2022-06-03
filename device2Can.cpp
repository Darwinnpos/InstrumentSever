#include "instrument.h"
#include "device2Can.h"
#include "flow.h"
#include "protoCfg.h"

CDevice2Can::CDevice2Can()
{
}

CDevice2Can::~CDevice2Can()
{
}

int CDevice2Can::Motor2Can(DeviceInfo* deviceInfo, ActInfo* actInfo)
{
	//板号放置于 can 头中
	//第1字节 channel
	uint8_t boardNum = deviceInfo->board_num;
	uint8_t channel = deviceInfo->channel;
	//第2字节 act mode
	//GetActModeMap
	uint8_t actMode = CInstrument::GetInstance()->GetActModeMap(actInfo->actMode);

	for(auto iter = actInfo->actParam.begin(); iter != actInfo->actParam.end(); iter++)
	{
		//根据描述类型开始组织包
		if (iter->paramName == "speed_num")
		{
			//double actParam = iter->param;
			uint8_t speedIndex = iter->u8_param;
			MotorSpdCfg motorSpdCfg = CInstrument::GetInstance()->GetMotorSpdCfgFromName(deviceInfo->name, speedIndex);
			char send_msg[8];			
			for(auto i = 0; i < sizeof(spdParamString2Int)/sizeof(spdParamString2Int[0]); i++)
			{
				send_msg[0] = channel;
				send_msg[1] = CInstrument::GetInstance()->GetActModeMap(spdParamString2Int[i]._string);
				float param = motorSpdCfg.paramList[spdParamString2Int[i]._string];
				memcpy(&param,&send_msg[4],4);
				Msg2Can(boardNum, send_msg);
			}
		}
		else if (iter->paramName == "speed_name")
		{			
			//string speed_name = iter->str_param;
			//MotorSpdCfg motorSpdCfg = CInstrument::GetInstance()->GetMotorSpdCfgFromName(deviceInfo->name, speed_name);
			//char send_msg[8];
			//for (auto i = 0; i < sizeof(spdParamString2Int) / sizeof(spdParamString2Int[0]); i++)
			//{
			//	send_msg[0] = channel;
			//	send_msg[1] = CInstrument::GetInstance()->GetActModeMap(spdParamString2Int[i]._string);
			//	float param = motorSpdCfg.paramList[spdParamString2Int[i]._string];
			//	memcpy(&param, &send_msg[4], 4);
			//	Msg2Can(boardNum, send_msg);
			//}

		}
		else
		uint8_t actParamName = CInstrument::GetInstance()->GetActParamMap(iter->paramName);

	}
	//第3字节 参数列表选择
	
	
	//第4字节

	return 0;
}

int CDevice2Can::Msg2Can(uint8_t boardNum, char msg[8])
{
	return 0;
}


int CDevice2Can::DeviceToCan(DeviceInfo* deviceInfo, ActInfo* actInfo)
{
	switch (deviceInfo->device_type)
	{
	case DeviceType::STEP_MOTOR:
		return Motor2Can(deviceInfo, actInfo);
		break;
	case DeviceType::IO:
		break;
	default:
		break;
	}
	return 0;
}

