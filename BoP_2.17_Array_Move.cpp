/*
 * HelloWorld.cpp
 *
 *  Created on: 2013.11.7
 *      Author: Caroline
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main (void) {
	std::vector<std::string> sv =
	{"a", "b", "c", "d", "1", "2", "3", "4"};
	unsigned int n = 4;
	std::cout << "array : ";
	for(const auto s : sv)
		std::cout << s << " ";
	std::cout << std::endl;
	std::reverse(sv.begin(), sv.begin()+4);
	std::reverse(sv.begin()+4, sv.end());
	std::reverse(sv.begin(), sv.end());
	std::cout << "reverse (" << n <<") : ";
	for(const auto s : sv)
		std::cout << s << " ";
	std::cout << std::endl;
	return 0;
}



