/*
* LabWork#202
* 输入x计算表达式的值
* 2025.11.13/11.17
*/
#include<iostream>

int main()
{
	double x = 1.0;
	std::cout << "Awaiting input x (0<x<10)\n";
	std::cin >> x;
	//检验输入
	if (x <= 0 || x >= 10)
	{
		std::cout << "Inputted x is beyond domain of definition!";
		return -1;
	}
	//主体部分
	if (x < 1)
	{
		std::cout << "y=" << 3 - 2 * x;
	}
	else if (x < 5)
	{
		std::cout << "y=" << 2.0 / (4 * x) + 1;
	}
	else
	{
		std::cout << "y=" << x * x;
	}
	return 0;
}