 /*From Beauty of Programming, By C.L.Wang*/
/*题目参见 编程之美 P189*/
/*编程之美2.15 子数组之和的最大值(二维)*/
/*一维子数组之和的推广, 采用确定上下边界之后, 进行动态规划*/
/*时间复杂度: O(N*M*min(M,N)=O(N^2*M)*/
#include "stdafx.h"
#include <iostream>
#include <climits> //包含最大最小值
#include <vector>
#include <string>
using namespace std;
int segValue(int A[][4], const int& a, const int& c, const int& m){
 if(a > c){
  std::cerr << "The first value should be small than the second value." << std::endl;
 }
 int totalnum(0);
 for(int i=a; i<=c; i++){
  totalnum += A[i][m];
 }
 return totalnum;
}
inline int max(const int& x, const int& y){
 return (x>y)? x : y;
}
int maxSum2D(int A[][4], const int& n, const int& m){
 int maxinum = INT_MIN;
 int middlenum(0); //中间值
 int startnum(0); //起始值
 int allnum(0); //总值
 for(int i=0; i<n; ++i){
  for(int j=i; j<n; ++j){
   startnum = segValue(A, i, j, m-1);
   allnum = segValue(A, i, j, m-1);
   for(int k=m-2; k>=0; --k){
    middlenum = segValue(A, i, j, k);
    startnum = max(middlenum, startnum+middlenum);
    allnum = max(startnum, allnum);
   }
   maxinum = max(maxinum, allnum);
  }
 }
 return maxinum;
}
int main(void){
 int A[][4] = {
  1, 2, -3, 4,
  -1, 2, 3, -4,
  -1, 2, 3, -4,
  -1, -2, -3, -4};
 int result = maxSum2D(A, 4, 4);
 std::cout << "result = " << result << std::endl;
}