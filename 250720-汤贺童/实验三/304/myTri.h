/*
 * LabWork#304
 * 创建头文件声明函数,一文件定义函数,主文件只调用函数,
 * 读取三角形三边长,如输入合法,计算面积,否则输出错误信息.
 * 其中面积使用海伦公式计算,Area=sqrt(s(s-a)(s-b)(s-c)),s为半周长.
 * 本文件为头文件
 * 2025.12.18
 */
#ifndef TRIANGLE_AREA_H
#define TRIANGLE_AREA_H
bool is_valid(double a, double b, double c);
double calc_area(double a, double b, double c);
#endif // TRIANGLE_AREA_H