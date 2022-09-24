
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

struct Tube
{
	float length=0, diametr=0;
	bool maintenance;
};

struct KS
{
	string name="";
	int count=0, workCount=0;
	float efficiency=0;
};


int main()
{

	Tube tb;
	KS ks;
	int menu = 0;
	cout << "1.Add new tube.\n" << "2.Add new KS.\n" << "3.Added objects.\n" << "4.Change tube.\n" << "5.Change KS.\n" << "6.Add to file.\n" << "7.Exit\n" << ">";
	cin >> menu;
	switch(menu)
	{
	case 1:
	{
		cout << "\nLength:";
		cin >> tb.length;
		cout << "\nDiametr:";
		cin >> tb.diametr;
		cout << "\nEnter 0 if tube is in repair and 1 if it works:";
		cin >> tb.maintenance;
		break;
	}
	case 2:
	{
		cout << "\nName:";
		cin >> ks.name;
		cout << "\nTotal number of workshops:";
		cin >> ks.count;
		cout << "\nNumber of working workshops:";
		cin >> ks.workCount;
		break;
	}
	case 3:
	{
		cout << "\nTube.\n" << "\nLength:" << tb.length << "\nDiametr:" << tb.diametr << "\nMaintanance:" << tb.maintenance << endl;
		cout << "\nKS.\n" << "\nName:" << ks.name << "\nTotal number of workshops:" << ks.count << "\nNumber of working workshops:" << ks.workCount << endl;
		break;
	}
	}
	_getch();
	return 0;
}
