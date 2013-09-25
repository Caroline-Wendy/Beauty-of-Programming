/*From Beauty of Programming, By C.L.Wang*/
/*约束条件: 输入数据不宜过大*/

#include <iostream>
#include <vector>

using namespace std;

bool search_num(long long int& result,const int my_num){

	/*初始化*/
	vector<long long int> r_vec(my_num);
	for(unsigned int i=0; i<r_vec.size(); i++)
		r_vec[i] = -1;

	r_vec[0] = 0; //0整除余0
	r_vec[1] = 1; //1整除余1

	unsigned int temp(0); //余数
	long long int temp_num(0); //1&0整数

	int begin(2); //起始个数
	int count(0); //遍历次数
	int update(0); //数据增加个数

	/*10的倍数渐增*/
	for (int i=10; ; i*=10){

		/*遍历所有余数级*/
		for(unsigned int j=0; j<r_vec.size(); j++){

			if(r_vec[j] != -1){

				count++;

				temp_num =  i+r_vec[j]; //被除数
				temp = temp_num % my_num; //余数

				/*未初始化 或 小于 置换*/
				if(r_vec[temp] == -1 || r_vec[temp] > temp_num){
					r_vec[temp] = temp_num;
					update++;
				}

				/*返回余数为0的数*/
				if(temp == 0){
					result = temp_num;
					return true;
				}

				/*次数等于数组元素个数停止*/
				if(count == begin)
					break;
			}
		}

		/*更新*/
		begin += update;
		update = 0;
		count = 0;

	}

	return false;
}

int main(){

	vector<vector<int>> remainder_array;
	int my_num(-1);
	long long int result;

	std::cout << "Please input your number: " << std::endl;
	std::cin >> my_num;

	if(!search_num(result, my_num)){
		std::cout << "Sorry, the result is too large! " << std::endl;
	}else{
		std::cout << "The 0-1 number: " << result << std::endl;
		std::cout << "The result: " << result/my_num << std::endl;
	}

	return 0;
}