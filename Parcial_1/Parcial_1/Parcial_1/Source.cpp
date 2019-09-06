#include<iostream>
#include"Buffer.h"

int main() {
	Buffer<int> buf;
	buf.init(3, 3);
	buf.printBuffer();
	std::cout << std::endl<<buf.get(2,1);
	std::cout << std::endl;

	buf.set(2, 1, 90);
	std::cout << std::endl<<buf.get(2,1); 
	std::cout << std::endl;
	
	buf.printBuffer();
	std::cout << std::endl;
	system("pause");

	return 0;
}