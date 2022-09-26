﻿
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Tube
{
	float length=0, diametr=0;
	int maintenance=0;
};

struct KS
{
	string name="";
	int workshops=0, workingWork=0;
	float efficiency=0;
};

float numeric_check(float l)
{
	while ((l <= 0) || (!l))
	{
		cout << ("Enter number > 0.\n");
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cin >> l;
	}
	return l;
}

int maint_check(int m)
{
	while ((!m) || (m < 1) || (m > 2))
	{
		cout << ("Enter 1 or 2.\n");
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cin >> m;
	}
	return m;
}

string maint_check_2(int m)
{
	if (m == 1)
		return ("Tube is in maintenance\n");
	else
		return ("Tube works\n");
}

int numeric_check_2(int w)
{
	while ((w <= 0) || (!w))
	{
		cout << ("Enter number > 0.\n");
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cin >> w;
	}
	return w;
}

int working_worshops_check(int ww, int w)
{
	while ((ww <= 0) || (!ww) || (ww > w))
	{
		cout << ("Enter number > 0 and less than total amount of workshops.\n");
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cin >> ww;
	}
	return ww;
}
void clear_file()
{
	ofstream out;
	out.open("Запись.txt", ofstream::out | ofstream::trunc);
	out.close();
	cout<< "File is empty.\n";
	return ;
}


int main()
{
	Tube tb;
	KS ks;
	int menu = -1;
	while (menu)
	{
		cout << "1.Add new tube.\n" << "2.Add new KS.\n" << "3.Added objects.\n"
			<< "4.Change tube.\n" << "5.Change KS.\n" << "6.Add to file\n"
			<< "7.Load from file.\n" << "0.Exit\n" << ">";
		cin >> menu;
		switch (menu)
		{
		case 1:
		{
			cout << "\nLength:";
			cin >> tb.length;
			tb.length = numeric_check(tb.length);
			cout << "\nDiametr:";
			cin >> tb.diametr;
			tb.diametr = numeric_check(tb.diametr);
			cout << "\nEnter 0 if tube is in repair and 1 if it works:";
			cin >> tb.maintenance;
			tb.maintenance = maint_check(tb.maintenance);
			cout << maint_check_2(tb.maintenance) << endl;
			break;
		}
		case 2:
		{
			cout << "\nName:";
			cin >> ks.name;
			cout << "\nTotal number of workshops:";
			cin >> ks.workshops;
			ks.workshops = numeric_check_2(ks.workshops);
			cout << "\nNumber of working workshops:";
			cin >> ks.workingWork;
			ks.workingWork = working_worshops_check(ks.workingWork, ks.workshops);
			ks.efficiency = float(ks.workingWork) / float(ks.workshops)*100;
			cout << ("\nEfficiency:") << ks.efficiency << "%"<< endl;
			break;
		}
		case 3:
		{
			if(tb.length == 0)
				cout << "There is no tube.\n";
			else
				cout << "\nTube.\n" << "\nLength:" << tb.length << "\nDiametr:"
					<< tb.diametr << "\nMaintanance:" << maint_check_2(tb.maintenance) << endl;
			if (ks.name == "")
				cout << "There is no KS.\n";
			else
				cout << "\nKS.\n" << "\nName:" << ks.name << "\nTotal number of workshops:"
					<< ks.workshops << "\nNumber of working workshops:" << ks.workingWork 
					<<"\nEfficiency:" << ks.efficiency << endl;
			break;
		}
		case 4:
		{	if (tb.maintenance == 0)
			{
			cout << "There is no tube to edit.\n";
			break;
			}
			if (tb.maintenance !=0)
				cout << "\nInput new tube status (Enter 1 if tube is in repair and 2 if it works):";
				cin >> tb.maintenance;
				tb.maintenance = maint_check(tb.maintenance);
				cout << maint_check_2(tb.maintenance) << endl;
			break;
		}
		case 5:
		{
			if (ks.workshops == 0)
			{
				cout << "There are no workshops to edit.\n";
				break;
			}
			if (ks.workshops != 0)
				cout << "\nWorkshops:";
				cin >> ks.workshops;
				ks.workshops = numeric_check_2(ks.workshops);
				cout << "\nNumber of working workshops:";
				cin >> ks.workingWork;
				ks.workingWork = working_worshops_check(ks.workingWork, ks.workshops);
				ks.efficiency = float(ks.workingWork) / float(ks.workshops) * 100;
				cout << ("\nEfficiency:") << ks.efficiency << "%" << endl;
			break;
		}
		case 6:
		{
			
			if ((ks.name == "") & (tb.length == 0))
			{
				cout << "There is no data to load.\n";
				break;
			}
			if ((ks.name != "") & (tb.length != 0))
			{
				cout << "Check file.\n";
				ofstream fout;
				fout.open("Запись.txt");
				fout << "\nTube" << endl << "Length:" << tb.length << endl << "Diametr" << tb.diametr
					<< endl << "Maintenance:" << tb.maintenance << endl
					<< "\nKS" << endl << "Name:"<< ks.name << endl <<"Workshops:" <<ks.workshops 
					<< endl <<"Working workshops:"<< ks.workingWork << endl<< "Efficiency: "<<ks.efficiency << endl;
					fout.close();
				break;
			}
			if ((tb.length == 0) &(ks.name != ""))
			{
				cout << "There is no data abot tube to load. Check file for ks information. \n";
				ofstream fout;
				fout.open("Запись.txt");
				fout << "\nKS" << endl << "Name:" << ks.name << endl << "Workshops:" << ks.workshops
					<< endl << "Working workshops:"<< ks.workingWork << endl << "Efficiency: "<<ks.efficiency << endl;
				fout.close();
				break;
			}
			if ((ks.name == "") & (tb.length != 0))
			{
				cout << "There is no data about KS to load. Check file for tube information.\n";
				ofstream fout;
				fout.open("Запись.txt");
				fout << "\nTube" << endl << "Length:" << tb.length << endl << "Diametr" << tb.diametr
					<< endl << "Maintenance:" << tb.maintenance << endl;
				fout.close();
				break;
			}

			break;
		}
		case 7:
		{
			if ((ks.name == "") & (tb.length == 0))
				clear_file();
			string line;
			ifstream fin;
			fin.open("Запись.txt");
			if (fin.is_open())
			{
				while (getline(fin, line))
				{
					cout << line << endl;
				}
			}
			fin.close();
			break;
		}
		case 0:
		{
			return 0;
		}
		default:
			cout << "Input number between 0 and 7" << endl;
			break;
		}
	}
	return 0;
}
