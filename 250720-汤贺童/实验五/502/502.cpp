/*
 * LabWork#502
 * 分别给出3个文件:含类定义的头文件,含成
 * 员函数定义的源文件,含主函数的源文件.
 * 请完善该程序,在类中增加一个对数据成员
 * 赋初值的成员函数set_value.
 * 此处为含主函数的源文件.
 * 2026.01.07
 */
#include "student.h"
int main()
{
	Student student1;
	student1.set_value(123, "Zhang San", 'M');
	student1.display();
	return 0;
}