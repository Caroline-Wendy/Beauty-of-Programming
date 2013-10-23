/*From Beauty of Programming, By C.L.Wang*/
/*编程之美1.1 让CPU占用率曲线听你的指挥*/
/*计算busy和idle的时间, 使用空循环和sleep()进行处理*/

#include "stdafx.h"

#include <iostream>
#include <cstdlib>
#include <cmath>

#include <windows.h>

const int SAMPLING_COUNT = 200; //抽样点数量
const double PI = 3.1415926535;
const int TOTAL_AMPLITUDE = 300; //整个振幅

int main(void){
	SetThreadAffinityMask(GetCurrentThread(), 1); //使用单核
	DWORD busySpan[SAMPLING_COUNT];
	int amplitude= TOTAL_AMPLITUDE/2; //振幅
	double radian= 0.0; //半径
	double radianIncrement = 2.0 / static_cast<double>(SAMPLING_COUNT); //半径增加量
	for(int i=0; i<SAMPLING_COUNT; i++){
		/*系统忙的时间在2倍振幅和0之间*/
		busySpan[i] = (DWORD)(amplitude+(sin(PI*radian)*amplitude)); 
		radian += radianIncrement; //振幅在0-2之间
		std::cout << "Busy Time: " << busySpan[i] << " "
			<< "Idle Time: " << TOTAL_AMPLITUDE-busySpan[i] << std::endl;
	}
	DWORD startTime = 0;
	/*无限循环, 忙用空循环, 空闲用sleep()*/
	for(int j=0; ; j=(j+1)%SAMPLING_COUNT){
		startTime = GetTickCount();
		while((GetTickCount()-startTime)<= busySpan[j])  //Busy
			;
		Sleep(TOTAL_AMPLITUDE-busySpan[j]); //Idle
	}
	return 0;
}