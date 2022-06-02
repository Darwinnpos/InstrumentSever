#pragma once

#include <iostream>
#include <vector>
#include <map>
using namespace std;

//����˳��ṹ
typedef struct ActInfo
{
	string actMode;  
	vector<string> actParam;  //�����豸���е�һ�Ѳ���
}ActInfo;

typedef struct DevActInfo
{
	string device_name;
	ActInfo actInfo;         //һ���豸�����������еĲ���
}DevActInfo;

//һ����ʱ������ ֧����һ�����������ִ�� �Ӷ������������Ĳ���
typedef struct subTiming
{
	string name;
	bool nextActRunNow; //֧�ִ��кͲ���
	vector<DevActInfo> actInfoGroup; //һ���豸���ж���
}subTiming;

typedef struct Timing
{
	string name;
	//��֧�ֲ���
	vector<subTiming> TimingVec;
}Timing;


typedef struct Flow
{
	string name;
	Timing timing;
}Flow;

class CFlow
{
public:
	CFlow();
	~CFlow();

private:

public:
	int FlowExe(Flow flow);
};

