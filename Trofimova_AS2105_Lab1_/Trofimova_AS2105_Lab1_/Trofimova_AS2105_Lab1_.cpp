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
string maintenance_check(bool x)
{
    if (x == true)
        return ("Tube works");
    else if (x == false)
        return ("Tube is repairing");
}
template <typename T>
using filter_p = bool (*) (Tube& p, T par);
template <typename T>
using filter_ks = bool(*) (KS& ks, T par);
template <typename T>
vector <int> search_p_by_parametr(unordered_map <int, Tube>& tube_group, filter_p<T> f, T par) {
    vector <int> id;
    for (auto& tube : tube_group) {
        if (f(tube.second, par))
            id.push_back(tube.second.get_id());
    }
    return id;
}
template <typename T>
vector <int> search_ks_by_parametr(unordered_map <int, KS>& ks_group, filter_ks<T> f, T par) {
    vector <int> id;
    for (auto& ks : ks_group) {
        if (f(ks.second, par))
            id.push_back(ks.second.get_idd());
    }
    return id;
}
bool check_p_name(Tube& p, string name) {
    return (p.name.find(name) != string::npos);
}
bool check_p_maintenance(Tube& p, bool maintenance) {
    return (p.maintenance == maintenance);
}
bool check_ks_name(KS& ks, string name) {
    return (ks.name.find(name) != string::npos);
}
bool check_unworking(KS& ks, double p) {
    return (ks.get_unused() >= p);
}
void search_p(unordered_map <int, Tube>& tube_group, vector<int>& id) {
    int x;
    cout << "Search tube by 1.name 2.maintenance" << endl;
    x = numberCheck(1, 2);
    if (x == 1) {
        string name;
        cout << "Enter the name of tube: " << endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        getline(cin, name);
        id = search_p_by_parametr(tube_group, check_p_name, name);
    }
    else {
        bool k;
        cout << "Enter maintenance of tube (0 if repairing, 1 if in work): " << endl;
        k = numberCheck(0, 1);
        id = search_p_by_parametr(tube_group, check_p_maintenance, k);
    }
}
void Tube::edit_Pipe() {
    cout << "Status: " << maintenance_check(maintenance) << endl;
    cout << "Enter new maintenance of pipe (0 if in repairing, 1 if works)" << endl;
    maintenance = numberCheck(0, 1);
    cout << maintenance_check(maintenance);
}
istream& operator>> (istream& in, Tube& p)
{
    cout << "\n Index of tube: " << p.idtb;
    cout << "\nInput name ";

    cin.clear();
    cin.ignore(INT_MAX, '\n');

    getline(cin, p.name);
    cout << "\nInput lenght ";
    p.lenght = numberCheck(0.0, DBL_MAX);
    cout << "\nInput diameter ";
    p.diameter = numberCheck(0.0, DBL_MAX);
    cout << "\nChoose maintenance of tube (0 if repairing, 1 if works) ";
    p.maintenance = numberCheck(0, 1);
    cout << maintenance_check(p.maintenance) << endl;
    return in;
}
istream& operator>> (istream& in, KS& ks)
{
    cout << "\nIndex of ks: " << ks.idks;
    cout << "\nInput name ";
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    getline(cin, ks.name);
    cout << "\nNumber of workshops ";
    ks.workshop = numberCheck(0, INT_MAX);
    cout << "\nNumber of working workshops ";
    ks.working_workshop = numberCheck(0, ks.workshop);
    cout << "\nEnter the effectiveness ";
    ks.effectiveness = numberCheck(0, 100);
    return in;
}
ostream& operator<< (ostream& out, Tube& p) {
    out << "\nIndex of tube: " << p.idtb << "\nPipe info: " << "\nName: " << p.name << "\nLenght: "
        << p.lenght << "\nDiameter : " << p.diameter
        << "\nStatus: " << maintenance_check(p.maintenance) << endl;
    return out;
}
ostream& operator<< (ostream& out, KS& ks) {
    out << "\nIndex of KS: " << ks.idks << "\nKS info:\nName: " << ks.name << "\nNumber of workshops: " << ks.workshop
        << "\nNumber of working workshops: " << ks.working_workshop << "\nEffectiveness: "
        << ks.effectiveness << "%" << endl;
    return out;
}
ostream& operator<< (ostream& out, unordered_set <int>& p) {
    out << "Exiting id: ";
    for (auto& i : p) {
        out << i << " ";
    }
    out << endl;
    return out;
}

void search_ks(unordered_map <int, KS>& ks_group, vector<int>& id) {
    int x;
    cout << "Search KS by 1.name 2.percentage of unused shops" << endl;
    x = numberCheck(1, 2);
    if (x == 1) {
        string name;
        cout << "Enter the name of KS: " << endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        getline(cin, name);
        id = search_ks_by_parametr(ks_group, check_ks_name, name);

    }
    else {
        double k;
        cout << "Enter the percentage of unused shops" << endl;
        k = numberCheck(0, 100);
        id = search_ks_by_parametr(ks_group, check_unworking, k);
    }

}
void information(unordered_map<int, Tube>& tube_group, unordered_map<int, KS>& ks_group) {
    for (auto& tube : tube_group) {
        cout << tube.second << endl;
    }
    for (auto& ks : ks_group) {
        cout << ks.second << endl;
    }
}

int main()
{
    int option = -1;
    unordered_map<int, Tube> tube_group;
    unordered_map<int, KS> ks_group;
    while (option) {
        cout << "\n 1.Add tube \n2.Add KS \n3.View all objects " <<
            "\n4.Edit tube \n5.Edit KS \n6.Save \n7.Load \n8.Search tube \n9.Search KS \n0.Exit\n";
        option = numberCheck(0, 9);
        switch (option) {
        case 1: {
            iddp.insert(Tube::max_id);
            Tube p;
            cin >> p;
            tube_group.insert({ p.get_id(), p });
            cout << iddp.size();
            break;
        }
        case 2: {
            KS ks;
            cin >> ks;
            ks_group.insert({ ks.get_idd(), ks });
            break;
        }
        case 3: {
            information(tube_group, ks_group);
            break;
        }
        case 4: {
            int edit;
            int id1;
            int x;
            Tube p;
            if (tube_group.size() != 0) {
                cout << "1.Choose one tube 2.Choose tubes 3.Delete tube" << endl;;
                edit = numberCheck(1, 3);
                if (edit == 1) {
                    cout << "1.Choose tube to edit" << endl;
                    cout << iddp;
                    id1 = numberCheck(0, (int)tube_group.size());
                    tube_group[id1].edit_Pipe();

                }
                if (edit == 2) {
                    vector <int> idtb;
                    cout << "Choose tubes by 1.filter 2.id" << endl;
                    x = numberCheck(1, 2);
                    if (x == 1) {
                        search_p(tube_group, idtb);
                        cout << "Enter new maintenance (0 if repairing, 1 if works)" << endl;
                        bool s;
                        s = numberCheck(0, 1);
                        for (auto& i : idtb)
                            tube_group[i].maintenance = s;
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
                            if (tube_group.find(y) != tube_group.end())
                                ids.insert(y);

                        }
                        cout << "Enter new maintenance (0 if repairing, 1 if works)" << endl;
                        bool s;
                        s = numberCheck(0, 1);
                        for (auto& i : ids)
                            tube_group[i].maintenance = s;
                    }
                }
                if (edit == 3) {
                    cout << "Enter the id of tube you want to delete" << endl;
                    int n;
                    n = numberCheck(0, Tube::max_id);
                    tube_group.erase(tube_group.find(n));
                    iddp.erase(iddp.find(n));
                    cout << "Tube was deleted";
                }
            }
            else
                cout << "There is no tube to edit" << endl;
            break;
        }
        case 5: {
            vector <int> idks;
            if (ks_group.size() != 0) {
                cout << "1.Edit one KS 2.Edit KSs 3.Delete KS" << endl;
                int edit;
                edit = numberCheck(1, 3);
                if (edit == 1) {
                    int id;
                    cout << "Choose KS to edit" << endl;
                    id = numberCheck(0, (int)ks_group.size());
                    ks_group[id].edit_ks();
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
                            if (ks_group.find(i) != ks_group.end())
                                idw.insert(i);

                        }
                        for (auto& i : idw)
                            ks_group[i].edit_ks();

                    }
                    else {
                        search_ks(ks_group, idks);
                        for (auto& i : idks)
                            ks_group[i].edit_ks();
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
                        ks_group.erase(ks_group.find(n));
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
                                if (ks_group.find(i) != ks_group.end())
                                    idd.insert(i);
                            }
                            for (auto& i : idd)
                                ks_group.erase(ks_group.find(i));
                        }
                        else {
                            search_ks(ks_group, idks);
                            for (auto& i : idks)
                                ks_group.erase(ks_group.find(i));
                            for (auto& i : iddks)
                                iddks.erase(i);
                        }

                        cout << "KS was deleted";
                    }
                }
            }
            else
                cout << "There is no KS to edit" << endl;
            break;
        }
        case 6: {
            string x;
            cout << "Enter the name of file " << endl;
            cin >> x;
            ofstream file;
            file.open(x + ".txt");
            if (!file)
                cout << "Error" << endl;
            else {
                file << tube_group.size() << " " << ks_group.size() << endl;
                for (auto tube : tube_group)
                    tube.second.save_tube(file);
                for (auto ks : ks_group)
                    ks.second.save_ks(file);
            }
            break;
        }
        case 7: {
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
                tube_group.clear();
                ks_group.clear();
                file >> len1 >> len2;
                for (int i = 0; i < len1; i++) {
                    newP.load_tube(file);
                    tube_group.insert({ newP.get_id(),newP });
                    if (Tube::max_id < newP.get_id())
                        Tube::max_id = newP.get_id();

                }
                for (int i = 0; i < len2; i++) {
                    newKS.load_ks(file);
                    ks_group.insert({ newKS.get_idd(),newKS });
                    if (KS::max_idd < newKS.get_idd());
                    KS::max_idd = newKS.get_idd();

                }
            }
            break;
        }
        case 8: {
            vector <int> x;
            if (tube_group.size() != 0) {
                search_p(tube_group, x);
                if (x.size() != 0) {
                    for (auto& i : x)
                        cout << tube_group[i] << endl;
                }
                else
                    cout << "There is no such tube" << endl;
            }
            else
                cout << "There is no tube to find" << endl;
            break;
        }
        case 9: {
            vector <int> x;
            if (ks_group.size() != 0) {
                search_ks(ks_group, x);
                if (x.size() != 0) {
                    for (auto& i : x)
                        cout << ks_group[i] << endl;
                }
                else
                    cout << "There is no such KS";
            }
            else
                cout << "There is no KS to find" << endl;
            break;
        }
        case 0: {
            return 0;
        }
        default: cout << "Input correct number (0-7)";
            break;
        }
    }
    return 0;
}