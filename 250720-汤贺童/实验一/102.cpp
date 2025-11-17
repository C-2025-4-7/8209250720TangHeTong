/*
* LabWork#102
* ÇóÔ²×¶Ìå»ı
* 2025.11.12/11.17
*/
#include<iostream>

int main()
{
	const float Pi = 3.1415;
	float r = 0, h = 0;
	std::cout << "Awaiting input:\nr=";
	std::cin >> r;
	std::cout << "h=";
	std::cin >> h;
	std::cout << "\nV=" << Pi * r * r * h / 3;
	return 0;
}