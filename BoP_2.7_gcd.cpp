/*From Beauty of Programming, By C.L.Wang*/

#include <iostream>

using namespace std;

typedef unsigned long long int ULLI;

bool isEven(const ULLI& x){
	unsigned int temp;
	temp = x%2;
	if(temp == 0){
		return true;
	}else{
		return false;
	}
}

ULLI gcd(const ULLI& x, const ULLI& y){
	if(x < y) return gcd(y, x);
	if(y==0){
		return x;
	}else{
		if(isEven(x)){
			if(isEven(y))
				return (gcd(x>>1, y>>1) << 1);
			else
				return gcd(x>>1, y);
		}else{
			if(isEven(y)) 
				return gcd(x, y>>1);
			else
				return gcd(y, x-y);
		}
	}
}

int main(void){
	//x = 125478536; y = 1631220968;
	ULLI x, y, z;
	std::cout << "Please input two numbers:" << std::endl;
	std::cin >> x >> y;
	std::cout << "Thanks! The numbers are " << x 
		<< " and " << y << ". " << std::endl;
	z = gcd(x, y);
	std::cout << "The greatest common divisor is " 
		<< z << ". " << std::endl;
	return 0;
}

/*simple method*/
ULLI simple_gcd(const ULLI& x,const ULLI& y){
	return (!y)?x:simple_gcd(y, x%y);
}