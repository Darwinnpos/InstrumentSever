#pragma once
#include "define.h"


//1. 约定一些字符串对应的传输时的字符型替代，简化传输的数据量
//2. 将字符串索引为int类型，方便使用switch
const String2Int string2Int[] =
{
	//can 通信协议层 统一编码
	//第一层级  act mode
	{	"run",		StringCode::RUN	,			StrType::ACT_MODE_CAN	},
	{	"run_back", StringCode::RUN_BACK	,	StrType::ACT_MODE_CAN	},
	{	"on",		StringCode::ON	,			StrType::ACT_MODE_CAN	},
	{	"off",		StringCode::OFF	,			StrType::ACT_MODE_CAN	},
	//  name    
	{	"VMax",				StringCode::V_MAX					,	StrType::SPD_PARAM_CAN	},
	{	"A1",				StringCode::A1						,	StrType::SPD_PARAM_CAN	},
	{	"A2",				StringCode::A2						,	StrType::SPD_PARAM_CAN	},
	{	"V_A1A2",			StringCode::V_A1A2					,	StrType::SPD_PARAM_CAN	},
	{	"D1",				StringCode::D1						,	StrType::SPD_PARAM_CAN	},
	{	"D2",				StringCode::D2						,	StrType::SPD_PARAM_CAN	},
	{	"V_D1D2",			StringCode::V_D1D2					,	StrType::SPD_PARAM_CAN	},
	{	"VStart",			StringCode::V_START					,	StrType::SPD_PARAM_CAN	},
	{	"VStop",			StringCode::V_STOP					,	StrType::SPD_PARAM_CAN	},
	{	"ACurrentOffset",	StringCode::V_A_CURRENT_OFFSET		,	StrType::SPD_PARAM_CAN	},
	{	"DCurrentOffset",	StringCode::V_D_CURRENT_OFFSET		,	StrType::SPD_PARAM_CAN	},
	{	"Default",			StringCode::V_DEFAULT				,	StrType::SPD_PARAM_CAN	},

	// 非can传输级 仅仅做内部switch索引使用的
	//第二层级  act param
	{	"absolute_position",	 StringCode::ABS_POSITION	,	StrType::ACT_PARAM	},
	{	"relative_position",	 StringCode::REL_POSITION	,	StrType::ACT_PARAM	},
	{	"now",					 StringCode::ACT_NOW		,	StrType::ACT_PARAM	},
	{	"delay_time",			 StringCode::DELAY_TIME		,	StrType::ACT_PARAM	},
	{	"device_state",			 StringCode::DEV_STATE		,	StrType::ACT_PARAM	},
	{	"speed",			     StringCode::SPEED			,	StrType::ACT_PARAM	},

	//第三层级  sub act param 是由act param 分解出的参数描述
	{	"speed_num",				StringCode::SPEED_NUM	,	StrType::SUB_ACT_PARAM	},
	{	"speed_name",				StringCode::SPEED_NAME	,	StrType::SUB_ACT_PARAM	}

};


