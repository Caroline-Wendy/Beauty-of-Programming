/*From Beauty of Programming, By C.L.Wang*/
/*编程之美2.11 寻找最近点对*/
/*分治思想, 递归算法, 时间复杂度O(N*log2(N)), 其中按Y值排序没有写*/

#include "stdafx.h"

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

typedef unsigned int uint;

#define MAX_INT ((unsigned)(-1)>>1)

struct point{
	double x;
	double y;
};

/*两点之间的距离*/
double pointsDistance(const point& p1, const point& p2)
{
	double xd = std::pow((p1.x - p2.x), 2);
	double yd = std::pow((p1.y - p2.y), 2);
	return sqrt(xd + yd);
}

/*多点之间的最小距离*/
double shortestDistance(const point* pa, const uint& num){
	if(num < 2)
		std::cerr << "Number should be >= 2. " << std::endl;
	double result = pointsDistance(pa[0], pa[1]); //最小距离
	double temp = -1;
	for(uint i=0; i<num; i++){
		for(uint j=i+1; j<num; j++){
			temp = pointsDistance(pa[i], pa[j]);
			if(temp < result)
				result = temp;
		}
	}
	return result;
}

bool comparePointY(const point& p1, const point& p2){
	return (p1.y < p2.y);
}

/*找到最小的距离*/
double findShortestDistance(const point* pa, const uint& num){
	if(num == 2)
		return shortestDistance(pa, 2);
	if(num == 1)
		return MAX_INT;
	uint mid(0); //中值
	double dleft(0.0); //左距离
	double dright(0.0); //右距离
	double dmiddle(0.0); //中间距离
	double dmin(0.0); //最小距离
	mid = (num+1)/2;
	dleft = findShortestDistance(pa, mid);
	dright = findShortestDistance(pa+mid, (num-mid));
	dmin = (dleft<dright) ? dleft : dright;
	uint distBeg(MAX_INT);
	uint distEnd(0);
	uint size(0);

	/*寻找中间距离近的点的区域*/
	for (uint i=0; i<num; i++){
		if ( pa[i].x>(pa[mid-1].x-dmin) || pa[i].x<(pa[mid-1].x+dmin) ){
			distEnd = i;
			if(distEnd < distBeg)
				distBeg = distEnd;
		}
	}
	if((distEnd-distBeg+1) >= 2){
		dmiddle = shortestDistance(pa+distBeg, distEnd-distBeg+1);
	}
	if(dmiddle < dmin)
		dmin = dmiddle;
	return dmin;
}

int main(void){
	point p1 = {1, 1};
	point p2 = {3, 2};
	point p3 = {3, 7};
	point p4 = {4, 4};
	point p5 = {5, 6};
	point p6 = {5, 10};
	point p7 = {6, 12};
	point p8 = {7, 3};
	point pa[8] = {p1, p2, p3, p4, p5, p6, p7, p8};
	std::cout << "最近点对 = " << findShortestDistance(pa, 8) << std::endl;
	return 0;
}