/*From Beauty of Programming, By C.L.Wang*/
/*Լ������: �������ݲ��˹���*/

#include <iostream>
#include <vector>

using namespace std;

bool search_num(long long int& result,const int my_num){

	/*��ʼ��*/
	vector<long long int> r_vec(my_num);
	for(unsigned int i=0; i<r_vec.size(); i++)
		r_vec[i] = -1;

	r_vec[0] = 0; //0������0
	r_vec[1] = 1; //1������1

	unsigned int temp(0); //����
	long long int temp_num(0); //1&0����

	int begin(2); //��ʼ����
	int count(0); //��������
	int update(0); //�������Ӹ���

	/*10�ı�������*/
	for (int i=10; ; i*=10){

		/*��������������*/
		for(unsigned int j=0; j<r_vec.size(); j++){

			if(r_vec[j] != -1){

				count++;

				temp_num =  i+r_vec[j]; //������
				temp = temp_num % my_num; //����

				/*δ��ʼ�� �� С�� �û�*/
				if(r_vec[temp] == -1 || r_vec[temp] > temp_num){
					r_vec[temp] = temp_num;
					update++;
				}

				/*��������Ϊ0����*/
				if(temp == 0){
					result = temp_num;
					return true;
				}

				/*������������Ԫ�ظ���ֹͣ*/
				if(count == begin)
					break;
			}
		}

		/*����*/
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