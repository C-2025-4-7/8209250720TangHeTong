/*
 * LabWork#421
 * 编写函数检查字符串s1是否为字符串s2的子串
 * 若是,返回第一次匹配的下标,否则返回-1.
 * 在主程序中输入字符串s1与s2,调用函数实现.
 * 2025.12.20
 */
#include <iostream>

static int indexOf(const char* s1, const char* s2)
{
	if (s1 == nullptr || s2 == nullptr)//检查指针有效性
		return -1;
	if (s1[0] == '\0')//空串为任意串的子串
		return 0;
	if (s2[0] == '\0')//非空串不为空串的子串
		return -1;

	//计算字符串长度
	int len1 = 0, len2 = 0;
	for (len1 = 0; s1[len1] != '\0'; ++len1);
	for (len2 = 0; s2[len2] != '\0'; ++len2);
	if (len1 > len2)//s1长于s2时不可能为子串
		return -1;

	//开始匹配
	for (int i = 0; i <= len2 - len1; ++i)
	{
		bool match = true;
		for (int j = 0; j < len1; ++j)
		{
			if (s2[i + j] != s1[j])
			{
				match = false;
				break;
			}
		}
		if (match)
			return i;
	}
	return -1;
}

int main() {
	const int MAX_LEN = 100;
	char s1[MAX_LEN], s2[MAX_LEN];

	std::cout << "请输入第一个字符串 (s1): ";
	std::cin.getline(s1, MAX_LEN);
	std::cout << "请输入第二个字符串 (s2): ";
	std::cin.getline(s2, MAX_LEN);

	int index = indexOf(s1, s2);
	if (index != -1)
		std::cout << "字符串s1是字符串s2的子串, 第一次匹配的下标为: "
		<< index << std::endl;
	else
		std::cout << "字符串s1不是字符串s2的子串." << std::endl;
	return 0;
}