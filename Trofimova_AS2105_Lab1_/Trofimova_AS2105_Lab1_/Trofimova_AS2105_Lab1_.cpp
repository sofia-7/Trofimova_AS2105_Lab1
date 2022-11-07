#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <float.h>
#include <unordered_map>
#include <unordered_set>
#include "Class.h"
#include "check.h"
using namespace std;

template <typename T>
using filter_p = bool (*) (Tube& tb, T param);
template <typename T>
using filter_ks = bool(*) (KS& ks, T param);
template <typename T>
vector <int> search_tb_by_parametr(unordered_map <int, Tube>& tubeMap, filter_p<T> f, T param) {
    vector <int> id;
    for (auto& tube : tubeMap) {
        if (f(tube.second, param))
            id.push_back(tube.second.get_id());
    }
    return id;
}
template <typename T>
vector <int> search_ks_by_parametr(unordered_map <int, KS>& KSMap, filter_ks<T> f, T param) {
    vector <int> id;
    for (auto& ks : KSMap) {
        if (f(ks.second, param))
            id.push_back(ks.second.get_idd());
    }
    return id;
}
bool check_tb_name(Tube& tb, string name) {
    return (tb.name.find(name) != string::npos);
}
bool check_tb_maintenance(Tube& tb, bool maintenance) {
    return (tb.maintenance == maintenance);
}
bool check_ks_name(KS& ks, string name) {
    return (ks.name.find(name) != string::npos);
}
bool check_unworking(KS& ks, double tb) {
    return (ks.get_unused() >= tb);
}
void search_tb(unordered_map <int, Tube>& tubeMap, vector<int>& id) {
    int x;
    cout << "Search tube by 1.name 2.maintenance" << endl;
    x = numberCheck(1, 2);
    if (x == 1) {
        string name;
        cout << "Enter the name of tube: " << endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        getline(cin, name);
        id = search_tb_by_parametr(tubeMap, check_tb_name, name);
    }
    else {
        bool k;
        cout << "Enter maintenance of tube (0 if repairing, 1 if in work): " << endl;
        k = numberCheck(0, 1);
        id = search_tb_by_parametr(tubeMap, check_tb_maintenance, k);
    }
}
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
    cout << maintenance_check(tb.maintenance) << endl;
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
    out << "\nIndex of tube: " << tb.idp  << "\nName: " << tb.name << "\nLenght: "
        << tb.lenght << "\nDiameter : " << tb.diameter
        << "\nStatus: " << maintenance_check(tb.maintenance) << endl;
    return out;
}
ostream& operator<< (ostream& out, KS& ks) {
    out << "\nIndex of KS: " << ks.idks << "\nName: " << ks.name << "\nWorkshops: " << ks.workshop
        << "\nWorking workshops: " << ks.working_workshop << "\nEffectiveness: "
        << ks.effectiveness << "%" << endl;
    return out;
}
ostream& operator<< (ostream& out, unordered_set <int>& tb) {
    out << "Exicting id: ";
    for (auto& i : tb) {
        out << i << " ";
    }
    out << endl;
    return out;
}
void search_ks(unordered_map <int, KS>& KSMap, vector<int>& id) {
    int x;
    cout << "Search KS by 1.name 2.percentage of unused shops" << endl;
    x = numberCheck(1, 2);
    if (x == 1) {
        string name;
        cout << "Enter the name of KS: " << endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        getline(cin, name);
        id = search_ks_by_parametr(KSMap, check_ks_name, name);

    }
    else {
        double k;
        cout << "Enter the percentage of unused shops:" << endl;
        k = numberCheck(0, 100);
        id = search_ks_by_parametr(KSMap, check_unworking, k);
    }

}
void information(unordered_map<int, Tube>& tubeMap, unordered_map<int, KS>& KSMap) {
    for (auto& tube : tubeMap) {
        cout << tube.second << endl;
    }
    for (auto& ks : KSMap) {
        cout << ks.second << endl;
    }
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

    getline(file, name);
    getline(file, name);
    file >> workshop;
    file >> working_workshop;
    file >> effectiveness;
}

void load_to_file(unordered_map<int, Tube>& tubeMap, unordered_map<int, KS>& KSMap)
{
    string x;
    cout << "Enter the name of file " << endl;
    cin >> x;
    ofstream file;
    file.open(x + ".txt");
    if (!file)
        cout << "Error" << endl;
    else {
        file << tubeMap.size() << " " << KSMap.size() << endl;
        for (auto tube : tubeMap)
            tube.second.save_tube(file);
        for (auto ks : KSMap)
            ks.second.save_ks(file);
    }
    cout << "Data is loaded";
}
void Menu()
{
    cout << "\n1.Add tube \n2.Add KS\n3.View all objects " <<
        "\n4.Edit tube \n5.Edit KS \n6.Save \n7.Load \n8.Search tube \n9.Search KS \n0.Exit\n";
}

void load_from_file(unordered_map<int, Tube>& tubeMap, unordered_map<int, KS>& KSMap)
{
    string x;
    int len1, len2;
    Tube newP;
    KS newKS;
    cout << "Enter the name of file  " << endl;
    cin >> x;
    ifstream file;
    file.open(x + ".txt");
    if (!file)
        cout << "There is no such file";
    else {
        Tube::max_id = 0;
        KS::max_idd = 0;
        tubeMap.clear();
        KSMap.clear();
        file >> len1 >> len2;
        for (int i = 0; i < len1; i++) {
            newP.load_tube(file);
            tubeMap.insert({ newP.get_id(),newP });
            if (Tube::max_id < newP.get_id())
                Tube::max_id = newP.get_id();

        }
        for (int i = 0; i < len2; i++) {
            newKS.load_ks(file);
            KSMap.insert({ newKS.get_idd(),newKS });
            if (KS::max_idd < newKS.get_idd());
            KS::max_idd = newKS.get_idd();

        }
        cout << "Data is loaded";
    }
}
void search_tube(unordered_map<int, Tube>& tubeMap)
{
    vector <int> x;
    if (tubeMap.size() != 0) {
        search_tb(tubeMap, x);
        if (x.size() != 0) {
            for (auto& i : x)
                cout << tubeMap[i] << endl;
        }
        else
            cout << "There is no such tube" << endl;
    }
    else
        cout << "There is no tube to find" << endl;
}
void tube_edit(unordered_map<int, Tube>& tubeMap)
{
    int edit;
    int id1;
    int x;
    Tube tb;
    if (tubeMap.size() != 0) {
        cout << "1.Choose one tube \n2.Choose tubes \n3.Delete tube" << endl;;
        edit = numberCheck(1, 3);
        if (edit == 1) {
            cout << "1.Choose tube to edit" << endl;
            cout << iddtb;
            id1 = numberCheck(0, (int)tubeMap.size());
            tubeMap[id1].edit_Tube();

        }
        if (edit == 2) {
            vector <int> idp;
            cout << "Choose tubes by 1.filter 2.id" << endl;
            x = numberCheck(1, 2);
            if (x == 1) {
                search_tb(tubeMap, idp);
                cout << "Enter new maintenance (0 if repairing, 1 if works)" << endl;
                bool s;
                s = numberCheck(0, 1);
                for (auto& i : idp)
                    tubeMap[i].maintenance = s;
            }
            if (x == 2) {
                unordered_set <int> ids;
                cout << "Enter the number of identifiers of tube you want to edit" << endl;
                int n;
                n = numberCheck(0, Tube::max_id);
                cout << "Enter idetifiers of tubes" << endl;
                int y;
                for (int i = 0; i < n; i++) {
                    y = numberCheck(0, Tube::max_id - 1);
                    if (tubeMap.find(y) != tubeMap.end())
                        ids.insert(y);

                }
                cout << "Enter new maintenance (0 if repairing, 1 if works)" << endl;
                bool s;
                s = numberCheck(0, 1);
                for (auto& i : ids)
                    tubeMap[i].maintenance = s;
            }
        }
        if (edit == 3) {
            cout << "Enter the id of tube you want to delete" << endl;
            int n;
            n = numberCheck(0, Tube::max_id);
            tubeMap.erase(tubeMap.find(n));
            iddtb.erase(iddtb.find(n));
            cout << "Tube was deleted";
        }
    }
    else
        cout << "There is no tube to edit" << endl;
}
void edit_ks(unordered_map<int, KS>& KSMap)
{
    vector <int> idks;
    if (KSMap.size() != 0) {
        cout << "1.Edit one KS 2.Edit KSs 3.Delete KS" << endl;
        int edit;
        edit = numberCheck(1, 3);
        if (edit == 1) {
            int id;
            cout << "Choose KS to edit" << endl;
            id = numberCheck(0, (int)KSMap.size());
            KSMap[id].edit_ks();
        }
        if (edit == 2) {
            unordered_set <int> idw;
            cout << "Choose  by 1.filter 2.id" << endl;
            int n;
            n = numberCheck(1, 2);
            if (n == 2) {
                cout << "Enter the number of ks you want to edit";
                int y;
                y = numberCheck(0, KS::max_idd);
                cout << "Enter idetifiers of KSs" << endl;
                for (int i = 0; i < y; i++) {
                    if (KSMap.find(i) != KSMap.end())
                        idw.insert(i);

                }
                for (auto& i : idw)
                    KSMap[i].edit_ks();

            }
            else {
                search_ks(KSMap, idks);
                for (auto& i : idks)
                    KSMap[i].edit_ks();
            }

        }
        if (edit == 3) {
            cout << "1. identifier of one KS you want to delete 2.delete some KS" << endl;
            int d;
            d = numberCheck(1, 2);
            if (d == 1) {
                cout << "Enter id of KS you want to delete" << endl;
                int n;
                n = numberCheck(0, KS::max_idd);
                KSMap.erase(KSMap.find(n));
            }
            else {
                unordered_set <int> idd;
                cout << "1.delete by filter 2.delete by id" << endl;
                int n;
                n = numberCheck(1, 2);
                if (n == 2) {
                    cout << "Enter the number of ks you want to edit";
                    int y;
                    y = numberCheck(0, KS::max_idd);
                    cout << "Enter idetifiers of KSs" << endl;
                    for (int i = 0; i < y; i++) {
                        if (KSMap.find(i) != KSMap.end())
                            idd.insert(i);
                    }
                    for (auto& i : idd)
                        KSMap.erase(KSMap.find(i));
                }
                else {
                    search_ks(KSMap, idks);
                    for (auto& i : idks)
                        KSMap.erase(KSMap.find(i));
                    for (auto& i : iddks)
                        iddks.erase(i);
                }

                cout << "KS was deleted";
            }
        }
    }
    else
        cout << "There is no KS to edit" << endl;
}
void ks_search(unordered_map<int, KS>& KSMap)
{
    vector <int> x;
    if (KSMap.size() != 0) {
        search_ks(KSMap, x);
        if (x.size() != 0) {
            for (auto& i : x)
                cout << KSMap[i] << endl;
        }
        else
            cout << "There is no such KS";
    }
    else
        cout << "There is no KS to find" << endl;
}

int main()
{
    int menu = -1;
    unordered_map<int, Tube> tubeMap;
    unordered_map<int, KS> KSMap;
    while (menu) {
        Menu();
        menu = numberCheck(0, 9);
        switch (menu) {
        case 1: {
            iddtb.insert(Tube::max_id);
            Tube tb;
            cin >> tb;
            tubeMap.insert({ tb.get_id(), tb });
            break;
        }
        case 2: {
            KS ks;
            cin >> ks;
            KSMap.insert({ ks.get_idd(), ks });
            break;
        }
        case 3: {
            information(tubeMap, KSMap);
            break;
        }
        case 4: {
            tube_edit(tubeMap);
            break;
        }
        case 5: {
            edit_ks(KSMap);
            break;
        }
        case 6: {
            load_to_file(tubeMap,KSMap);
            break;
        }
        case 7: {
            load_from_file(tubeMap, KSMap);
            break;
        }
        case 8: {
            search_tube(tubeMap);
            break;
        }
        case 9: {
            ks_search(KSMap);
            break;
        }
        case 0: {
            return 0;
        }
        default: cout << "Input correct number (0-9)";
            break;
        }
    }
    return 0;
}