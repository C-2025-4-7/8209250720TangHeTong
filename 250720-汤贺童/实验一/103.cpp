/*
* LabWork#103
* 验证基本数据类型的长度
* 2025.11.12/11.17
*/
#include<iostream>

int main()
{
	std::cout << "Data Type\tLength"
		<< "\n\nchar\t\t" << sizeof(char)
		<< "\nint\t\t" << sizeof(int)
		<< "\nshort\t\t" << sizeof(short)
		<< "\nlong\t\t" << sizeof(long)
		<< "\nfloat\t\t" << sizeof(float)
		<< "\ndouble\t\t" << sizeof(double)
		<< "\nlong double\t" << sizeof(long double)
		<< "\nwchar_t\t\t" << sizeof(wchar_t)
		<< "\n";
	return 0;
}