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
	//��ŷ����� can ͷ��
	//��1�ֽ� channel
	uint8_t boardNum = deviceInfo->board_num;
	uint8_t channel = deviceInfo->channel;
	//��2�ֽ� act mode
	//GetActModeMap
	StringCode actMode = CInstrument::GetInstance()->GetStringMap(actInfo->actMode);

	//ʹ�õ���������������Ҫ�ô��˶�������Ҫ���õĲ�����
	for(auto iter = actInfo->actParam.begin(); iter != actInfo->actParam.end(); iter++)
	{
		//��ȡ�ò������������� ����ʹ��switch����ɸѡ 
		StringCode Index = CInstrument::GetInstance()->GetStringMap(iter->paramName);
		
		vector<SpeedMap> speedMap;
		uint8_t speedIndex;
		MotorSpdCfg motorSpdCfg;
		char send_msg[8];
		string speed_name;
		uint32_t position;

		switch (Index)
		{
		//	����������Ϊ�ٶȱ��ʱ �����ٶȰ��Ĳ�� �������ٶȲ�����CAN
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
	//�������  �������ڷ�����Ϣ����
	
	

	//�������ذ� �����ذ�ֵ����Ҫ�� �򷵻���ȷ
	//���������ȴ�
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

