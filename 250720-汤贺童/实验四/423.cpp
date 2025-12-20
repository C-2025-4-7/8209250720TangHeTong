/*
 * LabWork#423
 * 主程序中使用new建立一动态数组,键盘输入数组元素及个数,
 * 动态调试观察指针及指针指向的内容.
 * 设计一个函数对数组由小到大排序,
 * 主程序中用指针方式输出数组元素,最后释放数组内存.
 * 2025.12.20
 */
#include <iostream>

static void sortArray(int* arr, int size)//排序
{
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = 0; j < size - i - 1; ++j)
		{
			if (*(arr + j) > *(arr + j + 1))
			{
				int temp = *(arr + j);
				*(arr + j) = *(arr + j + 1);
				*(arr + j + 1) = temp;
			}
		}
	}
}

int main()
{
	const int MAX_SIZE = 100;
	//输入数组大小
	int size;
	std::cout << "Enter the number of elements: ";
	while (true)
	{
		if (!(std::cin >> size))
		{
			std::cout << "Invalid input. Please enter an integer: ";
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
		else if (size <= 0)
		{
			std::cout << "Size must be a positive integer. Please enter again: ";
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
		else if (size > MAX_SIZE)
		{
			std::cout << "Size exceeds maximum limit of " << MAX_SIZE
				<< ". Please enter again: ";
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
		else
			break;
	}
	//动态分配数组
	int* arr = new int[size];
	//输入数组元素
	std::cout << "Enter " << size << " integers:" << std::endl;
	for (int i = 0; i < size; ++i)
	{
		if (!(std::cin >> *(arr + i)))
		{
			std::cout << "Invalid input. Please enter an integer: ";
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			--i;//重新输入该位置元素
		}
	}
	//显示输入的数组
	std::cout << "Original array:\n\tThe pointer address: " << arr;
	for (int i = 0; i < size; ++i)
	{
		std::cout << "\n\tptr + " << i << " address: " << (arr + i)
			<< ", value: " << *(arr + i);
	}
	std::cout << std::endl;

	//排序数组
	sortArray(arr, size);
	//输出排序后的数组元素
	std::cout << "Sorted elements:" << std::endl;
	for (int i = 0; i < size; ++i)
	{
		std::cout << *(arr + i) << " ";
	}
	std::cout << std::endl;

	//显示排序后的数组
	std::cout << "Sorted array:\n\tThe pointer address: " << arr;
	for (int i = 0; i < size; ++i)
	{
		std::cout << "\n\tptr + " << i << " address: " << (arr + i)
			<< ", value: " << *(arr + i);
	}
	std::cout << std::endl;

	delete[] arr;//释放内存
	arr = nullptr;//防止悬空指针
	return 0;
}