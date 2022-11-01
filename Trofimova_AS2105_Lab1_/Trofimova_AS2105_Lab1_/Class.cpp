#include <string>
#include <iostream>
#include "Class.h"
using namespace std;

void Tube::add_tube()
{
	cout << "Length:";
	cin >> length;
	cout << "Diametr:";
	cin >> diametr;
	cout << "Maintenance:";
	cin >> maintenance;
}
void Tube::print_tube() 
{
	cout << "\nLength:" << length << "\nDiametr:" << diametr << "\nMaintenance:" << maintenance << endl;
}

void KS::add_ks()
{
	cout << "Name:";
	cin >> name;
	cout << "Workshops:";
	cin >> workshops;
	cout << "Working Workshops:";
	cin >> workingWork;
	cout << "Efficiency:";
	cin >> efficiency;
}
void KS::print_ks()
{
	cout << "Name:" << name << "\nWorkshops:" << workshops << "\nWorking workshops" << workingWork << "\nEfficiency:" << efficiency << endl;
}