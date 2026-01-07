/*
 * LabWork#502
 * 分别给出3个文件:含类定义的头文件,含成
 * 员函数定义的源文件,含主函数的源文件.
 * 请完善该程序,在类中增加一个对数据成员
 * 赋初值的成员函数set_value.
 * 此处为头文件.
 * 2026.01.07
 */
#ifndef STUDENT_H
#define STUDENT_H
class Student {
private:
	int id;
	char name[20];
	char sex;
public:
	void set_value(int i, const char* n, char s);
	void display() const;
};
#endif