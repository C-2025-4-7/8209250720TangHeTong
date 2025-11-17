/*
* LabWork#101
* 找出下面代码的错误并改正
* 2025.11.12/11.17
*/

//原代码
//include<iostream>
//using namespace std;
//int Main()
//{
//	int i = k + 1;
//	cout << i++ << endl;
//	int i = 1;
//	cout << i++ << endl;
//	cout << ”Welcome to C++!<< endl;
//	return 0
//}

//修改后
#include<iostream>
using namespace std;
int main()
{
	int i = 1 + 1;
	cout << i++ << endl;
	i = 1;
	cout << i++ << endl;
	cout << "Welcome to C++!" << endl;
	return 0;
}