/*
 * LabWork#401
 * 打印不同的数
 * 读入10个数, 将其中不同的数打印出来
 * 2025.12.18
 */
#include <iostream>

int main() {
	double numbers[10] = { 0 };
	bool is_unique = true;
	std::cout << "请输入10个数\n";
	for (int i = 0; i < 10; i++)
	{
		if (!(std::cin >> numbers[i]))
		{
			std::cout << "输入无效,请输入数字.\n";
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			i--;
		}
	}
	std::cout << "不同的数有:\n";
	for (int i = 0; i < 10; i++)
	{
		is_unique = true;
		for (int j = 0; j < i; j++)
		{
			if (numbers[i] == numbers[j])
			{
				is_unique = false;
				break;
			}
		}
		if (is_unique)
		{
			std::cout << numbers[i] << "\t";
		}
	}
	std::cout << std::endl;
	return 0;
}