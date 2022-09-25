
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Tube
{
	float length=0, diametr=0;
	int maintenance=-1;
};

struct KS
{
	string name="";
	int workshops=0, workingWork=0;
	float efficiency=0;
};


int main()
{

	Tube tb;
	KS ks;
	int menu = 0;
	cout << "1.Add new tube.\n" << "2.Add new KS.\n" << "3.Added objects.\n" 
		<< "4.Change tube.\n" << "5.Change KS.\n" << "6.Add to file\n"
		<<"7.Load from file.\n" << "0.Exit\n" << ">";
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
			cin >> ks.workshops;
			cout << "\nNumber of working workshops:";
			cin >> ks.workingWork;
			break;
		}
		case 3:
		{
			cout << "\nTube.\n" << "\nLength:" << tb.length << "\nDiametr:" 
				<< tb.diametr << "\nMaintanance:" << tb.maintenance << endl;
			cout << "\nKS.\n" << "\nName:" << ks.name << "\nTotal number of workshops:" 
				<< ks.workshops << "\nNumber of working workshops:" << ks.workingWork << endl;
			break;
		}
		case 4:
		{
			cout << "\nInput new tube status (Enter 0 if tube is in repair and 1 if it works):";
			cin >> tb.maintenance;
			break;
		}
		case 5:
		{
			cout << "\nWorkshops:";
			cin >> ks.workshops;
			cout << "\nWorking workshops:";
			cin >> ks.workingWork;
			break;
		}
		case 6:
		{
			ofstream fout;
			fout.open("Запись.txt");
				fout << "\nTube" << endl << tb.length << endl << tb.diametr << endl << tb.maintenance << endl
					<< "\nKS" << endl << ks.name << endl << ks.workshops << endl << ks.workingWork << endl
					<< ks.efficiency << endl;
				fout.close();
				break;
		}
		case 7:
		{
			ifstream fin;
			string line;
			fin.open("Запись.txt");
			getline(fin, line);
			tb.length = stoi(line);
			getline(fin, line);
			tb.diametr = stoi(line);
			getline(fin, line);
			tb.maintenance = stoi(line);
			getline(fin, line);
			ks.name = line;
			getline(fin, line);
			ks.workshops = stoi(line);
			getline(fin, line);
			ks.workingWork = stoi(line);
			getline(fin, line);
			ks.efficiency = stoi(line);
			break;
		}
		case 0:
		{
			return 0;
		}

	}
	return 0;
}
