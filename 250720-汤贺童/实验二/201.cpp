/*
* LabWork#201
* 输入一个字符,如果为小写,转换为大写输出,否则,输出其后继字符的ASCII码值.
* 另:加入了输入合法性检查.
* 2025.11.13/11.17
*/
#include<iostream>
#include<string>

int main()
{
	std::string ipt;//Input string
	std::cout << "Awaiting input (1 single character)\n";
	getline(std::cin, ipt);//用getline读取整行输入
	//检查是否为单个字符
	if (ipt.length() != 1)
	{
		std::cout << "Not a single character!";
		return -1;
	}
	//取第一个
	char fst = ipt[0];//First character,方括号表示取一组东西中的某一个
	if (fst >= 'a' && fst <= 'z')
	{
		char cap = fst - 32;//Capitalize
		std::cout << cap;
	}
	else
	{
		int nxt = fst + 1;//Next ASCII value
		std::cout << nxt;
	}
	return 0;
}