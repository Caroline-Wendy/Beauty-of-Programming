/*From Beauty of Programming, By C.L.Wang*/
/*编程之美2.12 快速寻找满足条件的两个数*/
/*采用先排序, 然后收尾相加, 向内查找, 直到首次找到为止*/

#include "stdafx.h"

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(const double& x, const double& y){
	return (x < y);
}

bool findSum(std::vector<double>& ia, 
			 const double sum, double& x, double& y){
	std::sort(ia.begin(), ia.end());
	unsigned int size = ia.size();
	for(int i=0, j=size-1; i<j; ){
		if((ia[i]+ia[j])==sum){
			x=ia[i];
			y=ia[j];
			break;
		}else if((ia[i]+ia[j])<sum){
			i++;
		}else{
			j--;
		}
	}
	if((x+y)==sum){
		return true;
	}else{
		return false;
	}
}

int main(void){
	double arr[7] = {5,6,1,4,7,9,8};
	vector<double> ia;
	for(unsigned int i=0; i<7; i++){
		ia.push_back(arr[i]);
	}
	double x, y;
	double sum(10);
	if(findSum(ia, sum, x, y)){
		std::cout << "sum = " << sum
			<< " x = " << x << " y = " << y
			<< std::endl;
	}else{
		std::cout << "Sorry! " << std::endl;
	}
	return 0;
}