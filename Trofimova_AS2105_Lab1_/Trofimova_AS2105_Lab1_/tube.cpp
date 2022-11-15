#include "tube.h"
#include "check.h"


int Tube::max_id_tb = 0;

string Tube:: maintenance_check(bool x)
{
    if (x == true)
        return ("Tube works");
    else if (x == false)
        return ("Tube is in maintenance");
}

using namespace std;

istream& operator>> (istream& in, Tube& tb)
{
    cout << "\n Index of tube: " << tb.id;
    cout << "\nInput name ";
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    getline(cin, tb.name);
    cout << "\nLenght: ";
    tb.lenght = numberCheck(0.0, DBL_MAX);
    cout << "\nDiameter: ";
    tb.diameter = numberCheck(0.0, DBL_MAX);
    cout << "\nChoose maintenance of tube (0 if in maintenance, 1 if works): ";
    tb.maintenance = numberCheck(0, 1);
    cout << tb.maintenance_check(tb.maintenance) << endl;
    return in;
}

ostream& operator<< (ostream& out, Tube& tb) {
    out << "\nIndex of tube: " << tb.id << "\nName: " << tb.name << "\nLenght: "
        << tb.lenght << "\nDiameter : " << tb.diameter
        << "\nStatus: " << tb.maintenance_check(tb.maintenance) << endl;
    return out;
}


void Tube::edit_Tube() {
    cout << "Status: " << maintenance_check(maintenance) << endl;
    cout << "Enter new maintenance of tube (0 if in repairing, 1 if works):" << endl;
    maintenance = numberCheck(0, 1);
    cout << maintenance_check(maintenance);
}
void Tube::save_tube(ofstream& file) {
    file << id << endl << name << endl << lenght << endl << diameter << endl << maintenance << endl;
}

void Tube::load_tube(ifstream& file) {
    file >> id;
    getline(file, name);
    getline(file, name);
    file >> lenght;
    file >> diameter;
    file >> maintenance;
}
