#include "KS.h"
#include "check.h"


using namespace std;

int KS::max_id_ks = 0;

istream& operator>> (istream& in, KS& ks)
{
    cout << "\nIndex of ks: " << ks.id;
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

ostream& operator<< (ostream& out, KS& ks) {
    out << "\nIndex of KS: " << ks.id << "\nName: " << ks.name << "\nWorkshops: " << ks.workshop
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
void KS::save_ks(ofstream& file) {
    file << id << endl << name << endl
        << workshop << endl << working_workshop << endl << effectiveness << endl;
}
void KS::load_ks(ifstream& file) {
    file >> id;
    getline(file, name);
    getline(file, name);
    file >> workshop;
    file >> working_workshop;
    file >> effectiveness;
}
