/*
* LabWork#207
* 使用循环结构输出下列图形：
*		    *
*		   **
*		  ***
*		 ****
*		*****
* 另:
*	使用不同方式实现上述图形的输出
* 2025.11.14/11.17
*/
#include <iostream>

static void printLoop(int n)//使用循环结构实现
{
	for (int i = 1; i <= n; ++i)//行
	{
		for (int j = n - i; j > 0; --j)//空格
		{
			std::cout << ' ';
		}
		for (int k = 1; k <= i; ++k)//星号
		{
			std::cout << '*';
		}
		std::cout << "\n";
	}
}

static void printSpaces(int n)//递归输出空格
{
	if (n <= 0) return;
	std::cout << ' ';
	printSpaces(n - 1);
}

static void printStars(int n)//递归输出星号
{
	if (n <= 0) return;
	std::cout << '*';
	printStars(n - 1);
}

static void printRecursion(int n, int t = 1)//使用递归结构实现,占用资源较多
{
	if (t > n) return;//递归终止条件
	printSpaces(n - t);
	printStars(t);
	std::cout << "\n";
	printRecursion(n, t + 1);//递归
}

static void printFormula(int n)//使用公式实现
{
	for (int i = 1; i <= n; ++i)
	{
		//利用string构造函数生成空格和星号字符串,专业对口了说是
		std::cout << std::string(n - i, ' ')
			<< std::string(i, '*') << "\n";
	}
}

static void printDiffuse(int n)//使用扩散法实现
{
	//这个思路有点意思,像冒泡排序,每次把一个星号替换到最右边
	char arr[100] = { 0 };//定义字符数组存储一行
	for (int i = 0; i < n; ++i)//初始化空格
	{
		arr[i] = ' ';
	}
	for (int i = 0; i < n; ++i)//逐步扩散星号
	{
		arr[n - i - 1] = '*';
		std::cout << arr << "\n";
	}
}

int main()
{
	int n = 5, opt = 1;
	std::cout << "Please enter the number of rows:(default 5) ";
	if (!(std::cin >> n) || n <= 0)
	{
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		n = 5;
	}
	std::cout << "\nPlease choose the method to print the pattern:\n"
		<< "1. Loop structure\n"
		<< "2. Recursion structure\n"
		<< "3. Formula method\n"
		<< "4. Diffusion method\n"
		<< "Enter your choice (1-4, default 1): ";
	if (!(std::cin >> opt))
	{
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		opt = 1;
	}
	switch (opt)
	{
	case 2:
		printRecursion(n);
		break;

	case 3:
		printFormula(n);
		break;

	case 4:
		printDiffuse(n);
		break;

	default:
		printLoop(n);
		break;
	}
	return 0;
}