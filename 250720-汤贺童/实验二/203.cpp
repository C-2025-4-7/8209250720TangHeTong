/*
* LabWork#203
* 求三角形周长,并判断该三角形是否为等腰三角形.
* 另:
* 1.加入了输入合法性检查.
* 2.使用vector存储边长和边名.
* 2025.11.13/11.17
*/
#include<iostream>
#include<vector>
#include<string>

int main()
{
	std::vector<double> sides(3);//有3个项
	std::vector<std::string> side_names = { "a", "b", "c" };//也是3个项,序号对应
	std::cout << "Awaiting input\n";
	//输入三边长
	for (int i = 0; i < 3; ++i)
	{
		std::cout << side_names[i] << "=";
		if (!(std::cin >> sides[i]))
			//判断输入合法性,这里cin会在接受输入时尝试将输入的内容
			//转换为double类型,如果失败则返回false,括起来取反即为true,
			//注意必须括起来,否则优先级会有问题,!的优先级高于>>,
			//会被解析为( !(std::cin) >> sides[i]),不再接受输入,
			//而是尝试将cin转换为bool类型取反,再将结果右移sides[i]位,
			//然而bool类型无法进行位移运算,这会导致编译错误.
		{
			std::cout << "Not a number.";
			return -2;
		}
		if (sides[i] <= 0)//同上
		{
			std::cout << "Negative number cannot be a length.";
			return -3;
		}
	}
	//将边长赋值给变量a,b,c
	double a = sides[0], b = sides[1], c = sides[2];
	//判断能否构成三角形
	if (a + b <= c || a + c <= b || b + c <= a)
	{
		std::cout << "Inputted lengths cannot form a triangle.";
		return -1;
	}
	//计算周长
	std::cout << "Perimeter of the triangle is " << a + b + c;
	//判断是否等腰
	if (a == b || a == c || b == c)
	{
		std::cout << "\nThe triangle is an isosceles triangle.";
	}
	else
	{
		std::cout << "\nThe triangle is NOT an isosceles triangle.";
	}
	return 0;
}