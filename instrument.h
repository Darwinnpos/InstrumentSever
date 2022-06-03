#pragma once


#include <iostream>
#include <vector>
#include "interface.h"
#include "abstractDevice.h"
#include "stepMotorCfg.h"
#include "IOCfg.h"

using namespace std;
//仪表类是抽象设备的具体实现
class CInstrument:public CInterface
{
public:
	CInstrument();
	~CInstrument();
private:
	CAbstractDevice* abstractDevice;
	CMotorCfg* motorCfg;
	CIOCfg* IOCfg;
public:


};




