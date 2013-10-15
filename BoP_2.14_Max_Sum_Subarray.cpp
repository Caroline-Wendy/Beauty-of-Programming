/*From Beauty of Programming, By C.L.Wang*/
/*��Ŀ�μ� ���֮�� P183*/
/*���֮��2.14 �������������֮�͵����ֵ*/
/*�ǳ��ǳ��������, ʹ�ö�̬�滮, �Ӻ��濪ʼ�Ƚ�, 
�ж����μ�����ֵ֮������ֵ, �͵���ֵ�Ƚ�, 
Ȼ���ٺ��ܵ����ֵ�Ƚ�*/
/*ʱ�临�Ӷ�: O(N)*/

#include "stdafx.h"

#include <iostream>

using namespace std;

inline int max(const int& x, const int& y){
	return (x>y)? x : y;
}

int maxSum(const int* A, int n){
	int nStart = A[n-1];
	int nAll = A[n-1];
	for(int i=n-2; i>=0; --i){
		nStart = max(A[i], nStart+A[i]);
		nAll = max(nStart, nAll);
	}
	return nAll;
}

int main(void){
	int A[6] = {1, -2, 3, 5, -3, 2};
	int B[6] = {0, -2, 3, 5, -1, 2};
	int C[6] = {-9, -2, -3, -5, -3, -2};
	std::cout << " maxSum(A, 6) = " << maxSum(A, 6) << std::endl;
	std::cout << " maxSum(B, 6) = " << maxSum(B, 6) << std::endl;
	std::cout << " maxSum(C, 6) = " << maxSum(C, 6) << std::endl;
	return 0;
}