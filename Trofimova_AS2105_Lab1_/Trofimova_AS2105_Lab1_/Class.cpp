#include "check.h"
#include "Class.h"

using namespace std;


void KS::edit_ks() {
	cout << "Workshops: " << workshop << endl;
	cout << "Working workshop: " << working_workshop << endl;
	cout << "Enter new number of working workshops" << endl;
	working_workshop = numberCheck(0, workshop);
}

void Tube::save_tube(ofstream& file) {
	file << idtb << endl << name << endl << lenght << endl << diameter << endl << maintenance << endl;
}
void KS::save_ks(ofstream& file) {
	file << idks << endl << name << endl
		<< workshop << endl << working_workshop << endl << effectiveness << endl;
}
void Tube::load_tube(ifstream& file) {
	file >> idtb;
	getline(file, name);
	getline(file, name);
	file >> lenght;
	file >> diameter;
	file >> maintenance;
}
void KS::load_ks(ifstream& file) {
	file >> idks;

	getline(file, name);
	getline(file, name); 
	file >> workshop;
	file >> working_workshop;
	file >> effectiveness;
}