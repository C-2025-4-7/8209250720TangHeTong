/*
 * LabWork#303
 * 实现头文件,包含两个函数,分别用于将华氏度
 * 转换为摄氏度和反过来,并保留两位小数
 * 主程序只调用函数,此处的头文件只有函数声明,函数定义写在另一文件
 * 2025.11.16
 */
#ifndef TEMPERATURE_CONVERSION_H
#define TEMPERATURE_CONVERSION_H
 //将摄氏度转换为华氏度
double celsius_to_fah(double celsius);
//将华氏度转换为摄氏度
double fahrenheit_to_cels(double fahrenheit);
#endif //TEMPERATURE_CONVERSION_H