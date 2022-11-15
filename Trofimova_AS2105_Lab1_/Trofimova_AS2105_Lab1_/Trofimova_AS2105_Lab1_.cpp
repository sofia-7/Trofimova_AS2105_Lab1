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
vector <int> search_tb(unordered_map <int, Tube>& tubeMap) {
    vector<int> search;
    int lookFor;
    cout << "Search tube by 1.name 2.maintenance" << endl;
    lookFor = numberCheck(1, 2);
    if (lookFor == 1) {
        string name;
        cout << "Enter the name of tube: " << endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        getline(cin, name);
        search = search_tb_by_parametr(tubeMap, check_tb_name, name);
    }
    else {
        bool maintenance;
        cout << "Enter maintenance of tube (0 if in maintenance, 1 if in work): " << endl;
        maintenance = numberCheck(0, 1);
        search = search_tb_by_parametr(tubeMap, check_tb_maintenance, maintenance);
    }
    return search;
}
void search_ks(unordered_map <int, KS>& KSMap, vector<int>& search) {
    int lookFor;
    cout << "Search KS by 1.name 2.percentage of unused shops" << endl;
    lookFor = numberCheck(1, 2);
    if (lookFor == 1) {
        string name;
        cout << "Enter the name of KS: " << endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        getline(cin, name);
        search = search_ks_by_parametr(KSMap, check_ks_name, name);

    }
    else {
        double percent;
        cout << "Enter the percentage of unworking workshops:" << endl;
        percent = numberCheck(0, 100);
        search = search_ks_by_parametr(KSMap, check_unworking, percent);
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
//ostream& operator<< (ostream& out, unordered_set <int>& id) {
//    out << "Exicting id: ";
//    for (auto& i : id) {
//        out << i << " ";
//    }
//    out << endl;
//    return out;
//}

void Menu()
{
    cout << "\n1.Add tube \n2.Add KS\n3.All objects " <<
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
        //tubeMap.clear();
        //KSMap.clear();
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
        file.close();
    }
}
void search_tube(unordered_map<int, Tube>& tubeMap)
{
    if (tubeMap.size() != 0)
    {
        auto search = search_tb(tubeMap);
        if (search.size() != 0)
        { 
            for (auto& i : search)
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
    if (tubeMap.size() != 0) 
    {
        cout << "1.Choose one tube \n2.Choose tubes \n3.Delete tube" << endl;;
        int edit = numberCheck(1, 3);
        int numId;
        if (edit == 1) {
            cout << "1.Choose tube to edit" << endl;
            //cout << tubeMap;
            int id1 = numberCheck(0, (int)tubeMap.size());
            if (tubeMap.find(id1) != tubeMap.end())
            {
                tubeMap[id1].edit_Tube();
                cout << "Tube was edited." << endl;
            }
            else
                cout << "There is no such tube.";
        }
        if (edit == 2) 
        {
            cout << "Choose tubes by 1.filter 2.id" << endl;
            int option = numberCheck(1, 2);
            if (option == 1) {
                auto id = search_tb(tubeMap);
                if (id.size() != 0)
                {
                    cout << "Enter new status (0 if in maintenance, 1 if works)" << endl;
                    bool maintenance;
                    maintenance = numberCheck(0, 1);
                    for (auto& i : id)
                        tubeMap[i].maintenance = maintenance;
                }
                else
                    cout << "There is no such tube.";
            }
            if (option == 2) 
            {
                unordered_set <int> ids;
                //cout << tubeMap;
                cout << "Enter the number of identifiers of tube you want to edit" << endl;
                int number;
                number = numberCheck(1, Tube::max_id_tb);
                cout << "Enter idetifiers of tubes" << endl;
                //int numId;
                for (int i = 0; ids.size() < number; i++) 
                {
                    cin >> numId;//
                    //numId = numberCheck(0, Tube::max_id_tb - 1);
                    if (tubeMap.find(numId) != tubeMap.end())
                    {
                        ids.insert(numId);
                    }
                    else
                    {
                        cout<< "There is no such tube.";
                    }
                }
                cout << "Enter new maintenance (0 if repairing, 1 if works)" << endl;
                bool maintenance;
                maintenance = numberCheck(0, 1);
                for (auto& i : ids)
                    tubeMap[i].maintenance = maintenance;
            }
        }
        if (edit == 3) {
            cout << "1. delete one tube 2.delete some tubes" << endl;
            int del;
            del = numberCheck(1, 2);
            if (del == 1) {
                //cout << tubeMap;
                cout << "Enter id of tube you want to delete" << endl;
                int id;
                id = numberCheck(0, Tube::max_id_tb);
                while (tubeMap.find(id) == tubeMap.end()) //
                {
                    cout << "There is no such tube" << endl;
                    id = numberCheck(0, Tube::max_id_tb - 1);
                }
                tubeMap.erase(tubeMap.find(id));
            }
            else {
                unordered_set <int> idtb;
                cout << "1.delete by filter 2.delete by id" << endl;
                int del;
                del = numberCheck(1, 2);
                int idTB;
                if (del == 2) {
                    //cout << tubeMap;
                    cout << "Enter the number of tubes you want to edit" << endl;;
                    int number;
                    int idTB;
                    number = numberCheck(0, (int)tubeMap.size());
                    cout << "Enter idetifiers of tubes" << endl;
                    for (int i = 0; i < number; i++)
                    {
                        idTB = numberCheck(0, Tube::max_id_tb);
                        if (tubeMap.find(idTB) != tubeMap.end()) {
                            idtb.insert(idTB);
                        }
                        else
                        {
                            cout << "There is no such tube" << endl;
                        }
                    }
                    for (auto& tube : idtb) 
                    {
                        tubeMap.erase(tubeMap.find(tube));
                    }
                     cout << "Tube was deleted";
                }
                else {
                    vector <int> id =search_tb(tubeMap);
                    if (id.size() != 0)
                    {
                        for (auto& i : id)
                        {
                            tubeMap.erase(tubeMap.find(i));
                        }
                        cout << "Tube was deleted.";
                    }
                    else
                    {
                        cout << "There is no such tube" << endl;
                    }
                }
            }
        }
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
        int idKS;
        edit = numberCheck(1, 3);
        if (edit == 1) {
            int id;
            //cout << KSMap;
            cout << "Choose KS to edit" << endl;
            id = numberCheck(0, (int)KSMap.size());
            if (KSMap.find(id) != KSMap.end())
            {
                KSMap[id].edit_ks();
                cout << "KS is edited." << endl;
            }
            
        }
        if (edit == 2) {
            unordered_set <int> ids;
            cout << "Choose  by 1.filter 2.id" << endl;
            int option;
            option = numberCheck(1, 2);
            if (option == 2) 
            {
                //cout << KSMap;
                cout << "Enter the number of ks you want to edit";
                int number;
                number = numberCheck(0, KS::max_id_ks);
                cout << "Enter idetifiers of KSs" << endl;
                for (int i = 0; ids.size() < number; i++) 
                {
                    cin >> idKS;
                    if (KSMap.find(idKS) != KSMap.end()) {

                        ids.insert(idKS);
                    } 
                    else 
                    {
                        cout << "There is no such KS" << endl;
                    }
                }
                for (auto& id : ids)
                    KSMap[id].edit_ks();
            }
            else {
                search_ks(KSMap, idks);
                if (idks.size() != 0)
                {
                    for (auto& i : idks)
                        KSMap[i].edit_ks();
                }
                else
                {
                    cout << "There is no such KS" << endl;
                }
            }
        }
        if (edit == 3) {
            cout << "1. delete one KS 2.delete some KS" << endl;
            int del;
            del = numberCheck(1, 2);
            if (del == 1) 
            {
                //cout << KSMap;
                cout << "Enter id of KS you want to delete" << endl;
                int id;
                id = numberCheck(0, KS::max_id_ks);
                while (KSMap.find(id) == KSMap.end())
                {
                    cout << "There is no such KS." << endl;
                    id = numberCheck(0, KS::max_id_ks);
                }
                KSMap.erase(KSMap.find(id));
            }
            else {
                unordered_set <int> idKS;
                cout << "1.delete by filter 2.delete by id" << endl;
                int del;
                del = numberCheck(1, 2);
                if (del == 2) 
                {
                    //cout << KSMap;
                    cout << "Enter the number of ks you want to edit";
                    int number;
                    int id;
                    number = numberCheck(0, KS::max_id_ks);
                    cout << "Enter idetifiers of KSs" << endl;
                    for (int i = 0; i < number; i++) 
                    {
                        id = numberCheck(0, KS::max_id_ks);
                        if (KSMap.find(id) != KSMap.end())
                            idKS.insert(id);
                        else
                        {
                            //i = i - 1;
                            cout << "There is no such KS" << endl;
                        }
                    }
                    for (auto& i : idKS)
                        KSMap.erase(KSMap.find(i));
                }
                else {
                    search_ks(KSMap, idks);
                    if (idks.size()!= 0) 
                    {
                        for (auto& i : idks)
                            KSMap.erase(KSMap.find(i));
                    }
                    else
                    {
                        cout << "There is no such KS" << endl;
                    }
                    //for (auto& i : id_ks)
                       // id_ks.erase(i);
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
    vector <int> search;
    if (KSMap.size() != 0) 
    {
        search_ks(KSMap, search);
        if (search.size() != 0) 
        {

            for (auto& i : search)
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
            Tube tb;
            cin >> tb;
            tubeMap.insert({ tb.get_id_tb(), tb });
            break;
        }
        case 2: {
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