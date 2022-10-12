
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Tube
{
	float length=0, diametr=0;
	bool maintenance=0;
};

struct KS
{
	string name="";
	int workshops=-1, workingWork=-1;
	float efficiency=0;
};

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

string maintenance(bool Maintenance)
{
	if (Maintenance == true)
		return ("Tube is in maintenance\n");
	else if (Maintenance == false)
		return ("Tube works\n");
}

int integer_check()
{
	int workshop;
	while (((cin>>workshop).fail())||(cin.peek()!='\n')||(workshop<=0))
	{
		cout << ("Enter integer number > 0.")<<endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}
	return workshop;
}

int working_worshops_check(int workshop)
{
	int working_workshop;
	while (((cin>>working_workshop).fail())||(cin.peek()!='\n')||(working_workshop <=0)||(working_workshop >workshop))
	{
		cout << ("Enter integer number > 0 and less than total amount of workshops.")<<endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}
	return working_workshop;
}

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
void add_tube(Tube& tb)
{
	cout << "\nLength:";
	tb.length = number_check();
	cout << "\nDiametr:";
	tb.diametr = number_check();
	cout << "\nEnter 0 if tube is in repair and 1 if it works:";
	tb.maintenance = maintenance_check();
	cout << maintenance(tb.maintenance) << endl;
}
void add_ks(KS& ks)
{
	cout << "\nName:";
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	getline(cin,ks.name);
	cout << "\nTotal number of workshops:";
	ks.workshops = integer_check();
	cout << "\nNumber of working workshops:";
	ks.workingWork = working_worshops_check(ks.workshops);
	ks.efficiency = float(ks.workingWork) / float(ks.workshops) * 100;
	cout << ("\nEfficiency:") << ks.efficiency << "%" << endl;
}
void added_objects(Tube& tb, KS& ks)
{
	if (tb.length == 0)
		cout << "There is no tube.\n";
	else
		cout << "\nTube.\n" << "\nLength:" << tb.length << "\nDiametr:"
		<< tb.diametr << "\nMaintanance:" << maintenance(tb.maintenance) << endl;
	if (ks.workshops==-1)
		cout << "There is no KS.\n";
	else
		cout << "\nKS.\n" << "\nName:" << ks.name << "\nTotal number of workshops:"
		<< ks.workshops << "\nNumber of working workshops:" << ks.workingWork
		<< "\nEfficiency:" << ks.efficiency << endl;
}
void edit_tube(Tube& tb)
{
	if (tb.maintenance == 0)
	{
		cout << "There is no tube to edit.\n";
	}
	if (tb.maintenance != 0)
	{
		cout << "\nInput new tube status (Enter 0 if tube is in repair and 1 if it works):";
		tb.maintenance = maintenance_check();
		cout << maintenance(tb.maintenance) << endl;
	}
}
void edit_ks(KS& ks)
{
	if (ks.workshops == -1)
	{
		cout << "There are no workshops to edit.\n";
	}
	if (ks.workshops != -1)
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
	if ((ks.workshops == -1) & (tb.length == 0))
	{
		cout << "There is no data to load.\n";
	}
	if ((ks.workshops != -1) & (tb.length != 0))
	{
		cout << "Check file.\n";
		ofstream fout;
		fout.open("Запись.txt");
		fout  << tb.length << endl << tb.diametr
			<< endl << maintenance(tb.maintenance) 
			<< endl  << ks.name << endl << ks.workshops
			<< endl  << ks.workingWork << endl << ks.efficiency << endl;
		fout.close();
	}
	if ((tb.length == 0) & (ks.workshops != -1))
	{
		cout << "There is no data abot tube to load. Check file for ks information. \n";
		ofstream fout;
		fout.open("Запись.txt");
		fout  << ks.name << endl << ks.workshops
			<< endl << ks.workingWork << endl  << ks.efficiency << endl;
		fout.close();
	}
	if ((ks.workshops == -1) & (tb.length != 0))
	{
		cout << "There is no data about KS to load. Check file for tube information.\n";
		ofstream fout;
		fout.open("Запись.txt");
		fout  << tb.length << endl << tb.diametr
			<< endl << maintenance(tb.maintenance) << endl;
		fout.close();
	}
}
void read_from_file(Tube&tb, KS&ks)
{
	ifstream fin;
	fin.open("Запись.txt");
	if (fin.is_open())
	{
		fin >> tb.length >> tb.diametr >> tb.maintenance;
		fin.ignore();
		fin >> ks.name >> ks.workshops >> ks.workingWork >> ks.efficiency;
		cout << "Data has been loaded." << endl;
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