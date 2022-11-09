#pragma once
#include <iostream>
#include <string>
#include <tuple>
using namespace std;

template <typename T>
T numberCheck(T min = 0, T max = 10000000)
{
	T x;
	while (!(cin >> x)||(cin.peek()!='\n')|| x<min || x>max)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Please, type number (" << min << "-" << max << "): ";
	}
	return x;
}

