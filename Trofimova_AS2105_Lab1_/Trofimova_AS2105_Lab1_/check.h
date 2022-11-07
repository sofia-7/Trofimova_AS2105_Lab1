#pragma once
#include <iostream>
#include <string>
#include <tuple>

template <typename T>
T numberCheck(T min = 0, T max = 10000000)
{
	T x;
	while ((std::cin >> x).fail() || x<min || x>max)
	{
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "Please, type number (" << min << "-" << max << "): ";
	}
	return x;
}

string maintenance_check(bool x)
{
	if (x == true)
		return ("Tube works");
	else if (x == false)
		return ("Tube is repairing");
}