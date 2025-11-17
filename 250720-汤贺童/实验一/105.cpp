/*
* LabWork#105
* 输入华氏温度,将其转换为摄氏温度后输出,保留两位小数
* 2025.11.12/11.17
*/
#include<iostream>
#include<iomanip>

int main()
{
	double F = 0;
	std::cout << "Awaiting input (in Fahrenheit):";
	std::cin >> F;
	std::cout << "Converted to Celsius:\t" << std::fixed
		<< std::setprecision(2) << (F - 32) / 1.8;
	return 0;
}