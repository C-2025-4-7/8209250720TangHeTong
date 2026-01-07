/*
 * LabWork#501
 * 改写程序，要求：
 * 将数据成员改为私有的；
 * 将输入和输出的功能改为由成员函数实现；
 * 在类体内定义成员函数。
 * 分析:成员的公有和私有,
 * 类内和类外定义的成员函数.
 * 2026.01.07
 */
#include <iostream>

class Time
{
private:
	//类的内部状态数据通常设为私有,
	//仅在类内部使用的辅助函数通常也是私有的.
	int hour;
	int minute;
	int second;
	bool isValidTime(int h, int m, int s) const
	{
		//私有辅助函数,验证时间有效性
		return (h >= 0 && h < 24) && (m >= 0 && m < 60) && (s >= 0 && s < 60);
	}
public:
	//对外提供服务的接口函数通常应设为公有的,
	//构造函数,析构函数等通常也是公有的,
	//如果需要访问私有数据,应提供公有的get和set函数.
	//简单短小的函数最好放在类中定义.另外,
	//在类体内定义的成员函数默认为内联函数.
	Time(int h = 0, int m = 0, int s = 0)
	{
		//构造函数
		setTime(h, m, s);
	}
	~Time()
	{
		//析构函数,此处无动态分配资源,无需特殊处理
	}
	void setTime(int h, int m, int s)
	{
		//修改器setter
		if (!isValidTime(h, m, s))
		{
			std::cout << "Invalid time! Setting to 00:00:00." << std::endl;
			h = m = s = 0;
		}
		hour = h;
		minute = m;
		second = s;
	}
	void getTime(int& h, int& m, int& s) const
	{
		//访问器getter
		h = hour;
		m = minute;
		s = second;
	}
	void printTime() const
	{
		//输出时间
		std::cout << (hour < 10 ? "0" : "") << hour << ":"
			<< (minute < 10 ? "0" : "") << minute << ":"
			<< (second < 10 ? "0" : "") << second << std::endl;
	}
	void inputTime()
	{
		//输入时间
		int h, m, s;
		std::cout << "Enter time (hh mm ss): ";
		std::cin >> h >> m >> s;
		setTime(h, m, s);
	}
};
//理论上,复杂而代码量大的函数,最好在类体外定义,以减少编译时间,
//但是,事实上,现代编译器会自动判断是否要内联函数,
//于是类体内外定义函数的区别只在于代码组织和可读性.
//另外,如果是需要在多个源文件中共享的函数,则应在头文件中声明,
//以便多个源文件包含该头文件时,都能访问该函数.

int main()
{
	Time t1;//定义t1为Time类对象
	t1.inputTime();//输入时间
	t1.printTime();//输出时间
	return 0;
}