#include <iostream>
#include <string>

int main()
{
	unsigned u = 10 , u2 = 42;
	std::cout << u2 - u << std::endl;
	std::cout << u - u2 << std::endl;
	
	int i = 10 , i2 = 42;
	std::cout << i2 - i <<std::endl;
	std::cout << i - i2 <<std::endl;
	std::cout << i-u <<std::endl;
	std::cout << u - i <<std::endl;
	
	//char a = 145;
	std::cout << "Who goes with F\145rgus?\012" << std::endl;
	long double b = 3.14e1L ;
	std::cout << b << std::endl;
	float c = 1024.0f ;
	std::cout << c << std::endl;
	long double d = 3.14L ;
	std::cout << d << std::endl;
	
	return 0;
}