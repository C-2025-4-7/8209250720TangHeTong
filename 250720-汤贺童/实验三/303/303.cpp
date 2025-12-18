/*
 * LabWork#303
 * 实现头文件,包含两个函数,分别用于将华氏度
 * 转换为摄氏度和反过来,并保留两位小数
 * 此处的主程序只调用函数,头文件只有函数声明,函数定义写在另一文件
 * 调用函数显示如下结果：
 * Celsius	Fahrenheit	|	Fahrenheit	Celsius
 *	40.0	105.0		|	120.0		48.89
 *	39.0	102.0		|	110.0		43.33
 *	...		...			|	...			...
 *	31.0	87.8		|	30.0		-1.11
 * (这里的示例是题目给出的,数值可能不准确)
 * 2025.12.18
 */
#include <iostream>
#include <iomanip>
#include "myTemp.h"

int main()
{
	std::cout << "Celsius    Fahrenheit  |  Fahrenheit    Celsius\n";
	for (double celsius = 40.0, fahrenheit = 120.0;
		celsius >= 31.0 && fahrenheit >= 30.0; celsius -= 1.0, fahrenheit -= 10.0)
	{
		double convertedFahrenheit = celsius_to_fah(celsius);
		double convertedCelsius = fahrenheit_to_cels(fahrenheit);
		std::cout << std::fixed << std::setprecision(2)
			<< std::setw(7) << celsius << "    "
			<< std::setw(10) << convertedFahrenheit << "  |  "
			<< std::setw(10) << fahrenheit << "    "
			<< std::setw(7) << convertedCelsius << "\n";
	}
	return 0;
}