﻿#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include "Class.h"


using namespace std;

int check_menu()
{
	int menu;
	while (((cin >> menu).fail()) || (cin.peek() != '\n'))
	{
		cout << "Input number between 0 and 7" << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}
	return menu;
}
void menu_list()
{
	cout << "1.Add new tube.\n" << "2.Add new KS.\n" << "3.Added objects.\n"
		<< "4.Change tube.\n" << "5.Change KS.\n" << "6.Add to file\n"
		<< "7.Load from file.\n" << "0.Exit\n" << ">";
}


int main()
{
	Tube tube;
	KS ks;
	unordered_map <int, Tube> tubeMap = {};
	unordered_map <int, KS> KSMap = {};
	int menu = -1;
	while (menu)
	{
		menu_list();
		menu = check_menu();
		switch (menu)
		{
		case 0:
		{
			return 0;
		}
		case 1:
		{
			cin >> tube;
			tubeMap.emplace(tube.MaxIdTb, tube);
			cout << " " << endl;
			break;
		}
		case 2:
		{
			cin >> ks;
			KSMap.emplace(ks.MaxIdKs, ks);
			cout << " " << endl;
			break;
		}
		case 3:
		{
			cout << " " << endl;
			if (tubeMap.size() != 0)
			{
				//for (const auto& [id, tube] : tubeMap)
				//{
					cout << tube << endl;
				//}
			}
			else cout << "There are no tubes" << endl;
			if (KSMap.size() != 0)
			{
				//for (const auto& [id, ks] : KSMap)
				//{
					cout << ks << endl;
				//}
			}
			else
				cout << "There are no KS" << endl;
			break;
		}
		default:
			cout << "Input correct number between 0 and 7.\n";
			break;
		}
	}
	return 0;
}

/*
void added_objects(Tube& tb, KS& ks)
{
	if (tb.length == 0)
		cout << "There is no tube.\n";
	else
		cout << "\nTube.\n" << "\nLength:" << tb.length << "\nDiametr:"
		<< tb.diametr << "\nMaintanance:" << maintenance(tb.maintenance) << endl;
	if (ks.workshops==0)
		cout << "There is no KS.\n";
	else
		cout << "\nKS.\n" << "\nName:" << ks.name << "\nTotal number of workshops:"
		<< ks.workshops << "\nNumber of working workshops:" << ks.workingWork
		<< "\nEfficiency:" << ks.efficiency << endl;
}
void edit_tube(Tube& tb)
{
	if (tb.maintenance == 2)
	{
		cout << "There is no tube to edit.\n";
	}
	if (tb.maintenance != 2)
	{
		cout << "\nInput new tube status (Enter 0 if tube is in repair and 1 if it works):";
		tb.maintenance = maintenance_check();
		cout << maintenance(tb.maintenance) << endl;
	}
}
void edit_ks(KS& ks)
{
	if (ks.workshops == 0)
	{
		cout << "There are no workshops to edit.\n";
	}
	if (ks.workshops != 0)
	{
		cout << "\nWorkshops:";
		ks.workshops = integer_check();
		cout << "\nNumber of working workshops:";
		ks.workingWork = working_worshops_check( ks.workshops);
		ks.efficiency = float(ks.workingWork) / float(ks.workshops) * 100;
		cout << ("\nEfficiency:") << ks.efficiency << "%" << endl;
	}
}
void load_to_file(Tube& tb, KS& ks)
{
	ofstream fout;
	fout.open("Запись.txt");
	if (fout.is_open())
	{
		if (tb.length != 0)
		{
			fout << "1" << endl << tb.length << endl << tb.diametr << endl << tb.maintenance << endl;
		}
		else fout << "0" << endl;

		if (ks.workshops != 0)
		{
			fout << "1" << endl << ks.name << endl << ks.workshops << endl << ks.workingWork << endl << ks.efficiency << endl;
		}
		else fout << "0" << endl;
		fout.close();
	}
}

void read_from_file(Tube&tb, KS&ks)
{
	ifstream fin;
	fin.open("Запись.txt");
	int presence;
	string line;
	if (fin.is_open())
	{
		fin >> presence;
		if (presence == 1)
		{
			fin >> tb.length >> tb.diametr >> tb.maintenance;
			cout << "Data has been loaded." << endl;
		}

		fin >> presence;
		if (presence == 1)
		{
			getline(fin >>ws, ks.name);
			fin  >> ks.workshops >> ks.workingWork >> ks.efficiency;
		}
	}
	else
	{
		cout << "There is no file." << endl;
	}
	fin.close();
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
		menu = check_menu();
		switch (menu)
		{
		case 1:
		{
			add_tube(tb);
			break;
		}
		case 2:
		{
			add_ks(ks);
			break;
		}
		case 3:
		{
			added_objects(tb,ks);
			break;
		}
		case 4:
		{	
			edit_tube(tb);
			break;
		}
		case 5:
		{
			edit_ks(ks);
			break;
		}
		case 6:
		{
			load_to_file(tb, ks);
			break;
		}
		case 7:
		{
			read_from_file(tb, ks);
			break;
		}
		case 0:
		{
			return 0;
		}
		default:
			cout << "Input correct number between 0 and 7.\n";
			break;
		}
	}
	return 0;
}
*/