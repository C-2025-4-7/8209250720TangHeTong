/*
 * LabWork#422
 * 编写函数将以字符串形式表示的一个16进制数转换为10进制数
 * 并在主函数中调用函数测试
 * 注:
 *	1. 包含输入有效性检查
 *	2. 支持处理带有前缀的16进制数
 * 2025.12.20
 */
#include <iostream>
#include <cctype>
#include <limits>

enum ParseResult//解析结果枚举
{
	SUCCESS = 0,
	ERROR_NULL_PTR = -1,
	ERROR_INVALID_CHAR = 1,
	ERROR_OVERFLOW = 2,
	ERROR_UNDERFLOW = 3,
	ERROR_EMPTY = 4,
};

//转换函数,通过返回值返回结果,通过参数返回错误信息,此时可以区分错误和结果
static int parseHex(const char* const hexString, ParseResult& feedback)
{
	//空指针检查
	if (hexString == nullptr)
	{
		std::cerr << "\tError: Null pointer input." << std::endl;
		feedback = ERROR_NULL_PTR;
		return 0;
	}

	const char* ptr = hexString;
	//跳过前导空格
	while (isspace(*ptr)) ptr++;
	//处理符号
	bool negative = false;
	if (*ptr == '-')
	{
		negative = true;
		ptr++;
	}
	else if (*ptr == '+')
		ptr++;

	//处理"0x"或"0X"前缀
	bool prefix_0_found = false;
	bool prefix_X_found = false;
	for (; *ptr != '\0'; ++ptr)
	{
		if (isspace(*ptr))
			continue;
		else if (!prefix_0_found && *ptr == '0')
			prefix_0_found = true;
		else if (prefix_0_found && *ptr == '0')
			break;//前缀不应该有多个0
		else if (prefix_0_found && !prefix_X_found && (*ptr == 'x' || *ptr == 'X'))
		{
			prefix_X_found = true;
			++ptr;
			break;
		}
		else
			break;
	}

	//开始转换	
	bool has_digits = false;
	if (prefix_0_found && !prefix_X_found)
		has_digits = true;//只有"0"的情况视为有效数字
	int decimalValue = 0;
	for (; *ptr != '\0'; ++ptr)
	{
		if (isspace(*ptr))
			continue;
		has_digits = true;
		char ch = *ptr;
		int digitValue = 0;
		if (ch >= '0' && ch <= '9')
			digitValue = ch - '0';
		else if (ch >= 'a' && ch <= 'f')
			digitValue = ch - 'a' + 10;
		else if (ch >= 'A' && ch <= 'F')
			digitValue = ch - 'A' + 10;
		else
		{
			std::cerr << "\tError: Invalid character '" << ch << "' in hex string." << std::endl;
			feedback = ERROR_INVALID_CHAR;
			return 0;
		}
		//检查溢出
		if (decimalValue > (std::numeric_limits<int>::max() - digitValue) / 16)
		{
			if (negative)
			{
				std::cerr << "\tWarning: Hex value underflow." << std::endl;
				feedback = ERROR_UNDERFLOW;
			}
			else
			{
				std::cerr << "\tWarning: Hex value overflow." << std::endl;
				feedback = ERROR_OVERFLOW;
			}
			return 0;
		}
		decimalValue = (decimalValue << 4) + digitValue;//使用位移避免乘法
	}

	if (!has_digits)//检查是否有数字
	{
		std::cerr << "\tError: No digits found in hex string." << std::endl;
		feedback = ERROR_EMPTY;
		return 0;
	}
	if (negative)//处理负号
		decimalValue = -decimalValue;
	return decimalValue;
}

static void testParseHex()
{
	const int numTests = 26;
	//测试字符串表
	const char* test_strings[numTests] =
	{
		"1A3F5",
		"0x1A3F5",
		"  1A3F5  ",
		"0X1a3F5",
		"    0  X   1 A   3 f  5   ",
		"-1A3F5",
		"+0x1A3F5",
		"   -  0  x  1  a  3  f  5   ",
		"12345",
		"0x123G45",
		"0xGHIJ",
		"0",
		"0x0000",
		"   ",
		"0x",
		"0000x00FF",
		"0x0x00FF",
		"7e4",
		"",
		nullptr,
		"FFFFFFFFFFFFFFFFFFFFFFFF",
		"7FFFFFFF",
		"80000000",
		"-FFFFFFFF",
		"2147483648",
		"-2147483649",
	};
	//预期结果表
	int expected_results[numTests][2] =
	{
		{ 107509, 0 },
		{ 107509, 0 },
		{ 107509, 0 },
		{ 107509, 0 },
		{ 107509, 0 },
		{ -107509, 0 },
		{ 107509, 0 },
		{ -107509, 0 },
		{ 74565, 0 },
		{ 0, ERROR_INVALID_CHAR },
		{ 0, ERROR_INVALID_CHAR },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, ERROR_EMPTY },
		{ 0, ERROR_EMPTY },
		{ 0, ERROR_INVALID_CHAR },
		{ 0, ERROR_INVALID_CHAR },
		{ 2020, 0 },
		{ 0, ERROR_EMPTY },
		{ 0, ERROR_NULL_PTR },
		{ 0, ERROR_OVERFLOW },
		{ 2147483647, 0 },
		{ 0, ERROR_OVERFLOW },
		{ 0, ERROR_UNDERFLOW },
		{ 0, ERROR_OVERFLOW },
		{ 0, ERROR_UNDERFLOW },
	};
	//运行测试
	int num_failed = 0;
	for (int i = 0; i < numTests; ++i)
	{
		const char* str = test_strings[i];
		std::cout << "Testing \"" << (str ? str : "nullptr")
			<< "\" while expecting result " << expected_results[i][0]
			<< " and feedback " << expected_results[i][1] << std::endl;
		ParseResult feedback = SUCCESS;
		int result = parseHex(str, feedback);
		if (result == expected_results[i][0] && feedback == expected_results[i][1])
			std::cout << "Passed.";
		else
		{
			++num_failed;
			std::cout << "Failed.";
		}
		std::cout << "\tResult: " << result << " with feedback: " << feedback << "\n" << std::endl;
	}
	if (num_failed == 0)
		std::cout << "All tests passed!" << std::endl;
	else
		std::cout << num_failed << " tests failed." << std::endl;
}

int main()
{
	testParseHex();
	return 0;
}