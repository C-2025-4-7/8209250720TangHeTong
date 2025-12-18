/*
 * LabWork#405
 * 读入两个C字符串,检验串s1是否是串s2的子串,
 * 如果匹配,输出子串s1在s2中的下标,即s1在s2
 * 中首次出现的位置(从0开始计数),否则返回-1.
 * 注:
 *	1.空串是任何串的子串,非空串不可能是空串的子串.
 *	2.对于中文字符,下标按字节计算,每个中文字符占2个字节.
 * 2025.12.18
 */
#include <iostream>

static int indexOf(const char s1[], const char s2[])
{
	//检查空串情况
	if (s1[0] == '\0')
		return 0;//空串是任何串的子串
	if (s2[0] == '\0')
		return -1;//非空串不可能是空串的子串
	//开始匹配
	for (int i = 0; s2[i] != '\0'; ++i)
	{
		bool match = true;
		//检查s1是否与s2从i开始的子串匹配
		for (int j = 0; s1[j] != '\0'; ++j)
		{
			//如果s2到达末尾或者字符不同,则不匹配
			if (s2[i + j] == '\0' || s2[i + j] != s1[j])
			{
				match = false;
				break;
			}
		}
		//如果匹配成功,返回起始下标
		if (match)
			return i;
	}
	//未找到匹配子串,返回-1
	return -1;
}

int main()
{
	const int MAX_LEN = 100;
	char s1[MAX_LEN], s2[MAX_LEN];
	std::cout << "请输入第一个字符串 (s1): ";
	std::cin.getline(s1, MAX_LEN);
	std::cout << "请输入第二个字符串 (s2): ";
	std::cin.getline(s2, MAX_LEN);
	int index = indexOf(s1, s2);
	if (index != -1)
		std::cout << "字符串 \"" << s1 << "\" 是字符串 \""
		<< s2 << "\" 的子串,起始下标为:" << index << std::endl;
	else
		std::cout << "字符串 \"" << s1 << "\" 不是字符串 \""
		<< s2 << "\" 的子串,返回:-1" << std::endl;
	return 0;
}