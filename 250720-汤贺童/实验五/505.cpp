/*
 * LabWork#505
 * 定义类Point(x,y)描述点坐标值,利用构造函数传递参数.
 * 主函数中通过定义对象初始化坐标值为(60,80),
 * 用函数修改为(60+i,80+j)并输出.
 * 2026.01.07
 */
#include <iostream>

class Point
{
private:
	int x;
	int y;
public:
	Point(int a, int b)
	{
		setPoint(a, b);
	}
	~Point() {}
	void setPoint(int a, int b)
	{
		x = a;
		y = b;
	}
	void display() const
	{
		std::cout << "point(" << x << "," << y << ")" << std::endl;
	}
	void shiftPoint(int i, int j)
	{
		x += i;
		y += j;
	}
};

int main()
{
	int i, j;
	Point p(60, 80);
	std::cout << "Initial ";
	p.display();
	std::cout << "Enter the offsets to shift the point (dx dy):\n";
	std::cin >> i >> j;
	p.shiftPoint(i, j);
	std::cout << "Modified ";
	p.display();
	return 0;
}