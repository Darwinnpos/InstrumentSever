#pragma once
#include "define.h"


//约定一些字符串对应的传输时的字符型替代，简化传输的数据量
const String2Int spdParamString2Int[] =
{		//NAME				//OP_INDEX
	{	"VMax",				11	},
	{	"A1",				12	},
	{	"A2",				13	},
	{	"V_A1A2",			14	},
	{	"D1",				15	},
	{	"D2",				16	},
	{	"V_D1D2",			17	},
	{	"VStart",			18	},
	{	"VStop",			19	},
	{	"ACurrentOffset",	20	},
	{	"DCurrentOffset",	21	},
	{	"Default",			22	}
};


//约定一些字符串对应的传输时的字符型替代，简化传输的数据量
const String2Int actModeString2Int[] =
{
	{	"run",		0	},
	{	"run_back", 1	},
	{	"on",		2	},
	{	"off",		3	},
};

//约定一些字符串对应的传输时的字符型替代，简化传输的数据量
const String2Int actParamString2Int[] =
{
	{	"absolute_position",	 0	},
	{	"relative_position",	 1	},
	{	"now",					 2	},
	{	"delay_time",			 3	},
	{	"device_state",			 4	},
	{	"speed",			     5	},
};




