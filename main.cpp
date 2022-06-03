
#include "instrument.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    //确保实现测试函数   
    CInstrument::GetInstance()->ClearIOCfg();
    std::cout << "Hello World!\n" << endl;
    return 0;
}