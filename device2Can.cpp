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
	StringCode actMode = CInstrument::GetInstance()->GetStringMap(actInfo->actMode);

	//使用迭代器遍历所有需要该次运动所有需要配置的参数表
	for(auto iter = actInfo->actParam.begin(); iter != actInfo->actParam.end(); iter++)
	{
		//获取该参数的索引号码 方便使用switch进行筛选 
		StringCode Index = CInstrument::GetInstance()->GetStringMap(iter->paramName);
		
		vector<SpeedMap> speedMap;
		uint8_t speedIndex;
		MotorSpdCfg motorSpdCfg;
		char send_msg[8];
		string speed_name;
		uint32_t position;

		switch (Index)
		{
		//	当参数描述为速度编号时 进行速度包的拆解 并配置速度参数到CAN
		case StringCode::SPEED_NUM://
			
			speedIndex = iter->u8_param;
			motorSpdCfg = CInstrument::GetInstance()->GetMotorSpdCfgFromName(deviceInfo->name, speedIndex);			
			speedMap = CInstrument::GetInstance()->GetSpeedParamList();
			for (auto iter = speedMap.begin(); iter != speedMap.end(); iter++)
			{
				send_msg[0] = channel;
				send_msg[1] = (char)iter->index;
				send_msg[2] = 0;
				send_msg[3] = 0;
				float param = motorSpdCfg.paramList[iter->speed_param_name];
				memcpy(&param, &send_msg[4], 4);
				Msg2Can(boardNum, send_msg);
			}
			break;
		case StringCode::SPEED_NAME:
			speed_name = iter->str_param;
			motorSpdCfg = CInstrument::GetInstance()->GetMotorSpdCfgFromName(deviceInfo->name, speed_name);
			speedMap = CInstrument::GetInstance()->GetSpeedParamList();
			for (auto iter = speedMap.begin(); iter != speedMap.end(); iter++)
			{
				send_msg[0] = channel;
				send_msg[1] = (char)iter->index;
				send_msg[2] = 0;
				send_msg[3] = 0;
				float param = motorSpdCfg.paramList[iter->speed_param_name];
				memcpy(&param, &send_msg[4], 4);
				Msg2Can(boardNum, send_msg);
			}
			break;
		
		case StringCode::ABS_POSITION:
			send_msg[0] = channel;
			send_msg[1] = (char)Index;
			send_msg[2] = 0;
			send_msg[3] = 0;
			position = round(iter->f_param);
			memcpy(&position, &send_msg[4], 4);
			Msg2Can(boardNum, send_msg);
			break;
		default:
			break;
		}
	}
	return 0;
}

int CDevice2Can::Msg2Can(uint8_t boardNum, char msg[8])
{
	//进行组包  并放置于发送消息队列
	
	

	//监听返回包 当返回包值满足要求 则返回正确
	//否则阻塞等待
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

