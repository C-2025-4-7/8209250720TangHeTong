/*
* LabWork#209
* 买苹果,每个0.8元,每第n天买2^n个苹果,直到购买的苹
* 果数为不超过100的最大值,求每天平均花多少钱.
* 另:
*	允许用户输入每次购买苹果的上限和每个苹果的价格,
* 2025.11.14/11.17
*/
#include <iostream> 

int main()
{
	int max_apples = 100;
	double price_per_apple = 0.8;
	std::cout << "累计购买的苹果数上限(默认值为" << max_apples << "个):";
	if (!(std::cin >> max_apples))
	{
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		max_apples = 100;
		std::cout << "输入无效,使用默认值" << max_apples << "个\n";
	}
	std::cout << "每个苹果价格(默认值为" << price_per_apple << "元):\n";
	if (!(std::cin >> price_per_apple))
	{
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		price_per_apple = 0.8;
		std::cout << "输入无效,使用默认值" << price_per_apple << "元\n";
	}
	int n = 1;
	int total_apples = 0;
	double cost = 0.0;
	while (true)
	{
		int apples_today = 1 << n;//2^n
		if (total_apples + apples_today > max_apples)
			break;
		total_apples += apples_today;
		cost += apples_today * price_per_apple;
		n += 1;
	}
	int day = n - 1;//减去最后一次超出100的天数
	if (day == 0)
		std::cout << "没有购买任何苹果\n";
	else
	{
		double average = cost / day;
		std::cout << "过了" << day << "天\n总共花了" << cost << "元买了"
			<< total_apples << "个苹果\n每天平均花费:" << average << "元\n";

	}
	return 0;
}

//这次用中文输出,在其他设备上不一定能正常显示.