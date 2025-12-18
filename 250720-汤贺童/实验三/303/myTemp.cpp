/*
 * LabWork#303
 * 实现头文件,包含两个函数,分别用于将华氏度
 * 转换为摄氏度和反过来,并保留两位小数
 * 主程序只调用函数,头文件只有函数声明,函数定义写在此处
 * 2025.11.16
 */
#include "myTemp.h"
 //将摄氏度转换为华氏度
double celsius_to_fah(double celsius) {
	double fahrenheit = (celsius * 1.8) + 32;
	return fahrenheit;
}
//将华氏度转换为摄氏度
double fahrenheit_to_cels(double fahrenheit) {
	double celsius = (fahrenheit - 32) / 1.8;
	return celsius;
}