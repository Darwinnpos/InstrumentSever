#pragma once


#include <iostream>
#include <vector>
#include "interface.h"
#include "abstractDevice.h"

using namespace std;

class CInstrument:public CInterface
{
public:
	CInstrument();
	~CInstrument();
private:
	//CAbstractDevice* m_abstractDevice;

public:


};

CInstrument::CInstrument()
{
}

CInstrument::~CInstrument()
{
}



