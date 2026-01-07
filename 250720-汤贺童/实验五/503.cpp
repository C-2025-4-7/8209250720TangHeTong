/*
 * LabWork#503
 * 由键盘分别输入3个长方柱的长,宽,高,
 * 计算并输出3个长方柱的体积.
 * 数据成员包括length,width,height.
 * 用成员函数实现功能.
 * 2026.01.07
 */
#include <iostream>

class Cuboid
{
private:
	double length;
	double width;
	double height;
	bool isValidDimension(double l, double w, double h) const
	{
		return (l >= 0 && w >= 0 && h >= 0);
	}
public:
	Cuboid(double l = 0, double w = 0, double h = 0)
	{
		setDimensions(l, w, h);
	}
	void setDimensions(double l, double w, double h)
	{
		if (!isValidDimension(l, w, h))
		{
			std::cout << "错误:长,宽,高必须为非负数.设置为0." << std::endl;
			l = w = h = 0;
		}
		length = l;
		width = w;
		height = h;
	}
	void inputDimensions()
	{
		std::cout << "请输入长方柱的长,宽,高:";
		double l, w, h;
		std::cin >> l >> w >> h;
		setDimensions(l, w, h);
	}
	double calculateVolume() const
	{
		return length * width * height;
	}
	void displayVolume() const
	{
		std::cout << "长方柱的体积是:" << calculateVolume() << std::endl;
	}
};

int main()
{
	const int numCuboids = 3;
	Cuboid cuboids[numCuboids];
	for (int i = 0; i < numCuboids; ++i)
	{
		std::cout << "第" << (i + 1) << "个长方柱:" << std::endl;
		cuboids[i].inputDimensions();
		cuboids[i].displayVolume();
	}
	return 0;
}