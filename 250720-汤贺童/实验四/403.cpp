/*
 * LabWork#403
 * 储物柜问题
 * 最初所有的储物柜都关闭,编号从1到100(N).
 * 有100(N)个学生依次经过储物柜.
 * 第i个学生会改变所有k*i的储物柜的开关状态.
 * 求最后所有打开的储物柜的编号.
 * 2025.12.18
 */
#include <iostream>

int main() {
	const int N = 100;
	bool lockers[N + 1] = { false };//false关,true开
	for (int student = 1; student <= N; ++student)
	{
		for (int locker = student; locker <= N; locker += student)
		{
			lockers[locker] = !lockers[locker];//切换状态
		}
	}
	std::cout << "最后打开的储物柜编号有:\n";
	for (int i = 1; i <= N; ++i)
	{
		if (lockers[i]) {
			std::cout << i << "\t";
		}
	}
	std::cout << std::endl;
	return 0;
}

/*
 * 注:
 * 最后打开的储物柜编号是完全平方数.
 * 每个柜会被编号为其因子的学生改变状态,
 * 而只有完全平方数的因子是奇数个.
 */