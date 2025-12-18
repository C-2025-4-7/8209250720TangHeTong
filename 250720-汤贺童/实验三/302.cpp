/*
 * LabWork#302
 * 用函数判断一个整数是否为素数,并找出前200个素数
 * 2025.12.18
 */
#include <iostream>

 //判断函数,这里使用了已经找到的质数来判断,提高效率
static bool isPrime(int n, int Primes[], int count)
{
	if (n < 3)
	{
		if (n <= 1) return false;//1或小于1的数不是质数
		if (n == 2) return true;//2是质数
	}
	if (n % 2 == 0) return false;//排除偶数
	for (int i = 0; i < count; ++i)
	{
		int p = Primes[i];//取出每个质数
		if (p > n / p) break;//质数的平方大于n时结束
		if (n % p == 0) return false;//找到了因子，不是质数
	}
	return true;//没有找到因子，是质数
}

int main()
{
	int Primes[200];
	int count = 0;
	//从0开始
	for (int n = 0; count < 200; ++n)
	{
		if (isPrime(n, Primes, count))
		{
			Primes[count] = n;//保存质数
			count += 1;//质数计数器加1
		}
	}
	//输出
	std::cout << "The first 200 primes are:\n";
	for (int i = 0; i < count; ++i)
	{
		std::cout << Primes[i] << "\t";
		if ((i + 1) % 10 == 0) std::cout << "\n";//每十个数换行
	}
	std::cout << "End.\n";
	return 0;
}

/*
 * 注:
 * 由于Primes数组是静态分配的栈内存,不需要手
 * 动释放内存,它会在main函数结束时自动释放.
 * 而如果使用动态内存分配,则需要手动释放内存以防止内存泄漏.
 * 使用new分配,需要delete,使用malloc分配,需要free.
 */