#include "instrument.h"



CInstrument::CInstrument()
{
	abstractDevice = new CAbstractDevice();
	motorCfg = new CMotorCfg();
	IOCfg = new CIOCfg();
}

CInstrument::~CInstrument()
{
	delete(abstractDevice);
	delete(motorCfg);
	delete(IOCfg);
}
