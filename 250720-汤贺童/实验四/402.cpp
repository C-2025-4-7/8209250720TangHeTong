/*
 * LabWork#402
 * 冒泡排序
 * 读入一个含有10个双精度数字的数组,
 * 调用函数并显示升序排列后的数字.
 * 2025.12.18
 */
#include <iostream>

 //未优化的冒泡排序,每次执行所有遍历,
 //不考虑数组是否已经有序.这里只作为对比.
static void bubbleSortLazy(double arr[], int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = 0; j < size - i - 1; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				double temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

//优化后的冒泡排序,如果在某次遍历中没有进行交换,
//则说明数组已经有序,可以提前结束排序.这是题目已经给出的.
static void bubbleSortOptimized(double arr[], int size)
{
	bool swapped = true;
	do
	{
		swapped = false;
		for (int i = 0; i < size - 1; ++i)
		{
			if (arr[i] > arr[i + 1])
			{
				double temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				swapped = true;
			}
		}
	} while (swapped);
}

int main() {
	double numbers[10] = { 0 };
	std::cout << "请输入10个双精度数字:\n";
	for (int i = 0; i < 10; i++)
	{
		if (!(std::cin >> numbers[i]))
		{
			std::cout << "输入无效,请输入数字.\n";
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			--i;
		}
	}
	bubbleSortOptimized(numbers, 10);//这里只使用优化后的
	std::cout << "排序后的数字为:\n";
	for (int i = 0; i < 10; i++)
	{
		std::cout << numbers[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}