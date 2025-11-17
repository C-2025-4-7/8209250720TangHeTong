/*
* LabWork#206
* 求两个正整数的最大公约数与最小公倍数
* 2025.11.14/11.17
*/
#include<iostream>
#include<vector>
#include<string>
#include<sstream>

//计算最大公约数的函数
static int calculate_gcd(int a, int b)
{
	//使用欧几里得算法迭代计算最大公约数
	while (b != 0)
	{
		int c = b;
		b = a % b;
		a = c;
	}
	//原理:用较大数除以较小数,若余数不为0,则用较小数
	//除以余数,直到余数为0时,较小数即为最大公约数,
	//这里如果a<b,则第一次迭代时会自动交换a,b的值
	return a;
}

int main()
{
	//使用vector存储输入的两个正整数及其名称
	std::vector<int> nums(2);
	std::vector<std::string> num_names = { "a", "b" };
	std::cout << "Awaiting input\n";
	//输入两个正整数
	for (int i = 0; i < 2; ++i)
	{
		while (true)
		{
			std::cout << num_names[i] << "=";
			if (!(std::cin >> nums[i]))
			{
				std::cout << "Not a number.\n";
				std::cin.clear();
				std::cin.ignore(10000, '\n');
				continue;
			}
			if (nums[i] <= 0)
			{
				std::cout << "Not a positive integer.\n";
				std::cin.clear();
				std::cin.ignore(10000, '\n');
				continue;
			}
			std::cin.ignore(10000, '\n');
			break;
		}
	}
	//将输入赋值给变量a,b
	int a = nums[0];
	int b = nums[1];

	int gcd = calculate_gcd(a, b);
	int lcm = a / gcd * b; //先除后乘可以避免溢出

	std::cout << "Greatest Common Divisor is:" << gcd
		<< "\nLeast Common Multiple is:" << lcm << "\n";

	return 0;
}