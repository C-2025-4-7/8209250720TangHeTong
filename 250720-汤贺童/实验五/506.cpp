/*
 * LabWork#506
 * 定义抽象基类Shape,派生出五个派生类:
 * Circle, Square, Rectangle, Trapezoid, Triangle.
 * 用虚函数分别计算各种图形的面积,并求出它们的和.
 * 用基类指针数组,使它的每一个元素指向一个派生类的对象.
 * 主函数中定义如下对象:
 * Circle circle(10.2);
 * Square square(3);
 * Rectangle rectangle(3,4);
 * Trapezoid trapezoid(2.0,4.5,3);
 * Triangle triangle(4,5,6).
 * 2026.01.07
 */
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <string>
constexpr double PI = 3.1415926535;

class Shape
{
public:
	virtual double area() const = 0;//纯虚函数,用于计算面积
	virtual ~Shape() = default;//使用默认析构函数
	virtual std::string getShapeName() const = 0;
	//辅助函数显示面积信息
	void displayArea() const
	{
		std::cout << "Area of the " << getShapeName()
			<< ": " << area() << std::endl;
	}
	//原本是用std::string(typeid(*shapes[i]).name()).substr(6)返回类名,
	//但substr(6)不一定在所有编译器上都适用,而且略复杂,
	//改为虚函数getShapeName()并在每个派生类中实现更加直观.
};

class Circle : public Shape
{
private:
	double radius;
	//辅助函数验证合法性,尝试使用try-catch捕获异常
	void validate() const
	{
		if (radius <= 0)
		{
			throw std::invalid_argument("Radius must be positive.");
		}
	}
public:
	//使用explicit防止隐式转换
	explicit Circle(double r) : radius(r)
	{
		validate();
	}
	double area() const override
	{
		return PI * radius * radius;
	}
	std::string getShapeName() const override
	{
		return "Circle";
	}
};

class Square : public Shape
{
private:
	double side;
	void validate() const
	{
		if (side <= 0)
		{
			throw std::invalid_argument("Side length must be positive.");
		}
	}
public:
	explicit Square(double s) : side(s)
	{
		validate();
	}
	double area() const override
	{
		return side * side;
	}
	std::string getShapeName() const override
	{
		return "Square";
	}
};

class Rectangle : public Shape
{
private:
	double length;
	double width;
	void validate() const
	{
		if (length <= 0 || width <= 0)
		{
			throw std::invalid_argument("Length and width must be positive.");
		}
	}
public:
	explicit Rectangle(double l, double w) : length(l), width(w)
	{
		validate();
	}
	double area() const override
	{
		return length * width;
	}
	std::string getShapeName() const override
	{
		return "Rectangle";
	}
};

class Trapezoid : public Shape
{
private:
	double base1;
	double base2;
	double height;
	void validate() const
	{
		if (base1 <= 0 || base2 <= 0 || height <= 0)
		{
			throw std::invalid_argument("Bases and height must be positive.");
		}
	}
public:
	explicit Trapezoid(double b1, double b2, double h) : base1(b1), base2(b2), height(h)
	{
		validate();
	}
	double area() const override
	{
		return 0.5 * (base1 + base2) * height;
	}
	std::string getShapeName() const override
	{
		return "Trapezoid";
	}
};

class Triangle : public Shape
{
private:
	double side1;
	double side2;
	double side3;
	void validate() const
	{
		if (side1 <= 0 || side2 <= 0 || side3 <= 0)
		{
			throw std::invalid_argument("Side lengths must be positive.");
		}
		else if (side1 + side2 <= side3 || side1 + side3 <= side2 || side2 + side3 <= side1)
		{
			throw std::invalid_argument("Cannot form a triangle.");
		}
	}
public:
	explicit Triangle(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3)
	{
		validate();
	}
	double area() const override
	{
		double s = (side1 + side2 + side3) / 2.0;
		double result = s * (s - side1) * (s - side2) * (s - side3);
		if (result <= 0)//处理浮点数精度问题
		{
			if (result > -1e-10)//考虑浮点误差
			{
				return 0.0;
			}
			else throw std::domain_error("Triangle area calculation produced negative value.");
		}
		return std::sqrt(result);
	}
	std::string getShapeName() const override
	{
		return "Triangle";
	}
};

int main()
{
	try
	{
		Circle circle(10.2);
		Square square(3);
		Rectangle rectangle(3, 4);
		Trapezoid trapezoid(2.0, 4.5, 3);
		Triangle triangle(4, 5, 6);
		Shape* shapes[5] =
		{
			&circle,
			&square,
			&rectangle,
			&trapezoid,
			&triangle
		};
		double totalArea = 0.0;
		for (int i = 0; i < 5; ++i)
		{
			shapes[i]->displayArea();
			totalArea += shapes[i]->area();
		}
		std::cout << "Total area of all shapes: " << totalArea << std::endl;
	}
	catch (const std::invalid_argument& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	catch (const std::domain_error& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return -1;
	}
	return 0;
}

/*
 * 注:
 *	这里尝试使用try-catch捕获异常,虽然比直接在原地处理异常
 *	更复杂,但能分离错误处理逻辑和正常逻辑,提高代码可读性.
 */