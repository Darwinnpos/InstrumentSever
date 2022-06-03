#pragma once


#include <iostream>
#include <vector>
#include "interface.h"
#include "abstractDevice.h"
#include "stepMotorCfg.h"
#include "IOCfg.h"

using namespace std;
//�Ǳ����ǳ����豸�ľ���ʵ��
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




