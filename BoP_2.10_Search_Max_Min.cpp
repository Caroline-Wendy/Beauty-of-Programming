/*From Beauty of Programming, By C.L.Wang*/
/*又是迭代, 采用分治思想, 每次求N/2的max和min*/

#include "stdafx.h"

#include <iostream>

struct max_min{
	int max;
	int min;
};

max_min search_max_min(const int arr[], const int b, const int e){

	max_min mm; //返回结果
	max_min lmm; //左侧最值
	max_min rmm; //右侧最值

	/*最后两个数返回*/
	if(e-b<=1){
		if(arr[b] < arr[e]){
			mm.max = arr[e];
			mm.min = arr[b];
			return mm;
		}else{
			mm.max = arr[b];
			mm.min = arr[e];
			return mm;
		}
	}

	/*迭代*/
	lmm = search_max_min(arr, b, b+(e-b)/2);
	rmm = search_max_min(arr, b+(e-b)/2+1, e);

	/*左右比较求最值*/
	if(lmm.max > rmm.max)
		mm.max = lmm.max;
	else
		mm.max = rmm.max;

	if(lmm.min > rmm.min)
		mm.min = rmm.min;
	else
		mm.min = lmm.min;
		
	return mm;

}

int _tmain(int argc, _TCHAR* argv[]){

	int arr[] = {1, 2, 8, 4, 5, 0, 7};
	int b(0);
	int e(sizeof(arr)/sizeof(*arr)-1);
	max_min mm;

	mm = search_max_min(arr, b, e);

	std::cout << " max = " << mm.max << "\t"
		<< "min = " << mm.min << std::endl;

	return 0;

}

