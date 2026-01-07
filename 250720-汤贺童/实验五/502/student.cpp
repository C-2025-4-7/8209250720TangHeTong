/*
 * LabWork#502
 * 分别给出3个文件:含类定义的头文件,含成
 * 员函数定义的源文件,含主函数的源文件.
 * 请完善该程序,在类中增加一个对数据成员
 * 赋初值的成员函数set_value.
 * 此处为含成员函数定义的源文件.
 * 2026.01.07
 */
#include "student.h"
#include <iostream>
void Student::set_value(int i, const char* n, char s)
{
	id = i;
	//在Visual Studio编译器中使用strncpy会报错,改为手动复制
	size_t j = 0;
	for (; j < 19 && n[j] != '\0'; ++j)
		name[j] = n[j];
	name[j] = '\0';
	sex = s;
}
void Student::display() const
{
	std::cout << "ID: " << id << std::endl;
	std::cout << "Name: " << name << std::endl;
	std::cout << "Sex: " << sex << std::endl;
}