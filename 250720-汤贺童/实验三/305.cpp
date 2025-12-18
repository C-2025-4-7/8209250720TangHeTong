/*
 * LabWork#304
 * 猴子吃桃
 * 第一天摘若干桃子,吃掉一半加一个,
 * 第二天再吃掉一半加一个,
 * 这样吃下去,到第n天时,只剩下一个桃子.
 * 求最初摘了多少桃子.
 * 用递归实现
 * 2025.12.18
 */
#include <iostream>

static int peach(int day)
{
	if (day > 10) return 0;//防止超过第十天
	if (day == 10) return 1;//第十天剩下1个桃子
	else return (peach(day + 1) + 1) * 2;//前一天的桃子数
}

int main()
{
	int total = peach(1);
	std::cout << "最初摘了" << total << "个桃子." << std::endl;
	return 0;
}