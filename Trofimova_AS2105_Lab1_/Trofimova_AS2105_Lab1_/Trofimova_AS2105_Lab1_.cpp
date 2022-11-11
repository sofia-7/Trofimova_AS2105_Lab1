#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <float.h>
#include <unordered_map>
#include <unordered_set>
#include "tube.h"
#include "KS.h"
#include "check.h"
using namespace std;

template <typename T>
using tube_filter = bool (*) (Tube& tb, T param);
template <typename T>
using ks_filter = bool(*) (KS& ks, T param);
template <typename T>

vector <int> search_tb_by_parametr(unordered_map <int, Tube>& tubeMap, tube_filter<T> f, T param) {
    vector <int> search;
    for (auto& tube : tubeMap) {
        if (f(tube.second, param))
            search.push_back(tube.second.get_id_tb());
    }
    return search; 
}
template <typename T>
vector <int> search_ks_by_parametr(unordered_map <int, KS>& KSMap, ks_filter<T> f, T param) {
    vector <int> search;
    for (auto& ks : KSMap) {
        if (f(ks.second, param))
            search.push_back(ks.second.get_id_ks());
    }
    return search;
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
bool check_unworking(KS& ks, double ws) {
    return (ks.get_unused_ws() >= ws);
}
void search_tb(unordered_map <int, Tube>& tubeMap, vector<int>& search) {
    int x;
    cout << "Search tube by 1.name 2.maintenance" << endl;
    x = numberCheck(1, 2);
    if (x == 1) {
        string name;
        cout << "Enter the name of tube: " << endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        getline(cin, name);
        search = search_tb_by_parametr(tubeMap, check_tb_name, name);
    }
    else {
        bool k;
        cout << "Enter maintenance of tube (0 if repairing, 1 if in work): " << endl;
        k = numberCheck(0, 1);
        search = search_tb_by_parametr(tubeMap, check_tb_maintenance, k);
    }
}
void search_ks(unordered_map <int, KS>& KSMap, vector<int>& search) {
    int x;
    cout << "Search KS by 1.name 2.percentage of unused shops" << endl;
    x = numberCheck(1, 2);
    if (x == 1) {
        string name;
        cout << "Enter the name of KS: " << endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        getline(cin, name);
        search = search_ks_by_parametr(KSMap, check_ks_name, name);

    }
    else {
        double k;
        cout << "Enter the percentage of unworking workshops:" << endl;
        k = numberCheck(0, 100);
        search = search_ks_by_parametr(KSMap, check_unworking, k);
    }

}
void information( unordered_map<int, Tube>& tubeMap, unordered_map<int, KS>& KSMap) {
    for (auto& tube : tubeMap) {
        cout << tube.second << endl;
    }
    for (auto& ks : KSMap) {
        cout << ks.second << endl;
    }
}
ostream& operator<< (ostream& out, unordered_set <int>& id) {
    out << "Exicting id: ";
    for (auto& i : id) {
        out << i << " ";
    }
    out << endl;
    return out;
}

void Menu()
{
    cout << "\n1.Add tube \n2.Add KS\n3.View all objects " <<
        "\n4.Edit tube \n5.Edit KS \n6.Save \n7.Load \n8.Search tube \n9.Search KS \n0.Exit\n";
}
void load_to_file(unordered_map<int, Tube>& tubeMap, unordered_map<int, KS>& KSMap)
{
    string filename;
    cout << "Enter the name of file " << endl;
    cin >> filename;
    ofstream file;
    file.open(filename + ".txt");
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
    file.close();
}
void load_from_file(unordered_map<int, Tube>& tubeMap, unordered_map<int, KS>& KSMap)
{
    string filename;
    int strNum, strNum2;
    Tube newTB;
    KS newKS;
    cout << "Enter the name of file  " << endl;
    cin >> filename;
    ifstream file;
    file.open(filename + ".txt");
    if (!file)
        cout << "There is no such file";
    else {
        Tube::max_id_tb = 0;
        KS::max_id_ks = 0;
        tubeMap.clear();
        KSMap.clear();
        file >> strNum >> strNum2;
        for (int i = 0; i < strNum; i++) {
            newTB.load_tube(file);
            tubeMap.insert({ newTB.get_id_tb(),newTB });
            if (Tube::max_id_tb < newTB.get_id_tb())
                Tube::max_id_tb = newTB.get_id_tb();
        }
        for (int i = 0; i < strNum2; i++) {
            newKS.load_ks(file);
            KSMap.insert({ newKS.get_id_ks(),newKS });
            if (KS::max_id_ks < newKS.get_id_ks());
            KS::max_id_ks = newKS.get_id_ks();

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
    int filter;
    Tube tb;
    vector <int> id;
    if (tubeMap.size() != 0) 
    {
        cout << "1.Choose one tube \n2.Choose tubes \n3.Delete tube" << endl;;
        edit = numberCheck(1, 3);
        if (edit == 1) {
            cout << "1.Choose tube to edit" << endl;
            cout << id_tb;
            id1 = numberCheck(0, (int)tubeMap.size());
            tubeMap[id1].edit_Tube();
        }
        if (edit == 2) 
        {
            cout << "Choose tubes by 1.filter 2.id" << endl;
            filter = numberCheck(1, 2);
            if (filter == 1) {
                search_tb(tubeMap, id);
                //cout << "Enter new maintenance (0 if repairing, 1 if works)" << endl;
                bool maintenance;
                maintenance = numberCheck(0, 1);
                for (auto& i : id)
                    tubeMap[i].maintenance = maintenance;
            }
            if (filter == 2) {
                unordered_set <int> ids;
                cout << "Enter the number of identifiers of tube you want to edit" << endl;
                int n;
                n = numberCheck(0, Tube::max_id_tb);
                cout << "Enter idetifiers of tubes" << endl;
                int y;
                for (int i = 0; i < n; i++) {
                    y = numberCheck(0, Tube::max_id_tb - 1);
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
            cout << "1. identifier of one tube you want to delete 2.delete some tubes" << endl;
            int d;
            d = numberCheck(1, 2);
            if (d == 1) {
                cout << id_tb;
                cout << "Enter id of pipe you want to delete" << endl;
                int n;
                n = numberCheck(0, (int)tubeMap.size());
                if (id_tb.find(n) != id_tb.end()) {
                    tubeMap.erase(tubeMap.find(n));
                }
            }
            else {
                unordered_set <int> idtb;
                cout << "1.delete by filter 2.delete by id" << endl;
                int n;
                n = numberCheck(1, 2);
                int x;
                if (n == 2) {
                    cout << id_tb;
                    cout << "Enter the number of pipe you want to edit" << endl;;
                    int y;
                    y = numberCheck(1, (int)tubeMap.size());
                    cout << "Enter idetifiers of tubes" << endl;
                    for (int i = 0; i < y; i++) {
                        cin >> x;
                        if (id_tb.find(x) != id_tb.end()) {
                            idtb.insert(x);
                        }
                        else
                        {
                            i = i - 1;
                            cout << "There is no such tube" << endl;
                        }
                    }
                    for (auto& pi : idtb) {
                        tubeMap.erase(tubeMap.find(pi));
                    }
                }
                else {
                    search_tb(tubeMap, id);
                    if (id.size() != 0)
                    {
                        for (auto& i : id)
                            tubeMap.erase(tubeMap.find(i));
                    }
                    else
                    {
                        cout << "There is no such pipe" << endl;
                    }
                }
            }
        }

        cout << "Pipe was deleted";
        }
    else
        cout << "There is no tube to edit" << endl;
}
void edit_ks(unordered_map<int, KS>& KSMap)
{
    vector <int> idks;
    if (KSMap.size() != 0) {
        cout << "1.Edit one KS 2.Edit KS 3.Delete KS" << endl;
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
                y = numberCheck(0, KS::max_id_ks);
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
                n = numberCheck(0, KS::max_id_ks);
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
                    y = numberCheck(0, KS::max_id_ks);
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
{   unordered_map<int, Tube> tubeMap;
    unordered_map<int, KS> KSMap;
    while (1)
    {
        Menu();
        switch (numberCheck(0, 9))
        {
        case 1: {
            id_tb.insert(Tube::max_id_tb);
            Tube tb;
            cin >> tb;
            tubeMap.insert({ tb.get_id_tb(), tb });
            break;
        }
        case 2: {
            iddks.insert(KS::max_id_ks);
            KS ks;
            cin >> ks;
            KSMap.insert({ ks.get_id_ks(), ks });
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
            load_to_file(tubeMap, KSMap);
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
        }
    }
    return 0;
}