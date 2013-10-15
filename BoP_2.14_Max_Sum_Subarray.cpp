/*From Beauty of Programming, By C.L.Wang*/
/*题目参见 编程之美 P183*/
/*编程之美2.14 求数组的子数组之和的最大值*/
/*非常非常经典的题, 使用动态规划, 从后面开始比较, 
判断依次加入新值之后的最大值, 和单个值比较, 
然后再和总的最大值比较*/
/*时间复杂度: O(N)*/

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