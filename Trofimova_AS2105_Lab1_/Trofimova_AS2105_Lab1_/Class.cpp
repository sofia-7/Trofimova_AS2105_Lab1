#include <string>
#include <iostream>
#include "Class.h"
#include <unordered_map>
#include <vector>
#include <tuple>
using namespace std;

float number_check()
{
	float number;
	while (((cin >> number).fail()) || (cin.peek() != '\n') || (number <= 0))
	{
		cout << ("Enter number > 0.\n");
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}
	return number;
}
bool maintenance_check()
{
	bool Maintenance;
	while (((cin >> Maintenance).fail()) || (cin.peek() != '\n'))
	{
		cout << ("Enter 0 or 1.\n");
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}
	return Maintenance;
}
string maintenance(bool maintenance)
{
	if (maintenance == true)
		return ("Tube is in maintenance\n");
	else if (maintenance == false)
		return ("Tube works\n");
}
int integer_check()
{
	int workshop;
	while (((cin >> workshop).fail()) || (cin.peek() != '\n') || (workshop <= 0))
	{
		cout << ("Enter integer number > 0.") << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}
	return workshop;
}
int working_worshops_check(int workshop)
{
	int working_workshop;
	while (((cin >> working_workshop).fail()) || (cin.peek() != '\n') || (working_workshop <= 0) || (working_workshop > workshop))
	{
		cout << ("Enter integer number > 0 and less than total amount of workshops.") << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}
	return working_workshop;
}

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

int Tube::MaxIdTb = 0;

int Tube::get_id() const
{
	return id;
}

void Tube::set_id()
{
	id = ++MaxIdTb;
}

istream& operator >> (istream& in, Tube tb)
{
	tb.set_id();
	cout << "Name:";
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	getline(cin, tb.tb_name);
	cout << "\nLength:";
	tb.length = numberCheck(1,10000000);
	cout << "\nDiametr:";
	tb.diametr = numberCheck(1, 10000000);
	cout << "\nEnter 0 if tube is in repair and 1 if it works:";
	tb.maintenance = numberCheck(0, 1);
	return in;
}
ostream& operator << (ostream& out, const Tube& tb)
{
	if (tb.length != 0)
	{
		cout << "Tube" << tb.id
			<< "\nName:" << tb.tb_name
			<< "\nLength:" << tb.length
			<< "\nDiametr:" << tb.diametr;
		if (tb.maintenance == 1)
		{
			out << "Tube is in maintenance.\n";
		}
		if (tb.maintenance == 0)
		{
			out << "Tube works.\n";
		}
		return out;
	}
	
}



/*void KS::add_ks()
{
	cout << "Name:";
	cin >> ks_name;
	cout << "Workshops:";
	cin >> workshops;
	cout << "Working Workshops:";
	cin >> workingWork;
	cout << "Efficiency:";
	cin >> efficiency;
}
void KS::print_ks()
{
	cout << "Name:" << ks_name 
		<< "\nWorkshops:" << workshops 
		<< "\nWorking workshops" << workingWork 
		<< "\nEfficiency:" << efficiency << endl;
}
*/