/*From Beauty of Programming, By C.L.Wang*/
/*��Ŀ�μ� ���֮�� P180*/
/*���֮��2.12 ����������˻�*/
/*�ռ任ʱ��, ��һ�α��������������ĳ˻�, �ٱ����Ƚ�ȱһ�����˻��Ĵ�С*/
/*ʱ�临�Ӷ�: O(2N)*/

#include "stdafx.h"

#include <iostream>
#include <vector>

using namespace std;

void productArray(const int srca[], const unsigned int num, int dstOrder[], int dstReverse[]){
	int tempOrder = srca[0];
	int tempReverse = srca[num-1];
	dstOrder[0] = tempOrder;
	dstReverse[num-1] = tempReverse;
	for(unsigned int i=1; i<num; ++i){
		tempOrder *= srca[i];
		dstOrder[i] = tempOrder; 
		tempReverse *= srca[num-1-i];
		dstReverse[num-1-i] = tempReverse; 
	}
}

void findMaxProduct(int& result, const int dstOrder[], const int dstReverse[], const unsigned int size){
	int temp(0);
	result = dstReverse[1];
	for(unsigned int i=0; i<size; ++i){
		if(0 == i){
			temp = dstReverse[i+1];
			if(result < temp)
				result = temp;
			continue;
		}else if((size-1) == i){
			temp = dstOrder[i-1];
			if(result < temp)
				result = temp;
			continue;
		}
		temp = dstOrder[i-1]*dstReverse[i+1];
		if(result < temp)
			result = temp;
	}
}

int main(void){
	const unsigned int size = 5;
	int srca[size] = {17, 3, 4, 5, 12};
	int dstOrder[size]; //�������Ҫ��ʼ����С
	int dstReverse[size];
	int result(0);
	productArray(srca, size, dstOrder, dstReverse);
	findMaxProduct(result, dstOrder, dstReverse, size);
	std::cout << "result = " << result << std::endl;
	return 0;
}