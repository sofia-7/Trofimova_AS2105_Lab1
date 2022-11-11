#include "tube.h"
#include "check.h"


int Tube::max_id_tb = 0;
int KS::max_id_ks = 0;

string Tube:: maintenance_check(bool x)
{
    if (x == true)
        return ("Tube works");
    else if (x == false)
        return ("Tube is repairing");
}

using namespace std;

istream& operator>> (istream& in, Tube& tb)
{
    cout << "\n Index of tube: " << tb.idp;
    cout << "\nInput name ";

    cin.clear();
    cin.ignore(INT_MAX, '\n');

    getline(cin, tb.name);
    cout << "\nLenght: ";
    tb.lenght = numberCheck(0.0, DBL_MAX);
    cout << "\nDiameter: ";
    tb.diameter = numberCheck(0.0, DBL_MAX);
    cout << "\nChoose maintenance of tube (0 if repairing, 1 if works): ";
    tb.maintenance = numberCheck(0, 1);
    cout << tb.maintenance_check(tb.maintenance) << endl;
    return in;
}
istream& operator>> (istream& in, KS& ks)
{
    cout << "\nIndex of ks: " << ks.idks;
    cout << "\nName ";
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    getline(cin, ks.name);
    cout << "\nWorkshops: ";
    ks.workshop = numberCheck(0, INT_MAX);
    cout << "\nWorking workshops: ";
    ks.working_workshop = numberCheck(0, ks.workshop);
    cout << "\nEffectiveness: ";
    ks.effectiveness = numberCheck(0, 100);
    return in;
}
ostream& operator<< (ostream& out, Tube& tb) {
    out << "\nIndex of tube: " << tb.idp << "\nName: " << tb.name << "\nLenght: "
        << tb.lenght << "\nDiameter : " << tb.diameter
        << "\nStatus: " << tb.maintenance_check(tb.maintenance) << endl;
    return out;
}
ostream& operator<< (ostream& out, KS& ks) {
    out << "\nIndex of KS: " << ks.idks << "\nName: " << ks.name << "\nWorkshops: " << ks.workshop
        << "\nWorking workshops: " << ks.working_workshop << "\nEffectiveness: "
        << ks.effectiveness << "%" << endl;
    return out;
}
void KS::edit_ks() {
    cout << "Workshops: " << workshop << endl;
    cout << "Working workshop: " << working_workshop << endl;
    cout << "Enter new number of working workshops:" << endl;
    working_workshop = numberCheck(0, workshop);
}
void Tube::edit_Tube() {
    cout << "Status: " << maintenance_check(maintenance) << endl;
    cout << "Enter new maintenance of tube (0 if in repairing, 1 if works):" << endl;
    maintenance = numberCheck(0, 1);
    cout << maintenance_check(maintenance);
}
void Tube::save_tube(ofstream& file) {
    file << idp << endl << name << endl << lenght << endl << diameter << endl << maintenance << endl;
}
void KS::save_ks(ofstream& file) {
    file << idks << endl << name << endl
        << workshop << endl << working_workshop << endl << effectiveness << endl;
}
void Tube::load_tube(ifstream& file) {
    file >> idp;
    getline(file, name);
    getline(file, name);
    file >> lenght;
    file >> diameter;
    file >> maintenance;
}
void KS::load_ks(ifstream& file) {
    file >> idks;
    iddks.insert(idks);
    getline(file, name);
    getline(file, name);
    file >> workshop;
    file >> working_workshop;
    file >> effectiveness;
}