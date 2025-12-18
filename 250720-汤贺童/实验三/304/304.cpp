/*
 * LabWork#304
 * 创建头文件声明函数,一文件定义函数,主文件只调用函数,
 * 读取三角形三边长,如输入合法,计算面积,否则输出错误信息.
 * 其中面积使用海伦公式计算,Area=sqrt(s(s-a)(s-b)(s-c)),s为半周长.
 * 本文件为源文件
 * 2025.12.18
 */
#include "myTri.h"
#include <iostream>
int main() {
	double a, b, c;
	std::cout << "请输入三角形的三边长(以空格或回车分隔):";
	std::cin >> a >> b >> c;
	if (is_valid(a, b, c))
	{
		double area = calc_area(a, b, c);
		std::cout << "三角形的面积为:" << area << std::endl;
	}
	else
	{
		std::cout << "输入的边长不能构成三角形!" << std::endl;
	}
	return 0;
}