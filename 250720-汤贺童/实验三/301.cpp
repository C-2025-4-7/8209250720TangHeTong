/*
 * LabWork#301
 * 求两个自然数的最大公约数与最小公倍数
 * 另:
 *    使用引用参数或值传递两种方式实现函数
 * 2025.12.18
 */
#include<iostream>
#include<string>

 //计算最大公约数以及最小公倍数的函数,使用引用参数
static void calculate_gcd_ref(const int& a, const int& b, int& gcd, int& lcm)
{
	//使用欧几里得算法迭代计算最大公约数
	int x = a;
	int y = b;
	while (y != 0)
	{
		int c = y;
		y = x % y;
		x = c;
	}
	//原理:用较大数除以较小数,若余数不为0,则用较小数
	//除以余数,直到余数为0时,较小数即为最大公约数,
	//这里如果a<b,则第一次迭代时会自动交换a,b的值
	gcd = x;
	//最小公倍数=两数之积/最大公约数
	lcm = a / gcd * b;//先除后乘可以避免溢出
	return;
}

//计算最大公约数的函数,使用值传递
static int calculate_gcd_val(int a, int b)
{
	//方法同上
	while (b != 0)
	{
		int c = b;
		b = a % b;
		a = c;
	}
	return a;
}

//计算最小公倍数的函数,使用值传递
static int calculate_lcm_val(int a, int b, int gcd)
{
	int lcm = a / gcd * b;
	return lcm;
}

int main()
{
	int nums[2] = { 0,0 };
	std::string num_names[2] = { "a","b" };
	std::cout << "Please enter two natural numbers "
		<< "(non-integer parts will be ignored):\n";
	//输入两个正整数
	for (int i = 0; i < 2; ++i)
	{
		while (true)
		{
			std::cout << num_names[i] << "=";
			if (!(std::cin >> nums[i]))
			{
				std::cout << "Not a number.\n";
				std::cin.clear();
				std::cin.ignore(10000, '\n');
				continue;
			}
			if (nums[i] < 0)
			{
				std::cout << "Not a non-negative number.\n";
				std::cin.clear();
				std::cin.ignore(10000, '\n');
				continue;
			}
			std::cin.ignore(10000, '\n');
			break;
		}
	}
	//将输入赋值给变量a,b
	int a = nums[0];
	int b = nums[1];

	if (a == 0 || b == 0)
	{
		std::cout << "\nGreatest Common Divisor is: 0"
			<< "\nLeast Common Multiple is: 0\n";
		return 0;
	}

	//使用引用参数的函数计算最大公约数与最小公倍数
	int gcd_ref, lcm_ref;
	calculate_gcd_ref(a, b, gcd_ref, lcm_ref);
	std::cout << "\n[Using reference parameters]"
		<< "\nGreatest Common Divisor is:" << gcd_ref
		<< "\nLeast Common Multiple is:" << lcm_ref;

	//使用值传递的函数计算最大公约数与最小公倍数
	int gcd_val = calculate_gcd_val(a, b);
	int lcm_val = calculate_lcm_val(a, b, gcd_val);
	std::cout << "\n\n[Using value parameters]"
		<< "\nGreatest Common Divisor is:" << gcd_val
		<< "\nLeast Common Multiple is:" << lcm_val << "\n";

	return 0;
}

/*
 * 总结:
 * 对于只需要返回单个结果的函数,如果使用引用参数,虽然可以减少拷
 * 贝开销,但会增加代码复杂度,且对于int等基本类型来说,拷贝开销微
 * 乎其微,因此更适合选择值传递.
 * 而对于需要返回多个结果的函数,使用引用参数可以避免返回结构体
 * 或类对象,从而减少内存开销和提高性能,因此更适合选择引用参数,
 * 但要注意如果不需要修改参数,应使用const引用以防止误修改.
 * 由此可见,输入不需要修改的参数时使用值传递,输入需要修改的参数
 * 或需要返回多个结果时使用引用参数,是较为合理的选择.
 */