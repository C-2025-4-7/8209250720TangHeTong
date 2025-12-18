/*
 * LabWork#404
 * 提示用户输入两个排列好的数组,将其合并,形成一个新的排列好的数组.
 * 输入数据的第一个数字是数组的元素数,而不是数组的一部分.
 * 假定数组大小不超过80.
 * 2025.12.18
 */
#include <iostream>
#include <string>

static void merge(const int A[], int sizeA,
	const int B[], int sizeB, int C[])
{
	int i = 0, j = 0, k = 0;
	while (i < sizeA && j < sizeB)
	{
		//if (A[i] < B[j]) C[k++] = A[i++];
		//else C[k++] = B[j++];
		C[k++] = (A[i] < B[j]) ? A[i++] : B[j++];//这里复习三元运算符
	}
	while (i < sizeA)//处理剩余元素,如果有
	{
		C[k++] = A[i++];
	}
	while (j < sizeB)
	{
		C[k++] = B[j++];
	}
}

static bool isSorted(const int arr[], int size)
{
	for (int i = 1; i < size; ++i)
	{
		if (arr[i] < arr[i - 1]) return false;
	}
	return true;
}

static void sortArray(int arr[], int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = 0; j < size - 1 - i; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

static bool inputArray(int arr[], int& realSize,
	int maxSize, const std::string& arrName)
{
	int size;
	std::cout << "请输入第" << arrName << "个数组的元素个数(不超过" << maxSize << "):";
	if (!(std::cin >> size))
	{
		std::cout << "请输入正整数作为数组大小." << std::endl;
		return false;
	}
	if (size < 1 || size > maxSize)
	{
		std::cout << "输入的元素个数太大或太小." << std::endl;
		return false;
	}
	//这里先清理输入缓冲区,以防止未使用的输入影响下一次输入
	std::cin.clear();
	std::cin.ignore(10000, '\n');
	realSize = size;
	std::cout << "请输入数组" << arrName << "的" << realSize << "个元素(整数,按升序排列):";
	for (int i = 0; i < realSize; ++i)
	{
		if (!(std::cin >> arr[i])) {
			std::cout << "请输入整数作为数组元素." << std::endl;
			return false;
		}
	}
	//这里同样清理输入缓冲区
	std::cin.clear();
	std::cin.ignore(10000, '\n');
	//检查数组是否有序,如果无序则排序
	if (!isSorted(arr, realSize))
	{
		std::cout << "第" << arrName << "个数组未排序,是否要自动排序?(y/n):";
		char choice;
		std::cin >> choice;
		if (choice != 'y' && choice != 'Y')
		{
			std::cout << "请重新输入第" << arrName << "个数组." << std::endl;
			return false;
		}
		else
			sortArray(arr, realSize);
		std::cout << "第" << arrName << "个数组已排序." << std::endl;
	}
	return true;
}

int main()
{
	const int MAX_SIZE = 80;
	int A[MAX_SIZE] = { 0 }, sizeA = 0;
	int B[MAX_SIZE] = { 0 }, sizeB = 0;
	int C[2 * MAX_SIZE] = { 0 }, sizeC = 0;
	//输入两个数组
	while (!inputArray(A, sizeA, MAX_SIZE, "一"))
	{
		std::cin.clear();
		std::cin.ignore(10000, '\n');
	}
	//这里同样清理输入缓冲区
	do {
		std::cin.clear();
		std::cin.ignore(10000, '\n');
	} while (!inputArray(B, sizeB, MAX_SIZE, "二"));
	//合并两个数组
	merge(A, sizeA, B, sizeB, C);
	sizeC = sizeA + sizeB;
	//检查结果数组是否已排序,理论上应该是已排序的
	if (!isSorted(C, sizeC))
	{
		std::cout << "合并后的数组未正确排序!请稍等..." << std::endl;
		sortArray(C, sizeC);
	}
	std::cout << "合并完成!合并后的数组已正确排序." << std::endl;
	//输出合并后的数组
	std::cout << "合并后的数组为:\n";
	for (int i = 0; i < sizeC; ++i)
	{
		std::cout << C[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}