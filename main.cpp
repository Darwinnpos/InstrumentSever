
#include "instrument.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    //ȷ��ʵ�ֲ��Ժ���   
    CInstrument::GetInstance()->ClearIOCfg();
    std::cout << "Hello World!\n" << endl;
    return 0;
}