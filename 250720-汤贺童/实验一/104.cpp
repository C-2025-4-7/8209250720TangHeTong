/*
* LabWork#104
* 观察不同数据类型对输出结果的影响
* 2025.11.12/11.17
*/
#include<iostream>
#include<iomanip>

int main()
{
	unsigned int testUnint = 65534;//0xFFFE
	std::cout << "output 65534 in..."
		<< "\n\tunsigned int type :\t " << testUnint
		<< "\n\tOct unsigned int type:\t" << std::oct << testUnint << std::dec
		<< "\n\tchar type:" << static_cast<char>(testUnint)
		//char截取低8位,变为0xFE,即254,对应的ASCII字符是非打印字符,什么都不会显示
		<< "\n\tshort type:\t\t" << static_cast<short>(testUnint)
		//有符号的short范围是-32768到32767,这里发生补码
		<< "\n\tint type:\t\t" << static_cast<int>(testUnint)
		<< "\n\tdouble type:\t\t" << static_cast<double>(testUnint)
		<< "\n\tdouble type (4):\t" << std::setprecision(4) << static_cast<double>(testUnint)
		<< "\n\tHex unsigned int type:\t" << std::hex << testUnint << std::dec;
	return 0;
}