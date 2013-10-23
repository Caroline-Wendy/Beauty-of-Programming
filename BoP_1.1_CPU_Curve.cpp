/*From Beauty of Programming, By C.L.Wang*/
/*���֮��1.1 ��CPUռ�������������ָ��*/
/*����busy��idle��ʱ��, ʹ�ÿ�ѭ����sleep()���д���*/

#include "stdafx.h"

#include <iostream>
#include <cstdlib>
#include <cmath>

#include <windows.h>

const int SAMPLING_COUNT = 200; //����������
const double PI = 3.1415926535;
const int TOTAL_AMPLITUDE = 300; //�������

int main(void){
	SetThreadAffinityMask(GetCurrentThread(), 1); //ʹ�õ���
	DWORD busySpan[SAMPLING_COUNT];
	int amplitude= TOTAL_AMPLITUDE/2; //���
	double radian= 0.0; //�뾶
	double radianIncrement = 2.0 / static_cast<double>(SAMPLING_COUNT); //�뾶������
	for(int i=0; i<SAMPLING_COUNT; i++){
		/*ϵͳæ��ʱ����2�������0֮��*/
		busySpan[i] = (DWORD)(amplitude+(sin(PI*radian)*amplitude)); 
		radian += radianIncrement; //�����0-2֮��
		std::cout << "Busy Time: " << busySpan[i] << " "
			<< "Idle Time: " << TOTAL_AMPLITUDE-busySpan[i] << std::endl;
	}
	DWORD startTime = 0;
	/*����ѭ��, æ�ÿ�ѭ��, ������sleep()*/
	for(int j=0; ; j=(j+1)%SAMPLING_COUNT){
		startTime = GetTickCount();
		while((GetTickCount()-startTime)<= busySpan[j])  //Busy
			;
		Sleep(TOTAL_AMPLITUDE-busySpan[j]); //Idle
	}
	return 0;
}