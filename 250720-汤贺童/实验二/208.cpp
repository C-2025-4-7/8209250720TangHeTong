/*
* LabWork#208
* 迭代法求a的平方根
* 另:
*	对于负数,输出虚数.
* 2025.11.14/11.17
*/
#include<iostream>
#include<cmath>

int main()
{
	double a = 0;
	std::cout << "Awaiting input\n";
	while (!(std::cin >> a))//输入检测
	{
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "Not a number.\nPlease enter a valid number:";
	}
	bool sign = true;//正负号
	if (a < 0)//负数
	{
		a = -a;
		sign = false;
	}
	double i = a;//前一次迭代值
	double j = 0.0;//本次迭代值
	double diff = 1.0;//差值
	while (diff >= 1.0e-10)//精度
	{
		j = (i + a / i) * 0.5;
		diff = fabs(j - i);
		i = j;
	}
	std::cout << "The square root of " << a << " is approximately " << j;
	if (sign)
		std::cout << "\n";
	else
		std::cout << "i\n";
	return 0;
}

//处理复数输入太复杂,计算与输出则几乎没区别,不整了.