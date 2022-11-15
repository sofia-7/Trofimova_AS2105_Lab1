#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <float.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Tube
{
public:
    static int max_id_tb;
    string name = "";
    bool maintenance = 0;
    Tube() {
        id = max_id_tb++;
    }
    string maintenance_check(bool x);
    friend istream& operator>> (istream& in, Tube& tb);
    //friend ostream& operator<< (ostream& out, unordered_set <int>& tb);
    friend ostream& operator<< (ostream& out, Tube& tb);
    void edit_Tube();
    void save_tube(ofstream& file);
    void load_tube(ifstream& file);
    int get_id_tb() { return id; }
    

private:

    int id = 0;
    double lenght = 0, diameter = 0;

};


//static unordered_set <int> id_tb;
