/*
 * LabWork#304
 * 创建头文件声明函数,一文件定义函数,主文件只调用函数,
 * 读取三角形三边长,如输入合法,计算面积,否则输出错误信息.
 * 其中面积使用海伦公式计算,Area=sqrt(s(s-a)(s-b)(s-c)),s为半周长.
 * 本文件为副文件
 * 2025.12.18
 */
#include "myTri.h"
#include <cmath>
bool is_valid(double a, double b, double c)
{
	return (a + b > c) && (a + c > b) && (b + c > a);
}
double calc_area(double a, double b, double c)
{
	double s = (a + b + c) / 2.0;
	return sqrt(s * (s - a) * (s - b) * (s - c));
}