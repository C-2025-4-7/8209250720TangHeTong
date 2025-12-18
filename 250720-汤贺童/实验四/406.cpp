/*
 * LabWork#406
 * 读入字符串,调用count函数数出字符串中
 * 每个字母出现的次数,不区分大小写,
 * 只显示次数非零的英文字母.
 * 2025.12.18
 */
#include <iostream>

static void count(const char s[], int counts[])
{
    for (int i = 0; i < 26; i++)
        counts[i] = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        char ch = s[i];
        if (ch >= 'a' && ch <= 'z')
            counts[ch - 'a']++;
        else if (ch >= 'A' && ch <= 'Z')
            counts[ch - 'A']++;
    }
}

int main()
{
    const int MAX = 1000;
    char str[MAX];
    int counts[26];
    std::cout << "请输入一个字符串(不超过1000个字符):\n";
    std::cin.getline(str, MAX);
    count(str, counts);
    std::cout << "各字母出现的次数如下:\n";
    bool found = false;
    for (int i = 0; i < 26; i++)
    {
        if (counts[i] > 0)
        {
            std::cout << static_cast<char>('a' + i)
                << ": " << counts[i] << std::endl;
            found = true;
        }
    }
    if (!found)
    {
        std::cout << "没有找到任何字母." << std::endl;
    }
    return 0;
}