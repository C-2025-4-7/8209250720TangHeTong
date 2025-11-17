/*
* LabWork#205
* 统计输入字符串中英文字母、空格、数字字符和其它字符出现的次数
* 2025.11.14/11.17
*/
#include<iostream>
#include<string>

int main()
{
	std::string input;
	std::cout << "Awaiting input\n";
	std::getline(std::cin, input);//使用getline读取整行,包括空格
	int lts = 0, sps = 0, dgs = 0, ots = 0;

	for (char c : input) {
		//for (char c : input)会自动遍历input中的每个字符,等价于:
		//for (int i = 0; i < input.length(); i++) {
		//	char c = input[i];
		//	...}
		if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') lts += 1;
		else if (c == ' ') sps += 1;
		else if (c >= '0' && c <= '9') dgs += 1;
		else ots += 1;
		//Tab会被统计为其他字符,每个中文字符会被统计为多个其他字符,
		//换行符不会被统计,因为getline读取时会去掉换行符
	}

	std::cout << "Letters: " << lts
		<< "\nSpaces: " << sps
		<< "\nDigits: " << dgs
		<< "\nOthers: " << ots << "\n";

	return 0;
}